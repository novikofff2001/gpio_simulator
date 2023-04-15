#pragma once

class SoundDetector_KY038 {
public:
    SoundDetector_KY038(double threshold);

    bool detect() const;

private:
    double readAnalogValue() const;

    const double threshold_;
    const double voltage_range_ = 5.0;
};