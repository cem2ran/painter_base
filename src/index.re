
let port = JsSerial.serial("/dev/ttyUSB0", ~config={ baudRate: 115200 }, ());
let readline = JsSerial.readline(port);

let dispatch = (port: JsSerial.t, msg: string) => {
  Js.log("> " ++ msg);
  
  JsSerial.writeOption(port, switch (msg) {
    | "[MSG:'$H'|'$X' to unlock]" => Some("$X")
    | _ => None
  });
};

readline
  -> JsSerial.on(`data(line => line
                       -> Js.String.trim
                       -> dispatch(port, _)))
  
  -> JsSerial.on(`close(() => {
  Js.log("port closed, exiting");
  Node.Process.exit(0);
}));

/* let write = JsSerial.write(port); */
/* write("$X"); */
/* write("G21"); */
/* write("G90"); */
/* write("G10 P1 L20 X0 Y0 Z0"); */

