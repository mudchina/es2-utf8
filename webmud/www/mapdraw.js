// var mapdata = {}; in mapdata.js

var curAddr = '';
var drawMarkedOnly = 0;

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
  canyon: [-14,-3],
  choyin: [12,-28],
  chuenyu: [-12,-18],
  city: [-20,-20],
  cloud: [8,-15],
  death: [-18,0],
  goathill: [4,14],
  graveyard: [15,-8],
  green: [11,10],
  ice: [16,-5],
  latemoon: [-3,-12],
  oldpine: [6,-8],
  sanyen: [2,-25],
  snow: [0,0],
  social_guild: [18,-20],
  temple: [18,6],
  village: [-18,-8],
  waterfog: [-7,4],
  wiz: [-3,2]
};

function getDomain(key) {
  return key.split('/')[2];
}
  
function mapAutoXY() {
  var domains = {};
  var rms = mapdata.rooms;
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
function drawMap() {
  var rms = mapdata.rooms;
  //console.log('drawing: ' + curAddr);

  // set center point
  var myPos = rms[curAddr];
  if(!myPos) {
    for(var k in rms) {
      myPos = rms[k];
      break;
    }
  }
  if(!myPos) return;

  var canvas = $('canvas#map')[0];
  var c = canvas.getContext("2d");

  // clear background
  c.fillStyle = MAP_BG;
  c.fillRect(0, 0, VIEW_W, VIEW_H);

  var x0 = VIEW_W/2, y0 = VIEW_H/2;

  // draw path / exits
  c.strokeStyle = MAP_COLOR;
  c.lineWidth = 2;
  for(var addr in rms) {
    var r = rms[addr];
    if(drawMarkedOnly && (!r.v)) continue;

    var x = x0 + (r.x - myPos.x) * ROOM_RANGE;
    var y = y0 - (r.y - myPos.y) * ROOM_RANGE;
    if(x<0 || x>VIEW_W || y<0 || y>VIEW_H) continue;

    c.beginPath();
    for(var k in r.exits) {
      var exit = r.exits[k];
      //console.log(exit);
      c.moveTo(x,y);
      var rm = rms[exit];
      if(rm) {
        var x2 = x0 + (rm.x - myPos.x) * ROOM_RANGE;
        var y2 = y0 - (rm.y - myPos.y) * ROOM_RANGE;
        c.lineTo(x2, y2);

      } else {
        var xy = DIR_XY[k];
        //console.log(exit, xy);
        if(xy) {
          var x2 = x + xy[0] * ROOM_RANGE;
          var y2 = y - xy[1] * ROOM_RANGE;
          c.lineTo(x2, y2);
        }
      }
    }
    c.stroke();
  }

  var domains = {};

  c.fillStyle = MAP_COLOR;
  for(var addr in rms) {
    var r = rms[addr];
    if(drawMarkedOnly && (!r.v)) continue;

    var x = x0 + (r.x - myPos.x) * ROOM_RANGE;
    var y = y0 - (r.y - myPos.y) * ROOM_RANGE;
    if(x<0 || x>VIEW_W || y<0 || y>VIEW_H) continue;

    // draw room
    c.fillRect(x-ROOM_SIZE/2, y-ROOM_SIZE/2, ROOM_SIZE, ROOM_SIZE);

    c.save();
    c.fillStyle = MAP_BG;
    c.fillRect(x-(ROOM_SIZE/2-2), y-(ROOM_SIZE/2-2), ROOM_SIZE-4, ROOM_SIZE-4);
    c.restore();

    // enlarge rect of domain
    var d = getDomain(addr);
    if(d in domains) {
      var dm = domains[d];
      if(x > dm.right) dm.right = x;
      else if(x < dm.left) dm.left = x;
      if(y > dm.bottom) dm.bottom = y;
      else if(y < dm.top) dm.top = y;

    } else {
      domains[d] = {
        left: x,
        right: x,
        top: y,
        bottom: y,
      };
    }
  }

  c.textBaseline = 'top';
  c.font = 'normal lighter 16px SimSun';
  c.lineWidth = 0.5;
  c.strokeStyle = '#ff0';

  // draw player pos
  c.fillStyle = ME_COLOR;
  c.fillRect(x0-ME_SIZE/2, y0-ME_SIZE/2, ME_SIZE, ME_SIZE);

  // draw domain rect
  for(var d in domains) {
    var dm = domains[d];
    c.save();
    c.strokeStyle = '#ddd';
    c.lineWidth = 0.2;
    c.strokeRect(dm.left - ROOM_RANGE, 
                 dm.top - ROOM_RANGE, 
                 (dm.right - dm.left) + ROOM_RANGE * 2, 
                 (dm.bottom - dm.top) + ROOM_RANGE * 2);
    c.restore();

    c.strokeText(d, dm.left - ROOM_RANGE +3, dm.top - ROOM_RANGE);
  }
  // draw room name at top-left
  c.strokeText(myPos.short, 5, 5);
}

function mapGoTo(addr) {
  var rms = mapdata.rooms;
  var r = rms[addr];
  if(r) {
    r.v = 1;
    curAddr = addr;
    drawMap();
  }
}

function mapSetDrawMarked(y) {
  drawMarkedOnly = y;
}

function mapGetCurAddr() {
  return curAddr;
}

function clearMap() {
  var rms = mapdata.rooms;
  for(var k in rms) {
    var r = rms[k];
    if(r) delete r.v;
  }
}

function saveMap() {
  var marks = {};

  // get all marks in map
  var rms = mapdata.rooms;
  for(var k in rms) {
    var r = rms[k];
    if(r.v) marks[k] = 1;
  }

  // save map info to local storage
  localStorage.setItem('marks', JSON.stringify(marks));
}

function loadMap() {
  var marks = {};

  // load map info from local storage
  var str = localStorage.getItem('marks');
  if(str && str.indexOf('{') === 0) {
    marks = JSON.parse(str);
  }

  // apply marks in map
  var rms = mapdata.rooms;
  for(var k in rms) {
    var r = rms[k];
    if(marks[k]) r.v = 1;
    else if('v' in r) delete r.v;
  }
}
