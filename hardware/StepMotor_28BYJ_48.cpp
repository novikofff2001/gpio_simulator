#include "StepMotor_28BYJ_48.h"

#include <thread>
#include <cmath>

StepMotor_28BYJ_48::StepMotor_28BYJ_48(Driver_ULN2003& driver) {
    auto [in1, in2, in3, in4] = driver.getPins();
}

void StepMotor_28BYJ_48::step(int steps)
{
    for (int i = 0; i < std::abs(steps); ++i)
    {
        int step = (i % 8) + 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}