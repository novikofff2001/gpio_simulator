#include "ColorSensor_TCS34725.h"

#include <iostream>
#include <random>

ColorSensor_TCS34725::ColorSensor_TCS34725() : red(0), green(0), blue(0), temp(30.0), luminosity(0.0)
{
    
}

bool ColorSensor_TCS34725::begin()
{
    // Здесь можно добавить инициализацию датчика, если это необходимо
    return true;
}

void ColorSensor_TCS34725::setRGB(uint8_t r, uint8_t g, uint8_t b)
{
    red = r;
    green = g;
    blue = b;
}

void ColorSensor_TCS34725::setLuminosity(double lumin) {
    luminosity = lumin;
}