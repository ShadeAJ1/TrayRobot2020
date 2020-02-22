/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * Copyright (c) 2017-2020, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convienent for most student programmers.
 */
// #define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
// #define PROS_USE_LITERALS

#include "api.h"
#include "pros/apix.h"

/**
 * You should add more #includes here
 */
//#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

#define BACK_LEFT_MTR_PORT 16
#define FRONT_LEFT_MTR_PORT 11
#define FRONT_RIGHT_MTR_PORT 12
#define BACK_RIGHT_MTR_PORT 17

#define ARM_MTR_PORT 6

#define LEFT_INTAKE_MTR_PORT 9
#define RIGHT_INTAKE_MTR_PORT 20

#define TRAY_MTR_PORT 13

#define TURNING_DIAM 9 // In inches, this is the width between the centers of the wheels, used for turning
#define TURNING_CIRCUM (M_PI * TURNING_DIAM)
#define INCHES_PER_TURN_DEG (TURNING_CIRCUM / 360.0)
#define FEET_PER_TURN_DEG (INCHES_PER_TURN_DEG / 12.0)

#define DIAM_OF_WHEEL 4.125 // In inches
#define ROTATIONS_PER_INCH (1.0 / (M_PI * DIAM_OF_WHEEL))
#define DEGREES_PER_INCH (ROTATIONS_PER_INCH * 360.0)
#define DEGREES_PER_FOOT (DEGREES_PER_INCH * 12.0)

/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
using namespace pros;
// using namespace pros::literals;
// using namespace okapi;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
