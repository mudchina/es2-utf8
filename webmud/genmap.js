#!/usr/bin/env node

'use strict';

// this utility can search rooms files in mudlib (inherit ROOM),
// generate rooms.json for drawing map.

var info = require('../package.json');
var path = require('path'),
    fs = require('fs');
var parser = require('./lib/parsemap');

var argv = process.argv;
var me = argv[1];
var args = require('minimist')(argv.slice(2));

process.stdout.write('MapGenerator, version ' + info.version + ', by ' + info.author.name + ' <' + info.author.email +'>\n');

if(args._.length < 2) {
  process.stdout.write('Syntax: \ngenmap <path/to/mudlib> <output.js/output.json>\n\n');
  process.exit(1);
}

var mudlib = path.resolve(args._[0]);
var file = path.resolve(args._[1]);
var ext = path.extname(file);
var folders = ['d', 'u'];

var map = parser.parseMap(mudlib, folders);
if(map) {
  console.log(map.count + ' rooms found from ' + map.total + ' files.\n');
  var text = JSON.stringify(map, null, '  ');
  if(ext === '.json') {
    fs.writeFileSync(file, text, 'utf8');
  } else if(ext === '.js') {
    fs.writeFileSync(file, 'var mapdata = \n' + text + ';\n', 'utf8');
  } else {
    console.log('Only export to .json/.js file');
  }
}
