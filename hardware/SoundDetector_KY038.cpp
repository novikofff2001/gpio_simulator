#include "SoundDetector_KY038.h"

#include <cstdlib>
#include <ctime>

SoundDetector_KY038::SoundDetector_KY038(double threshold) : threshold_(threshold)
{
    std::srand(std::time(NULL));
}

bool SoundDetector_KY038::detect() const
{
    double analog_value = readAnalogValue();
    return analog_value > threshold_;
}

double SoundDetector_KY038::readAnalogValue() const
{
    double analog_voltage = std::rand() / static_cast<double>(RAND_MAX) * voltage_range_;
    return analog_voltage;
}
