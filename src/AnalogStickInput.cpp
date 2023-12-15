#include "AnalogStickInput.h"

#include <Arduino.h>

auto AnalogStickInput::toZeroIfClose(int value, unsigned tolerance) const -> int
{
    if(static_cast<unsigned>(abs(value)) <= tolerance)
    {
        return 0;
    }

    return value;
}

AnalogStickInput::AnalogStickInput(uint8_t xPin, uint8_t yPin, uint8_t switchPin) :
    xPin{xPin}, yPin{yPin}, switchPin{switchPin}
{
}

auto AnalogStickInput::setup() -> void
{
    pinMode(switchPin, INPUT_PULLUP);
    xCenter = analogRead(xPin);
    yCenter = analogRead(yPin);
}

auto AnalogStickInput::getXPosition() const -> float
{
    auto offset = analogRead(xPin) - xCenter;
    offset = toZeroIfClose(offset);
    auto normalizedValue = static_cast<float>(offset) / MAX_VALUE;
    return normalizedValue;
}

auto AnalogStickInput::getYPosition() const -> float
{
    auto offset = analogRead(yPin) - yCenter;
    offset = toZeroIfClose(offset);
    auto normalizedValue = static_cast<float>(offset) / MAX_VALUE;
    return normalizedValue;
}

auto AnalogStickInput::getSwitch() const -> uint8_t
{
    auto switchState = !digitalRead(switchPin);
    return switchState;
}

