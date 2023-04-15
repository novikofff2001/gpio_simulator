#include <thread>
#include <unordered_map>

#include "../directory_manager.h"
#include "../fifo.h"
#include "gpio.h"

class GPIOManager {
public:
    GPIOManager();
    GPIO& get_instance();
    ~GPIOManager();
    
private:
    void start();

    std::thread read_thread;
    std::atomic<bool> stop_thread_;
    DirectoryManager dm_;
    FIFO export_;
    FIFO unexport_;
    std::unordered_map<int, std::unique_ptr<GPIO>> gpios;
};
