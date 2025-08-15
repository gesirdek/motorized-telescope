#pragma once
#include <Arduino.h>

class Motor {
public:
  Motor(int in1, int in2, int in3, int in4);
  void stepForward(int steps);
  void stepBackward(int steps);
  void stop();

private:
  int _in1, _in2, _in3, _in4;
  int _stepIndex; // ← BUNU EKLEMEN GEREKİYOR
  void step(int stepIndex);
};
