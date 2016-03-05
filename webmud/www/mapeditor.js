
function adjustLayout(){
  var w = $(window).width(), h = $(window).height();
  var w1 = (w/2);
  var h1 = (h);

  $('div#left, div#right').css({
    width: w1 + 'px',
    height: h1 + 'px',
  });

  var tools = $('div#tools'), list = $('select#list'), editor = $('textarea#editor');
  tools.css({
    width: w1 + 'px',
  });
  list.css({
    width: (w1-10) + 'px',
  });
  editor.css({
    width: (w1-20) + 'px',
    height: (h1 -20 - tools.outerHeight(true) - list.outerHeight(true)) + 'px',
  });
}

$(document).ready(function(){
  var getAddrByClick = function(e){
    var v = { x:e.offsetX, y:e.offsetY };
    var p = mapXYFromView(v);
    var k = mapFindAddrByXY(p.x, p.y);
    return k;
  }

  var div_map = $('div#map');
  var canvas = $('canvas#map');
  var lastK = '';

  canvas.mousemove(function(e){
    //console.log('hover');
    var k = getAddrByClick(e);
    if(k && (k !== lastK)) {
      lastK = k;

      if(typeof k === 'string') {
        var r = mapGetRoomByAddr(k);
        console.log(k, r);
      } else if(Array.isArray(k)) {
        k.forEach(function(i){
          var r = mapGetRoomByAddr(i);
          console.log(i, r);
        });
      }
    }
  });

  canvas.click(function(e){
    var k = getAddrByClick(e);
    if(k) {
      if(typeof k === 'string') {
        var r = mapGetRoomByAddr(k);
        console.log(k, r);
      } else if(Array.isArray(k)) {
        k.forEach(function(i){
          var r = mapGetRoomByAddr(i);
          console.log(i, r);
        });
      }
    }
  });

  canvas.contextmenu(function(e){
    console.log(e.offsetX, e.offsetY);
    e.preventDefault();
  });

  $(window).resize(adjustLayout);

  var w = 1600, h = 1400;
  $('div#map').css({
    width: w + 'px',
    height: h + 'px',
  });
  initMap({
    canvas: $('canvas#map')[0],
    width: w,
    height: h,
    center: '/d/snow/inn',
    drawMarked: false,
  });

  adjustLayout();
});
