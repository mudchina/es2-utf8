// var mapdata = {}; in mapdata.js

var curAddr = '', curDomain = '';
var curRoom = {};
var curX = 0, curY = 0;
var drawMarkedOnly = 0;
var drawDomain = 0;

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
  canyon: [-11,-2],
  choyin: [13,-27],
  chuenyu: [-18,1],
  city: [-18,-18],
  cloud: [8,-13],
  death: [-18,10],
  goathill: [4,19],
  graveyard: [15,-3],
  green: [11,15],
  ice: [16,0],
  latemoon: [-5,-25],
  oldpine: [6,-5],
  sanyen: [0,-17],
  snow: [0,5],
  temple: [19,12],
  village: [-21,-7],
  waterfog: [-8,9],
  wiz: [-4,8]
};

function getDomain(key) {
  return key.split('/')[2];
}

function mapXYToAddr(mapping, r, addr) {
  var key = r.x + ',' + r.y;
  var old = mapping[key];
  if(old) {
    if(typeof(old) === 'string') mapping[key] = [old, addr];
    else if(Array.isArray(old)) old.push(addr);
  } else {
    mapping[key] = addr;
  }
}

function mapAutoXY() {
  var rms = mapdata.rooms;
  var domains = mapdata.domains = {};
  var xy = mapdata.xy = {};
  var nNew = 0;
  for(var k in rms) {
    var r = rms[k];
    if('x' in r) continue;
    var d = getDomain(k);
    var pos = domainPos[d];
    if(pos) {
      r.x = pos[0];
      r.y = pos[1];
    } else {
      r.x = 0;
      r.y = 0;
    }
    mapXYToAddr(xy, r, k);

    var todo = [k];
    while(todo.length > 0) {
      var k = todo.pop();
      var r = rms[k];
      var e = r.exits;
      for(var d in e) {
        var key = e[d];
        var next = rms[key];
        if(!next) {
          //if(key.indexOf("random(")>0) console.log(key, k, r);
        }
        else if(!('x' in next)) {
          var delta = DIR_XY[d] || [0,0];
          var sameDomain = (getDomain(k) === getDomain(key));
          if(sameDomain) {
            next.x = r.x + delta[0];
            next.y = r.y + delta[1];
            mapXYToAddr(xy, next, key);

            todo.push(key);
          }
        }
      }
    }
  }

  // calculate domains
  for(var k in rms) {
    var r = rms[k];
    if(!('x' in r)) continue;
    var x = r.x;
    var y = r.y;
    var d = getDomain(k);
    if(d in domains) {
      var dm = domains[d];
      dm.count ++;
      if(x > dm.right) dm.right = x;
      else if(x < dm.left) dm.left = x;
      if(y < dm.bottom) dm.bottom = y;
      else if(y > dm.top) dm.top = y;

    } else {
      domains[d] = {
        count: 1,
        left: x,
        right: x,
        top: y,
        bottom: y,
      };
    }
  }
}

var mapCanvas = null;

// map view port size, canvas size
var VIEW_W = 240, VIEW_H = 190;
var x0 = VIEW_W/2, y0 = VIEW_H/2;

// virtual map size, we can touch to scroll map
var ROOM_RANGE = 20, ROOM_SIZE = 12, ME_SIZE = 8;
var MAP_BG = '#222', MAP_COLOR = '#fff', ME_COLOR = '#f00', DM_COLOR = '#ffc';
var SEL_COLOR = 'red';

function setMapViewSize(w,h) {
  VIEW_W = mapCanvas.width = w;
  VIEW_H = mapCanvas.height = h;
  x0 = VIEW_W/2;
  y0 = VIEW_H/2;
  drawMap();
}

function setMapViewCenter(p) {
  x0 = p.x;
  y0 = p.y;
  drawMap();
}

function getMapViewCenter() {
  return {
    x: x0,
    y: y0,
  };
}

function mapXYToView(r) {
  return {
    x: x0 + (r.x - curX) * ROOM_RANGE,
    y: y0 - (r.y - curY) * ROOM_RANGE,
  };
}

function mapXYFromView(p) {
  return {
    x: Math.round((p.x - x0) / ROOM_RANGE) + curX,
    y: Math.round((y0 - p.y) / ROOM_RANGE) + curY,
  };
}

function mapFindAddrByXY(x,y) {
  var xy = mapdata.xy;
  return xy ? xy[x+','+y] : '';
}

function mapFindDomainByXY(x,y) {
  var domains = mapdata.domains;
  for(var d in domains) {
    var dm = domains[d];
    if(x>=dm.left-1 && 
       x<=dm.right+1 && 
       y>=dm.bottom-1 && 
       y<=dm.top+1) 
      return d;
  }
  return '';
}

function mapGetRoomByAddr(addr) {
  if(Array.isArray(addr)) addr = addr[0];
  if(typeof addr !== 'string') return;

  return mapdata.rooms[addr];
}

function mapMarkActive(addr) {
  if(Array.isArray(addr)) addr = addr[0];
  if(typeof addr !== 'string') return;

  var r = mapdata.rooms[addr];
  if(r) {
    r.v = 1;
    curAddr = addr;
    curRoom = r;
  }
  var d = getDomain(addr);
  var dm = mapdata.domains[d];
  if(dm) {
    dm.v = 1;
    curDomain = d;
  }
  drawMap();
}

function mapCenter(addr) {
  if(Array.isArray(addr)) addr = addr[0];
  if(typeof addr !== 'string') return;

  if(addr) {
    var r = mapdata.rooms[addr];
    if(r) {
      curX = r.x || 0;
      curY = r.y || 0;
    }
  } else {
    curX = 0;
    curY = 0;
  }

  x0 = VIEW_W/2;
  y0 = VIEW_H/2;

  drawMap();
}

function mapGoTo(addr) {
  mapMarkActive(addr);
  mapCenter(addr);
}

function mapSetDrawMarked(y) {
  drawMarkedOnly = y;
}

function mapSetDrawDomain(y) {
  drawDomain = y;
}

function mapGetCurAddr() {
  return curAddr;
}

// draw map from map info
function drawMap() {
  var rms = mapdata.rooms;
  var canvas = $('canvas#map')[0];
  var c = canvas.getContext("2d");

  // clear background
  c.fillStyle = MAP_BG;
  c.fillRect(0, 0, VIEW_W, VIEW_H);

  // draw path / exits
  c.strokeStyle = MAP_COLOR;
  c.lineWidth = 2;
  for(var addr in rms) {
    var r = rms[addr];
    if(drawMarkedOnly && (!r.v)) continue;

    var p = mapXYToView(r);
    if(p.x<0 || p.x>VIEW_W || p.y<0 || p.y>VIEW_H) continue;

    c.beginPath();
    for(var k in r.exits) {
      var exit = r.exits[k];
      //console.log(exit);
      c.moveTo(p.x, p.y);
      var rm = rms[exit];
      if(rm) {
        var p2 = mapXYToView(rm);
        c.lineTo(p2.x, p2.y);

      } else {
        var xy = DIR_XY[k];
        //console.log(exit, xy);
        if(xy) {
          var x2 = p.x + xy[0] * ROOM_RANGE;
          var y2 = p.y - xy[1] * ROOM_RANGE;
          c.lineTo(x2, y2);
        }
      }
    }
    c.stroke();
  }

  c.fillStyle = MAP_COLOR;
  for(var addr in rms) {
    var r = rms[addr];
    if(drawMarkedOnly && (!r.v)) continue;

    var x = x0 + (r.x - curX) * ROOM_RANGE;
    var y = y0 - (r.y - curY) * ROOM_RANGE;
    if(x<0 || x>VIEW_W || y<0 || y>VIEW_H) continue;

    // draw room
    var addr = mapFindAddrByXY(r.x, r.y);
    c.fillRect(x-ROOM_SIZE/2, y-ROOM_SIZE/2, ROOM_SIZE, ROOM_SIZE);
    if(!Array.isArray(addr)) {
      c.save();
      c.fillStyle = MAP_BG;
      c.fillRect(x-(ROOM_SIZE/2-2), y-(ROOM_SIZE/2-2), ROOM_SIZE-4, ROOM_SIZE-4);
      c.restore();
    }
  }

  c.textBaseline = 'top';
  c.font = 'normal lighter 16px SimSun';
  c.lineWidth = 0.5;
  c.strokeStyle = DM_COLOR;

  // draw domain rect
  if(drawDomain) {
    var domains = mapdata.domains;
    for(var d in domains) {
      var dm = domains[d];
      if(drawMarkedOnly && (!dm.v)) continue;

      var p = mapXYToView({x:(dm.left-1), y:(dm.top+1)});
      var p2 = mapXYToView({x:(dm.right+1), y:(dm.bottom-1)});

      c.save();
      if(curDomain === d) {
        c.strokeStyle = SEL_COLOR;
        c.lineWidth = 1;
      } else {
        c.strokeStyle = DM_COLOR;
        c.lineWidth = 0.5;
      }
      c.strokeRect(p.x, p.y-10, (p2.x-p.x), (p2.y-p.y)+10);
      c.restore();

      c.strokeText(d, p.x +5, p.y-10 +3);
    }
  }

  // draw player pos
  if(curAddr) {
    var r = mapGetRoomByAddr(curAddr);
    if(r) {
      var p = mapXYToView(r);
      c.fillStyle = ME_COLOR;
      c.fillRect(p.x-ME_SIZE/2, p.y-ME_SIZE/2, ME_SIZE, ME_SIZE);
    }
  }
}

function clearMapMarks() {
  var rms = mapdata.rooms;
  for(var k in rms) {
    var r = rms[k];
    if(r) delete r.v;
  }
}

function saveMapMarks() {
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

function loadMapMarks() {
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

function initMap(opt) {
  if(!opt) opt = {};
  if(!opt.width) opt.width = 1600;
  if(!opt.height) opt.height = 1200;
  if(!opt.center) opt.center = '/d/snow/inn';
  if(!opt.canvas) opt.canvas = 'canvas#map';

  loadMapMarks();
  mapAutoXY();
  mapSetDrawMarked(opt.drawMarked ? 1 : 0);
  mapSetDrawDomain(opt.drawDomain ? 1 : 0);

  mapCanvas = $(opt.canvas)[0];
  setMapViewSize(opt.width, opt.height);

  mapGoTo(opt.center);
}
