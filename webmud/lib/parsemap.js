'use strict';

(function(){

var path = require('path'),
    fs = require('fs'),
    parser = require('./parselpc');

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

var domainPos = {
  canyon: [-10,-3],
  choyin: [8,-28],
  chuenyu: [-11,-15],
  city: [-20,-20],
  cloud: [8,-13],
  death: [15,0],
  goathill: [8,9],
  graveyard: [25,0],
  green: [1,11],
  ice: [20,0],
  latemoon: [-2,-11],
  oldpine: [6,-6],
  sanyen: [12,-18],
  snow: [0,0],
  social_guild: [11,-20],
  temple: [10,6],
  village: [-15,-7],
  waterfog: [-4,4],
  wiz: [-1,0]
};

var roomtypes = ['ROOM', 'BANK', 'HOCKSHOP', 'CLASS_GUILD'];

function jsonFromLPCFile(file, mudlib) {
  var text = fs.readFileSync(file, 'utf8');
  return text ? parser.jsonFromLPC(text, file, mudlib, roomtypes) : null;
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
      } else if(path.extname(file) === '.c'){
        results.push(file);
      }
    });
  }
  return results;
};

function getDomain(key) {
  return key.split('/')[2];
}
  
function autoXY(map) {
  var domains = {};
  var rms = map.rooms;
  var nNew = 0;
  for(var k in rms) {
    var r = rms[k];
    if('x' in r) continue;
    var d = getDomain(k);
    var xy = domainPos[d];
    if(xy) {
      r.x = xy[0];
      r.y = xy[1];
    } else {
      r.x = 0;
      r.y = 0;
    }
    //console.log(getDomain(k), k, '(' + r.x + ',' + r.y + ')');

    var todo = [k];
    while(todo.length > 0) {
      var k = todo.pop();
      var r = rms[k];
      var e = r.exits;
      for(var d in e) {
        var key = e[d];
        var next = rms[key];
        if(!next) console.log(key, k, r);
        else if(!('x' in next)) {
          var xy = DIR_XY[d] || [0,0];
          var sameDomain = (getDomain(k) === getDomain(key));
          if(sameDomain) {
            next.x = r.x + xy[0];
            next.y = r.y + xy[1];
            //console.log(key, '(' + next.x + ',' + next.y + ')');
            todo.push(key);
          }
        }
      }
    }
  }
}

function parseMap(mudlib, folders) {
  var domains = {};
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
      var json = jsonFromLPCFile(file, mudlib);
      if(json) {
        var key = file.replace(mudlib, '');
        key = key.replace(path.extname(key),'');
        rooms[key] = json;
        n ++;

        // count rooms in a domain
        var d = getDomain(key);
        if(!domains[d]) domains[d] = 1;
        else domains[d] += 1;
      }
    });
  }

  console.log('domains: \n', domains);
  var map = {
    total: m,
    count: n,
    domains: domains,
    rooms: rooms,
  };

  return map;
}

exports = module.exports = {
  walk: walk,
  jsonFromLPCFile: jsonFromLPCFile,
  parseMap: parseMap,
};
  
})();
