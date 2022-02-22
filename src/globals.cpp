#include "main.h"

// MOTORS
pros::Motor backRight(9, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor backLeft(18, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor frontRight(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor frontLeft(8, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor leftTop(1, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightTop(2, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor lift(15, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::Motor backLift(5, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);

//pros::Motor intake(1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);

// PNEUMATICS
#define DIGITAL_SENSOR_PORT 'B'
pros::ADIDigitalOut backPiston('B');
#define DIGITAL_SENSOR_PORT 'C'
pros::ADIDigitalOut actuator('C');
#define DIGITAL_SENSOR_PORT 'A'
pros::ADIDigitalOut clampPiston('A');

// SENSORS
pros::Imu inertial(8);

// CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// MISC
int autonState = 0;
