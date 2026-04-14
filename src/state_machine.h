#pragma once

enum class SystemState
{
    OFF,
    NORMAL,
    OVERHEAT,
    FAULT
};

SystemState updateState(float temp, bool ignition, bool levelOK);