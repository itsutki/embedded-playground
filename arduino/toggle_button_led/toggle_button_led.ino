#include "Arduino.h" 

int buttonPin = 7;
const int ledPin = 8;

int buttonState;
int lastButtonState = LOW;
int ledState = LOW;

void setup(){
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  
  buttonState = digitalRead(buttonPin);
  
  if(lastButtonState == LOW && buttonState == HIGH){
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    delay(50);
  }
  lastButtonState = buttonState;
}