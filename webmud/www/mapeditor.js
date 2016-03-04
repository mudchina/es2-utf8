$(document).ready(function(){
  var div_map = $('div#map');
  var canvas = $('canvas#map');
  var w = 1600, h = 1400;
  div_map.show();
  div_map.css({
    width: w +'px',
    height: h +'px',
  });
  canvas.click(function(e){
    // console.log(e.offsetX, e.offsetY);
    var v = { x:e.offsetX, y:e.offsetY };
    var p = mapXYFromView(v);
    var k = mapFindAddrByXY(p.x, p.y);
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
  canvas.mousedown(function(e){
  });
  canvas.mouseup(function(e){
  });
  canvas.contextmenu(function(e){
    console.log(e.offsetX, e.offsetY);
    e.preventDefault();
  });
  initMap({
    width: w,
    height: h,
    center: '/d/snow/inn',
    drawMarked: false,
  });
});
