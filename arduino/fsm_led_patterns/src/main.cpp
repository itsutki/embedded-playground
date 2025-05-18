#include <Arduino.h>

#define LED_1_PIN 10
#define LED_2_PIN 9
#define LED_3_PIN 8
#define BUTTON_PIN 4

bool ledOn = false;
unsigned long lastBlinkTime = 0;
int buttonPushCounter = 0;
int lastButtonState = HIGH;
unsigned long lastSlideTime = 0;
int currentLed = 0;

void blink() {
  if (millis() - lastBlinkTime >= 250) {
    ledOn = !ledOn;
    digitalWrite(LED_1_PIN, ledOn);
    digitalWrite(LED_2_PIN, ledOn);
    digitalWrite(LED_3_PIN, ledOn);
    lastBlinkTime = millis();
  }
}

void slide() {
  const unsigned long slideDelay = 250;

  if (millis() - lastSlideTime >= slideDelay) {
    // turn all LEDs off
    digitalWrite(LED_1_PIN, LOW);
    digitalWrite(LED_2_PIN, LOW);
    digitalWrite(LED_3_PIN, LOW);

    // turn next LED on
    if (currentLed == 0) digitalWrite(LED_1_PIN, HIGH);
    else if (currentLed == 1) digitalWrite(LED_2_PIN, HIGH);
    else if (currentLed == 2) digitalWrite(LED_3_PIN, HIGH);

    // select next LED
    currentLed++;
    if (currentLed > 2) currentLed = 0;

    lastSlideTime = millis();
  }
}

void setup() {
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) {
    buttonPushCounter++;
    if (buttonPushCounter > 3) buttonPushCounter = 0;
    delay(50); // debounce
  }

  lastButtonState = buttonState;

  switch (buttonPushCounter) {
    case 0:
      digitalWrite(LED_1_PIN, LOW);
      digitalWrite(LED_2_PIN, LOW);
      digitalWrite(LED_3_PIN, LOW);
      break;

    case 1:
      digitalWrite(LED_1_PIN, HIGH);
      digitalWrite(LED_2_PIN, HIGH);
      digitalWrite(LED_3_PIN, HIGH);
      break;

    case 2:
      blink();
      break;
    
    case 3:
      slide();
      break;
  }
}
