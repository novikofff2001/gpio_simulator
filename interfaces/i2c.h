#pragma once
#include <stdint.h>
#include <vector>

class I2C {
    std::vector<uint8_t> registers_;
public:
    I2C();
    I2C(ssize_t size);
    int read(uint8_t address);
    void write(uint8_t address, uint8_t data);

    uint8_t& operator[](uint8_t address);
    ssize_t size();
    std::vector<uint8_t>::iterator begin();
    std::vector<uint8_t>::iterator end();
};
