#include <OpenExposer/LaserDriver.h>
#include "gtest/gtest.h"
#include "TestLaserDriver.h"

TEST(laser_driver_test, simple_test)
{
    EXPECT_EQ(1, 1);
}

TEST(laser_driver_test, convert_position_to_timing_test_empty)
{
    laser_buffer.laser_timings[0] = 100;
    laser_buffer.length = 0;
    convert_positions_to_timings();
    EXPECT_EQ(laser_buffer.laser_timings[0], 0);
}

TEST(laser_driver_test, convert_position_to_timing_test_non_empty)
{
    laser_timing_scale_dividend = 3;
    laser_timing_scale_divisor = 2;
    laser_timing_center_offset = 10000;

    laser_buffer.positions[0] = -200;
    laser_buffer.positions[1] = 200;
    laser_buffer.positions[2] = 200;
    laser_buffer.length = 3;
    convert_positions_to_timings();
    EXPECT_EQ(laser_buffer.laser_timings[0], 9700);
    EXPECT_EQ(laser_buffer.laser_timings[1], 10000);
    EXPECT_EQ(laser_buffer.laser_timings[2], 10300);
}