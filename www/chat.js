var CHAT_CMDS = [
  ['Hi', 'say Hi~', 'emote'],
  ['大笑', 'emote 大笑起来，笑得眼泪都要出来了。', 'emote'],
  ['哭', 'emote 一屁股坐在地上，嚎啕大哭起来。', 'emote'],
  ['痛苦', 'emote 哎哟一声，一脸痛苦的样子。', 'emote'],
  ['邪恶', 'emote 眨了眨眼，邪恶的笑了。', 'emote'],
  ['欢迎', 'chat 欢迎欢迎，热烈欢迎！', 'chat'],
  ['再见', 'chat bye~', 'chat'],
  ['下了', 'chat 我先下线了哦，bye~', 'chat'],
];

var _chatChannel = '';

function setChatChannel(c,t) {
  switch(c) {
  case 'say':
  case 'chat':
  case 'whisper':
  case 'rumor':
  case 'wiz':
  case 'sys':
    break;
  default:
    c = '';
    t = '';
  }
  _chatChannel = c;
  $('a#chatchannel').text('频道:'+t);
}

function getChatChannel() {
  return _chatChannel;
}

function parseSmiley(str) {
  var targets = str.match(/：\/[0-9]+\//gi);
  if(targets) {
    targets = _.unique(targets);
    for(var i=0; i<targets.length; i++) {
      var quote_word = targets[i];
      var sm = parseInt(quote_word.replace('：\/',''), 10);
      var img = '<div class="triangle"></div><img class="sm" src="sm/' + sm + '.png"/>';
      str = str.replace(new RegExp('：\\/' + sm + '\\/', 'gi'), '：'+img);
    }
  }
  return str;
}

function sendChat(str) {
  var c = (_chatChannel || 'say');
  if(c == 'whisper') c += ' ' + getTargetChar();
  str = c + ' ' + str;
  if(sendCmd && str) sendCmd(str);
}

function onChannel(e) {
  var me = $(e.currentTarget);
  var c = me.attr('c');
  var t = me.text();
  setChatChannel(c,t);
}

function onSmiley(e) {
  var me = $(e.currentTarget);
  var c = (_chatChannel || 'say');
  if(c == 'whisper') c += ' ' + getTargetChar();
  var str = c + ' ' + me.attr('macro');
  if(sendCmd && str) sendCmd(str);
}

function initSmileys(div) {
  for(var i=0; i<=124; i++) {
    var src = 'sm/' + i + '.png';
    var macro = '/' + i + '/';
    $('<img>').attr('src', src).attr('macro', macro).addClass('smiley').click(onSmiley).appendTo(div);
  }
}

function initModChat(callback) {
  $('button.channel').click(onChannel);
  initKeys(CHAT_CMDS, 'div#chatkeys', callback);
  initSmileys('div#chatkeys');
}
