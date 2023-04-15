#include <stdlib.h>

#include "i2c.h"

I2C::I2C() : registers_(0xFF, 0x00) {};
I2C::I2C(ssize_t size) : registers_(size, 0x00) {};

int I2C::read(uint8_t address)
{
    if (address < registers_.size()) {
        return registers_[address];
    }
    return -1;
}

void I2C::write(uint8_t address, uint8_t data)
{
    if (address < registers_.size()) {
        registers_[address] = data;
    }
}

ssize_t I2C::size() {
    return registers_.size();
};

uint8_t& I2C::operator[](uint8_t address) {
    return registers_[address];
}

std::vector<uint8_t>::iterator I2C::begin() {
    return registers_.begin();
};
std::vector<uint8_t>::iterator I2C::end() {
    return registers_.end();
}