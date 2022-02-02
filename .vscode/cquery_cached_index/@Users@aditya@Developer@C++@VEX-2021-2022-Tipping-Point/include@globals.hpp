#include "main.h"

// GLOBALS

//drive motors
extern pros::Motor backLeft;
extern pros::Motor backRight;
extern pros::Motor frontLeft;
extern pros::Motor frontRight;

//lift motor
extern pros::Motor lift;

//back wings motors
extern pros::Motor backHook;

// clamp piston
extern pros::ADIDigitalOut clampPiston;

//auton switcher


// Main Controller
extern pros::Controller controller;



extern int autonState;
extern bool open;
