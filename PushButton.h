//
//  PushButton.h
//
//
//  Created by Let it Brain on 03/07/2017.
//
//

#ifndef ____PushButton__
#define ____PushButton__

//#include <stdio.h>
#include <Keyboard.h>


class PushButton{
public:
    PushButton();
    ~PushButton(){};
    void setup(const int pin, const int led, bool serialMsg);
    void pressKey(const char c);
    
    void setMyPin (const int);
    void setMyLed (const int);
    int getPin();
    int getLed();
                 
                 
    // this constant won't change:
     int  buttonPin = 0;    // the pin that the pushbutton is attached to
     int ledPin = 0;       // the pin that the LED is attached to
                 
                 
                 
private:
    //let's set serial port on false by default
    bool serial = false;
    // Variables will change:
    int buttonPushCounter = 0;   // counter for the number of button presses
    int buttonState = 0;         // current state of the button
    int lastButtonState = 0;     // previous state of the button
    
    
};




#endif /* defined(____PushButton__) */
