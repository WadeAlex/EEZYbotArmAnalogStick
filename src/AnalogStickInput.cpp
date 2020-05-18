#include "AnalogStickInput.h"

#include <Arduino.h>

AnalogStickInput::AnalogStickInput(uint8_t xPin, uint8_t yPin) : _xPin(xPin), _yPin(yPin)
{
}

void AnalogStickInput::setup()
{
    _xOffset = analogRead(_xPin);
    _yOffset = analogRead(_yPin);
}

void AnalogStickInput::loop()
{
}

auto AnalogStickInput::getXPosition() const -> float
{
    auto zeroCenterValue = analogRead(_xPin) - static_cast<float>(_xOffset);
    if(zeroCenterValue >= -ZERO_TOLERANCE && zeroCenterValue <= ZERO_TOLERANCE) {
        zeroCenterValue = 0;
    }
    auto normalizedValue = zeroCenterValue / MAX_VALUE;
    return normalizedValue;
}

auto AnalogStickInput::getYPosition() const -> float
{
    return static_cast<float>(analogRead(_yPin) - _yOffset) / MAX_VALUE;
}

