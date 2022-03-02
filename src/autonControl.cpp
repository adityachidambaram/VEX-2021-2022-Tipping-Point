#include "main.h"

void forwardClamp() {
//
} 

void forwardAWP() {
  /*
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
  pros::delay(100); */
}

void progSkill() {
  translate(-200, 80);
  backPiston.set_value(true);

  pros::delay(500);

  translate(250, 80);

  pros::delay(100);

  turn(250, 75);

  pros::delay(100);

  translate(610, 80);

  clampPiston.set_value(true);




}