#include "Gyro_L3G4200D.h"

#include <ctime>

Gyro_L3G4200D::Gyro_L3G4200D()
    : x(0), y(0), z(0), temperature(30.0), is_running(false)
{
    srand(time(NULL));
}

Gyro_L3G4200D::~Gyro_L3G4200D()
{
    stop();
}

void Gyro_L3G4200D::start()
{
    is_running = true;
    simulation_thread = std::thread(&Gyro_L3G4200D::simulate, this);
}

void Gyro_L3G4200D::stop()
{
    is_running = false;
    if (simulation_thread.joinable())
    {
        simulation_thread.join();
    }
}

int16_t Gyro_L3G4200D::getX()
{
    std::unique_lock<std::mutex> lock(data_mutex);
    return x;
}

int16_t Gyro_L3G4200D::getY()
{
    std::unique_lock<std::mutex> lock(data_mutex);
    return y;
}

int16_t Gyro_L3G4200D::getZ()
{
    std::unique_lock<std::mutex> lock(data_mutex);
    return z;
}

double Gyro_L3G4200D::getTemperature()
{
    std::unique_lock<std::mutex> lock(data_mutex);
    return temperature;
}

void Gyro_L3G4200D::setRotation(int16_t newX, int16_t newY, int16_t newZ)
{
    std::lock_guard<std::mutex> lock(data_mutex);
    stop();
    x = newX;
    y = newY;
    z = newZ;
}

void Gyro_L3G4200D::setTemperature(double newTemp) {
    std::lock_guard<std::mutex> lock(data_mutex);
    stop();
    temperature = newTemp;
}


void Gyro_L3G4200D::simulate()
{
    auto gen = [](double val, double step)
    {
        val = val + (rand() % 3 - 1) * (step); // [-STEP, STEP]
        return val;
    };
    while (is_running)
    {
        std::unique_lock<std::mutex> lock(data_mutex);
        x = gen(x, AXIS_STEP);
        y = gen(y, AXIS_STEP);
        z = gen(z, AXIS_STEP);
        temperature = gen(temperature, TEMP_STEP);
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}