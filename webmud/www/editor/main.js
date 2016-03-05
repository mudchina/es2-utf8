var client = new WebClient();

function handleErr(err, ret) {
  var str = '';
  switch(err) {
  case 403:
    str = 'Access denied';
    break;
  case 404:
    str = 'Not found';
    break;
  default:
    str = 'Error: ' + err;
    break;
  }
  alert(str);
  return false;
}

function loadFile(addr) {
  client.rpc('readfile', addr + '.c', function(err, ret) {
    if(err) handleErr(err, ret);
    else {
      var data = new Uint8Array(ret);
      var str = binayUtf8ToString(data, 0);
      $('textarea#editor').val(str);
      //console.log(err, ret, str);
    }
  });
}

function saveFile() {
  var addr = $('select#list').val();
  var text = $('textarea#editor').val();
  if(addr && text && confirm('Save to ' + addr + '.c ?')) {
    client.rpc('writefile', {
      path: addr + '.c',
      text: text,
    }, function(err, ret) {
      if(err) handleErr(err);
    });
  }
}

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

function addRoomToList(addr) {
  if(typeof addr !== 'string') return;
  var r = mapGetRoomByAddr(addr);
  var t = addr + ' - ' + r.short + ' (' + r.x + ',' + r.y + ')';
  $('<option>').val(addr).text(t).appendTo('select#list');
}

function addRoomsToList(addr) {
  if(!Array.isArray(addr)) return;
  addr.forEach(function(k){
    addRoomToList(k);
  });
}

function clearRoomList(){
  $('select#list').find('option').remove().end();
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
  var roomlist = $('select#list');
  var savebtn = $('button#save');
  var lastK = '';

  canvas.mousemove(function(e){
    var tips = $('div#tips');

    var k = getAddrByClick(e);
    if(!k) return tips.hide();

    if(k !== lastK) {
      lastK = k;
      if(Array.isArray(k) && k.length>0) k = k[0];
      if(typeof k !== 'string') return;

      var r = mapGetRoomByAddr(k);
      tips.show();
      tips.html(k + '<br/>' + r.short + '<br/>(' + r.x + ',' + r.y + ')');

      var div_left = $('div#left');
      var x = e.offsetX - div_left.scrollLeft();
      var y = e.offsetY - div_left.scrollTop();
      tips.css({
        left: x + 30,
        top: y,
      });
    }
  });

  canvas.click(function(e){
    var k = getAddrByClick(e);
    if(k) {
      clearRoomList();
      if(typeof k === 'string') {
        addRoomToList(k);
      } else if(Array.isArray(k) && k.length>0) {
        addRoomsToList(k);
        k = k[0];
      }
      $('select#list').val(k);
      loadFile(k);
    }
  });

  roomlist.change(function(e){
    var addr = roomlist.val();
    if(addr) loadFile(addr);
  });

  $(document).delegate('textarea', 'keydown', function(e) {
    var keyCode = e.keyCode || e.which;

    if (keyCode == 9) {
      e.preventDefault();
      var insert = '  ';
      var start = $(this).get(0).selectionStart;
      var end = $(this).get(0).selectionEnd;

      // set textarea value to: text before caret + tab + text after caret
      $(this).val($(this).val().substring(0, start)
                  + insert
                  + $(this).val().substring(end));

      // put caret at right position again
      $(this).get(0).selectionStart =
      $(this).get(0).selectionEnd = start + insert.length;
    }
  });

  savebtn.click(function(e){
    saveFile();
  });

  canvas.contextmenu(function(e){
    console.log(e.offsetX, e.offsetY);
    e.preventDefault();
  });

  $(window).resize(adjustLayout);

  var w = 1600, h = 1400;
  div_map.css({
    width: w + 'px',
    height: h + 'px',
  });
  initMap({
    canvas: canvas[0],
    width: w,
    height: h,
    center: '/d/snow/inn',
    drawMarked: false,
  });

  adjustLayout();

  client.bind(io(), false);
});
