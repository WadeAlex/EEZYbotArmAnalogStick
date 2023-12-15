#include "RobotArm.h"

#include "AnalogStickInput.h"
#include "ServoController.h"

#include <Arduino.h>

auto RobotArm::setup() -> void
{
    Serial.begin(9600);
    upperArmGripOpenStick.setup();
    lowerArmRotateGripCloseStick.setup();
    rotationServo.setup();
    lowerArmServo.setup();
    upperArmServo.setup();
    gripServo.setup();
}

auto RobotArm::loop() -> void
{
    auto upperArmDelta = SERVO_MOVEMENT_STEP * upperArmGripOpenStick.getYPosition();
    auto lowerArmDelta = SERVO_MOVEMENT_STEP * lowerArmRotateGripCloseStick.getYPosition();
    auto rotationDelta = SERVO_MOVEMENT_STEP * lowerArmRotateGripCloseStick.getXPosition();

    auto gripOpenSwitchState = upperArmGripOpenStick.getSwitch();
    auto gripCloseSwitchState = lowerArmRotateGripCloseStick.getSwitch();
    auto gripDelta = SERVO_MOVEMENT_STEP * (static_cast<int8_t>(gripOpenSwitchState) - static_cast<int8_t>(gripCloseSwitchState));

    upperArmServo.move(upperArmDelta);
    lowerArmServo.move(lowerArmDelta);
    rotationServo.move(rotationDelta);
    gripServo.move(gripDelta);
}
