#include "main.h"

// MOTORS
pros::Motor backRight(7, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); // *
pros::Motor backLeft(21, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // *

pros::Motor frontRight(4, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); // *
pros::Motor frontLeft(20, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);  // *

pros::Motor leftTop(18, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); // *
pros::Motor rightTop(5, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // * 

pros::Motor lift(3, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS); // *

pros::Motor backLift(5, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::Motor intake(6, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS); // *

// PNEUMATICS
#define DIGITAL_SENSOR_PORT 'D'
pros::ADIDigitalOut backPiston('D');
#define DIGITAL_SENSOR_PORT 'E'
pros::ADIDigitalOut actuator('E');
#define DIGITAL_SENSOR_PORT 'A'
pros::ADIDigitalOut clampPiston('A');

#define DIGITAL_SENSOR_PORT 'H'
pros::ADIButton autonSelector ('H');

// SENSORS
pros::Imu inertial(8);

// CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// MISC
int autonState = 0;
