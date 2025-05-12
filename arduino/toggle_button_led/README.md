# Toggle LED with Push Button (Arduino)

This project toggles an LED on and off each time a button is pressed.

---

## 🧠 What It Does
- Reads input from a push button connected to digital pin 7  
- Toggles an LED connected to digital pin 8  
- Stores LED state in a variable (`ledState`)  
- Tracks button state change (LOW → HIGH) using `lastButtonState`  
- Adds basic debounce using `delay(50)`
---


## ⚡ Circuit Diagram

- LED anode → Pin 8  
- LED cathode → 220Ω resistor → GND  
- Push button one leg → +5V  
- Other leg → Pin 7  
- 10KΩ resistor between Pin 7 and GND (pull-down)

+5V ---- Button ---- Pin 7
|
[10KΩ]
|
GND

Pin 8 ----> [220Ω] ----> LED ----> GND


---

## 🔧 Code Snippet

```cpp
if (lastButtonState == LOW && buttonState == HIGH) {
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
  delay(50); // debounce
}
```

---

## 🧪 Tested On

- Arduino Uno R3

- Standard push button

- Basic breadboard setup

---

## 📂 File Structure

```cpp
toggle_button_led/
├── toggle_button_led.ino
└── README.md
```
---
### 💡 Notes

You can replace INPUT + external pull-down with INPUT_PULLUP and invert the logic.

Replace delay() with millis() for non-blocking debounce in advanced projects.