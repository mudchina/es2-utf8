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

function getDirXY() {
  return DIR_XY;
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
      for(var k in DIR_XY) {
        var dirInfo = DIR_XY[k];
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
  var name = words[0];
  var addr = words[1];

  // update room inf in cache
  if(!rooms[addr]) {
    rooms[addr] = {};
    changed = true;
  }

  var inf = rooms[addr];
  if(!inf) console.log(_.keys(rooms));
  if(!inf.name) inf.name = name;
  if(!inf.x) inf.x = 0;
  if(!inf.y) inf.y = 0;
  for(var i=0; i<exits.length; i++) {
    var e = exits[i];
    if(e) e = alldirs[e];
    if(e) e = e[0];
    if(e && !inf[e]) {
      inf[e] = 1;
      changed = true;
    }
  }

  var stepDir = (steps.length > 0) ? steps.shift() : 'l';
  if(stepDir.indexOf(' ') >= 0) return;

  if(inf.x && inf.x) {
    // already has (x,y), no need calc
  } else if(stepDir !== 'l') {
    var dirInfo = DIR_XY[stepDir];
    if(dirInfo) {
      // calculate (x,y) from lastRoom
      if(curAddr) {
        var lastRoom = rooms[curAddr];
        if(lastRoom) {
          lastRoom[stepDir] = addr;
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
  if(mapstr.indexOf('{') === 0) {
    rooms = JSON.parse(mapstr);
  } else {
    rooms = {};
  }
}

// map view port size, canvas size
var VIEW_W = 240, VIEW_H = 190;

// virtual map size, we can touch to scroll map
var MAP_W = 640, MAP_H = 480;
var ROOM_RANGE = 20, ROOM_SIZE = 12, ME_SIZE = 8;
var MAP_BG = '#753', MAP_COLOR = '#fff', ME_COLOR = '#f00';

function setMapViewSize(w,h) {
  var canvas = $('canvas#map')[0];
  VIEW_W = canvas.width = w;
  VIEW_H = canvas.height = h;
  drawMap();
}

// draw map from map info
function drawMap() {
  var canvas = $('canvas#map')[0];
  var c = canvas.getContext("2d");
  c.fillStyle = MAP_BG;
  c.fillRect(0, 0, VIEW_W, VIEW_H);
  var x0 = VIEW_W/2, y0 = VIEW_H/2;

  var myPos = rooms[curAddr];
  if(!myPos) return;

  c.strokeStyle = MAP_COLOR;
  c.lineWidth = 2;
  for(var addr in rooms) {
    var inf = rooms[addr];
    var x = x0 + (inf.x - myPos.x) * ROOM_RANGE;
    var y = y0 - (inf.y - myPos.y) * ROOM_RANGE;
    if(x<0 || x>VIEW_W || y<0 || y>VIEW_H) continue;

    c.beginPath();
    for(var k in DIR_XY) {
      if(!inf[k]) continue;
      var xy = DIR_XY[k];
      if(xy[1] || xy[2]) {
        c.moveTo(x,y);
        c.lineTo(x+xy[1]*ROOM_RANGE, y-xy[2]*ROOM_RANGE);
      }
    }
    c.stroke();
  }

  c.fillStyle = MAP_COLOR;
  for(var addr in rooms) {
    var inf = rooms[addr];
    var x = x0 + (inf.x - myPos.x) * ROOM_RANGE;
    var y = y0 - (inf.y - myPos.y) * ROOM_RANGE;
    if(x<0 || x>VIEW_W || y<0 || y>VIEW_H) continue;

    c.fillRect(x-ROOM_SIZE/2, y-ROOM_SIZE/2, ROOM_SIZE, ROOM_SIZE);

    c.save();
    c.fillStyle = MAP_BG;
    c.fillRect(x-(ROOM_SIZE/2-2), y-(ROOM_SIZE/2-2), ROOM_SIZE-4, ROOM_SIZE-4);
    c.restore();
  }

  // draw player pos
  c.fillStyle = ME_COLOR;
  c.fillRect(x0-ME_SIZE/2, y0-ME_SIZE/2, ME_SIZE, ME_SIZE);

  // draw room name
  c.textBaseline = 'top';
  c.font = 'normal lighter 16px SimSun';
  c.lineWidth = 0.5;
  c.strokeStyle = MAP_COLOR;
  c.strokeText(myPos.name, 5, 5);
}

function initModMap(callback) {
  loadMap();
  drawMap();
}
