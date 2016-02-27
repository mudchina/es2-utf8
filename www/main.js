function scrollDown() {
  var out = $('div#out');
  out.scrollTop(out.prop('scrollHeight'));
}

function writeToScreen(str) {
  var p = $('<p>').append(str).addClass('out');
  p.appendTo('div#out');
  $('a.cmd', p).on('click', onMacroKey);
  scrollDown();
}

var ROOM_MARK = '▲ ', CHAR_MARK = '▼ ', ITEM_MARK = '◆ ', INV_MARK = '带著下列这些东西';
var LOGIN_MARK = '您的英文名字：', PASS_MARK = '请输入密码：';
var askingLogin = false, askingPass = false, autologin = false;

function writeServerData(buf) {
  var data = new Uint8Array(buf);
  var str = binayUtf8ToString(data, 0);

  askingLogin = askingPass = false;
  if(str.indexOf(ROOM_MARK) >= 0) str = parseRoom(str);
  else if(str.indexOf(CHAR_MARK) >= 0) str = parseChar(str);
  else if(str.indexOf(ITEM_MARK) >= 0) str = parseItem(str);
  else if(str.indexOf(INV_MARK) >= 0) str = addTargetLinks(str);
  else if(str.indexOf(LOGIN_MARK) >= 0) askingLogin = true;
  else if(str.indexOf(PASS_MARK) >= 0) askingPass = true;
  
  var lines = str.split('\r\n');
  for(var i=0; i<lines.length; i++) {
    var line = lines[i].replace(/\s\s/g, '&nbsp;');
    if(i < lines.length-1) line += '<br/>';

    // replace the prompt '> ' with a empty line
    var len = line.length;
    if(len>=2 && line.substr(len-2) == '> ') line = line.substr(0, line-2);

    line = ansi_up.ansi_to_html(line);

    writeToScreen(line);
  }

  if(askingLogin) {
    setTimeout(function(){
      autologin = localStorage.getItem('autologin');
      if(autologin) autologin = confirm('是否用记住的密码自动登录？');
      if(autologin) {
        var u = localStorage.getItem('username');
        if(sendCmd && u) sendCmd(u);
      }
    }, 100);
  }
  if(askingPass) {
    if(autologin) {
      var p = localStorage.getItem('password');
      if(sendCmd && p) sendCmd(p);
      $('button#explore').click();
    }
  }
}

var itemTarget = '', charTarget = '';

function setTargetItem(str) {
  itemTarget = str;
  $('span.itemtarget').text('物品目标：'+str);
}

function setTargetChar(str) {
  charTarget = str;
  $('span.chartarget').text('角色目标：'+str);
}

function connectServer() {
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
  window.sendCmd = function(str) {
    if(str.indexOf('$char')) str = str.replace('$char', charTarget);
    if(str.indexOf('$item')) str = str.replace('$item', itemTarget);
    str = str.trim();

    // when we look at sth, we set it as item target
    if((str.indexOf('l ') >= 0) || (str.indexOf('look ') >= 0)) {
      setTargetItem(str.split(' ')[1]);
    }

    //writeToScreen(str);
    if(sock) sock.emit('data', str + '\n');
  }
}

function initKeys(cmds, div, callback) {
  for(var i=0; i<cmds.length; i++) {
    var pair = cmds[i];
    var id = 'exp' + i;
    var txt = pair[0];
    var macro = pair[1];
    $('<button>').text(txt).attr('id', id).attr('macro', macro).addClass('keys').click(callback).appendTo(div);
  }
}

function adjustLayout() {
  var w = $(window).width(), h = $(window).height();

  // adjust input box width
  var w0 = $('div#in').width();
  var btns = ['explore', 'map', 'chat', 'fight'];
  for(var i=0; i<btns.length; i++) {
    w0 -= $('button#'+btns[i]).outerWidth(true)+5;
  }
  $('input#str').css({
    width: w0 + 'px',
  });

  // adjust output area, according to input area height
  var h0 = $('div#in').outerHeight(true);
  $('div#out').css({
    width: (w-22) + 'px',
    height: (h - h0 -32) + 'px',
  });

  scrollDown();
}

function showPad(name) {
  $('div.pad').hide();
  if(name) $('div#'+name).show();
  adjustLayout();
}

var cmdHistory = [];
var cmdIndex = 0;

function sendInput() {
  var cmd = $('input#str');
  var str = cmd.val().trim();

  if(askingLogin) localStorage.setItem('username', str);
  else if(askingPass) {
    localStorage.setItem('password', str);
    localStorage.setItem('autologin', confirm('是否记住密码？'));
  }

  // store cmd in history for re-use when press up / down arrow key
  if(cmdHistory.length > 20) cmdHistory.unshift();
  if(str && (str != cmdHistory[cmdHistory.length-1])) {
    cmdHistory.push(str);
  }
  cmdIndex = cmdHistory.length;

  if(sendCmd) sendCmd(str);
  cmd.val('');
}

function cmdHistoryUp() {
  if(cmdIndex > 0) {
    cmdIndex --;
    if(cmdIndex < cmdHistory.length) {
      var str = cmdHistory[cmdIndex];
      $('input#str').val(str);
    }
  } else $('input#str').val('');
}

function cmdHistoryDown() {
  if(cmdIndex < cmdHistory.length-1) {
    cmdIndex ++;
    var str = cmdHistory[cmdIndex];
    $('input#str').val(str);
  } else $('input#str').val('');
}

function onMacroKey(e) {
  var me = $(e.currentTarget);
  var str = me.attr('macro');
  //console.log(str);
  if(sendCmd && str) sendCmd(str);
}

function initUI() {
  $(window).resize(adjustLayout);

  $('button.menu').click(function(e) {
    var name = $(e.currentTarget).attr('id');
    showPad(name);
  });

  initExploreKeys(onMacroKey);

  // UI events
  $('input#str').keydown(function(e) {
    // console.log(e.keyCode);
    switch(e.keyCode) {
      case 38: // up arrow key
        cmdHistoryUp();
        break;
      case 40: // down arrow key
        cmdHistoryDown();
        break;
      case 13: // enter
        sendInput();
        break;
    }
  });
  $('input#str').focus(function(e){
    showPad(null);
  });
}

$(document).ready(function(){
  initUI();

  setTimeout(function(){
    adjustLayout();

    setTimeout(function(){
      connectServer();
    }, 200);
  }, 100)
});
