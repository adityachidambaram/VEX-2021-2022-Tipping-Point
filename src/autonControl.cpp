#include "main.h"

okapi::Motor lift1(18);
okapi::Motor intake1(4);

void forwardClamp() {
//
} 

void auton20() {
  clampPiston.set_value(false);
  backPiston.set_value(false);

  lift1.moveRelative(-0.8, 127);
  translate(780, 127);
  pros::delay(100);
  clampPiston.set_value(true);
  pros::delay(500);
  translate(-533, 100);
pros::delay(100);
  lift1.moveRelative(.7, 120);
pros::delay(100);
  turn(-190, 80);

  pros::delay(100);


}

void angle20() {

  
  clampPiston.set_value(false);
  backPiston.set_value(false);

  lift1.moveRelative(-1, 127);
  translate(890, 127);
  clampPiston.set_value(true);
  pros::delay(200);
  lift1.moveRelative(.7, 127);
  translate(-600, 100);
  pros::delay(300);

}


void auton40() {
  clampPiston.set_value(false);
  backPiston.set_value(false);

  lift1.moveRelative(-0.8, 127);
  translate(780, 90);
  pros::delay(100);
  clampPiston.set_value(true);
  pros::delay(500);
  translate(-533, 100);
  pros::delay(550);
  lift1.moveRelative(.7, 127);
  pros::delay(550);
  turn(310, 50);
  translate(-1000, 80);
  pros::delay(100);

  backPiston.set_value(true);
  pros::delay(100);

  translate(925, 80);

  pros::delay(100);

  backPiston.set_value(false);
  pros::delay(450);
  actuator.set_value(false);



}

void rightMiddle() {
  clampPiston.set_value(false);
  backPiston.set_value(false);

  translate(1200, 100);
  pros::delay(100);
  clampPiston.set_value(true);
  pros::delay(500);
  translate(-700, 100);

  pros::delay(100);
  turn(-101, 60);
  pros::delay(100);

  translate(-400, 100);

  backPiston.set_value(true);
  pros::delay(450);
  actuator.set_value(true);
  lift1.moveRelative(.7, 127);
  intake1.moveRelative(7, 127);
  translate(300, 60);

  backPiston.set_value(false);
  pros::delay(450);
  actuator.set_value(false);



}

void progSkill() {
  clampPiston.set_value(false);
  backPiston.set_value(false);

  translate(-57, 80);
  backPiston.set_value(true);
  pros::delay(450);
  actuator.set_value(true);
  pros::delay(100);


  swing(499, 95);
  pros::delay(100);
  lift1.moveRelative(-1, 10);
  translate(740, 80);
  pros::delay(100);
  clampPiston.set_value(true);
  pros::delay(100);

  turn(42 , 80);
  pros::delay(100);
  lift1.moveRelative(5.6, 100);
  pros::delay(1000);
  translate(1100, 40);
  pros::delay(100);

  lift1.moveRelative(-4.5, 100);
  pros::delay(1500);
  clampPiston.set_value(false);
  pros::delay(100);
  lift1.moveRelative(-2.7, 100);

  actuator.set_value(false);
  pros::delay(450);
  backPiston.set_value(false);
  translate(-500, 60);
  lift1.moveRelative(-4.3, 100);
  pros::delay(300);
  translate(200, 60);
  pros::delay(100);
  turn(-395, 80);
  pros::delay(200);

  lift1.moveRelative(-0.5, 10);
  translate(240, 60);
  pros::delay(100);
  clampPiston.set_value(true);

  pros::delay(250);
  lift1.moveRelative(3, 100);
  turn(-425, 60);
  pros::delay(500);
  translate(660, 60);
  lift1.moveRelative(-2.7, 100);
  turn(45, 60);
  clampPiston.set_value(false);



  lift1.moveRelative(2.7, 100);
  pros::delay(500);
  translate(-22, 100);
  turn(98, 80);
  pros::delay(100);


  translate(-680, 60);
  pros::delay(100);
  backPiston.set_value(true);
  pros::delay(450);
  actuator.set_value(true);

  pros::delay(100);
  swing(499, 95);
  translate(1300, 60);




  /*
  lift1.moveRelative(-2, 127);
  translate(790, 80);
  pros::delay(300);
  clampPiston.set_value(true);
  pros::delay(700);

  lift1.moveRelative(6, 115);
  turn(50, 80);
  pros::delay(100);
  translate(700, 80);

*/
  /*
  clampPiston.set_value(false);

  translate(310, 90);
  pros::delay(500);
  turn(-175, 80);
  pros::delay(200);
  translate(-225, 80);
  backPiston.set_value(true);
  pros::delay(450);
  actuator.set_value(true);
  pros::delay(200);

  translate(330, 80);
  pros::delay(200);
  turn(175, 80);
  pros::delay(200);
  lift1.moveRelative(-0.2, 10);
  translate(400, 90);
  pros::delay(100);
  clampPiston.set_value(true);
  pros::delay(500);

  pros::delay(1000);
  //lift1.moveRelative(1, 100);
  translate(450, 60);
  pros::delay(100);
  turn(-175, 80);
  pros::delay(100);
  translate(1000, 60);
  pros::delay(100);
  translate(-450, 60);
  pros::delay(100);
  turn(175, 80);
  lift1.moveRelative(5, 100);
  pros::delay(100);
  translate(300, 60);
  lift1.moveRelative(-4.9, 100);
  pros::delay(1000);
  clampPiston.set_value(false);
  pros::delay(100);
  lift1.moveRelative(-2.7, 100);

  actuator.set_value(false);
  pros::delay(450);
  backPiston.set_value(false);
  translate(-500, 60);
  lift1.moveRelative(-4.1, 100);
  pros::delay(300);
  translate(200, 60);
  pros::delay(100);
  turn(-395, 80);
  pros::delay(200);

  translate(300, 60);
  lift1.moveRelative(-3.1, 100);
  pros::delay(250);
  clampPiston.set_value(true);
  pros::delay(250);
  lift1.moveRelative(3, 100);
  intake1.moveRelative(-4.2, 127);
  turn(-363, 60);
  pros::delay(500);
  translate(567, 60);
  lift1.moveRelative(-2.3, 100);
  clampPiston.set_value(false);

  translate(-25, 80);
  pros::delay(100);
  turn(-260, 80);
  pros::delay(600);
  translate(750, 80);
  backPiston.set_value(true);
  pros::delay(450);
  actuator.set_value(true);
  pros::delay(200);

  */



}