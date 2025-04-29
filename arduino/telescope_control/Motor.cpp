#include "Motor.h"

Motor::Motor(uint8_t step, uint8_t dir, uint8_t enable, float stepsPerMM)
  : stepPin(step), dirPin(dir), enablePin(enable), stepsPerMM(stepsPerMM), movement(0) {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH);
}

void Motor::setMovement(float mm) {
  movement = mm;
}

bool Motor::direction() const {
  return movement >= 0;
}

long Motor::steps() const {
  return abs(movement * stepsPerMM);
}

void Motor::setEnable(bool enable) {
  digitalWrite(enablePin, enable ? LOW : HIGH);
}