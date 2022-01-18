#include "main.h"
using namespace okapi;

/* Notes
Open Close Boolean Values for Clamp

Open --> false
Close --> True;
*/


std::shared_ptr<ChassisController> chassis = ChassisControllerBuilder()
    .withMotors(9,2,4,5)
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
    .withMaxVelocity(140)
    .build();

okapi::MotorGroup wings({10, 3});


void right() {

}

void left() {

}

void forward() {
  wings.moveRelative(1.9, 110);
  chassis->moveDistance(-1.75_ft);
  pros::delay(50);
  wings.moveRelative(-0.75, 70);
  pros::delay(700);
  chassis->moveDistance(1.45_ft);
}

void forwardAngle() {
  wings.moveRelative(1.9, 110);
  chassis->moveDistance(-1.7_ft);
  pros::delay(50);
  wings.moveRelative(-0.75, 70);
  pros::delay(700);
  chassis->moveDistance(1.45_ft);
}

void centerLeft() {
  wings.moveRelative(-1.9, 110);
  pros::delay(100);
  chassis->moveDistance(-2.1_ft);
  pros::delay(100);
  wings.moveRelative(0.5, 70);
  pros::delay(100);
  chassis->moveDistance(1.7_ft);
  pros::delay(100);
  wings.moveRelative(-0.5, 90);
  pros::delay(100);
  chassis->moveDistance(0.25_ft);
}