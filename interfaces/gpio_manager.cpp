#include <iostream>
#include <string>

#include "gpio_manager.h"

#include "../cvars.h"

GPIOManager::GPIOManager() :    stop_thread_(false),
                                dm_(path_gpio),
                                export_(path_gpio / "export"),
                                unexport_(path_gpio / "unexport")
{
    read_thread = std::thread(&GPIOManager::start, this);
};

GPIOManager::~GPIOManager() {
    stop_thread_.store(true);
    if(read_thread.joinable()) {
        read_thread.join();
    }
    std::cout << "GPIO Manager stopped" << std::endl;
}

void GPIOManager::start()
{
    std::cout << "GPIO Manager started" << std::endl;

    while (!stop_thread_.load())
    {
        int port_num =  -1;
        bool is_exporting;

        auto get_port_num = [&port_num](FIFO& f) { 
            std::string data = f.read();
            port_num = data.empty()? -1 : std::stoi(data);
            return port_num;
        };

        if (get_port_num(export_) != -1) {
            is_exporting = true;
        } else if (get_port_num(unexport_) != -1) {
            is_exporting = false;
        } else {
            continue;
        }
        if (is_exporting) {
            std::cout << "Exporting port " << port_num << std::endl;
            gpios[port_num] = std::make_unique<GPIO>(port_num, GPIO::Direction::INPUT);
        } else {
            std::cout << "Unexporting port " << port_num << std::endl;
            gpios[port_num].reset();
            gpios.erase(port_num);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}