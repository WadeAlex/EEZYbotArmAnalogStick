#pragma once

#include <stdint.h>

class AnalogStickInput
{
private:
    static const uint16_t MAX_VALUE = 511;
    static const uint8_t ZERO_TOLERANCE = 3;

    const uint8_t _xPin = {};
    const uint8_t _yPin = {};

    uint16_t _xOffset = 0;
    uint16_t _yOffset = 0;
public:
    AnalogStickInput(uint8_t xPin, uint8_t yPin);
    auto setup() -> void;
    auto loop() -> void;
    auto getXPosition() const -> float;
    auto getYPosition() const -> float;
};
