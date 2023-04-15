#include "Driver_ULN2003.h"

#include <iostream>
#include <chrono>

Driver_ULN2003::Driver_ULN2003(double in1, double in2, double in3, double in4)
    : pin1(in1), pin2(in2), pin3(in3), pin4(in4), step_(0) {}

void Driver_ULN2003::setStep(int step)
{
    step_ = step;
}

DriverPinsTuple Driver_ULN2003::getPins() {
    return DriverPinsTuple(pin1, pin2, pin3, pin4);
}