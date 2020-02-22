#include "drivebase.h"

DriveBase::DriveBase(int front_left_mtr_port, int back_left_mtr_port, int front_right_mtr_port, int back_right_mtr_port)
{
    this->front_left_mtr = std::make_unique<Motor>(front_left_mtr_port);
    this->back_left_mtr = std::make_unique<Motor>(back_left_mtr_port);
    this->front_right_mtr = std::make_unique<Motor>(front_right_mtr_port);
    this->back_right_mtr = std::make_unique<Motor>(back_right_mtr_port);
}

DriveBase::~DriveBase()
{
}

void DriveBase::move(double left, double right)
{
    this->front_left_mtr->move(left);
    this->back_left_mtr->move(left);
    this->front_right_mtr->move(right);
    this->back_right_mtr->move(right);
}

void DriveBase::move_degrees(double degrees, double power)
{
    this->front_left_mtr->move_relative(degrees, power);
    this->back_left_mtr->move_relative(degrees, power);
    this->front_right_mtr->move_relative(degrees, power);
    this->back_right_mtr->move_relative(degrees, power);
    while (this->front_left_mtr->get_position() > this->front_left_mtr->get_target_position() + 5 || this->front_left_mtr->get_position() < this->front_left_mtr->get_target_position() - 5)
    {
    }
    this->front_right_mtr->move(0);
    this->back_right_mtr->move(0);
    this->front_left_mtr->move(0);
    this->back_left_mtr->move(0);
}

void DriveBase::move_feet(double feet, double power)
{
    int degrees = feet * DEGREES_PER_FOOT;
    this->front_left_mtr->move_relative(degrees, power);
    this->back_left_mtr->move_relative(degrees, power);
    this->front_right_mtr->move_relative(degrees, power);
    this->back_right_mtr->move_relative(degrees, power);
    while (this->front_left_mtr->get_position() > this->front_left_mtr->get_target_position() + 5 || this->front_left_mtr->get_position() < this->front_left_mtr->get_target_position() - 5)
    {
    }
    this->front_right_mtr->move(0);
    this->back_right_mtr->move(0);
    this->front_left_mtr->move(0);
    this->back_left_mtr->move(0);
}

void DriveBase::turn(double degrees, double power)
{
    float start = this->front_right_mtr->get_position();
    float feet = degrees * FEET_PER_TURN_DEG;
    float motorDeg = feet * DEGREES_PER_FOOT;
    this->front_right_mtr->move(power);
    this->back_right_mtr->move(power);
    this->front_left_mtr->move(-power);
    this->back_left_mtr->move(-power);
    while ((degrees > 0 && motorDeg + start - this->front_right_mtr->get_position() >= 10) || (degrees <= 0 && motorDeg + start - this->front_right_mtr->get_position() <= -10))
    {
    }
    this->front_right_mtr->move(0);
    this->back_right_mtr->move(0);
    this->front_left_mtr->move(0);
    this->back_left_mtr->move(0);
}