/*
// room info data format:

'/d/snow/inn': {
  name: '饮风客栈',
  e: '/d/snow/square',
  u: '/d/snow/inn_2f',
  x: 0,
  y: 0,
}
*/

var rooms = {};
var steps = [];
var curAddr = '';

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

var DIR_EXY = {
  'n': ['north', 0, 1],
  's': ['south', 0, -1],
  'e': ['east', 1, 0],
  'w': ['west', -1, 0],
  'nu': ['northup', 0, 1],
  'su': ['southup', 0, -1],
  'eu': ['eastup', 1, 0],
  'wu': ['westup', -1, 0],
  'nd': ['northdown', 0, 1],
  'sd': ['southdown', 0, -1],
  'ed': ['eastdown', 1, 0],
  'wd': ['westdown', -1, 0],
  'ne': ['northeast', 1, 1],
  'nw': ['northwest', -1, 1],
  'se': ['southeast', 1, -1],
  'sw': ['southwest', -1, -1],
  'u': ['up', 0, 0],
  'd': ['down', 0, 0],
  'out': ['out', 0, 0],
  'enter': ['enter', 0, 0],
};

function getDirEXY() {
  return DIR_EXY;
}

function mapCheckCmd(str) {
  var cmds = str.split('\n');
  var alldirs = getAllDirs();
  for(var i=0; i<cmds.length; i++) {
    var words = _.compact(cmds[i].trim().split(' '));
    var cmd = words[0];
    if(!cmd) return;

    // if look/go dir, get dir
    if(words.length > 1) {
      switch(cmd) {
        case 'go':
          if(alldirs[words[1]]) cmd = words[1];
          break;
        case 'l':
        case 'look':
          if(alldirs[words[1]]) cmd = 'l ' + words[1];
          break;
      }
    }

    // convert long dir to short
    if((cmd === 'l') || (cmd === 'look')) {
      steps.push('l');
    } else {
      for(var k in DIR_EXY) {
        var dirInfo = DIR_EXY[k];
        if((cmd === k) || (cmd === dirInfo[0])) {
          steps.push(k);
          break;
        }
      }
    }
  }
  // console.log(str, steps);
}

function mapOnGoFail() {
  steps.shift();
}

function mapOnFlee(str) {
}

function mapCheckRoom(nameAddr, exits) {
  var alldirs = getAllDirs();
  var changed = false;
  
  var words = nameAddr.split(' - ');
  if(words.length != 2) return;
  var short = words[0];
  var addr = words[1];

  // update room inf in cache
  if(!rooms[addr]) {
    rooms[addr] = {
      exits: {},
    };
    changed = true;
  }

  var inf = rooms[addr];
  if(!inf) console.log(_.keys(rooms));
  if(!inf.short) inf.short = short;
  if(!inf.x) inf.x = 0;
  if(!inf.y) inf.y = 0;
  for(var i=0; i<exits.length; i++) {
    var e = exits[i];
    if(e && !inf.exits[e]) {
      inf.exits[e] = 1;
      changed = true;
    }
  }

  var stepDir = (steps.length > 0) ? steps.shift() : 'l';
  if(stepDir.indexOf(' ') >= 0) return;

  if(inf.x && inf.x) {
    // already has (x,y), no need calc
  } else if(stepDir !== 'l') {
    var dirInfo = DIR_EXY[stepDir];
    if(dirInfo) {
      // calculate (x,y) from lastRoom
      if(curAddr) {
        var lastRoom = rooms[curAddr];
        if(lastRoom) {
          lastRoom.exits[dirInfo[0]] = addr;
          inf.x = lastRoom.x + dirInfo[1];
          inf.y = lastRoom.y + dirInfo[2];
        }
      }
    }
  }

  curAddr = addr;
  drawMap();

  if(changed) saveMap();
}

// save map info to local storage
function saveMap() {
  localStorage.setItem('rooms', JSON.stringify(rooms));
}

// load map info from local storage
function loadMap() {
  var mapstr = localStorage.getItem('rooms');
  if(mapstr && mapstr.indexOf('{') === 0) {
    rooms = JSON.parse(mapstr);
  } else {
    rooms = {};
  }
}

var domainPos = {
  canyon: [-10,-3],
  choyin: [8,-28],
  chuenyu: [-11,-15],
  city: [-20,-20],
  cloud: [8,-13],
  death: [15,0],
  goathill: [8,9],
  graveyard: [15,-8],
  green: [1,11],
  ice: [16,-5],
  latemoon: [-2,-10],
  oldpine: [6,-6],
  sanyen: [2,-20],
  snow: [0,0],
  social_guild: [11,-20],
  temple: [10,6],
  village: [-15,-7],
  waterfog: [-4,4],
  wiz: [-1,0]
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

// map view port size, canvas size
var VIEW_W = 240, VIEW_H = 190;

// virtual map size, we can touch to scroll map
var ROOM_RANGE = 20, ROOM_SIZE = 12, ME_SIZE = 8;
var MAP_BG = '#753', MAP_COLOR = '#fff', ME_COLOR = '#f00';

function setMapViewSize(w,h) {
  var canvas = $('canvas#map')[0];
  VIEW_W = canvas.width = w;
  VIEW_H = canvas.height = h;
}

// draw map from map info
function drawMap(rms, cur) {
  if(!rms) rms = rooms;
  if(!cur) cur = curAddr;
  var domains = {};

  var myPos = rms[cur];
  if(!myPos) {
    for(var k in rms) {
      myPos = rms[k];
      break;
    }
  }
  if(!myPos) return;

  var canvas = $('canvas#map')[0];
  var c = canvas.getContext("2d");
  c.fillStyle = MAP_BG;
  c.fillRect(0, 0, VIEW_W, VIEW_H);
  var x0 = VIEW_W/2, y0 = VIEW_H/2;

  c.strokeStyle = MAP_COLOR;
  c.lineWidth = 2;
  for(var addr in rms) {
    var inf = rms[addr];
    var x = x0 + (inf.x - myPos.x) * ROOM_RANGE;
    var y = y0 - (inf.y - myPos.y) * ROOM_RANGE;
    if(x<0 || x>VIEW_W || y<0 || y>VIEW_H) continue;

    c.beginPath();
    for(var k in inf.exits) {
      var rm = rms[inf.exits[k]];
      if(!rm) continue;
      
      var x2 = x0 + (rm.x - myPos.x) * ROOM_RANGE;
      var y2 = y0 - (rm.y - myPos.y) * ROOM_RANGE;

      c.moveTo(x,y);
      c.lineTo(x2, y2);
    }
    c.stroke();
  }

  c.textBaseline = 'top';
  c.font = 'normal lighter 16px SimSun';
  c.lineWidth = 0.5;
  c.strokeStyle = '#ff0';

  c.fillStyle = MAP_COLOR;
  for(var addr in rms) {
    var inf = rms[addr];
    var x = x0 + (inf.x - myPos.x) * ROOM_RANGE;
    var y = y0 - (inf.y - myPos.y) * ROOM_RANGE;
    if(x<0 || x>VIEW_W || y<0 || y>VIEW_H) continue;

    c.fillRect(x-ROOM_SIZE/2, y-ROOM_SIZE/2, ROOM_SIZE, ROOM_SIZE);

    c.save();
    c.fillStyle = MAP_BG;
    c.fillRect(x-(ROOM_SIZE/2-2), y-(ROOM_SIZE/2-2), ROOM_SIZE-4, ROOM_SIZE-4);
    c.restore();

    var d = getDomain(addr);
    if(!domains[d]) {
      domains[d] = 1;
      c.strokeText(d, x, y);
    }
  }

  // draw player pos
  c.fillStyle = ME_COLOR;
  c.fillRect(x0-ME_SIZE/2, y0-ME_SIZE/2, ME_SIZE, ME_SIZE);

  // draw room name
  c.strokeText(myPos.short, 5, 5);
}

function initModMap(callback) {
  loadMap();
  drawMap();

  addLocalCmd('clear map', function(){
    rooms = {};
    localStorage.removeItem('rooms');
    drawMap();
  });
}
