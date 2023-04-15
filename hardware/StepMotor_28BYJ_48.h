#pragma once

#include "Driver_ULN2003.h"

class StepMotor_28BYJ_48 {
private:
    int in1, in2, in3, in4;
    
public:
    StepMotor_28BYJ_48(Driver_ULN2003& driver);

    void step(int steps);
};