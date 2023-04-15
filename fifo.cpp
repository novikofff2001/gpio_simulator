#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <atomic>

#include "fifo.h"

FIFO::FIFO(const std::string &path) : fifo_path(path), stop_thread(false)
{
    if (mkfifo(fifo_path.c_str(), 0666) == -1) {
        std::cerr << "Не удалось создать именованный канал." << std::endl;
    }

    fifo_fd_read = open(fifo_path.c_str(), O_RDONLY | O_NONBLOCK);
    if (fifo_fd_read == -1) {
        std::cerr << "Не удалось открыть именованный канал для чтения." << std::endl;
    }

    fifo_fd_write = open(fifo_path.c_str(), O_WRONLY | O_NONBLOCK);
    if (fifo_fd_write == -1) {
        std::cerr << "Не удалось открыть именованный канал для записи." << std::endl;
    }

    read_thread = std::thread(&FIFO::th_read, this);
}

FIFO::~FIFO()
{
    stop_thread.store(true);
    if (read_thread.joinable()) {
        read_thread.join();
    }
    close(fifo_fd_read);
    close(fifo_fd_write);
    unlink(fifo_path.c_str());
}

void FIFO::write(const std::string &data)
{
    ssize_t bytes_written = ::write(fifo_fd_write, data.c_str(), data.size());
    if (bytes_written == -1) {
        std::cerr << "Не удалось записать данные в именованный канал." << std::endl;
    }
}

void FIFO::th_read()
{
    for(; !stop_thread.load(); std::lock_guard(m)) {
        char buffer[1024];
        ssize_t bytes_read = ::read(fifo_fd_read, buffer, sizeof(buffer) - 1);
        if (bytes_read <= 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        buffer[bytes_read] = '\0';
        std::cout << "Считанные данные: " << buffer << std::endl;
        data.push(std::string(buffer));
    }
}

std::string FIFO::read() {
    std::lock_guard lg(m);
    std::string ret = "";
    if(!data.empty()) {
        ret = data.front();
        data.pop();
    }
    return ret;
}

void FIFO::flush() {
    std::lock_guard lg(m);
    data = std::queue<std::string>();
}