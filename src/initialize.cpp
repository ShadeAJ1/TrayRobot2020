#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
    // Drive base is 200 rpm
    // Reverse diagonal
    Motor front_right_mtr(FRONT_RIGHT_MTR_PORT, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
    Motor back_left_mtr(BACK_LEFT_MTR_PORT, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
    Motor front_left_mtr(FRONT_LEFT_MTR_PORT, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
    Motor back_right_mtr(BACK_RIGHT_MTR_PORT, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
    Motor arm_mtr(ARM_MTR_PORT, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
    Motor tray_mtr(TRAY_MTR_PORT, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
    Motor left_intake_mtr(LEFT_INTAKE_MTR_PORT, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
    Motor right_intake_mtr(RIGHT_INTAKE_MTR_PORT, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}