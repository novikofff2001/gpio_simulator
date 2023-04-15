#include <iostream>
#include <random>

class Module_L3G4200D {
public:
    Module_L3G4200D();

    bool begin();

    bool readAcceleration(int& ax, int& ay, int& az);

    bool readGyroscope(int& gx, int& gy, int& gz);

    bool readMagnetometer(int& mx, int& my, int& mz);

private:
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist;
};