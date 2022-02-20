#include "main.h"

okapi::Motor backWing(9);

void forwardClamp() {
  translate(575, 150);
  pros::delay(520);
  clampPiston.set_value(true);
  pros::delay(100);

  translate(-540, 90);
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
