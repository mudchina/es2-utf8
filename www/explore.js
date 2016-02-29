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

function getAllDirs() {
  return ALL_DIRS;
}

var SHORT_DIRS = ['n','s','e','w','nw','sw','ne','se','up','d'];

function parseExits(str) {
  // parse exits, enable / disable go keys
  var marks = str.split(ROOM_MARK);
  for(var i=1; i<marks.length; i++) {
    var desc = marks[i];
    var nameAddr = desc.split('\n')[0];
    var p = desc.indexOf(EXITS_MARK);
    if(p < 0) {
      p = desc.indexOf(EXITS_MASK2);
      if(p < 0) continue;
    }
    p += EXITS_MARK.length;
    var p2 = desc.indexOf('。', p);
    if(p2 < 0) continue;

    // extra open exits to array
    var exits = desc.substr(p, p2-p)
      .replace(ESC_1, '').replace(ESC_2, '').replace(/、/g, ',').replace('和', ',')
      .split(',');
    for(var j=0; j<exits.length; j++) {
      exits[j] = exits[j].trim();
    }

    // pass to map module
    mapCheckRoom(nameAddr, exits);

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
  }
}

function parseRoom(str) {
  // when we move or look room, we reset target char & item
  setTargetChar('');
  setTargetItem('');
  
  // when new room info comes, we remove old links
  $('div#out').find('a').contents().unwrap();

  parseExits(str);

  return addTargetLinks(str, 'look');
}

// TODO: find NPC id,
// 1. set as default target
// 2. show context-sensitive commands
function parseChar(str) {
  // when we look at char, we reset targt item
  setTargetItem('');

  var marks = str.split(CHAR_MARK);
  for(var i=1; i<marks.length; i++) {
    var desc = marks[i];
    var targets = desc.match(/\([\w ]+\)/gi);
    if(targets) {
      var word = targets[0].replace('(','').replace(')','');
      var id = word.toLowerCase();
      setTargetChar(id);
      break;
    }
  }
  
  return addTargetLinks(str, 'item');
}

var exploreCmds = [
  ['捡', 'get $item', 'explore'],
  ['放', 'put', 'explore'],
  ['给', 'give $item to $char', 'explore'],
  ['丢', 'drop $item', 'explore'],
  ['买', 'buy $item from $char', 'explore'],
  ['偷', 'steal $item from $char', 'explore'],

  ['吃', 'eat $item', 'explore'],
  ['喝', 'drink $item', 'explore'],
  ['跟随', 'follow $char', 'explore'],
  ['组队', 'team with $char', 'explore'],
  ['开门', 'open door\nl', 'explore'],
  ['关门', 'close door\nl', 'explore'],

  ['穿', 'wear $item', 'fight'],
  ['脱', 'remove $item', 'fight'],
  ['装备', 'wield $item', 'fight'],
  ['放下', 'unwield $item', 'fight'],
  ['挑战', 'fight $char', 'warn'],
  ['投降', 'surrender', 'warn'],

  ['物品', 'i', 'status'],
  ['状态', 'hp $char', 'status'],
  ['技能', 'skills $char', 'status'],
  ['成就', 'score $char', 'status'],
  ['杀', 'kill $char', 'warn'],
  ['逃', 'wimpy 20', 'warn'], // we escape when < 20%
];

var martialCmds = [
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
  ['画符', 'scribe $item on $item', 'prepare'],
  ['挑战', 'fight $char', 'warn'],
  ['投降', 'surrender', 'warn'],

  ['传功', 'exert transfer', 'exert'],
  ['疗伤', 'exert heal', 'exert'],
  ['冲穴', 'exert mobilize', 'exert'],
  ['逼毒', 'exert depoison', 'exert'],
  ['杀', 'kill $char', 'warn'],
  ['逃', 'wimpy 20', 'warn'], // we escape when < 20%
];

var otherCmds = [
  ['物品', 'i', 'status'],
  ['头衔', 'title', 'status'],
  ['帮助', 'help', 'status'],
  ['巫师', 'wizlist', 'status'],

  ['绰号', 'nick', 'warn'],
  ['密码', 'passwd', 'warn'],
  ['保存', 'save', 'warn'],
  //['自杀', 'suicide', 'warn'],
  ['退出', 'quit', 'warn'],

  ['列举', 'list', 'explore'],
  ['推', 'push', 'explore'],
  ['拉', 'pull', 'explore'],
  ['灌水', 'fillwater', 'explore'],

  ['典当', 'pawn $item', 'explore'],
  ['赎回', 'retrieve', 'explore'],
  ['卖', 'sell $item', 'explore'],
  ['工作', 'work', 'explore'],

];

function initModExplore(callback) {
  $('button.go').click(callback);
  initKeys(exploreCmds, 'div#expkeys', callback);
  initKeys(martialCmds, 'div#markeys', callback);
  initKeys(otherCmds, 'div#otherkeys', callback);
}


