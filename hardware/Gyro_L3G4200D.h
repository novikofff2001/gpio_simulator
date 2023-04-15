#pragma once
#include <cstdlib>
#include <thread>
#include <atomic>
#include <mutex>

#define AXIS_STEP 5
#define TEMP_STEP 0.5

class Gyro_L3G4200D
{
public:
    Gyro_L3G4200D();
    ~Gyro_L3G4200D();

    void start();
    void stop();
    int16_t getX();
    int16_t getY();
    int16_t getZ();
    double getTemperature();
    void setRotation(int16_t newX, int16_t newY, int16_t newZ);
    void setTemperature(double temp);
private:
    void simulate();

    int16_t x, y, z;
    double temperature;
    
    std::atomic<bool> is_running;
    std::thread simulation_thread;
    std::mutex data_mutex;

};