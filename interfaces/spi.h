#pragma once

#include "../fifo.h"
#include "../directory_manager.h"

#include <thread>
#include <atomic>
#include <mutex>

class SPI {
private:
    DirectoryManager dm;

    FIFO fifo_; 
    std::string data_;

    std::mutex m;
    std::thread read_thread;
    std::atomic<bool> stop_thread;

    void th_read();

public:
    SPI();
    ~SPI();
    
    std::string read();
};