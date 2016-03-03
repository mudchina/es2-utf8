#!/usr/bin/env node

'use strict';

var info = require('../package.json');
var path = require('path');
var WebTelnetProxy = require('./lib/webtelnet.js');

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
  logTraffic: true,
};

var argv = process.argv;
var me = argv[1];
var args = require('minimist')(argv.slice(2));

process.stdout.write('WebTelnet, version ' + info.version + ', by ' + info.author.name + ' <' + info.author.email +'>\n');

if(args._.length < 2) {
  process.stdout.write('Syntax: \nwebtelnet <http-port> <telnet-port> [-h <telnet-host>] [-w <path/to/www>]\n\n');
  process.exit(1);
}

conf.web.port = parseInt(args._[0], 10);
conf.telnet.port = parseInt(args._[1], 10);

if(args.h) conf.telnet.host = args.h;
if(args.w) conf.www = path.resolve(args.w);

WebTelnetProxy.startProxy(conf);
