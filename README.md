# Motorized Telescope

A fully motorized telescope project using 3D-printed parts, FreeCAD modeling, and ROS-based control system.  
The telescope uses an equatorial mount (Bresser AR102/1000) and will be upgraded with motors on the **Right Ascension (RA)**, **Declination (DEC)**, and **Focuser** axes for automatic tracking, alignment, and remote focusing.

This repository documents the full development process, including CAD models, electronics, motor control, ROS integration, and testing.

---

## 🚀 Project Goals

- ✅ Motorize **RA**, **DEC**, and **Focuser** axes using NEMA 17 planetary gear stepper motors.
- ✅ Design all mechanical parts in **FreeCAD** and prototype them with a **3D printer**.
- ✅ Control the motors via **stepper drivers (A4988 → TMC2209)** and a **microcontroller (Arduino → D1 Mini)**.
- ✅ Use **ROS** for high-level control and coordination.
- ✅ Implement **GoTo & Tracking** based on celestial coordinates.
- ✅ Support solar-powered operation for outdoor autonomy.
- ✅ Document all failed and revised prototypes to reduce material waste and improve design efficiency.
- 🕒 Future plan: switch to **Raspberry Pi** for portable, self-contained operation.

---

## ⚙️ Hardware Overview

| Component             | Description                                  |
|----------------------|----------------------------------------------|
| Telescope             | Bresser AR102/1000, Equatorial Mount         |
| Motors                | NEMA 17 with Planetary Gear                  |
| Motor Drivers         | A4988 (initial) → TMC2209 (planned)          |
| Microcontroller       | Arduino Uno (initial) → D1 Mini (ESP8266)    |
| Host Controller       | Raspberry Pi 3 Model B+                      |
| Power Supply          | 5V 2A USB Adapter (later: solar panel)       |
| 3D Printer            | Bambu Lab P1P |

---

## 🛠️ Current Status

- [x] Repository initialized and documented
- [x] CAD measurements started, prototype V1 tested
- [ ] Final RA motor mount design in progress
- [ ] DEC mount modeling
- [ ] Focuser gear mechanism prototyping
- [ ] ROS communication layer setup
- [ ] Integrated system test

---

## 📸 Photos & Prototyping Log

🗂️ Detailed iteration logs and photos are available in  
👉 [prototype-log.md](prototype-log.md)

---

## 📂 Repository Structure

