// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Process = require("process");
var JsSerial$Base = require("./JsSerial.bs.js");

var port = JsSerial$Base.serial("/dev/ttyUSB0", {
      baudRate: 115200
    }, /* () */0);

var readline = JsSerial$Base.readline(port);

readline.on("data", (function (line) {
          console.log(line.trim());
          return /* () */0;
        })).on("close", (function (param) {
        console.log("port closed, exiting");
        return Process.exit(0);
      }));

exports.port = port;
exports.readline = readline;
/* port Not a pure module */
