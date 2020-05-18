#pragma once

#include <Servo.h>
#include <stdint.h>

class ServoOutput
{
private:
  uint8_t _pin = {};
  float _angle = 90;
  Servo _servo;
  const char *_name = {};

public:
  ServoOutput(uint8_t pin, const char *name = "");
  auto setup() -> void;
  auto loop(float stickDelta) -> void;
};