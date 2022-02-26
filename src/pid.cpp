#include "main.h"
using namespace okapi;

class PID {
  private:
    double m_kP = 0;
    double m_kD = 0;
    int m_minDt = 10;

    okapi::Timer m_timer;
    double m_error = 0;
    double m_lastError = 0;
    double m_lastTime = 0;
    double m_derivative = 0;
    double m_output = 0;

  public:
    PID(double kP, double kD, int minDt = 10);
    double calculateErr(double);
    double calculate(double, double);
    double getError();
    void reset();
};

PID::PID(double kP, double kD, int minDt) {
  m_kP = kP;
  m_kD = kD;
  m_minDt = minDt;
  m_lastTime = m_timer.millis().convert(millisecond);
}

double PID::calculateErr(double ierror) {
  m_error = ierror;

  double dT = m_timer.millis().convert(millisecond) - m_lastTime;

  if(dT < m_minDt)
    return m_output;

  if(dT > 0)
    m_derivative = (m_error - m_lastError) / dT;

  m_output = (m_error * m_kP) + (m_derivative * m_kD);

  if(std::abs(m_output) > 127)
    m_output = (std::abs(m_output) / m_output) * 127;

  m_lastTime = m_timer.millis().convert(millisecond);
  m_lastError = m_error;

  return m_output;
}

double PID::calculate(double target, double current) {
  return calculateErr(target - current);
}

double PID::getError() {
  return m_error;
}

void PID::reset() {
  m_error = 0;
  m_lastError = 0;
  m_lastTime = m_timer.millis().convert(millisecond);
  m_derivative = 0;
  m_output = 0;
}

void driveDistancePID(PID distancePID, double target) {
  int direction = abs(target) / target;
  resetDriveEncoders();

  while(avgDriveEncoderValue() < abs(target)) {
    double drivePos = avgDriveEncoderValue();

    double drivePower = distancePID.calculate(target, drivePos);

    double leftPower = direction * drivePower;
    double rightPower = direction * drivePower;

    setDrive(leftPower, rightPower);
    pros::delay(10);
  }

  distancePID.reset();
}

void turnAnglePID(PID anglePID, double target) {
  int direction = abs(target) / target;
  resetDriveEncoders();
  inertSensor.reset();

  while(inertSensor.get_rotation() < abs(target)) {
    double drivePower = anglePID.calculate(abs(target), inertSensor.get_rotation());

    double leftPower = direction * drivePower;
    double rightPower = -direction * drivePower;

    setDrive(leftPower, rightPower);
    pros::delay(10);
  }

  distancePID.reset();
}
