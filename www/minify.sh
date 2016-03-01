#!/bin/bash

uglifyjs chat.js explore.js map.js main.js -o main.min.js -p 5 -c -m

uglifycss main.css > main.min.css

