var ROOM_MARK = '▲ ', CHAR_MARK = '▼ ', ITEM_MARK = '◆ ';
var EXITS_MARK = '这里明显的出口是';
var EXITS_MASK2 = '这里唯一的出口是';
var ESC_CHAR = String.fromCharCode(27);
var ESC_1 = new RegExp(ESC_CHAR+'\\[1m', 'g');
var ESC_2 = new RegExp(ESC_CHAR+'\\[2;37;0m', 'g');

// copy from es2 mudlib: /cmds/std/go.c
var ALL_DIRS = {
  'north': ['n', '北'],
  'south': ['s', '南'],
  'east': ['e', '东'],
  'west': ['w', '西'],
  'northup': ['n', '北上'],
  'southup': ['s', '南上'],
  'eastup': ['e', '东上'],
  'westup': ['w', '西上'],
  'northdown': ['n', '北下'],
  'southdown': ['s', '南下'],
  'eastdown': ['e', '东下'],
  'westdown': ['w', '西下'],
  'northeast': ['ne', '东北'],
  'northwest': ['nw', '西北'],
  'southeast': ['se', '东南'],
  'southwest': ['sw', '西南'],
  'up': ['up', '上'],
  'down': ['d', '下'],
  'out': ['up', '外'],
  'enter': ['d', '里'],
};

var SHORT_DIRS = ['n','s','e','w','nw','sw','ne','se','up','d'];

var EXPLORE_CMDS = [
  ['捡', 'get $item', 'explore'],
  ['放', 'put $item in $char', 'explore'],
  ['给', 'give $item to $char', 'explore'],
  ['丢', 'drop $item', 'explore'],
  ['买', 'buy $item from $char', 'explore'],
  ['物品', 'i $char', 'status,varargs'],

  ['吃', 'eat $item', 'explore'],
  ['喝', 'drink $item', 'explore'],
  ['问', 'ask $char', 'explore'],
  ['偷', 'steal $item from $char', 'warn'],
  ['兑换', 'convert $item', 'explore'],
  ['状态', 'hp $char', 'status,varargs'],

  ['跟随', 'follow $char', 'practice'],
  ['组队', 'team with $char', 'practice'],
  ['学习', 'learn $item from $char', 'practice'],
  ['切磋', 'fight $char', 'practice'],
  ['投降', 'surrender', 'practice'],
  ['技能', 'skills $char', 'status,varargs'],

  ['穿', 'wear $item', 'fight'],
  ['脱', 'remove $item', 'fight'],
  ['装备', 'wield $item', 'fight'],
  ['放下', 'unwield $item', 'fight'],
  ['重复', 'repeat', 'explore'],
  ['成就', 'score $char', 'status,varargs'],
];

var MARTIAL_CMDS = [
  ['全技', 'enable ?', 'learn'], // 显示全部技能类别
  ['拜师', 'apprentice $char', 'learn'],
  ['收徒', 'recruit $char', 'learn'],
  ['开除', 'expell $char', 'learn'],
  // ['绰号', 'nick'], // nick <外号, 绰号>
  ['学习', 'learn $item from $char', 'learn'],
  ['弃技', 'abandon $item', 'learn'],

  ['练习', 'practice $item', 'practice'],
  ['研读', 'study $item', 'practice'],
  ['打坐', 'respirate 30', 'practice'], // 精 -> 灵力。
  ['练气', 'exercise 30', 'practice'],  // 气 -> 内力
  ['冥想', 'meditate 30', 'practice'],  // 神 -> 法力
  ['放弃', 'abandon $item', 'warn'],

  ['用技', 'enable %skilltype $item', 'prepare'], // 指定所要用的技能，需指明技能种类和技能名称。
  ['施法', 'enchant 30', 'prepare'],   // enchant <灵力点数>, 设定使用魔法武器时要用来导引武器魔力所用的灵力强度。
  ['发力', 'enforce 30', 'prepare'],   // enforce <内力点数>, 指定每次击中敌人时，要发出几点内力伤敌。
  ['画符', 'scribe $item on $char', 'prepare'],
  ['切磋', 'fight $char', 'warn'],
  ['投降', 'surrender', 'warn'],

  ['传功', 'exert transfer', 'exert'],
  ['疗伤', 'exert heal', 'exert'],
  ['冲穴', 'exert mobilize', 'exert'],
  ['逼毒', 'exert depoison', 'exert'],
  ['杀', 'kill $char', 'warn'],
  ['逃', 'wimpy 20', 'warn'], // we escape when < 20%
];

var OTHER_CMDS = [
  ['物品', 'i', 'status'],
  ['头衔', 'title', 'status'],
  ['帮助', 'help', 'status'],
  ['巫师', 'wizlist', 'status'],

  ['兑换', 'convert $item', 'explore'],
  ['询价', 'list', 'explore'],
  ['推', 'push', 'explore'],
  ['拉', 'pull', 'explore'],
  ['灌水', 'fillwater', 'explore'],

  ['典当', 'pawn $item', 'explore'],
  ['赎回', 'retrieve', 'explore'],
  ['卖', 'sell $item', 'explore'],
  ['工作', 'work', 'explore'],

  ['绰号', 'nick', 'warn'],
  ['密码', 'passwd', 'warn'],
  ['保存', 'save', 'warn'],
//  ['自杀', 'suicide', 'warn'],
  ['退出', 'quit', 'warn'],

  // local cmds
  ['重置地图', 'clear map', 'warn'],
];

function getAllDirs() {
  return ALL_DIRS;
}

function parseNameAddr(desc) {
  // parse exits, enable / disable go keys
  var nameAddr = desc.split('\n')[0];
  var words = nameAddr.split(' - ');
  if(words.length != 2) return;
  var name = words[0].trim();
  var addr = words[1].trim();
  $('div#roomname').text(name);
  // mark visited in map
  mapGoTo(addr);
}

function parseExits(desc) {
  var exitsmark = '';
  var p = desc.indexOf(EXITS_MARK);
  if(p >= 0) {
    exitsmark = EXITS_MARK;
  } else {
    p = desc.indexOf(EXITS_MASK2);
    if(p >= 0) {
      exitsmark = EXITS_MASK2;
    } else {
      return {};
    }
  }
  p += EXITS_MARK.length;
  var p2 = desc.indexOf('。', p);
  if(p2 < 0) return;

  // extra open exits to array
  var exitstr = desc.substr(p, p2-p);
  var exits = exitstr.replace(ESC_1, '').replace(ESC_2, '').replace(/、/g, ',').replace('和', ',').split(',');
  var exitscn = [];
  for(var j=0; j<exits.length; j++) {
    exits[j] = exits[j].trim();
    exitscn.push(ALL_DIRS[exits[j]][1]);
  }

  var openDirs = {};
  for(var j=0; j<SHORT_DIRS.length; j++) {
    openDirs[ SHORT_DIRS[j] ] = 0;
  }
  var domGo = $('table#go');
  for(var j=0; j<exits.length; j++) {
    var dir = exits[j];
    var dirInfo = ALL_DIRS[ dir ];
    if(!dirInfo) continue;

    // enable go keys for valid exits
    var dirShort = dirInfo[0];
    var dirName = dirInfo[1];
    $('button#'+dirShort, domGo).attr('macro',dir).text(dirName).removeClass('disable');
    openDirs[ dirShort ] = 1;
  }
  // disable go keys for invalid exits
  for(var k in openDirs) {
    var btn = $('button#'+k, domGo);
    if(!openDirs[k]) btn.attr('macro','').text('').addClass('disable');
  }

  return {
    mark: exitsmark,
    str: exitstr,
    en: exits,
    zh: exitscn,
  };
}

function parseRoom(str) {
  // when we move or look room, we reset target char & item
  setCmdChar('');
  setCmdItem('');
  // when new room info comes, we remove old links
  //$('div#out1').find('a').contents().unwrap();
  $('div#out1').html('');

  var exits = {};
  var marks = str.split(ROOM_MARK);
  if(marks.length >= 2) {
    var lines = marks[1].split('\n');
    parseNameAddr(lines.shift());
    str = lines.join('\n');
    exits = parseExits(str);
  }

  str = addTargetLinks(str, 'look');
  str = str.replace(/    /g, '');

  // replace the exits with cmd links
  if(exits.str &&
     Array.isArray(exits.en) &&
     Array.isArray(exits.zh) &&
     (exits.en.length === exits.zh.length)) {
    var e = [];
    for(var i=0; i<exits.en.length; i++) {
      var id = exits.en[i];
      var dirzh = exits.zh[i];
      e.push(dirzh + '(<a class="target" href="#" type="cmd" ob="' + id + '">' + id + '</a>)');
    }
    str = str.replace(exits.mark+exits.str, exits.mark+e.join('、'));
  }

  return str;
}

// TODO: find NPC id,
// 1. set as default target
// 2. show context-sensitive commands
function parseChar(str) {
  // when we look at char, we reset targt item
  setCmdItem('');

  var marks = str.split(CHAR_MARK);
  if(marks.length < 2 ) return str;
  var desc = marks[1];
  var lines = desc.split('\n');
  var name = lines.shift();
  var targets = name.match(/\([\w ]+\)/gi);
  if(targets) {
    var word = targets[0].replace('(','').replace(')','');
    var id = word.toLowerCase();
    setCmdChar(id);
  }
  return name + '\n' + addTargetLinks(lines.join('\n'), 'item');
}

function parseItem(str) {
  // when we look at char, we reset targt item
  setCmdItem('');

  var marks = str.split(ITEM_MARK);
  if(marks.length < 2 ) return str;
  var desc = marks[1];
  var lines = desc.split('\n');
  var name = lines.shift();
  
  var targets = name.match(/\([\w ]+\)/gi);
  if(targets) {
    var word = targets[0].replace('(','').replace(')','');
    var id = word.toLowerCase();
    setCmdItem(id);
  }

  return name + '\n' + addTargetLinks(lines.join('\n'), 'cmdv');
}

function initModExplore(callback) {
  $('button.go').click(function(e){
    showMap(true);
    callback(e);
  });
  $('button#look').click(callback);
  $('button#opendoor').attr('macro', 'open door\nlook'); // HTML5 string not accept \n
  initKeys(EXPLORE_CMDS, 'div#expkeys', callback);
  initKeys(MARTIAL_CMDS, 'div#markeys', callback);
  initKeys(OTHER_CMDS, 'div#otherkeys', callback);
}
