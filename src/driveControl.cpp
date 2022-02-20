#include "main.h"

bool open = true;
int powerMultiplier = 2;

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
    clampPiston.set_value(false);
  }
  if(isBPressed) {
     clampPiston.set_value(true);
   }
}

void moveBackLift() {
  bool getLiftUp = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
  bool getLiftDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);

/*
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
  */
   
   if(getLiftUp) {
     backLift = 115;
   }
   else if(getLiftDown) {
     backLift = -115;
   }
   else {
     backLift = 0;
   }
  
}
/*
void intakeMove() {
  bool on = controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
  bool off = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
  const int liftSpeed = 115;
  bool running = false;
  if(on) {
    running = true;
  }
  if(off) {
    running = false;
  }

  while(running) {
    intake = liftSpeed;
  }
  
}
*/

//TESTING
void test()
{
  //
}
