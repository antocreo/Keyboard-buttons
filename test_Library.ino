#include <Keyboard.h>
#include "PushButton.h"


// this constant won't change:
const int  button1 = 2;    // the pin that the pushbutton is attached to
const int  buttonPlay = 3;    // the pin that the pushbutton is attached to
const int  button2 = 4;    // the pin that the pushbutton is attached to
const int  buttonReplay = 5;    // the pin that the pushbutton is attached to

const int led = 13;       // the pin that the LED is attached to

PushButton play;
PushButton but1;
PushButton but2;
PushButton replay;


void setup() {
  play.setup(buttonPlay, led, true);
  but1.setup(button1, led, true);
  but2.setup(button2, led, true);
  replay.setup(buttonReplay, led, true);

}


void loop() {
  play.pressKey('p');
  replay.pressKey('.');
  but1.pressKey('z');
  but2.pressKey('m');

}
