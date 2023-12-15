#pragma once

#include <Arduino.h>
#include <Servo.h>

#include <stdint.h>

class ServoController
{
private:
  const uint8_t _pin = {};
  const float _minimumAngle = {};
  const float _maximumAngle = {};
  float _angle = 90;
  Servo _servo;

  auto clampAngle(float angle) -> float;
  auto floatsEqual(float first, float second, float tolerance = .01) -> bool;

public:
  ServoController(uint8_t pin, float minimumAngle = 0.0, float maximumAngle = 180.0);
  auto setup() -> void;
  auto move(float stickDelta) -> void;
};