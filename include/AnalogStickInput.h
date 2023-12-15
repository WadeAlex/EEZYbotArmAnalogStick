#pragma once

#include <stdint.h>

class AnalogStickInput
{
public:
    AnalogStickInput(uint8_t xPin, uint8_t yPin, uint8_t switchPin);
    auto setup() -> void;
    auto getXPosition() const -> float;
    auto getYPosition() const -> float;
    auto getSwitch() const -> uint8_t;

private:
    static const int MAX_VALUE = 511;
    static const uint8_t ZERO_TOLERANCE = 3;

    const uint8_t xPin = {};
    const uint8_t yPin = {};
    const uint8_t switchPin = {};

    int xCenter = 0;
    int yCenter = 0;

    auto toZeroIfClose(int value, unsigned tolerance = ZERO_TOLERANCE) const -> int;
};
