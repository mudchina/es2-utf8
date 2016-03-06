'use strict';

(function(){

var Class = require('mixin-pro').createClass;

var path = require('path'),
    fs = require('fs'),
    parser = require('./parsemap');

var FileMan = Class({
  constructor: function FileMan() {
    this.reset();
  },

  reset: function() {
    this.server = null;
    this.root = '/tmp';
  },

  bind: function(server, root) {
    this.server = server;
    this.root = root;

    // bind service to server
    var services = {
      readfile: this.readFile,
      writefile: this.writeFile,
      listfile: this.readDir,
      removefile: this.removeFileOrDir,
      loadmap: this.parseMap,
    };
    for(var k in services) {
      server.addService(k, services[k], this);
    }
  },

  parseMap: function(args, reply) {
    console.log('parseMap');
    var map = parser.parseMap(this.root, ['d','u']);
    if(map) {
      // cache to www/mapdata.js
      try {
        var mapdatafile = path.resolve(__dirname, '../www/mapdata.js');
        var text = JSON.stringify(map, null, '  ');
        fs.writeFileSync(mapdatafile, 'var mapdata = \n' + text + ';\n', 'utf8');
        return reply(0, map);
      } catch(e) {
        return reply(403);
      }
    } else return reply(404);
  },

  // req = path
  // reply(err, data = ['file', 'dir/', ...])
  readDir: function(args, reply) {
    var f = path.resolve(this.root + args);
    try {
      console.log('readDir', f);
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
  readFile: function(args, reply) {
    var f = path.resolve(this.root + args);
    try {
      console.log('readFile', f);
      var content = fs.readFileSync(f);
      return reply(0, content);
    } catch(e){
      return reply(404);
    };
  },

  // req = { path:'xxx', text: 'xxx', binary: ArrayBuffer }
  // reply(err, ret = 'text message');
  writeFile: function(args, reply) {
    var f = path.resolve(this.root + args.path);
    try {
      if(!this.ensureWriteDir(f))
        reply(403, 'Denied');

      if(args.text) {
        fs.writeFileSync(f, args.text);
        console.log('writeFile', f);

      } else if(args.binary) {
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
  removeFileOrDir: function(args, reply) {
    var f = path.resolve(this.root + args);
    var stat = null;
    try {
      stat = fs.statSync(f);
    } catch(e) {}
    if(!stat) 
      return reply(404);

    try {
      console.log('removeFileOrDir', f);
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
