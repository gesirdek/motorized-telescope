#pragma once

#include <Arduino.h>

class Motor {
  public:
    uint8_t stepPin;
    uint8_t dirPin;
    uint8_t enablePin;
    float movement;
    float stepsPerMM;

    Motor(uint8_t step, uint8_t dir, uint8_t enable, float stepsPerMM);
    void setMovement(float mm);
    bool direction() const;
    long steps() const;
    void setEnable(bool enable);
};
