#include "ServoController.h"

#include <Arduino.h>

auto ServoController::clampAngle(float angle) -> float
{
    if (angle < _minimumAngle)
    {
        angle = _minimumAngle;
    }
    else if (angle > _maximumAngle)
    {
        angle = _maximumAngle;
    }

    return angle;
}

auto ServoController::floatsEqual(float first, float second, float tolerance) -> bool
{
    return fabs(second - first) <= tolerance;
}

ServoController::ServoController(uint8_t pin, float minimumAngle, float maximumAngle)
    : _pin{pin}, _minimumAngle{minimumAngle}, _maximumAngle{maximumAngle}
{
}

auto ServoController::setup() -> void
{
    _servo.attach(_pin);
}

auto ServoController::move(float stickDelta) -> void
{
    if (!floatsEqual(stickDelta, 0))
    {
        auto nextPosition = _angle + stickDelta;

        nextPosition = clampAngle(nextPosition);

        if (!floatsEqual(_angle, nextPosition))
        {
            _angle = nextPosition;
            _servo.write(_angle);
            //Serial.print(_angle);
            //Serial.print('\n');
        }
    }
}
