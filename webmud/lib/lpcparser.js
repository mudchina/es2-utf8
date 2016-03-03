'use strict';

(function(){

var path = require('path'),
    fs = require('fs'),
    _ = require('underscore');

function smartTrim(text) {
  // strip line comments, // xxx
  text = text.replace(/([\/]{2}[^\n]*)/g, '');
  // strip seg comments, /* xxx */
  text = text.replace(/(\/\*[^\*]*\*\/)/g, '');
  // strip extra white space & empty line
  text = text.replace(/[\n]*/g, '');
  text = text.replace(/([ ]+|[\t])/g, ' ');
  text = text.replace(/\n[ ]+/g, '\n');
  text = text.replace(/;/g, ';\n');
  return text;
}

// replace __DIR__
function replaceDIR(str, refFile, mudlib) {
  if(str.indexOf('__DIR__')>=0) {
    var dir = path.dirname(refFile).replace(mudlib, '') + '/';
    str = str.replace("__DIR__", dir);
  }
  return str;
}
  
var alltypes = {};
var roomtypes = ['ROOM', 'BANK', 'HOCKSHOP'];

function jsonFromLPC(file, mudlib) {
  var text = fs.readFileSync(file, 'utf8');
  if(!text) return null;

  var bases = text.match(/inherit [A-Z]+;/g);
  if(!bases) return null;

  var base = bases[0].replace(/(inherit[ ]*|[ ]*;)/g, '')
  if(!alltypes[base]) alltypes[base] = 1;
  else alltypes[base] += 1;

  if(!_.contains(roomtypes, base)) return null;

  text = smartTrim(text);

  var json = {};
  var sets = text.match(/set[ ]*\(.*\)[ ]*;/g);
  if(sets) sets.forEach(function(str){
    var keys = str.match(/\([ ]*"[a-z_]+"[ ]*,/);
    if(!keys) return;
    var key = keys[0].replace(/[\(",]/g,'');
    var value = null;
    str = str.replace('"'+key+'"', '');
    switch(key) {
      case 'short':
        value = str.replace(/set[ ]*\([ ]*,[ ]*"|"[ ]*\)[ ]*;[ ]*/g, '');
        break;
      case 'long':
        value = str.replace(/set[ ]*\([ ]*,[ ]*@LONG[ ]*|[ ]*LONG[ ]*\)[ ]*;[ ]*|set[ ]*\([ ]*,[ ]*"[ ]*|[ ]*"[ ]*\)[ ]*;[ ]*/g, '').replace(/。[ ]*/g, '。');
        break;
      case 'exits':
      case 'objects':
        value = {};
        var items = str.replace(/set[ ]*\([ ]*,[ ]*\(\[|\]\)[ ]*\)[ ]*;[ ]*/g, '').split(',');
        for(var j=0; j<items.length; j++) {
          var item = items[j].trim();
          if(!item) continue;
          var words = item.replace(/""/g,'').split(':');
          var k = words[0].replace(/[" ]*/g, '');
          var v = words[1].replace(/[" ]*/g, '');
          if(key === 'exits') {
            value[k] = replaceDIR(v, file, mudlib);
          } else {
            value[replaceDIR(k, file, mudlib)] = parseInt(v);
          }
        }
        break;
    }
    if(value) json[key] = value;
  });
  return json;
}

var walk = function(dir) {
  var results = [];
  var list = fs.readdirSync(dir);
  if(list) {
    list.forEach(function(file) {
      file = path.resolve(dir, file);
      var stat = fs.statSync(file);
      if (stat && stat.isDirectory()) {
        results = results.concat(walk(file));
      } else {
        results.push(file);
      }
    });
  }
  return results;
};

function searchRooms(mudlib, folders) {
  var rooms = {};
  var n = 0, m = 0;

  var stat = fs.statSync(mudlib);
  if(stat && stat.isDirectory()) {
    if(!folders) folders = ['d', 'u'];

    var files = [];
    folders.forEach(function(dir, j){
      dir = path.resolve(mudlib, dir);
      files = files.concat(walk(dir));
    });
    m = files.length;

    files.forEach(function(file){
      var json = jsonFromLPC(file, mudlib);
      if(json) {
        var key = file.replace(mudlib, '');
        key = key.replace(path.extname(key),'');
        rooms[key] = json;
        n ++;
      }
    });
  }

  console.log('types: \n', alltypes);

  return {
    total: m,
    types: alltypes,
    rooms: rooms,
    count: n,
  };
}

var DIR_XY = {
  'north': [0, 1],
  'south': [0, -1],
  'east': [1, 0],
  'west': [-1, 0],
  'northup': [0, 1],
  'southup': [0, -1],
  'eastup': [1, 0],
  'westup': [-1, 0],
  'northdown': [0, 1],
  'southdown': [0, -1],
  'eastdown': [1, 0],
  'westdown': [-1, 0],
  'northeast': [1, 1],
  'northwest': [-1, 1],
  'southeast': [1, -1],
  'southwest': [-1, -1],
  'up': [0, 0],
  'down': [0, 0],
  'out': [0, 0],
  'enter': [0, 0],
};

var rooms = {};
var domains = {};

function autoXY(todo) {
  while(todo.length > 0) {
    var k = todo.pop();
    var r = rooms[k];
    r.ok = true;
    var e = r.exits;
    for(var d in e) {
      var key = e[d];
      var next = rooms[key];
      if(!next) console.log(key, next, k, r);
      else if(!next.ok) {
        var xy = DIR_XY[d] || [0,0];
        next.x = r.x + xy[0];
        next.y = r.y + xy[1];
        console.log(key, '(' + next.x + ',' + next.y + ')');
        todo.push(key);
      }
    }
  }
}

function autoMap(map) {
  rooms = map.rooms;
  domains = {};
  
  for(var k in rooms) {
    var r = rooms[k];
    if(r.ok) continue;
    r.x = 0;
    r.y = 0;
    console.log(k, '(' + r.x + ',' + r.y + ')');
    autoXY([k]);
  }

  map.domains = domains;
  rooms = {};
  domains = {};
}

exports = module.exports = {
  walk: walk,
  smartTrim: smartTrim,
  replaceDIR: replaceDIR,
  jsonFromLPC: jsonFromLPC,
  searchRooms: searchRooms,
  autoMap: autoMap,
};
  
})();
