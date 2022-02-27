#include "main.h"

// STATE VARIABLES 
bool running = true;


// CONSTANTS
const double powerMultiplier = 2.00;
const double rightMultiplier = 1.00;
const double leftMultiplier = 1.00;

// MOTOR POWER
void setDrive(int left, int right) {

  // MAIN MOTORS
  backLeft = left;
  backRight = right;

  frontLeft = left;
  frontRight = right;

  // ADDITIONAL MOTORS
  rightTop = right;
  leftTop = left;
}

// RESET ENCODERS
void resetMotorEncoders() {
  backLeft.tare_position();
  backRight.tare_position();
  frontRight.tare_position();
  frontLeft.tare_position();
}

// GET ENCODER VALUES
double getRightEncoder() {
  return (fabs(backRight.get_position()) + fabs(frontRight.get_position())) / 2;
}

double getLeftEncoder() {
  return (fabs(frontLeft.get_position()) + fabs(backLeft.get_position())) / 2;
}

double getAvgEncoder() {
  return (fabs(backRight.get_position()) + fabs(backLeft.get_position()) +
         fabs(frontRight.get_position()) + fabs(frontLeft.get_position())) / 4;
}

// CONTROLLER INPUT 
void setDriveMotors() {

  // INPUT VALUES
  double power = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  double direction = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);


  power *= powerMultiplier;

  // MOTOR POWER EQUATION
  int left = power + (direction * leftMultiplier);
  int right = power - (direction * rightMultiplier);

  // DEADZONES
  if (abs(power) <= 20)
    setDrive(0, 0);
  if(abs(direction) <= 20)
    setDrive(0, 0);

  // SET MOTOR POWER
  setDrive(left, right);
}

// LIFT
void moveLift() {
  bool getLiftUp = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
  bool getLiftDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
  const int liftSpeed = 115;

  if(getLiftUp) {
    lift = liftSpeed;
  }
  else if(getLiftDown) {
    lift = -liftSpeed;
  }
  else {
    lift = 0;
  }
}

// CLAMP
void moveClamp() {
  bool isAPressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_A);
  bool isBPressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);

  if(isAPressed) {
    clampPiston.set_value(false);
  }
  
  if(isBPressed) {
     clampPiston.set_value(true);
  }
}

// BACK LIFT
void moveBackLift() {
  bool getLiftUp = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
  bool getLiftDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);


  if(getLiftUp) {
    backPiston.set_value(true);
    pros::delay(200);
    actuator.set_value(false);
  }

  else if(getLiftDown) {
    actuator.set_value(true);
    pros::delay(200);
    backPiston.set_value(false);
  }   

}

void intakeMove() {
  bool on = controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);

  const int intakeSpeed = -127;

  if(on) {
    running = !running;
    delay(1000);
  } 

  if(running) {
    intake = -intakeSpeed;
  }
}


//TESTING
void test()
{
  /*
  bool x = controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
  bool y = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);

  bool a = controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT);
  bool b = controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT);


  if(x) {
    backPiston.set_value(true);
  }
  else if(y) {
    backPiston.set_value(false);
  }

  if(a) {
    actuator.set_value(false);
  }
  if(b) {
    actuator.set_value(true);
  }
  */

}
