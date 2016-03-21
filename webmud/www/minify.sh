#!/bin/bash

uglifyjs chat.js explore.js mapdata.js maprender.js main.js -o main.min.js -p 5 -c -m

uglifycss main.css > main.min.css

