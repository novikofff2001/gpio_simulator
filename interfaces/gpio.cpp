#include <string>
#include <fstream>

#include "gpio.h"
#include "../cvars.h"

GPIO::GPIO(uint8_t port, Direction direction) : 
                dm(path_gpio / ("gpio" + std::to_string(port))),
                stop_thread(false)
{
    port_ = port;
    set_value(GPIO::LOW);
    set_direction(direction);
    
    read_thread = std::thread(&GPIO::th_read, this);
};

GPIO::~GPIO() {
    stop_thread.store(true);
    if(read_thread.joinable()) {
        read_thread.join();
    }
}

void GPIO::set_value(Value val) {
    val_ = val;
    std::ofstream fout(dm.get_path() / "value");
    fout << (val_ == Value::LOW? 0 : 1);
    fout.close();
}

void GPIO::set_direction(Direction direction) { 
    direction_ = direction;
    std::ofstream fout(dm.get_path() / "direction");
    fout << (direction_ == Direction::INPUT? "in" : "out");
    fout.close();
}

void GPIO::th_read() {
    std::ifstream Fin;
    std::string data;

    for(; !stop_thread.load() ; std::lock_guard(m)) {
        Fin.open(dm.get_path() / "value");
        Fin >> data;
        if (data.empty()) {
            continue;
        }
        switch(std::stoi(data)) {
            case Value::HIGH:
                val_ = Value::HIGH;
                break;
            case Value::LOW:
                val_ = Value::LOW;
                break;
        }
        Fin.close();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}