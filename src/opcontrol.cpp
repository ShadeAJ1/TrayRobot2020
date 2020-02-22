#include "main.h"
#include "drivebase.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol()
{
    Controller master(E_CONTROLLER_MASTER);

    DriveBase base(FRONT_LEFT_MTR_PORT, BACK_LEFT_MTR_PORT, FRONT_RIGHT_MTR_PORT, BACK_RIGHT_MTR_PORT);

    Motor arm_mtr(ARM_MTR_PORT);
    Motor tray_mtr(TRAY_MTR_PORT);

    Motor left_intake_mtr(LEFT_INTAKE_MTR_PORT);
    Motor right_intake_mtr(RIGHT_INTAKE_MTR_PORT);

    while (true)
    {
        // Tank Drive
        double left = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        double right = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);
        base.move(left, right);

        // Intake
        if (master.get_digital(E_CONTROLLER_DIGITAL_R1))
        {
            // Outtake
            left_intake_mtr = 127;
            right_intake_mtr = 127;
        }
        else if (master.get_digital(E_CONTROLLER_DIGITAL_R2))
        {
            // Intake
            left_intake_mtr = -127;
            right_intake_mtr = -127;
        }
        else
        {
            // Stop
            left_intake_mtr = 0;
            right_intake_mtr = 0;
        }

        // Arm
        if (master.get_digital(E_CONTROLLER_DIGITAL_L1))
        {
            // Up
            arm_mtr = 127;
        }
        else if (master.get_digital(E_CONTROLLER_DIGITAL_L2))
        {
            // Down
            arm_mtr = -127;
        }
        else
        {
            // Hold
            arm_mtr = 0;
        }

        // Tray
        if (master.get_digital(E_CONTROLLER_DIGITAL_X))
        {
            // Up
            tray_mtr = 127;
        }
        else if (master.get_digital(E_CONTROLLER_DIGITAL_B))
        {
            // Down
            tray_mtr = -127;
        }
        else
        {
            // Hold
            tray_mtr = 0;
        }
    }
}
