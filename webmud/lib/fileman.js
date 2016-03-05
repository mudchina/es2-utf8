'use strict';

(function(){

var Class = require('mixin-pro').createClass;

var path = require('path'),
    fs = require('fs');

var FileMan = Class({
  constructor: function FileMan() {
    this.reset();
  },

  reset: function() {
    this.root = '/tmp';
  },

  bind: function(server, root) {
    var fileman = this;
    this.root = root;

    server.addService('listfile', function(req, reply){
      fileman.readDir(req, reply);
    });
    server.addService('readfile', function(req, reply){
      fileman.readFile(req, reply);
    });
    server.addService('writefile', function(req, reply){
      fileman.writeFile(req, reply);
    });
    server.addService('removefile', function(req, reply){
      fileman.removeFileOrDir(req, reply);
    });
  },

  // req = path
  // reply(err, data = ['file', 'dir/', ...])
  readDir: function(req, reply) {
    var f = path.resolve(this.root, req);
    try {
      var list = fs.readdirSync(f);
      for(var i=0; i<list.length; i++) {
        var stat = fs.statSync(path.resolve(f, list[i]));
        if(stat && stat.isDirectory()) list[i] += '/';
      }
      return reply(0, list);
    } catch(e){
      return reply(404);
    };
  },

  // Notice: first version, we handle text file only.

  // req: path
  // reply(err, ret = { path:'xxx', text: 'xxx', binary: ArrayBuffer });
  readFile: function(req, reply) {
    var f = path.resolve(this.root, req);
    try {
      var content = fs.readFileSync(f);
      return reply(0, content);
    } catch(e){
      return reply(404);
    };
  },

  // req = { path:'xxx', text: 'xxx', binary: ArrayBuffer }
  // reply(err, ret = 'text message');
  writeFile: function(req, reply) {
    var f = path.resolve(this.root, req.path);
    try {
      if(!this.ensureWriteDir(f))
        reply(403, 'Denied');

      if(req.text) {
        fs.writeFileSync(f, req.text);

      } else if(req.binary) {
        // TODO:
        // var content = decode(req.binary);
        // fs.writeFileSync(f, content);
        return reply(400, 'binary not supported yet');
      } else {
        return reply(400, 'no text or binary data');
      }
      return reply(0, 'OK');
    } catch(e){
      return reply(404);
    };
  },

  // req: path
  // reply(err, ret = 'text message');
  removeFileOrDir: function(req, reply) {
    var f = path.resolve(this.root, req);
    var stat = null;
    try {
      stat = fs.statSync(f);
    } catch(e) {}
    if(!stat) 
      return reply(404);

    try {
      if(stat.isDirectory()) {
        fs.rmdirSync(f);
      } else if(stat.isFile()){
        fs.unlinkSync(f);
      }
      return reply(0, 'OK');
    } catch(e){
      return reply(403);
    };
  },

  // make sure dir for file exits, if not exists, create recursively
  ensureWriteDir: function(f) {
    var fileman = this;

    var basedir = path.dirname(f);
    var stat = null;
    try {
      stat = fs.statSync(basedir);
    } catch(e) {};

    if(!stat) {
      if(!this.ensureWriteDir(basedir)) 
        return false;

      try {
        fs.mkdirSync(basedir);
      } catch(e) {
        return false;
      }
    }

    return true;
  },
});

exports = module.exports = FileMan;

})();
