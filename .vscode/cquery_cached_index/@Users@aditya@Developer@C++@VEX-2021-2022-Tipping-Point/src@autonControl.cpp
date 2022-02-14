#include "main.h"

okapi::Motor backWing(9);

void translate(int units, int voltage) {
   int direction = abs(units) / units;

   resetMotorEncoders();

   while(getAvgEncoder() < abs(units)) {
       setDrive(voltage * direction, voltage * direction);
       pros::delay(10);
   }

   setDrive(-10 * direction, -10 * direction);
   pros::delay(10);

   setDrive(0, 0);
}

void turnInertial(int degrees, int voltage) {
  int direction = abs(degrees) / degrees;

  inertial.reset();

  while(inertial.get_heading() < fabs(degrees)) {
    if(direction < 0)
      setDrive(voltage * -direction, voltage * direction);
    else 
      setDrive(voltage * direction, voltage * -direction);

    pros::delay(10);
  }
   
  setDrive(-10 * direction, -10 * direction);
  pros::delay(10);

  setDrive(0, 0);
}

void turn(int units, int voltage) {
  int direction = abs(units) / units;

  resetMotorEncoders();

  while(getAvgEncoder() < abs(units)) {
      setDrive(voltage * direction, voltage * -direction);
      pros::delay(10);
  }

  setDrive(-10 * direction, -10 * direction);
  pros::delay(10);

  setDrive(0, 0);
}


void forwardClamp() {
  translate(590, 250);
  pros::delay(490);
  clampPiston.set_value(true);
  pros::delay(100);

  translate(-575, 90);
  pros::delay(100);


}

void forwardAWP() {

  backWing.moveRelative(0.75, 100);
  pros::delay(750);
  backWing.moveRelative(-0.75, 100);
  translate(125, 50);

  turn(190, 80);
  pros::delay(175);

  translate(590, 200);
  pros::delay(500);
  clampPiston.set_value(true);
  pros::delay(100);

  translate(-500, 90);
  pros::delay(100);




}
