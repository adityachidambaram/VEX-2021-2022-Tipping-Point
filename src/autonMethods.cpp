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

void gyroPID(double angle){

	double threshold;
	if(angle <= 0.0){
		threshold = 1.5;
	}
	else{
		threshold = 0.7;
	}

	double error = angle - inertial.get_rotation();
	double integral;
	double derivative;
	double prevError;
	double kp = 0.98;
	double ki = 0.001;
	double kd = 5.5;

	while(fabs(error) > threshold){
		error = angle - inertial.get_rotation();
		integral  = integral + error;
		if(error == 0 || fabs(error) >= angle){
			integral = 0;
		}
		derivative = error - prevError;
		prevError = error;
		double p = error * kp;
		double i = integral * ki;
		double d = derivative * kd;

		double vel = p + i + d;

		setDrive(vel, -vel);

		pros::delay(15);
	}
}




