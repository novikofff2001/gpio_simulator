#include <thread>
#include <atomic>
#include <mutex>

#include "../directory_manager.h"

class GPIO
{
public:
    enum Direction
    {
        INPUT = 0,
        OUTPUT
    };

    enum Value
    {
        LOW = 0,
        HIGH
    };

    GPIO(uint8_t port, Direction direction);
    ~GPIO();
    void set_direction(Direction direction);
    void set_value(Value val);
private:
    void th_read();

    DirectoryManager dm;

    std::mutex m;
    std::atomic<bool> stop_thread;
    std::thread read_thread;

    uint8_t port_;
    Value val_;
    Direction direction_;
};
