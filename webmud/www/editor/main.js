var client = new WebClient();
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

function loadFile(addr, drilldown) {
  var f = addr + '.c';
  $('div#filename').text(f);
  client.rpc('readfile', f, function(err, ret) {
    if(err) handleErr(err, ret);
    else {
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
  });
}

function saveFile() {
  var addr = $('select#list').val();
  var text = editor ? editor.getValue() : '';
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
  var w1 = (w/2) - 5;
  var h1 = (h - 10);

  $('div#left').css({
    width: w1 + 'px',
    height: (h1-2) + 'px',
  });
  $('div#right').css({
    width: w1 + 'px',
    height: h1 + 'px',
  });

  var list = $('select#list, select#sublist');
  var tools = $('div#tools'), editor = $('#editor');
  var w2 = w1 - 5-2;
  list.css({
    width: (w2/2-10+2) + 'px',
  });
  tools.css({
    width: w2 + 'px',
  });
  editor.css({
    width: (w2-10) + 'px',
    height: (h1 -10-2 - tools.outerHeight(true) - list.outerHeight(true)) + 'px',
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
  
  canvas.mouseout(function(e){
    var tips = $('div#tips');
    tips.hide();
  });

  canvas.click(function(e){
    var k = getAddrByClick(e);
    if(k) {
      $('select#list').find('option').remove().end();

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

  $('select#list').change(function(e){
    var me = $(e.currentTarget);
    var addr = me.val();
    if(addr) loadFile(addr);
  });

  $('select#sublist').change(function(e){
    var me = $(e.currentTarget);
    var addr = me.val();
    if(addr) loadFile(addr, true);
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

  editor = ace.edit("editor");
  editor.setTheme("ace/theme/xcode");
  editor.session.setMode("ace/mode/lpc");
  editor.session.setOptions({
    tabSize: 2,
  });

  client.bind(io(), false);
});
