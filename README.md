# Motorized Telescope

A fully motorized telescope project using 3D-printed parts, FreeCAD modeling, and ROS-based control system.  
The telescope uses an equatorial mount (Bresser AR102/1000) and will be upgraded with motors on the **Right Ascension (RA)**, **Declination (DEC)**, and **Focuser** axes for automatic tracking, alignment, and remote focusing.

This repository documents the full development process, including CAD models, electronics, motor control, ROS integration, and testing.

---

## 🚀 Project Goals

- ✅ Motorize **RA**, **DEC** axes using NEMA 17 planetary gear stepper motors.
- ✅ Motorize **Focuser** using 28BYJ-48 stepper motor.
- ✅ Design all mechanical parts in **FreeCAD** and prototype them with a **3D printer**.
- ✅ Control the motors via **stepper drivers (A4988 → TMC2209, ULN 2003)** and a **microcontroller (Arduino → D1 Mini)**.
- ✅ Use **ROS** for high-level control and coordination.
- ✅ Implement **GoTo & Tracking** based on celestial coordinates.
- ✅ Document all failed and revised prototypes to reduce material waste and improve design efficiency.
- ✅ Switched to **Raspberry Pi** for portable, self-contained operation.
- 🕒 Future plan - Support solar-powered operation for outdoor autonomy.

---

## ⚙️ Hardware Overview

| Component             | Description                                  |
|----------------------|----------------------------------------------|
| Telescope             | Bresser AR102/1000, Equatorial Mount              |
| Motors                | NEMA 17 with Planetary Gear, 28BYJ-48 Step Motor  |
| Motor Drivers         | NEMA 17 - A4988 (initial) → TMC2209 (planned), 28BYJ-48 - ULN 2003            |
| Microcontroller       | D1 Mini (ESP8266)                                  |
| Host Controller       | Raspberry Pi 5 Model                               |
| Power Supply          | 12V 5A USB Adapter (later: solar panel)            |
| 3D Printer            | Bambu Lab P1P |


## 🛠️ Current Status

- [x] Repository initialized and documented
- [x] CAD measurements started, prototype V1 tested
- [x] Final RA motor mount design in progress
- [x] DEC mount modeling
- [x] Focuser gear mechanism prototyping
- [ ] ROS communication layer setup
- [ ] Integrated system test

---

## 📸 Photos & Prototyping Log

🗂️ Detailed iteration logs and photos are available in  
👉 [prototype-log.md](prototype-log.md)


## 📂 Repository Structure (Simplified)

- `cad/` → FreeCAD source file and STL files for 3D printing, and Bambu Studio `.3mf` project files
- `photos/` → Images of prototypes, failed prints, and final assemblies  
- `pcb/` → Gerber files and PCB resources for the motor control board
- `arduino/` → Microcontroller firmware for stepper drivers  
- `ros/` → ROS nodes for telescope control logic  
- `prototype-log.md` → Iteration notes, measurements, and learning from each step


## 📐 CAD Files

- All mechanical parts are designed in individual FreeCAD files.

- Each functional group (e.g. RA/DEC parts, power box) lives in its own folder under `/cad/`.

- Discarded or outdated parts are moved to a central file: [`TelescopeProject.FCStd`](cad/TelescopeProject.FCStd)

- Bodies that are no longer in use are marked with the suffix `_discarded`.  
  These represent either failed prints or designs that were intentionally replaced with better alternatives.

- STL files in `/cad/stl/` are **cleaned and curated**: they represent only the **most up-to-date and usable** versions of each part. 
- STL files in `/cad/stl/` follow the **same folder structure** as the FreeCAD source files.
- Discarded or outdated versions (which may have been printed previously) are **not included here**, but still exist as separate bodies in the FreeCAD source file

<details>
<summary>📁 CAD Folder Structure (click to expand)</summary>

```
/cad/
├── telescope_body_parts/
│ ├── DEC-Half-Pipe.FCStd
│ └── RA-Half-Pipe.FCStd
├── power-box-parts/
│ ├── Pin.FCStd
│ ├── Power-Box-Back.FCStd
│ ├── Power-Box-Base.FCStd
│ ├── Power-Box-Front.FCStd
│ ├── Power-Box-Left-Side.FCStd
│ ├── Power-Box-Right-Side.FCStd
│ └── Power-Box-Top.FCStd
├── ec-box-parts/
│ ├── EC-base.FCStd
│ ├── EC-Box-Assembly.FCStd
│ ├── EC-Box-Side-L.FCStd
│ ├── EC-Box-Side-R.FCStd
│ └── EC-Box-Top.FCStd
├── shared_parts/
│ ├──  L-Grabber.FCStd
│ └── TripodGrabber.FCStd
├── crayford_focuser/
│ ├── bearings-base.FCStd
│ ├── crayford-focuser-presser.FCStd
│ ├── crayford-holder.FCStd
│ └── crayford-tube.FCStd
├── stl/
│ ├── telescope_body_parts/
│ ├── power-box-parts/
│ ├── ec-box-parts/
│ ├── crayford_focuser/
│ └── shared_parts/
└── TelescopeProject.FCStd
```
</details>

## 🎛️ Bambu Studio Project Files

The `bambu-studio/` folder contains `.3mf` project files created with Bambu Studio. These files include both the 3D model(s) and all relevant print settings (such as layer height, speed, support configuration, and filament type) used for slicing.

Unlike some other slicers, Bambu Studio does not store print settings as separate configuration files — all settings are embedded within the `.3mf` file itself.

### Notes
- File names may indicate specific profiles (e.g., "high-quality", "draft", or nozzle size), but the actual configuration is always included in the `.3mf` file.
- If you're using a different slicer or printer, refer to the `.stl` files in the `stl/` folder and manually adjust your settings based on the intended configuration.
- Optional: some setting screenshots may also be included for reference.


## 🧩 PCB Files

Initial Gerber files for the motor control board are provided under `/pcb/gerber-files/`.

These are **v1 design files** and **have not yet been sent for PCB manufacturing**.  
Future versions may include design improvements based on testing results.

## ⚡ Power Supply Setup

The power supply consists of a ready-made 12V 5A unit mounted inside a protective enclosure.  
An inline T1A fuse (slow-blow) is installed on the AC input for safety, and a DC power distributor with integrated fuses is used to organize the 12V outputs.

No custom PCB is created for the power supply; connections are made manually using standard wiring.

## ⚠️ Disclaimer

This project involves work with high voltages (230V AC) and is provided as-is without any warranty.  
Use at your own risk. Ensure you have proper knowledge and take appropriate safety measures when replicating or modifying this system.

