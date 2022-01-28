#include "main.h"


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


