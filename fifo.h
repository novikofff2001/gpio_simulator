#pragma once

#include <thread>
#include <atomic>
#include <queue>
#include <mutex>

class FIFO
{
private:
    void th_read();

    std::string fifo_path;
    std::queue<std::string> data;
    int fifo_fd_read, fifo_fd_write;

    std::thread read_thread;
    std::atomic<bool> stop_thread;
    std::mutex m;

public:
    FIFO(const std::string &path);
    ~FIFO();
    void write(const std::string &data);
    void flush();
    std::string read();
};