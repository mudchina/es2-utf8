'use strict';

(function(){

function smartTrim(text) {
  // strip line comments, // xxx
  text = text.replace(/([\/]{2}[^\n]*)/g, '');
  // strip seg comments, /* xxx */
  text = text.replace(/(\/\*[^\*]*\*\/)/g, '');
  // strip extra white space & empty line
  text = text.replace(/[\n]*/g, '');
  text = text.replace(/([ ]+|[\t])/g, ' ');
  text = text.replace(/\n[ ]+/g, '\n');
  text = text.replace(/;/g, ';\n');
  return text;
}

// replace __DIR__
function replaceDIR(str, refFile, mudlib) {
  if(str.indexOf('__DIR__')>=0) {
    if(refFile.indexOf(mudlib) === 0) {
      refFile = refFile.substring(mudlib.length);
      var words = refFile.split('/');
      if(words.length > 0) words[words.length-1] = '';
      var dir = words.join('/');
      str = str.replace('__DIR__', dir);
    }
  }
  return str;
}
  
var alltypes = {};

function contains(a, obj) {
  var i = a.length;
  while (i--) {
   if (a[i] === obj) return true;
  }
  return false;
}
  
function jsonFromLPC(text, file, mudlib, types) {
  var bases = text.match(/inherit [A-Z_]+;/g);
  if(!bases) return null;
  for(var i=0; i<bases.length; i++) {
    var base = bases[i] = bases[i].replace(/(inherit[ ]*|[ ]*;)/g, '');
    if(!alltypes[base]) alltypes[base] = 1;
    else alltypes[base] += 1;
  }

  // check valid type
  if(Array.isArray(types)) {
    var validtype = false;
    for(var i=0; i<bases.length; i++) {
      if(contains(types, bases[i])) {
        validtype = true;
        break;
      }
    }
    if(!validtype) return null;
  }

  text = smartTrim(text);

  var json = {
    type: (bases.length===1) ? bases[0] : bases,
  };
  var sets = text.match(/set[ ]*\(.*\)[ ]*;/g);
  if(sets) sets.forEach(function(str){
    var keys = str.match(/\([ ]*"[a-z_]+"[ ]*,/);
    if(!keys) return;
    var key = keys[0].replace(/[\(",]/g,'');
    var value = null;
    str = str.replace('"'+key+'"', '');
    switch(key) {
      case 'short':
        value = str.replace(/set[ ]*\([ ]*,[ ]*"|"[ ]*\)[ ]*;[ ]*/g, '');
        break;
      case 'long':
        //value = str.replace(/set[ ]*\([ ]*,[ ]*@LONG[ ]*|[ ]*LONG[ ]*\)[ ]*;[ ]*|set[ ]*\([ ]*,[ ]*"[ ]*|[ ]*"[ ]*\)[ ]*;[ ]*/g, '').replace(/。[ ]*/g, '。');
        break;
      case 'exits':
      case 'objects':
      case 'vendor_goods':
        value = {};
        var items = str.replace(/set[ ]*\([ ]*,[ ]*\(\[|\]\)[ ]*\)[ ]*;[ ]*/g, '').split(',');
        for(var j=0; j<items.length; j++) {
          var item = items[j].trim();
          if(!item) continue;
          var words = item.replace(/""/g,'').split(':');
          var k = words[0].replace(/[" ]*/g, '');
          var v = words[1].replace(/[" ]*/g, '');
          k = replaceDIR(k, file, mudlib);
          v = replaceDIR(v, file, mudlib);
          if(key === 'objects') {
            value[k] = parseInt(v);
          } else {
            value[k] = v;
          }
        }
        break;
    }
    if(value) json[key] = value;
  });
  return json;
}

if(typeof window !== 'undefined')
  window.jsonFromLPC = jsonFromLPC;
else
  exports = module.exports = {
    jsonFromLPC: jsonFromLPC,
  };

})();
