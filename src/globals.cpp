#include "main.h"

// Left --> -20, -21, 18
// Right --> 4, 7, -5

// MOTORS
pros::Motor backRight(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); // *
pros::Motor backLeft(2, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // *

pros::Motor frontRight(17, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); // *
pros::Motor frontLeft(20, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);  // *

pros::Motor leftTop(16, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); // *
pros::Motor rightTop(19, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // * 

pros::Motor lift(18, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS); // *

pros::Motor backLift(5, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::Motor intake(4, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_ROTATIONS); // *

// PNEUMATICS
#define DIGITAL_SENSOR_PORT 'G'
pros::ADIDigitalOut backPiston('G');
#define DIGITAL_SENSOR_PORT 'A'
pros::ADIDigitalOut actuator('A');
#define DIGITAL_SENSOR_PORT 'D'
pros::ADIDigitalOut clampPiston('D');

    
// SENSORS
pros::Imu inertial(11);

// CONTROLLERs
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// MISC
int autonState = 0;
