#include "ButtonController.h"

#include <Servo.h>

//
// MARK: SERVO
//

Servo servo;

bool ignoreApi = false;

void setupServo() {
  servo.attach(13);
}

void runServoStep() {
  servo.write(30);
  delay(500);
  servo.write(0);
}

void tapButton() {
  runServoStep();
}

void makeGap() {
  runServoStep();
  delay(1000);

  runServoStep();
  delay(4000);
  runServoStep();
  delay(1000);
  runServoStep();
  delay(2000);
  runServoStep();
}
