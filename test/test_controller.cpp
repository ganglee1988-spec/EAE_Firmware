#include "gtest/gtest.h"
#include "controller.h"

// =======================
// Test: Normal condition
// =======================
TEST(ControllerTest, NormalTemperature)
{
    float temp = 60.0f; // equal to setpoint
    Output out = computeControl(temp);

    // Expect minimal control action
    EXPECT_NEAR(out.fan, 0.0f, 0.1f);
    EXPECT_NEAR(out.pump, 40.0f, 0.1f); // baseline
}

// =======================
// Test: High temperature
// =======================
TEST(ControllerTest, HighTemperature)
{
    float temp = 80.0f; // above setpoint
    Output out = computeControl(temp);

    EXPECT_GT(out.fan, 0.0f);
    EXPECT_GT(out.pump, 40.0f);
}

// =======================
// Test: Very high temperature (clamping)
// =======================
TEST(ControllerTest, MaxClamp)
{
    float temp = 200.0f; // unrealistic high
    Output out = computeControl(temp);

    EXPECT_LE(out.fan, 100.0f);
    EXPECT_LE(out.pump, 100.0f);
}

// =======================
// Test: Low temperature
// =======================
TEST(ControllerTest, LowTemperature)
{
    float temp = 40.0f; // below setpoint
    Output out = computeControl(temp);

    // No cooling needed
    EXPECT_NEAR(out.fan, 0.0f, 0.1f);
    EXPECT_NEAR(out.pump, 40.0f, 0.1f);
}