# Embedded Playground

A personal collection of embedded systems projects using **PlatformIO**, **Arduino**, and **C programming**.  
This repo serves as my learning lab and portfolio while building real hardware-based microcontroller projects.

---

## 🧰 Tools & Stack
- PlatformIO + VS Code
- Arduino Uno R3 (for now)
- C / C++
- Breadboard prototyping

---

## 📁 Projects

| Project | Description |
|--------|-------------|
| [toggle_button_led](./arduino/toggle_button_led/) | LED toggled on button press with debounce logic |
| [toggle_led_3mode](./arduino/toggle_led_3mode/) | 3-mode LED control: ON, OFF, and BLINK using separate buttons |
| [fsm_led_patterns](./arduino/fsm_led_patterns/) | FSM-based LED pattern system with 4 modes and single-button control |
| [analog_uart_logger](./arduino/analog_uart_logger/) | Outputs voltage and temperature over `Serial` every 1000ms and lights LEDs accordingly |

More projects coming soon...

---

## 🚀 How to Run

All projects are structured as independent [PlatformIO](https://platformio.org/) projects.

To build and upload any project:

```bash
cd arduino/<project_name>
pio run --target upload
```

---

## 🧪 Notes

- Each project includes its own `README.md`
- Hardware used: Arduino Uno R3, breadboard, basic components
- Some projects use `INPUT_PULLUP`, others external pull-down resistors
