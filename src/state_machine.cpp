#include "state_machine.h"

const float TEMP_MAX = 80.0f;
const float TEMP_MIN = -20.0f;
const float TEMP_MAX_VALID = 120.0f;

bool sensorFault(float temp)
{
    return (temp < TEMP_MIN || temp > TEMP_MAX_VALID);
}

SystemState updateState(float temp, bool ignition, bool levelOK)
{
    if (!ignition)
        return SystemState::OFF;

    if (!levelOK)
        return SystemState::FAULT;

    if (sensorFault(temp))
        return SystemState::FAULT;

    if (temp > TEMP_MAX)
        return SystemState::OVERHEAT;

    return SystemState::NORMAL;
}