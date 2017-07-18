//
//  PushButton.cpp
//
//
//  Created by Let it Brain on 03/07/2017.
//
//

#include "PushButton.h"


PushButton::PushButton() {};

void PushButton::setup(const int pin, const int led, bool serialMsg) {
  //passing the variables
  setMyPin(pin);
  setMyLed (led);
  serial = serialMsg;

  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);

  // initialize serial communication:
  if (serial) {
    Serial.begin(9600);
  }
  //start the keyboard library
  Keyboard.begin();
}


void PushButton::pressKey(const char c) {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      //HIGH the LED
      digitalWrite(getLed(), HIGH);

      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
      if (serial) {
        Serial.println("on");
        Serial.print("number of button pushes:  ");
        Serial.println(buttonPushCounter);
      }

    } else {
      //LOW the LED
      digitalWrite(getLed(), LOW);

      // if the current state is LOW then the button
      // wend from on to off:
      if (serial) {
        Serial.println("off");
      }

      //press and realease the char c
      Keyboard.press(c);
      Keyboard.releaseAll();

    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;



}


void PushButton::setMyPin ( int pin) {
  buttonPin = pin;
}
void PushButton::setMyLed ( int led) {
  ledPin = led;
}
int PushButton::getPin() {
  return buttonPin;
}
int PushButton::getLed() {
  return ledPin;
}

