#include "main.h"

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

void translateInertial(int units, int voltage) {
  int direction = abs(units) / units;

  inertial.reset();

  setDrive(voltage * direction, voltage * direction);
  while(inertial.get_heading() > abs(units)) {
    pros::delay(10);
  }
   
  setDrive(-10 * direction, -10 * direction);
  pros::delay(10);

  setDrive(0, 0);
}

void turnInertial(int degrees, int voltage) {
  int direction = abs(degrees) / degrees;

  inertial.reset();
  setDrive(voltage * direction, voltage * -direction);
  while(inertial.get_rotation() < abs(degrees)) {
    //setDrive(voltage * direction, voltage * -direction);
    pros::delay(10);
  }
  
  translate(500, 100);
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

void swing(int units, int voltage) {
   resetMotorEncoders();

   while(getLeftEncoder() < abs(units)) {
       setDrive(voltage, 0);
       pros::delay(10);
   }

   setDrive(-10, 0);
   pros::delay(10);

   setDrive(0, 0);
}


void swingRight(int units, int voltage) {
   resetMotorEncoders();

   while(getRightEncoder() < abs(units)) {
       setDrive(0, voltage);
       pros::delay(10);
   }

   setDrive(0, -10);
   pros::delay(10);

   setDrive(0, 0);
}






