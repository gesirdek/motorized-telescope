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

## 📅 April 12, 2025 — RA Half Pipe V2 (Screw Alignment Issue)

- **Goal**: Redesign the RA half-pipe with a longer arc and improved screw hole alignment for M8 bolts.
- **Result**: The arc length was sufficient, but the screw hole geometry still didn't align properly with the mount holes. The piece couldn’t be mounted without excessive force.
- **Learning**: In the next version, precise measurement around the telescope collar and bolt spacing is required. Hole offset needs to be based on actual curvature path, not just diameter.
- 📸 `photos/RA-half-pipe-v2-failed-to-fit screw-2025-04-12 at 20.13.03.jpeg`

## 📅 April 13, 2025 — RA Half-Pipe Adjustment Planning
- Slight increase in arc length (~3–5°) is required for better alignment of the motor arm.
- The M8 bolt hole needs a flared or curved entry for easier fitment, and slight sanding might be needed where the bracket meets the telescope.
- 📸 `photos/RA-half-pipe-adjustments-requıired-pipe-length.jpeg`, 
- 📸 `photos/RA-half-pipe-adjustments-requıired-screw.jpeg`

## 📅 April 14, 2025 — RA Half Pipe Stable Version
- **Goal**: Produce a structurally stable RA half-pipe mount to carry the stepper motor.
- **Result**: The latest printed version successfully holds the motor with sufficient stability. Minor alignment refinements may still be required.
- 📸 `photos/14-04-2025-RA-half-pipe-stable_1.jpeg`,
- 📸 `photos/14-04-2025-RA-half-pipe-stable_2.jpeg`

