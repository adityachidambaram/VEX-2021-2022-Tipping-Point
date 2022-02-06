#include "main.h"
/* Notes
Open Close Boolean Values for Clamp

Open --> false
Close --> True;
*/

// 0.008 --> D


std::shared_ptr<ChassisController> chassis = ChassisControllerBuilder()
    .withMotors(10, 20, 17, 5)
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
    .withMaxVelocity(110)
    .build();

std::shared_ptr<ChassisController> chassis1 = ChassisControllerBuilder()
    .withMotors(20, 5, 17, 10)
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
    .withMaxVelocity(50)
    .build();



okapi::Motor aFrontLeft(20);
okapi::Motor aFrontRight(5);
okapi::Motor aBackLeft(17);
okapi::Motor aBackRight(10);

okapi::Motor wings(18);

void forward() {
    wings.moveRelative(1.35, 110);
    //pros::delay(100);
    chassis->moveDistance(-1.3_ft);
    pros::delay(50);
    wings.moveRelative(-1.0, 70);
    pros::delay(700);
    chassis->moveDistance(1_ft);
    pros::delay(100);
    //wings.moveRelative(0.8, 90);
    //pros::delay(100);
    pros::delay(1000);
}

void forwardClamp() {

    //chassis->moveDistance(1.1_ft);
    aFrontLeft.moveRelative(1000, 110);
    aFrontRight.moveRelative(1000, 110);
    aBackLeft.moveRelative(1000, 110);
    aBackRight.moveRelative(1000, 110);

    pros::delay(1550);

    clampPiston.set_value(true);

    aFrontLeft.moveRelative(-870, 110);
    aFrontRight.moveRelative(-870, 110);
    aBackLeft.moveRelative(-870, 110);
    aBackRight.moveRelative(-870, 110);

    pros::delay(1200);

    aFrontLeft.moveRelative(-600, 110);
    aFrontRight.moveRelative(-600, 110);
    aBackLeft.moveRelative(-600, 110);
    aBackRight.moveRelative(600, 110);
    pros::delay(1000);
}

void rightAWP() {
  wings.moveRelative(1.15, 50);
  pros::delay(1000);
  chassis1->moveDistance(0.2_ft);
  pros::delay(100);
}
