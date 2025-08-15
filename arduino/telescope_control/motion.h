#pragma once

#include <Arduino.h>
#include "Motor.h"
#include <algorithm>
#include <PubSubClient.h>

// External declarations
extern Motor raMotor;
extern Motor decMotor;
extern PubSubClient client;

extern bool isStopped;

// Function to drive both motors synchronously
void moveMotorMM() {
  client.publish("teleskop/status", "busy");
  raMotor.setEnable(true);
  decMotor.setEnable(true);

  digitalWrite(raMotor.dirPin, raMotor.direction());
  digitalWrite(decMotor.dirPin, decMotor.direction());

  long ra_steps = raMotor.steps();
  long dec_steps = decMotor.steps();
  long steps = std::max(ra_steps, dec_steps);

  for (long i = 0; i < steps; i++) {
    if (isStopped) break;

    if (i < ra_steps) digitalWrite(raMotor.stepPin, HIGH);
    if (i < dec_steps) digitalWrite(decMotor.stepPin, HIGH);

    delayMicroseconds(80);

    if (i < ra_steps) digitalWrite(raMotor.stepPin, LOW);
    if (i < dec_steps) digitalWrite(decMotor.stepPin, LOW);

    delayMicroseconds(80);
  
    if (i >= ra_steps) raMotor.setEnable(false);
    if (i >= dec_steps) decMotor.setEnable(false);

    if (i % 20 == 0) yield(); // WDT protection
  }

  // Disable motors
  raMotor.setEnable(false);
  decMotor.setEnable(false);
}