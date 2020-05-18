#include "ServoOutput.h"

#include <Arduino.h>

ServoOutput::ServoOutput(uint8_t pin, const char *name)
    : _pin{pin}, _name{name}
{
}

auto ServoOutput::setup() -> void
{
    _servo.attach(_pin);
}

auto ServoOutput::loop(float delta) -> void
{
    if (delta != 0)
    {
        auto nextPosition = _angle + delta;

        /*Serial.print(_name);
        Serial.print(":\t");
        Serial.print(nextPosition);
        Serial.print('\n');*/

        if (nextPosition <= 0)
        {
            nextPosition = 0;
        }
        else if (nextPosition >= 180)
        {
            nextPosition = 180;
        }

        if (_angle != nextPosition)
        {
            _angle = nextPosition;
            _servo.write(_angle);
        }
    }
}
