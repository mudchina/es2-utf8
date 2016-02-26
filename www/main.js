var ROOM_MARK = '▲ ', CHAR_MARK = '□ ', ITEM_MARK = '◇ ';

// remove \r\n in a room description, to fit window width
function parseRoom(str) {
  var marks = str.split(ROOM_MARK);
  for(var i=1; i<marks.length; i++) {
    var desc = marks[i];
  }
  return str;
}

function parseChar(str) {
  var marks = str.split(CHAR_MARK);
  for(var i=1; i<marks.length; i++) {
    var desc = marks[i];
  }
  return str;
}

function parseItem(str) {
  var marks = str.split(ITEM_MARK);
  for(var i=1; i<marks.length; i++) {
    var desc = marks[i];
  }
  return str;
}

function writeToScreen(str) {
  var out = $('div#out');
  out.append('<span class="out">' + str + '</span>');
  out.scrollTop(out.prop("scrollHeight"));
}

function writeServerData(buf) {
  var data = new Uint8Array(buf);
  var str = binayUtf8ToString(data, 0);

  if(str.indexOf(ROOM_MARK) >= 0) str = parseRoom(str);
  if(str.indexOf(CHAR_MARK) >= 0) str = parseChar(str);
  if(str.indexOf(ITEM_MARK) >= 0) str = parseItem(str);
  
  var lines = str.split('\r\n');
  for(var i=0; i<lines.length; i++) {
    var line = lines[i].replace(/\s\s/g, '&nbsp;');
    if(i < lines.length-1) line += '<br/>';

    // replace the prompt "> " with a empty line
    var len = line.length;
    if(len>=2 && line.substr(len-2) == '> ') line = line.substr(0, line-2);

    line = ansi_up.ansi_to_html(line);

    writeToScreen(line);
  }
}

function adjustLayout() {
  var w = $(window).width(), h = $(window).height();
  var w0 = $('div#cmd').width();
  var w1 = $('button#send').outerWidth(true);
  var w2 = $('button#clear').outerWidth(true);
  $('input#cmd').css({
    width: (w0 - (w1+w2+14)) + 'px',
  });
  var h0 = $('div#cmd').outerHeight(true);
  $('div#out').css({
    width: (w-32) + 'px',
    height: (h - h0 -32) + 'px',
  });
}

$(window).resize(adjustLayout);

var cmdHistory = [];
var cmdIndex = 0;

$(document).ready(function(){
  //$.cookie('lang', 'zh');
  //hotjs.i18n.setLang('zh');
  //hotjs.i18n.translate();

  // websocket
  var sock = io.connect();
  sock.on('data', function(buf){
    writeServerData(buf);
  });
  sock.on('status', function(str){
    writeToScreen(str);
  });
  sock.on('connected', function(){
    console.log('connected');
  });
  sock.on('disconnect', function(){
    console.log('disconnected');
  });

  // send
  var send = function(str) {
    //writeToScreen(str);
    if(sock) sock.emit('data', str);
  }
  var sendInput = function() {
    var cmd = $('input#cmd');
    var str = cmd.val().trim();

    // store cmd in history for re-use when press up / down arrow key
    if(str && (str != cmdHistory[cmdHistory.length-1])) {
      if(cmdHistory.length > 100) cmdHistory.unshift();
      cmdHistory.push(str);
      cmdIndex = cmdHistory.length;
    }

    send(str + '\n');
    cmd.val('');
  }

  // UI events
  $('input#cmd').keydown(function(e) {
    // console.log(e.keyCode);
    switch(e.keyCode) {
      case 37: // left arrow key
        break;
      case 39: // right arrow key
        break;
      case 38: // up arrow key
        if(cmdIndex > 0) {
          cmdIndex --;
          if(cmdIndex < cmdHistory.length) {
            var str = cmdHistory[cmdIndex];
            $('input#cmd').val(str);
          }
        } else $('input#cmd').val('');
        break;
      case 40: // down arrow key
        if(cmdIndex < cmdHistory.length-1) {
          cmdIndex ++;
          var str = cmdHistory[cmdIndex];
          $('input#cmd').val(str);
        } else $('input#cmd').val('');
        break;
      case 13: // enter
        sendInput();
        break;
    }
  });
  $('button#send').click(function(e) {
    sendInput();
  });
  $('button#clear').click(function(e) {
    $('div#out').html('');
  });

  setTimeout(function(){
    adjustLayout();
  },200)
});
