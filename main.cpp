#include <iostream>
#include <signal.h>

#include "cvars.h"
#include "fifo.h"
#include "directory_manager.h"

#include "hardware/ColorSensor_TCS34725.h"
#include "hardware/Display_MSP3521.h"
#include "hardware/Driver_ULN2003.h"
#include "hardware/Gyro_L3G4200D.h"
#include "hardware/InfraRed_GP2Y0A02YK0F.h"
#include "hardware/Keypad_PN410_195.h"
#include "hardware/Module_L3G4200D.h"
#include "hardware/RotaryEncoder_PN410_117.h"
#include "hardware/SoundDetector_KY038.h"
#include "hardware/StepMotor_28BYJ_48.h"
#include "hardware/UltraSonic_HC_SR04.h"

std::atomic<bool> is_running(true);

void signal_handler(int signum)
{
    if (signum == SIGINT)
    {
        is_running.store(false);
        std::cout << "\nПрерывание Ctrl+C обработано. Завершение работы..." << std::endl;
    }
}

int main()
{
    signal(SIGINT, signal_handler);
    DirectoryManager hardware(path_hardware);

    ColorSensor_TCS34725 cs0;
    Display_MSP3521 disp0(320, 240);

    Driver_ULN2003 drv0(0, 0, 0, 0);
    StepMotor_28BYJ_48 sm0(drv0);

    Gyro_L3G4200D gyro0;
    InfraRed_GP2Y0A02YK0F infred0(0);
    Keypad_PN410_195 kp0;
    Module_L3G4200D mod0;
    RotaryEncoder_PN410_117 rt0;
    SoundDetector_KY038 sd0(5);

    UltraSonic_HC_SR04 us0(0);
    /////////
    while (is_running)
    {

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    /////////
    return 0;
}