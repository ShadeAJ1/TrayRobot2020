#pragma once

#include "main.h"
#include <memory>

class DriveBase
{
private:
    std::unique_ptr<Motor> front_left_mtr;
    std::unique_ptr<Motor> back_left_mtr;
    std::unique_ptr<Motor> front_right_mtr;
    std::unique_ptr<Motor> back_right_mtr;

public:
    DriveBase(int front_left_mtr_port, int back_left_mtr_port, int front_right_mtr_port, int back_right_mtr_port);
    ~DriveBase();
    void move(double left, double right);
    void move_degrees(double degrees, double power);
    void move_feet(double feet, double power);
    void turn(double degrees, double power);
};
