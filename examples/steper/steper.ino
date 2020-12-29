//  Сonnecting the library
#include <LibA4988.h>

#define STEP 2
#define MS1 3
#define MS2 4
#define MS3 5
#define DIR 6

//  Creating a class object
LibA4988 L_1(STEP, MS1, MS2, MS3, DIR);

void setup() {
  L_1.direction(1); //  Setting the direction of the motor clockwise
  L_1.setSpeed(1000); //  Setting the speed to 1000
  L_1.setAcceleration(0); //  Setting the acceleration value to 0
  L_1.stepSplit(2); //  Set the split ratio of the increment to 2
}

void loop() {
  // We take one step once a second
  L_1.steper(); 
  delay(1000);
}