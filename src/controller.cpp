#include "controller.h"

const float TEMP_SETPOINT = 60.0f;
const float KP = 2.0f;

Output computeControl(float temp)
{
    float error = temp - TEMP_SETPOINT;

    float control = KP * error;

    if (control < 0) control = 0;
    if (control > 100) control = 100;

    Output out;

    // Pump baseline
    out.pump = 40 + control * 0.6f;
    if (out.pump > 100) out.pump = 100;

    // Fan aggressive
    out.fan = control;

    return out;
}