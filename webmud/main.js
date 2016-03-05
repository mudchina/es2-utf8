#!/usr/bin/env node

'use strict';

var info = require('../package.json');
var path = require('path');
var WebTelnetProxy = require('./lib/webtelnet.js');
var FileMan = require('./lib/fileman.js');

var conf = {
  telnet: {
    host: '127.0.0.1',
    port: 23,
  },
  web: {
    host: '0.0.0.0',
    port: 8080,
  },
  www: __dirname + '/../www',
  // mudlib: __dirname + '/../../mudib',
  logTraffic: true,
  fileMan: false,
};

var argv = process.argv;
var me = argv[1];
var args = require('minimist')(argv.slice(2));

process.stdout.write('WebTelnet, version ' + info.version + ', by ' + info.author.name + ' <' + info.author.email +'>\n');

if(args._.length < 2) {
  process.stdout.write(
    'Syntax: webtelnet <http-port> <telnet-port> [options]\n' +
    'Options: \n' +
    '    [-h <telnet-host>]\n' +
    '    [-w <path/to/www>]\n' +
    '    [-m <path/to/mudlib]\n\n' );
  process.exit(1);
}

conf.web.port = parseInt(args._[0], 10);
conf.telnet.port = parseInt(args._[1], 10);

if(args.h) conf.telnet.host = args.h;
if(args.w) conf.www = path.resolve(args.w);

var server = WebTelnetProxy.startProxy(conf);

// if mudlib specified, we allow edit files from remote
if(args.m) {
  var fileman = new FileMan.bind(server, args.m);
}
