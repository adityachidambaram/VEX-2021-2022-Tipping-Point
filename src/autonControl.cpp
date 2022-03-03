#include "main.h"

okapi::Motor lift1(18);
okapi::Motor intake1(4);

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
  /*
  lift1.moveRelative(1, 80);

  translate(-290, 80);
  backPiston.set_value(true);
  pros::delay(450);
  actuator.set_value(true);

  intake1.moveRelative(5, 100);

  pros::delay(700);
  turn(250, 75);
  pros::delay(100);
  translate(900, 80);
  pros::delay(100);
  lift1.moveRelative(-1.15, 80);
  translate(-100, 80);
  pros::delay(500);
  translate(100, 80);
  pros::delay(100);
  clampPiston.set_value(true);
  */

  translate(310, 90);
  pros::delay(500);
  turn(-190, 80);
  pros::delay(200);
  translate(-225, 80);
  backPiston.set_value(true);
  pros::delay(450);
  actuator.set_value(true);
  pros::delay(200);
  //intake1.moveRelative(3, 127);
  translate(330, 80);
  pros::delay(200);
  turn(175, 80);
  pros::delay(200);

  lift1.moveRelative(-0.2, 10);
  translate(400, 90);
  pros::delay(100);
  clampPiston.set_value(true);
  pros::delay(500);

  turn(-85, 80);
  pros::delay(500);
  //intake1.moveRelative(-9, 80);
  lift1.moveRelative(6.5, 100);
  pros::delay(1000);
  translate(1130, 80);
  pros::delay(100);
  lift1.moveRelative(-3.1, 100);
  pros::delay(750);
  clampPiston.set_value(false);
  pros::delay(100);
  lift1.moveRelative(-2.7, 100);
  translate(-500, 80);
  pros::delay(300);
  translate(200, 80);

  turn(-190, 80);


}