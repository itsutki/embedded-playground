#include <Arduino.h>

const int buttonOff = 7;
const int buttonBlink = 6;
const int buttonOn = 5;
const int ledPin = 8;

int modeState = 0; // 0: off, 1: on, 2: blink
unsigned long lastBlinkTime = 0;
bool ledOn = false;

void blink() {
  if (millis() - lastBlinkTime >= 250) {
    ledOn = !ledOn;
    digitalWrite(ledPin, ledOn);
    lastBlinkTime = millis();
  }
}

void setup(){
  pinMode(buttonOff, INPUT);
  pinMode(buttonBlink, INPUT);
  pinMode(buttonOn, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  
  if (digitalRead(buttonOff) == HIGH) modeState = 0;
  if (digitalRead(buttonOn) == HIGH) modeState = 1;
  if (digitalRead(buttonBlink) == HIGH) modeState = 2;
  
  switch(modeState){
    case 0: 
    digitalWrite(ledPin, LOW);
    break;
    case 1: 
    digitalWrite(ledPin, HIGH);
    break;
    case 2: 
    blink();
    break;
  }
}