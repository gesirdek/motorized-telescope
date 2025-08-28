#include "Motor.h"

Motor::Motor(int in1, int in2, int in3, int in4)
  : _in1(in1), _in2(in2), _in3(in3), _in4(in4), _stepIndex(0) {
  pinMode(_in1, OUTPUT);
  pinMode(_in2, OUTPUT);
  pinMode(_in3, OUTPUT);
  pinMode(_in4, OUTPUT);
  stop();
}

// 8-step half-stepping sequence
void Motor::step(int index) {
  static const bool steps[8][4] = {
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {1, 0, 0, 1}
  };

  digitalWrite(_in1, steps[index][0]);
  digitalWrite(_in2, steps[index][1]);
  digitalWrite(_in3, steps[index][2]);
  digitalWrite(_in4, steps[index][3]);
}

void Motor::stepForward(int steps) {
  for (int i = 0; i < steps; ++i) {
    _stepIndex = (_stepIndex + 1) % 8;
    step(_stepIndex);
    delay(5);
  }
}

void Motor::stepBackward(int steps) {
  for (int i = 0; i < steps; ++i) {
    _stepIndex = (_stepIndex + 7) % 8; // -1 % 8 = 7
    step(_stepIndex);
    delay(5);
  }
}

void Motor::stop() {
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, LOW);
}
