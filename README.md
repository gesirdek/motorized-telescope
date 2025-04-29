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
| Telescope             | Bresser AR102/1000, Equatorial Mount              |
| Motors                | NEMA 17 with Planetary Gear, 28BYJ-48 Step Motor  |
| Motor Drivers         | NEMA 17 - A4988 (initial) → TMC2209 (planned), 28BYJ-48 - ULN 2003            |
| Microcontroller       | D1 Mini (ESP8266)                                 |
| Host Controller       | Via Ubuntu, (Raspberry Pi 3 Model B+ future)      |
| Power Supply          | 5V 2A USB Adapter (later: solar panel)            |
| 3D Printer            | Bambu Lab P1P |


📁 The full CAD source is available in a single FreeCAD file:  
[`TelescopProject.FCStd`](cad/TelescopProject.FCStd)  
Each version (v1, v2, failed prototypes) is modeled as a separate Body for clarity and iteration tracking.

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


## 📂 Repository Structure (Simplified)

- `cad/` → FreeCAD source file and printed STL files  
- `photos/` → Images of prototypes, failed prints, and final assemblies  
- `arduino/` → Microcontroller firmware for stepper drivers  
- `ros/` → ROS nodes for telescope control logic  
- `prototype-log.md` → Iteration notes, measurements, and learning from each step


## 📐 CAD Files

- All mechanical parts are designed in a single FreeCAD file:  
  [`TelescopProject.FCStd`](cad/TelescopProject.FCStd)
  
- Each prototype or revision is stored as a separate **Body** within the file:
  - `RA_half_pipe_v2`, `DEC_half_pipe_current`, `NEMA_L_bracket_narrow`, etc.

- Bodies that are no longer in use are marked with the suffix `_discarded`.  
  These represent either failed prints or designs that were intentionally replaced with better alternatives.

- STL files in `/cad/stl/` are **cleaned and curated**: they represent only the **most up-to-date and usable** versions of each part.
- Discarded or outdated versions (which may have been printed previously) are **not included here**, but still exist as separate bodies in the FreeCAD source file

## 🧩 PCB Files

Initial Gerber files for the motor control board are provided under `/pcb/gerber-files/`.

These are **v1 design files** and **have not yet been sent for PCB manufacturing**.  
Future versions may include design improvements based on testing results.

## ⚡ Power Supply Setup

The power supply consists of a ready-made 12V 5A unit mounted inside a protective enclosure.  
An inline 3A fuse is installed on the AC input for safety, and a DC power distributor with integrated fuses is used to organize the 12V outputs.

No custom PCB is created for the power supply; connections are made manually using standard wiring.

## ⚠️ Disclaimer

This project involves work with high voltages (230V AC) and is provided as-is without any warranty.  
Use at your own risk. Ensure you have proper knowledge and take appropriate safety measures when replicating or modifying this system.

