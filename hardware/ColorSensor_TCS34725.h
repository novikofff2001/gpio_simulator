#pragma once

#include <stdint.h>

class ColorSensor_TCS34725 {
public:
    ColorSensor_TCS34725();

    bool begin();

    void setRGB(uint8_t r, uint8_t g, uint8_t b);
    void setLuminosity(double lumin);

private:
    uint8_t red, green, blue;
    double temp, luminosity;
};