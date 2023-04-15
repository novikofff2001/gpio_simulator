#include "Module_L3G4200D.h"

Module_L3G4200D::Module_L3G4200D()
{
    rng.seed(std::random_device()());
    dist = std::uniform_int_distribution<int>(-32768, 32767);
}

bool Module_L3G4200D::begin()
{
    // Здесь можно добавить инициализацию модуля, если это необходимо
    return true;
}

bool Module_L3G4200D::readAcceleration(int &ax, int &ay, int &az)
{
    // Симуляция чтения значений ускорения
    ax = dist(rng);
    ay = dist(rng);
    az = dist(rng);
    return true;
}

bool Module_L3G4200D::readGyroscope(int &gx, int &gy, int &gz)
{
    // Симуляция чтения значений гироскопа
    gx = dist(rng);
    gy = dist(rng);
    gz = dist(rng);
    return true;
}

bool Module_L3G4200D::readMagnetometer(int &mx, int &my, int &mz)
{
    // Симуляция чтения значений магнетометра
    mx = dist(rng);
    my = dist(rng);
    mz = dist(rng);
    return true;
}