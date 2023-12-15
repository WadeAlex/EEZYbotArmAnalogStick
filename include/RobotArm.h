#pragma once

#include "AnalogStickInput.h"
#include "ServoController.h"

class RobotArm
{
public:
    auto setup() -> void;
    auto loop() -> void;

private:
    const float SERVO_MOVEMENT_STEP = 0.1;

    AnalogStickInput upperArmGripOpenStick = AnalogStickInput{A0, A1, 2};
    AnalogStickInput lowerArmRotateGripCloseStick = AnalogStickInput{A2, A3, 4};
    
    ServoController rotationServo = ServoController{6};
    ServoController lowerArmServo = ServoController{9};
    ServoController upperArmServo = ServoController{10};
    ServoController gripServo = ServoController{11};
};

