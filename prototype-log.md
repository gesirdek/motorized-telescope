# Prototyping & Iteration Log

This document records all 3D printed prototypes, their testing results, and learnings. Even failed or broken parts are documented to highlight design evolution and material efficiency.

---

## 📅 April 2025 — RA Half Pipe (First Attempt)

- **Goal**: Design a half-pipe mount to secure motor housing around the RA axis.
- **Result**: The piece cracked near the bolt hole. Instead of increasing wall thickness, I decided to extend the length of the half-circle so that the mounting holes would be easier to align and allow M5 screws to fit without stress.
- **Learning**: Geometric adjustments (e.g., part length) can sometimes be more effective than increasing thickness. This change also helped with assembly tolerance.
- 📸 `photos/RA-half-pipe-end-fail.jpeg`

---

## 📅 April 2025 — DEC Half Pipe (First Version)

- **Goal**: Create a symmetrical half-pipe bracket for the DEC axis mount.
- **Result**: Initial design printed correctly but cracked under bolt pressure.
- **Fix**: Strengthened the model with wider edge and offset the holes from edge.
- 📸 `photos/DEC-half-pipe-first-version.jpeg`
- 📸 `photos/DEC-Half-pipe-crack.jpeg`

---

## 📅 April 2025 — L-Bracket Motor Mounts (Comparison)

- **Goal**: Compare and test two L-bracket versions for mounting the NEMA17 planetary gear motor.
- **Result**: Both versions had compatible hole positions. However, the **left version was narrower**, which allowed correct positioning. The wider one did not leave enough clearance for the desired alignment.
- **Learning**: Bracket width matters for motor and coupling orientation — even if hole alignment is correct.
- 📸 `photos/nema17-L-bracket-2-versions-left-fits.jpeg`

---

## 📅 April 2025 — DEC Motor Mount (Mechanical Assembly Test)

- **Goal**: Assemble the DEC motor mount using the latest half-pipe version and L-bracket to test mechanical alignment and fit.
- **Result**: Mounting was mechanically successful. The motor aligned well with the coupling, and the bracket provided stable support. However, the DEC half-pipe still needs visual and geometric refinement for better fit and finish.
- **Next**: Perform motor test (rotation + holding torque) before proceeding to final cabling and driver installation.
- 📸 `photos/DEC-mount-succes-motor-L-connect.jpeg`
- 📸 `photos/DEC-mount-success-up.jpeg`
- 📸 `photos/DEC-coupling-motor-success.jpeg`

## 📅 April — RA Half Pipe V2 (Screw Alignment Issue)

- **Goal**: Redesign the RA half-pipe with a longer arc and improved screw hole alignment for M8 bolts.
- **Result**: The arc length was sufficient, but the screw hole geometry still didn't align properly with the mount holes. The piece couldn’t be mounted without excessive force.
- **Learning**: In the next version, precise measurement around the telescope collar and bolt spacing is required. Hole offset needs to be based on actual curvature path, not just diameter.
- 📸 `photos/RA-half-pipe-v2-failed-to-fit screw-2025-04-12 at 20.13.03.jpeg`

## 📅 April — RA Half-Pipe Adjustment Planning
- Slight increase in arc length (~3–5°) is required for better alignment of the motor arm.
- The M8 bolt hole needs a flared or curved entry for easier fitment, and slight sanding might be needed where the bracket meets the telescope.
- 📸 `photos/RA-half-pipe-adjustments-requıired-pipe-length.jpeg`, 
- 📸 `photos/RA-half-pipe-adjustments-requıired-screw.jpeg`

## 📅 April — RA Half Pipe Stable Version
- **Goal**: Produce a structurally stable RA half-pipe mount to carry the stepper motor.
- **Result**: The latest printed version successfully holds the motor with sufficient stability. Minor alignment refinements may still be required.
- 📸 `photos/14-04-2025-RA-half-pipe-stable_1.jpeg`,
- 📸 `photos/14-04-2025-RA-half-pipe-stable_2.jpeg`

## 📅 April — Updated L-Grabbers and Half-Pipe Mounts Installed
- **Goal**: Update L-grabbers and produce/install new half-pipe mounts for both RA and DEC motor setups.
- **Result**:Updated L-grabbers were successfully installed with revised half-pipe designs. Mounting alignment achieved with solid mechanical fit.
- 📸 `photos/L-Grabber-mounted-1.jpeg`,
- 📸 `photos/L-Grabber-mounted-2.jpeg`,
- 📸 `photos/L-Grabber-mounted-3.jpeg`

## 📅 April — First Motor Spin with D1 Mini
- **Goal**:  Verify stepper motor movement using D1 Mini and initial breadboarded electronics.
- **Result**: Successfully controlled one stepper motor via D1 Mini using STEP/DIR pins. Stable rotation achieved.
- 📸 `photos/Stepper-Motor-1.jpeg`,
- 📸 `photos/Stepper-Motor-E.jpeg`,
- 📸 `photos/Elect-Stepper-Motor.png`

## 📅 April 24, 2025 — Electronics Enclosure Design Started
- **Goal**: Begin designing a housing/enclosure for the electronics, including the D1 Mini and driver boards.
- **Result**:  Initial sketches and measurements completed. Enclosure will accommodate future upgrades. Next goal: drive two motors via a single D1 Mini.
- 📸 `photos/Elect-Box-1.png`
- 📸 `photos/Elect-Box-2.png`

## 📅 May 6, 2025 — Power Supply Enclosure Design in Progress
- **Goal**: Create a stable and compact enclosure to house the power supply and related wiring.
- **Result**:  Preliminary design completed in FreeCAD. Dimensions adjusted to fit under telescope tripod. Ventilation and cable routing considered.
- 📸 `photos/PETG-power-supply-fail.png`
- 📸 `photos/PETG-power-supply-fail-2.png`

## 📅 May 8, 2025 — Power Box Assembly Test (Right, Rear, Base)
- **Goal**: Print and test-fit the right, rear, and base parts of the power supply box.
- **Result**: Parts interlocked successfully. Some minor issues occurred.
- 📝 Forgot to include one of the holes on the rear panel — drilled manually.
- 📝 The lower interlock on the right side was printed with support; removal left a rough surface.
- 📝 Didn't sand the surface; assembly required some force but was possible.
- 📝 Fit was not smooth; alternative support strategy needed for future prints.
- 📸 `photos/power-box-fit-test-2025-05-08.png`
- 📸 `photos/power-box-back.jpeg`
- 📸 `photos/power-box-base-back-right.jpeg`
- 📸 `photos/power-box-right-panel.jpeg`

## 📅 May 14, 2025 — Power Box Final Assembly and Verification
- **Goal**: Complete assembly of the power supply box and perform final verification.
- **Result**: Assembly completed successfully. Output stable under load.
- 📝 All panels fully assembled and interlocked.
- 📝 Fluorescent tape applied to edges for visibility in low light.
- 📝 Hot glue used to secure internal components.
- 📝 Output voltage and current tested — stable operation confirmed.
- 📝 No overheating or noise detected during test.
- 📸 photos/power-box-assembled.jpeg
- 📸 photos/power-box-assembled-2.jpeg
- 📸 photos/power-box-internal-hotglue.jpeg
- 📸 photos/power-box-fluorescent-edges.jpeg

## 📅 May 21, 2025 — RA/DEC Motor Box Assembly and Test
- **Goal**: Assemble the RA/DEC control box, wire the electronics, and verify functionality via MQTT.
- **Result**: System operational; motors respond correctly to MQTT commands.
- 📝 RA/DEC box assembled and electronics placed inside.
- 📝 All internal wiring completed; connections verified.
- 📝 One faulty Dupont cable was replaced.
- 📝 Box closed and system tested.
- 📝 After powering D1 Mini and sending MQTT command via Mosquitto, both RA and DEC motors moved as expected.
- 📝 Noticed that motor power must be connected after D1 Mini is powered on — this behavior needs investigation.
- 📝 Planned task completed: Structured Wi-Fi command interface implemented using MQTT; remote control now functional.
- 📽️ [Watch test video on YouTube](https://youtube.com/shorts/sel-l1Y8c-Y)

🛠️ Planned: 
- Gerber file needs to be updated to reflect latest wiring and component layout.
- Focuser motor integration.