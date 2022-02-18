#include "main.h"

bool open = true;
int powerMultiplier = 1;

int rightMultiplier = 1;
int leftMultiplier = 1;

//DRIVE
void setDrive(int left, int right) {
  backLeft = left;
  backRight = right;
  frontLeft = left;
  frontRight = right;
}

void resetMotorEncoders() {
  backLeft.tare_position();
  backRight.tare_position();
  frontRight.tare_position();
  frontLeft.tare_position();
}

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

void setDriveMotors() {

  //Input values
  double power = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  double direction = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);


  power *= powerMultiplier;

  //Set velocity to each side
  int left = power + (direction * leftMultiplier);
  int right = power - (direction * rightMultiplier);


  // Set power to both sides of chassis
  //Setting deadzones
  if (abs(power) <= 20)
    setDrive(0, 0);
  if(abs(direction) <= 20)
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
    //pros::delay(100);
  }
  if(isBPressed) {
     clampPiston.set_value(true);
   }
}

//WING

/*
void moveHook() {
  bool getLiftUp = controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
  bool getLiftDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
  const int wingSpeed = 127;

  if(getLiftUp) {
    backHook = wingSpeed;

  }
  else if(getLiftDown) {
    backHook = -wingSpeed;

  }
  else {
    backHook = 0;

  }
}
*/

void moveBackLift() {
  bool getLiftUp = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
  bool getLiftDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
  const int liftSpeed = 115;

  if(getLiftUp) {
    backLift = liftSpeed;
  }
  else if(getLiftDown) {
    backLift = -liftSpeed;
  }
  else {
    backLift = 0;
  }
}

//TESTING
void test()
{
  //
}
