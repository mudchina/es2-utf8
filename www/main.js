var _itemTarget = '', _charTarget = '';

function setTargetItem(str) {
  _itemTarget = str;
  $('a#itemtarget').text('物品/技能:'+str);
}

function getTargetItem() {
  return _itemTarget;
}

function setTargetChar(str) {
  _charTarget = str;
  $('a#chartarget').text('目标:'+str);
}

function getTargetChar() {
  return _charTarget;
}

function onMacroKey(e) {
  var me = $(e.currentTarget);
  var str = me.attr('macro');
  //console.log(str);
  if(sendCmd && str) sendCmd(str);
}

function onTargetLink(e) {
  var me = $(e.currentTarget);
  var ob = me.attr('ob');
  if(!ob) return;
  
  setTargetItem(ob);

  switch(me.attr('type')) {
    case 'look':
      if(sendCmd && ob) sendCmd('l ' + ob);
      break;
    case 'item':
      break;
    case 'skill':
      break;
  }
}

function scrollDown() {
  var out = $('div#out');
  out.scrollTop(out.prop('scrollHeight'));
}

function writeToScreen(str) {
  var p = $('<p>').append(str).addClass('out');
  p.appendTo('div#out');
  $('a.target', p).on('click', onTargetLink);
  scrollDown();
}

function addTargetLinks(str, type) {
  if(!type) type = 'look';
  var targets = str.match(/\([\w \-]+\)/gi);
  if(targets) {
    targets = _.unique(targets);
    for(var i=0; i<targets.length; i++) {
      var quote_word = targets[i];
      var word = quote_word.replace('(','').replace(')','');
      var id = word.toLowerCase();
      var link_word = '(<a class="target" href="#" type="' + type + '" ob="' + id + '">' + word + '</a>)';
      str = str.replace(new RegExp('\\(' + word + '\\)', 'gi'), link_word);
    }
  }
  return str;
}

var ROOM_MARK = '▲ ', CHAR_MARK = '▼ ', ITEM_MARK = '◆ ';
var INV_MARK = '带著下列这些东西', SKILLS_MARK = '目前所学过的技能';
var LOGIN_MARK = '您的英文名字：', PASS_MARK = '请输入密码：';
var SMILEY_MARK = '：/';
var askingLogin = false, askingPass = false, autologin = false;

function writeServerData(buf) {
  var data = new Uint8Array(buf);
  var str = binayUtf8ToString(data, 0);

  askingLogin = askingPass = false;
  if(str.indexOf(ROOM_MARK) >= 0) str = parseRoom(str);
  else if(str.indexOf(CHAR_MARK) >= 0) str = parseChar(str);
  else if(str.indexOf(ITEM_MARK) >= 0) str = addTargetLinks(str, 'item');
  else if(str.indexOf(INV_MARK) >= 0) str = addTargetLinks(str, 'look');
  else if(str.indexOf(SKILLS_MARK) >= 0) str = addTargetLinks(str, 'skill');
  else if(str.indexOf(SMILEY_MARK) >= 0) str = parseSmiley(str);
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
    if(str.indexOf('$char')) str = str.replace('$char', getTargetChar());
    if(str.indexOf('$item')) str = str.replace('$item', getTargetItem());
    str = str.trim();

    // when we look at sth, we set it as item target
    if((str.indexOf('l ') >= 0) || (str.indexOf('look ') >= 0)) {
      var words = str.split(' ');
      words.shift();
      setTargetItem(words.join(' '));
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
    var cls = pair[2];
    $('<button>').text(txt).attr('id', id).attr('macro', macro).addClass('keys').addClass(cls).click(callback).appendTo(div);
  }
}

function adjustLayout() {
  var w = $(window).width(), h = $(window).height();

  // adjust input box width
  var w0 = $('div#in').width();
  var btns = ['explore', 'martial', 'map', 'chat', 'others'];
  for(var i=0; i<btns.length; i++) {
    w0 -= $('button#'+btns[i]).outerWidth(true)+4;
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

  if(sendCmd) {
    var c = getChatChannel();
    if(c && (!askingLogin) && (!askingPass)) {
      sendChat(str)
    } else {
      sendCmd(str);
    }
  }

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

function initUI() {
  $(window).resize(adjustLayout);

  $('button.menu').click(function(e) {
    var name = $(e.currentTarget).attr('id');
    showPad(name);
  });
  $('a#chartarget').click(function(e){
    setTargetChar('');
  });
  $('a#itemtarget').click(function(e){
    setTargetItem('');
  });
  $('a#chatchannel').click(function(e){
    setChatChannel('');
  });

  initModExplore(onMacroKey);
  initModChat(onMacroKey);
  initModMap(onMacroKey);

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
