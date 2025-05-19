#include <Arduino.h>

#define LED_1_PIN 10
#define LED_2_PIN 9
#define LED_3_PIN 8
#define TMP36_PIN A0

int reading = 0;
unsigned long last_reading = 0;
int modeState = 0;

void display(int modeState){
  switch(modeState){
    case 0: {
      digitalWrite(LED_1_PIN, HIGH);
      digitalWrite(LED_2_PIN, LOW);
      digitalWrite(LED_3_PIN, LOW);
      break;
    }
    case 1: {
      digitalWrite(LED_1_PIN, HIGH);
      digitalWrite(LED_2_PIN, HIGH);
      digitalWrite(LED_3_PIN, LOW);
      break;
    }
    case 2: {
        digitalWrite(LED_1_PIN, LOW);
    	digitalWrite(LED_2_PIN, HIGH);
    	digitalWrite(LED_3_PIN, HIGH);
        break;
    }
    case 3: {
    	digitalWrite(LED_1_PIN, HIGH);
    	digitalWrite(LED_2_PIN, HIGH);
    	digitalWrite(LED_3_PIN, HIGH);
        break;
    }
  }
}
void setup(){
  Serial.begin(9600);
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
}

void loop(){
  if (millis() - last_reading >=1000){
      reading = analogRead(TMP36_PIN);
      float voltage = reading * 5.0;
      voltage /= 1024;
      float temperature = (voltage - 0.5) * 100; // -40 <-> 113 celcius range
    if (temperature <= 0) modeState = 0;
    if (temperature > 0 && temperature <= 40) modeState = 1;
    if (temperature > 40 && temperature <= 80) modeState = 2;
    if (temperature > 80) modeState = 3;
	display(modeState);
      Serial.print(voltage); Serial.println(" volts");
      Serial.print(temperature);Serial.println(" celcius");
      last_reading = millis();
  }
}