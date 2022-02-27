#include "main.h"

// MOTORS
extern pros::Motor backLeft;
extern pros::Motor backRight;

extern pros::Motor frontLeft;
extern pros::Motor frontRight;

extern pros::Motor rightTop;
extern pros::Motor leftTop;

extern pros::Motor lift;
extern pros::Motor backLift;

extern pros::Motor intake;

// PNEUMATICS
extern pros::ADIDigitalOut clampPiston;
extern pros::ADIDigitalOut backPiston;
extern pros::ADIDigitalOut actuator;

// SENSORS
extern pros::Imu inertial;

// CONTROLLER
extern pros::Controller controller;

// MISC
extern int autonState;
extern bool open;
extern bool intakeRunning;
