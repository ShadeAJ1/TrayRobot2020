#include "main.h"
#include "drivebase.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

DriveBase base(FRONT_LEFT_MTR_PORT, FRONT_RIGHT_MTR_PORT, BACK_LEFT_MTR_PORT, BACK_RIGHT_MTR_PORT);
Motor tray_mtr(TRAY_MTR_PORT);
Motor arm_mtr(ARM_MTR_PORT);
Motor left_intake_mtr(LEFT_INTAKE_MTR_PORT);
Motor right_intake_mtr(RIGHT_INTAKE_MTR_PORT);

base.move_feet(0.5,127);
arm_mtr = 127;
delay(500);
arm_mtr = -127;

left_intake_mtr = 127;
right_intake_mtr = 127;
base.move_feet(3, 127);
delay(700);
base.move_feet(-2.5, 127);

base.turn(90, 100);
base.move_feet(1, 127);


}