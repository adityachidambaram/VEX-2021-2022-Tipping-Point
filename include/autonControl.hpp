#include "main.h"
using namespace okapi;

extern std::shared_ptr<ChassisController> chassis;

extern okapi::Motor backWing;

void translate(int units, int voltage);
void turn(int degrees, int voltage);

void forwardClamp();

void forwardAWP();