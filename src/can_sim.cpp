#include "can_sim.h"
#include <iostream>

void sendCAN(const std::string& msg)
{
    std::cout << "[CAN TX] " << msg << std::endl;
}

void receiveCAN()
{
    std::cout << "[CAN RX] Command received (simulated)" << std::endl;
}