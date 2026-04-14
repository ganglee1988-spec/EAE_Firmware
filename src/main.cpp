#include <iostream>
#include "state_machine.h"
#include "controller.h"
#include "can_sim.h"

int main()
{
    float temp = 55.0f;
    bool ignition = true;
    bool levelOK = true;

    for (int i = 0; i < 12; i++)
    {
        temp += 6.0f;

        SystemState state = updateState(temp, ignition, levelOK);

        switch (state)
        {
        case SystemState::OFF:
            std::cout << "System OFF\n";
            break;

        case SystemState::FAULT:
            std::cout << "Temp: " << temp <<  " FAULT → Full cooling\n";
            sendCAN("FAULT");
            break;

        case SystemState::OVERHEAT:
            std::cout << "Temp: " << temp << " OVERHEAT → Max cooling\n";
            sendCAN("OVERHEAT");
            break;

        case SystemState::NORMAL:
        {
            Output out = computeControl(temp);
            std::cout << "Temp: " << temp
                      << " Pump: " << out.pump
                      << " Fan: " << out.fan << "\n";

            sendCAN("NORMAL");
            break;
        }
        }

        receiveCAN();
    }

    return 0;
}