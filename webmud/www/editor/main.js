var client = new WebRPCClient();
var editor = null;

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

function loadFile(addr, drilldown, center) {
  var f = addr + '.c';
  $('input#filename').val(f);
  client.rpc('readfile', f, function(err, ret) {
    if(err) handleErr(err, ret);
    else {
      mapMarkActive(addr);

      // convert to string
      var data = new Uint8Array(ret);
      var str = binayUtf8ToString(data, 0);

      // set editor content
      if(editor) {
        editor.setValue(str);
        editor.gotoLine(0,0,false);
      }

      var list = $('select#list'), sublist = $('select#sublist');

      // move all items from sublist to list
      if(drilldown) {
        list.find('option').remove().end();
        sublist.find('option').each(function(){
          var me = $(this);
          $('<option>').val(me.val()).text(me.text()).appendTo('select#list');
        });
      }

      // add exits / objects to sublist
      sublist.find('option').remove().end();
      var json = jsonFromLPC(str, addr, "");
      // console.log(JSON.stringify(json));
      // console.log(err, ret, str);
      if(json) {
        var keys = ['exits', 'vendor_goods'];
        keys.forEach(function(key){
          if(key in json) {
            var items = json[key];
            for(var i in items) {
              var ob = items[i];
              $('<option>').val(ob).text(ob).appendTo('select#sublist');
            }
          }
        });
        if(json.objects) {
          for(var ob in json.objects) {
            $('<option>').val(ob).text(ob).appendTo('select#sublist');
          }
        }
      }
    }

    if(center) mapCenter(addr);
  });
}

function saveFile() {
  var f = $('input#filename').val();
  var text = editor ? editor.getValue() : '';
  if(f && text && confirm('Save to ' + f + '?')) {
    client.rpc('writefile', {
      path: f,
      text: text,
    }, function(err, ret) {
      if(err) handleErr(err);
    });
  }
}

function loadMap(){
  client.rpc('loadmap', 0, function(err, ret) {
    if(err) handleErr(err);
    else {
      mapdata = ret;
      mapAutoXY();
      drawMap();
    }
  });
}

function adjustLayout(){
  var page = $(window);
  var w = page.width(), h = page.height();
  var w1 = (w/2) - 5;
  var h1 = (h - 5);

  var toolbar = $('div#toolbar');
  toolbar.css({
    width: (w-10) + 'px',
  });

  var h2 = h1 - toolbar.outerHeight(true);
  $('div#left').css({
    width: w1 + 'px',
    height: h2 + 'px',
  });
  $('div#right').css({
    width: w1 + 'px',
    height: h2 + 'px',
  });

  setMapViewSize(w1+1, h2);

  var list = $('select#list, select#sublist');
  var tools = $('div#tools'), div_editor = $('#editor');
  var w2 = w1 - 5-2;
  list.css({
    width: (w2/2-5+2) + 'px',
  });
  tools.css({
    width: w2 + 'px',
  });
  div_editor.css({
    width: (w2-10) + 'px',
    height: (h2-10 - tools.outerHeight(true) - list.outerHeight(true)) + 'px',
  });
}

function showTips(t, x, y) {
  var tips = $('div#tips');
  tips.show();
  tips.html(t);

  var div_left = $('div#left');
  tips.css({
    left: x - div_left.scrollLeft() + 20,
    top: y - div_left.scrollTop(),
  });
}

function showRoomTips(k) {
  if(Array.isArray(k) && k.length>0) k = k[0];
  if(typeof k !== 'string') return;

  var r = mapGetRoomByAddr(k);
  if(!r) return;

  var p = mapXYToView(r);
  var t = k + '<br/>' + r.short + '<br/>(' + r.x + ',' + r.y + ')';
  showTips(t, p.x, p.y);
}

$(document).ready(function(){
  var getAddrByClick = function(e){
    var v = { x:e.offsetX, y:e.offsetY };
    var p = mapXYFromView(v);
    var k = mapFindAddrByXY(p.x, p.y);
    return k;
  }
  var getDomainByClick = function(e) {
    var v = { x:e.offsetX, y:e.offsetY };
    var p = mapXYFromView(v);
    var d = mapFindDomainByXY(p.x, p.y);
    return d;
  }

  var div_map = $('div#map');
  var canvas = $('canvas#map');
  var roomlist = $('select#list');
  var savebtn = $('button#save');

  var mouseMode = 'select';
  var mouseDown = false;
  var lastMouse, lastPoint, lastRoom;

  $('button#loadmap').click(function(e){
    loadMap();
  });
  $('button#movemap').click(function(e){
    mouseMode = 'move';
  });
  $('button#select').click(function(e){
    mouseMode = 'select';
  });
  $('button#link').click(function(e){
    mouseMode = 'link';
  });
  $('button#unlink').click(function(e){
    mouseMode = 'unlink';
  });

  canvas.mousedown(function(e){
    mouseDown = true;
    lastMouse = { x:e.offsetX, y:e.offsetY };
    lastPoint = getMapViewCenter();

    if(mouseMode === 'select') {
      var k = getAddrByClick(e);
      if(k) {
        lastRoom = k;
        mapMarkActive(k);
      } else {
        curDomain = getDomainByClick(e);
      }
    }
    drawMap();
    e.preventDefault();
  });

  canvas.mouseup(function(e){
    mouseDown = false;

    if(mouseMode === 'select') {
      var k = getAddrByClick(e);
      if(k) {
        if(lastRoom === k) {
          $('select#list').find('option').remove().end();
          if(typeof k === 'string') {
            addRoomToList(k);
          } else if(Array.isArray(k) && k.length>0) {
            addRoomsToList(k);
            k = k[0];
          }
          $('select#list').val(k);
          loadFile(k, false);
        }
      }
    }
    drawMap();
    e.preventDefault();
  });

  canvas.mousemove(function(e){
    if(mouseDown) {
      var p = {
        x: (e.offsetX - lastMouse.x) + lastPoint.x,
        y: (e.offsetY - lastMouse.y) + lastPoint.y,
      };
      switch(mouseMode) {
        case 'select':
          drawMap();
          // draw rect
          break;
        case 'move':
          setMapViewCenter(p);
          drawMap();
          break;
        case 'link':
        case 'unlink':
          drawMap();
          // draw link
          break;
      }

    } else if(mouseMode !== 'move') {
      var k = getAddrByClick(e);
      if(!k) return $('div#tips').hide();
      else if(k !== lastRoom) {
        lastRoom = k;
        showRoomTips(k, e.offsetX, e.offsetY);
      }
    }
  });

  canvas.mouseenter(function(e){
    switch(mouseMode) {
    case 'move':
      document.body.style.cursor = 'move';
      break;
    case 'select':
      document.body.style.cursor = 'default';
      break;
    case 'link':
    case 'unlink':
      document.body.style.cursor = 'cross';
      break;
    }
  });

  canvas.mouseout(function(e){
    $('div#tips').hide();
    document.body.style.cursor = 'default';
  });

  $('select#list').change(function(e){
    var me = $(e.currentTarget);
    var addr = me.val();
    if(addr) loadFile(addr, false, true);
  });

  $('select#sublist').change(function(e){
    var me = $(e.currentTarget);
    var addr = me.val();
    if(addr) loadFile(addr, true, true);
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
    canvas: 'canvas#map',
    width: w,
    height: h,
    center: '/d/snow/inn',
    drawMarked: false,
    drawDomain: true,
  });

  adjustLayout();

  editor = ace.edit("editor");
  editor.setTheme("ace/theme/xcode");
  editor.session.setMode("ace/mode/lpc");
  editor.session.setOptions({
    tabSize: 2,
  });

  client.bind(io(), false);
});
