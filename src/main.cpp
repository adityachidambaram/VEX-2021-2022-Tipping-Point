#include "main.h"

void on_center_button() {
	/**
	 * A callback function for LLEMU's center button.
	 *
	 * When this callback is fired, it will toggle line 2 of the LCD text between
	 * "I was pressed!" and nothing.
	 */
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}


void initialize() {
	/**
	 * Runs initialization code. This occurs as soon as the program is started.
	 *
	 * All other competition modes are blocked by initialize; it is recommended
	 * to keep execution time for this mode under a few seconds.
	 */

	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hi monkey ");
	pros::lcd::register_btn1_cb(on_center_button);


	backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	backRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	backLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	backLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	clampPiston.set_value(true);
	actuator.set_value(false);
    backPiston.set_value(false);

	inertial.reset();
}


void disabled() {
	backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	backRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);


	backLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

//pros::ADIButton switch2('H');
void competition_initialize() {
	/**
	 * Runs after initialize(), and before autonomous when connected to the Field
	 * Management System or the VEX Competition Switch. This is intended for
	 * competition-specific initialization routines, such as an autonomous selector
	 * on the LCD.
	 *
	 * This task will exit when the robot is enabled and autonomous or opcontrol
	 * starts.
	 */
	pros::lcd::initialize();
	pros::lcd::set_text(1, "750C :)");
	pros::lcd::register_btn1_cb(on_center_button);
	pros::lcd::clear_line(1);


	pros::lcd::set_text(1, "No auton currently selected.");

	//if(switch2.isPressed()) {

	//}
 }


void autonomous() {
	//progSkill();
	//auton20();
	//auton40();
	angle20();
	//rightMiddle();

} 


void opcontrol() {
	backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	backRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	leftTop.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	rightTop.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);


	backLift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	while(true) {
		setDriveMotors();
		moveLift();
		moveClamp();
		moveBackLift();
		intakeMove();
		//test();
		pros::delay(10);
	}
}
