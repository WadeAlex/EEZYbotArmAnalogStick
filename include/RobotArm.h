#pragma once

#include "AnalogStickInput.h"
#include "ServoOutput.h"

class RobotArm
{
private:
    AnalogStickInput _xyStick = AnalogStickInput{0, 2};
    AnalogStickInput _gripStick = AnalogStickInput{4, 5};
    ServoOutput _xServo = ServoOutput{9, "x"};
    ServoOutput _yServo = ServoOutput{10, "y"};
    ServoOutput _gripServo = ServoOutput{11, "grip"};

public:
    auto setup() -> void;
    auto loop() -> void;
};