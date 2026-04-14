#pragma once

struct Output
{
    float pump;
    float fan;
};

Output computeControl(float temp);