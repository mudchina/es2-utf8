#!/usr/bin/env node

'use strict';

// this utility can search rooms files in mudlib (inherit ROOM),
// generate rooms.json for drawing map.

var info = require('../package.json');
var path = require('path');

var mudlib = __dirname + '/../mudlib';

