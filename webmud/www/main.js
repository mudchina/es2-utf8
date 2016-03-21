var _cmdItem = '', _cmdChar = '';
var _localCmds = {};

var _allCmds = {};
var _cmdLast = '';
var _cmdHistory = [];
var _cmdIndex = 0;

// set cmd item, if already same, then count +1
function setCmdItem(str) {
  if(_cmdItem && str) {
    var n = parseInt(_cmdItem, 10) || 0;
    var oldItem = '';
    if(n > 1) {
      var words = _cmdItem.split(' ');
      words.shift();
      oldItem = words.join(' ');
    } else {
      oldItem = _cmdItem;
    }
    if(oldItem === str) {
      n = n ? (n+1) : 2;
      _cmdItem = n + ' ' + str;
    } else {
      _cmdItem = str;
    }
  } else {
    _cmdItem = str;
  }

  $('a#cmditem').text(_cmdItem || '物品/技能:');

  // update macro key status
  // console.log('setCmdItem', str);
  var needCharItem = $('button.needCharItem');
  var needItem = $('button.needItem');
  var varargs = $('button.varargs');
  if(_cmdChar && _cmdItem) {
    needCharItem.removeClass('disable');
    needItem.addClass('disable');
  } else {
    needCharItem.addClass('disable');
    (_cmdItem) ? needItem.removeClass('disable') : needItem.addClass('disable');
  }
  varargs.removeClass('disable');
}

function getCmdItem() {
  return _cmdItem;
}

function setCmdChar(str) {
  // console.log('setCmdChar', str);
  _cmdChar = str;
  $('a#cmdtarget').text(_cmdChar || '目标:');

  // update macro key status
  var needCharItem = $('button.needCharItem');
  var needChar = $('button.needChar');
  var varargs = $('button.varargs');
  if(_cmdChar && _cmdItem) {
    needCharItem.removeClass('disable');
    needChar.addClass('disable');
  } else {
    needCharItem.addClass('disable');
    (_cmdChar) ? needChar.removeClass('disable') : needChar.addClass('disable');
  }
  varargs.removeClass('disable');
}

function getCmdChar() {
  return _cmdChar;
}

function addLocalCmd(cmd, func) {
  if(typeof func === 'function') _localCmds[cmd] = func;
}

function onMacroKey(e) {
  var me = $(e.currentTarget);
  var str = me.attr('macro');
  var func = _localCmds[str];
  if(func && typeof(func) === 'function')
    func();
  else if(sendCmd && str)
    sendCmd(str);
}

function onTargetLink(e) {
  var me = $(e.currentTarget);
  var ob = me.attr('ob');
  if(!ob) return;
  
  var type = me.attr('type');
  switch(type) {
    case 'look':
      if(sendCmd && ob) sendCmd('l ' + ob);
      break;
    case 'item':
    case 'skill':
      setCmdItem(ob);
      break;
    case 'cmd':
      sendCmd(ob);
      break;
    case 'cmdv':
      if(_cmdItem) {
        var relook = ['open','close'].indexOf(ob) >= 0;
        ob += ' ' + _cmdItem;
        setCmdItem('');
        if(relook) ob += '\nl';
      }
      sendCmd(ob);
      break;
    case 'ask':
      if(_cmdChar) {
        sendCmd('ask ' + _cmdChar + ' about ' + ob);
      }
      break;
  }
}

function scrollDown(which) {
  var out = $('div#out' + (which || 1));
  out.scrollTop(out.prop('scrollHeight'));
}

function writeLine(str, which) {
  which = (which || 1);
  var p = $('<p>').append(str).addClass('out');
  p.appendTo('div#out' + which);
  $('a.target', p).on('click', onTargetLink);
  scrollDown(which);
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
      var link_word = '(<a class="target" href="#" type="' + type + '" ob="' + id + '">' + word.toLowerCase() + '</a>)';
      str = str.replace(new RegExp('\\(' + word + '\\)', 'gi'), link_word);
    }
  }
  return str;
}

function addTopicLinks(str, type) {
  if(!type) type = 'ask';
  var targets = str.match(/『[^x00-xFF^※]+』/gi);
  if(targets) {
    targets = _.unique(targets);
    for(var i=0; i<targets.length; i++) {
      var quote_word = targets[i];
      var word = quote_word.replace('『','').replace('』','');
      var link_word = '『<a class="target" href="#" type="' + type + '" ob="' + word + '">' + word + '</a>』';
      str = str.replace(new RegExp('『' + word + '』', 'gi'), link_word);
    }
  }
  return str;
}

var ROOM_MARK = '▲ ', CHAR_MARK = '▼ ', ITEM_MARK = '◆ ', ITEM_DESC_MARK = '※ ';
var TELNET_MARK = 'ﺢ탿퟿떿놿ﻉ';
var INV_MARK = '带著下列这些东西', SKILLS_MARK = '目前所学过的技能', ASK_MARK = '你可以打听这些事情';
var LOGIN_MARK = '您的英文名字：', PASS_MARK = '请输入密码：';
var SMILEY_MARK = '：/';
var askingLogin = false, askingPass = false, autologin = false;

function writeServerData(buf) {
  var data = new Uint8Array(buf);
  var str = binayUtf8ToString(data, 0);
  if(str.indexOf(TELNET_MARK) >= 0) str = str.replace(TELNET_MARK, '');

  askingLogin = askingPass = false;
  if(str.indexOf(ROOM_MARK) >= 0) str = parseRoom(str);
  else if(str.indexOf(CHAR_MARK) >= 0) {
    $('div#out2').html('');
    str = parseChar(str);
    return writeToScreen(str, 2);

  } else if(str.indexOf(ITEM_MARK) >= 0) {
    $('div#out2').html('');
    str = parseItem(str);
    return writeToScreen(str, 2);

  } else if(str.indexOf(ITEM_DESC_MARK) >= 0) {
    str = addTargetLinks(str, 'cmdv');
    return writeToScreen(str);

  } else if(str.indexOf(INV_MARK) >= 0) {
    $('div#out2').html('');
    str = addTargetLinks(str, 'look');
    return writeToScreen(str, 2);

  } else if(str.indexOf(ASK_MARK) >= 0) {
    $('div#out2').html('');
    str = addTopicLinks(str, 'ask');
    return writeToScreen(str, 2);

  } else if(str.indexOf(SKILLS_MARK) >= 0) {
    $('div#out2').html('');
    str = addTargetLinks(str, 'skill');
    return writeToScreen(str, 2);

  } else if(str.indexOf(SMILEY_MARK) >= 0) str = parseSmiley(str);
  else if(str.indexOf(LOGIN_MARK) >= 0) askingLogin = true;
  else if(str.indexOf(PASS_MARK) >= 0) askingPass = true;
  else if(str.indexOf('(y/n)') >= 0) {
    sendCmd(confirm(str) ? 'y' : 'n');
  }

  if(str) writeToScreen(str);
}

function writeToScreen(str, which) {
  which = (which || 1);
  if(which === 2) {
    $('div#out1').hide();
    $('div#out2box').show();
    showMap(false);
  }

  var lines = str.split('\n');
  for(var i=0; i<lines.length; i++) {
    var line = lines[i];//.replace(/\s\s/g, '&nbsp;');
    // replace the prompt '> ' with a empty line
    var len = line.length;
    if(len>=2 && line.substr(len-2) == '> ') line = line.substr(0, line-2);
    writeLine( ansi_up.ansi_to_html(line), which );
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
      
      showPad('explore');
      showMap(false);
      showScene(true);
    }
  }
}

function connectServer() {
  // websocket
  var sock = io.connect();
  sock.on('stream', function(buf){
    writeServerData(buf);
  });
  sock.on('status', function(str){
    console.log(str);
    if(str.indexOf('disconnected')>=0) {
      alert('服务器连接已断开。');
    } else if(str.indexOf('connected')>=0) {
      if(confirm('前方是虚幻的武侠世界。\n\n即将开始冒险之旅，准备好了吗？')) {
        $('div#in').show();
        adjustLayout();
      } else {
        sock.disconnect();
      }
    }
  });
  sock.on('connected', function(){
    console.log('connected');
  });
  sock.on('disconnect', function(){
    console.log('disconnected');
  });

  // send any data to trigger a telnet connect
  sock.emit('stream', '\n');

  // send one or multi-cmds with \n
  window.sendCmd = function(str) {
    $('div#out2box').hide();
    $('div#out1').show();

    if(str.indexOf('$char')) str = str.replace('$char', getCmdChar());
    if(str.indexOf('$item')) str = str.replace('$item', getCmdItem());
    str = str.trim();

    // remember last command, we can repeat
    _cmdLast = str;

    // process cmds one by one
    var lines = str.split('\n');
    for(var i=0; i<lines.length; i++) {
      var line = lines[i].trim();
      // when we look at sth, we set it as item target
      if((line.indexOf('l ') === 0) || (line.indexOf('look ') === 0)) {
        var words = line.split(' ');
        words.shift();
        setCmdItem(words.join(' '));
      }
    }

    //writeToScreen(str);
    if(sock) sock.emit('stream', str + '\n');
  }
}

function initKeys(cmds, div, callback) {
  for(var i=0; i<cmds.length; i++) {
    var pair = cmds[i];
    var id = 'exp' + i;
    var txt = pair[0];
    var macro = pair[1];
    var cls = pair[2];

    var btn = $('<button>');
    var needItem = (macro.indexOf('$item') >= 0);
    var needChar = (macro.indexOf('$char') >= 0);
    btn.text(txt).attr('id', id).attr('macro', macro).addClass('keys').click(callback).appendTo(div);
    if(cls) {
      if(cls.indexOf(',')>=0) {
        var items = cls.split(',');
        items.forEach(function(item){
          btn.addClass(item.trim());
        });
      } else btn.addClass(cls);
    }
    if(needItem && needChar) btn.addClass('needCharItem');
    else if(needItem) btn.addClass('needItem');
    else if(needChar) btn.addClass('needChar');
  }
}

function adjustLayout() {
  var w = $(window).width(), h = $(window).height();

  // adjust input box width
  var w0 = $('div#in').width();
  var w1 = w0;
  var btns = ['explore', 'martial', 'map', 'chat', 'others'];
  for(var i=0; i<btns.length; i++) {
    w1 -= $('button#'+btns[i]).outerWidth(true)+2;
  }
  $('input#str').css({
    width: w1 + 'px',
  });

  // adjust map size
  var tbGo = $('table#go');
  var mw = w0 - tbGo.outerWidth(true) -12;
  var mh = tbGo.outerHeight(true);
  $('div#map, div#expkeys').css({
    width: mw+'px',
    height: mh+'px',
    overflow: 'scroll',
  });

  // resize map & redraw
  setMapViewSize(mw, mh);
  drawMap();

  // adjust output area, according to input area height
  var h0 = $('div#in').outerHeight(true);
  var h1 = $('div#roomname').outerHeight(true);
  var h2 = $('button#out2x').outerHeight(true);
  $('div#room').css({
    width: (w-10) + 'px',
    height: (h - h0 -34) + 'px',
  });
  $('div#out1, div#out2box').css({
    width: (w-10-4) + 'px',
    height: (h - h0 -34 -h1 -4) + 'px',
  });
  $('div#out2').css({
    width: (w-20-4) + 'px',
    height: (h - h0 -34 -h1 -h2) + 'px',
  });

  scrollDown(1);
  scrollDown(2);
}

function showPad(name) {
  $('div.pad').hide();
  if(name) $('div#'+name).show();
  adjustLayout();
}

function sendInput() {
  var cmd = $('input#str');
  var str = cmd.val().trim();

  if(askingLogin) localStorage.setItem('username', str);
  else if(askingPass) {
    localStorage.setItem('password', str);
    localStorage.setItem('autologin', confirm('是否记住密码？'));
  }

  // store cmd in history for re-use when press up / down arrow key
  if(_cmdHistory.length > 20) _cmdHistory.unshift();
  if(str && (str != _cmdHistory[_cmdHistory.length-1])) {
    _cmdHistory.push(str);
  }
  _cmdIndex = _cmdHistory.length;

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
  if(_cmdIndex > 0) {
    _cmdIndex --;
    if(_cmdIndex < _cmdHistory.length) {
      var str = _cmdHistory[_cmdIndex];
      $('input#str').val(str);
    }
  } else $('input#str').val('');
}

function cmdHistoryDown() {
  if(_cmdIndex < _cmdHistory.length-1) {
    _cmdIndex ++;
    var str = _cmdHistory[_cmdIndex];
    $('input#str').val(str);
  } else $('input#str').val('');
}

function showMap(y) {
  var map = $('div#map');
  var expkeys = $('div#expkeys');
  var out1 = $('div#out1');
  var out2 = $('div#out2box');
  if(typeof y !== 'boolean') {
    y = ! map.is(':visible');
  }
  if(y) {
    map.show();
    expkeys.hide();
    out1.show();
    out2.hide();
  } else {
    map.hide();
    expkeys.show();
  }
}

function showScene(y) {
  var out1 = $('div#out1');
  var out2 = $('div#out2box');
  if(typeof y !== 'boolean') {
    y = ! out1.is(':visible');
  }
  if(y) {
    out1.show();
    out2.hide();
  } else {
    out1.hide();
    out2.show();
  }
}

function initUI() {
  $(window).resize(adjustLayout);

  $('button.menu').click(function(e) {
    var me = $(e.currentTarget);
    var menu = me.attr('id');
    var pad = me.attr('pad');
    showPad(pad);

    switch(menu) {
    case 'explore':
      showMap(false);
      showScene();
      break;
    case 'map':
      showMap();
      break;
    }
  });
  $('a#cmdtarget').click(function(e){
    setCmdChar('');
  });
  $('a#cmditem').click(function(e){
    setCmdItem('');
  });
  $('a#chatchannel').click(function(e){
    setChatChannel('');
  });

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
  $('button#out2x').click(function(e){
    $('div#out2box').hide();
    $('div#out1').show();
    $('div#out2').html('');
    setCmdChar('');
  });

  addLocalCmd('repeat', function(){
    sendCmd(_cmdLast);
  });

  initModExplore(onMacroKey);
  initModChat(onMacroKey);
  initModMap(onMacroKey);

  // now we find all cmds from macro keys
  var macroKeys = $('button.keys, button.go');
  var n = macroKeys.length;
  for(var i=0; i<n; i++) {
    var macro = $(macroKeys[i]).attr('macro');
    _allCmds[macro.split(' ')[0].trim()] = macro.trim();
  }
}

function initModMap(callback){
  addLocalCmd('clear map', function(){
    clearMapMarks();
    drawMap();
  });
  addLocalCmd('save map', function(){
    saveMapMarks();
  });
  initMap({
    canvas: 'canvas#map',
    width: 640,
    height: 640,
    drawMarked: true,
    drawDomain: false,
    center: '/d/snow/inn',
  });
}

$(document).ready(function(){
  initUI();
  setCmdChar('');
  setCmdItem('');
  $('div#roomname').text('天 朝 帝 国');
  setTimeout(function(){
    connectServer();
  }, 2000);
});
