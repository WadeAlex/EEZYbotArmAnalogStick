#include "RobotArm.h"

#include <Arduino.h>

static auto Arm = RobotArm{};

void setup() {
  Arm.setup();
}

void loop() {
  Arm.loop();
}