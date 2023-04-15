#include "spi.h"
#include "../cvars.h"

#include <iostream>

static unsigned int spi_num = 0;

SPI::SPI() :
            dm(path_spi),
            fifo_(path_spi / ("spi" + std::to_string(spi_num))),
            stop_thread(false)
{
    read_thread = std::thread(&SPI::th_read, this);
    std::cout << "SPI" << spi_num++ << "Started" << std::endl;
};

SPI::~SPI()
{
    stop_thread.store(true);
    if (read_thread.joinable())
    {
        read_thread.join();
    }
    std::cout << "SPI stopped" << std::endl;
}

void SPI::th_read()
{
    for (; !stop_thread.load(); std::lock_guard(m))
    {
        data_ = fifo_.read();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

std::string SPI::read()
{
    std::cout << "SPI data transfer: " << data_ << std::endl;
    return data_;
}