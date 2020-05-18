#include "RobotArm.h"

#include "AnalogStickInput.h"
#include "ServoOutput.h"

#include <Arduino.h>

auto RobotArm::setup() -> void
{
    Serial.begin(9600);
    Serial.print("Started\n");
    _xyStick.setup();
    _gripStick.setup();
    _xServo.setup();
    //yServo.setup();
    _gripServo.setup();
}

auto RobotArm::loop() -> void
{
    _xyStick.loop();
    //gripStick.loop();

    // TODO: Improve this.
    auto xDelta = .1 * _xyStick.getXPosition();
    _xServo.loop(xDelta);

    //yServo.loop(xyStick.getDeltaY());
    
    auto gripDelta = .1 * _gripStick.getXPosition();
    _gripServo.loop(gripDelta);
}
