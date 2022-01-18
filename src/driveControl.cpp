#include "main.h"

//DRIVE
void setDrive(int left, int right) {
  backLeft = left;
  backRight = right;
  frontLeft = left;
  frontRight = right;
}

void setDriveMotors() {

  //Input values
  int power = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int direction = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

  //Set velocity to each side
  int left = power + direction;
  int right = power - direction;

  //Reverse turns for backwards driving
  if(power < 0) {
    left = power - direction;
    right = power + direction;
  }

  // Set power to both sides of chassis
  //Setting deadzones
  if (abs(power) <= 20)
    setDrive(0, 0);
  if(abs(direction) <= 40)
    setDrive(0, 0);

  setDrive(left, right);
}

//LIFT
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

//CLAMP
void moveClamp() {
  bool isAPressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_A);
  bool isBPressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);

  if(isAPressed) {
    //open = !open;
    clampPiston.set_value(false);
  }
  if(isBPressed) {
    clampPiston.set_value(true);
  }
}

//WING
void moveWing() {
  bool getLiftUp = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
  bool getLiftDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
  const int wingSpeed = 127;

  if(getLiftUp) {
    rightWing = wingSpeed;
    leftWing = wingSpeed;
  }
  else if(getLiftDown) {
    rightWing = -wingSpeed;
    leftWing = -wingSpeed;
  }
  else {
    rightWing = 0;
    leftWing =0;
  }
}

//TESTING
void test()
{
  //
}

