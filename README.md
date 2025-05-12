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
