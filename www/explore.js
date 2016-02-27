var ROOM_MARK = '▲ ', CHAR_MARK = '▼ ', ITEM_MARK = '◆ ';

var EXITS_MARK = '这里明显的出口是';
var EXITS_MASK2 = '这里唯一的出口是';
var ESC_CHAR = String.fromCharCode(27);
var ESC_1 = new RegExp(ESC_CHAR+'\\[1m', 'g');
var ESC_2 = new RegExp(ESC_CHAR+'\\[2;37;0m', 'g');

function addTargetLinks(str) {
  var targets = str.match(/\([\w ]+\)/gi);
  if(targets) {
    targets = _.unique(targets);
    for(var i=0; i<targets.length; i++) {
      var quote_word = targets[i];
      var word = quote_word.replace('(','').replace(')','');
      var id = word.split(' ')[0].toLowerCase();
      var link_word = '(<a class="cmd" href="#" macro="l ' + id + '">' + word + '</a>)';
      str = str.replace(new RegExp('\\(' + word + '\\)', 'gi'), link_word);
    }
  }
  return str;
}

// copy from es2 mudlib: /cmds/std/go.c
var allDirs = {
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
  'up': ['nw', '上'],
  'down': ['sw', '下'],
  'out': ['ne', '外'],
  'enter': ['ne', '里'],
};
var SHORT_DIRS = ['n','s','e','w','nw','sw','ne','se'];

function parseExits(str) {
  // parse exits, enable / disable go keys
  var marks = str.split(ROOM_MARK);
  for(var i=1; i<marks.length; i++) {
    var desc = marks[i];
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

    var openDirs = {};
    for(var j=0; j<SHORT_DIRS.length; j++) {
      openDirs[ SHORT_DIRS[j] ] = 0;
    }
    var domGo = $('table#go');
    for(var j=0; j<exits.length; j++) {
      var dir = exits[j];
      var dirInfo = allDirs[ dir ];
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

  return addTargetLinks(str);
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
      var id = word.split(' ')[0].toLowerCase();
      setTargetChar(id);
    }
  }
  
  return addTargetLinks(str);
}

// TODO: find Item id,
// 1. set as default target
// 2. show context-sensitive commands
function parseItem(str) {
  return addTargetLinks(str);
}

var exploreCmds = [
  ['捡', 'get $item'],
  ['放', 'put'],
  ['给', 'give $item to $char'],
  ['丢', 'drop $item'],
  ['买', 'buy $item from $char'],
  ['偷', 'steal $item from $char'],
  ['开门', 'open door\nl'],
  ['关门', 'close door\nl'],
  ['挑战', 'fight $char'],
  ['杀', 'kill $char'],
  ['跟随', 'follow $char'],
  ['组队', 'team with $char'],
  ['状态', 'hp $char'],
  ['物品', 'i'],
  ['技能', 'skills $char'],
  ['成就', 'score $char'],
];

function initExploreKeys(callback) {
  $('button.go').click(callback);
  initKeys(exploreCmds, 'div#expkeys', callback);
}


