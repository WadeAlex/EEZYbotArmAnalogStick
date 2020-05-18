#include "RobotArm.h"

#include <Arduino.h>

auto Arm = RobotArm{};

void setup() {
  Arm.setup();
}

void loop() {
  Arm.loop();
}