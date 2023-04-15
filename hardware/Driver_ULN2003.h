#pragma once

#include <tuple>

typedef std::tuple<double, double, double, double> DriverPinsTuple;

class Driver_ULN2003 {
public:
    Driver_ULN2003(double in1, double in2, double in3, double in4);

    DriverPinsTuple getPins();
    
    void setStep(int step);

private:
    double pin1, pin2, pin3, pin4;
    int step_;
};