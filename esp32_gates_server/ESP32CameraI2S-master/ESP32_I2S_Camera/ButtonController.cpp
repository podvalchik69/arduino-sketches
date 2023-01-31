#include "ButtonController.h"

#include <Servo.h>
#include <mutex>
#include <unistd.h>

//
// MARK: SERVO
//

Servo servo;

std::mutex m;

void setupServo()
{
  servo.attach(19);
}

void runServoStep()
{
  std::lock_guard<std::mutex> lg(m);
  Serial.println("Run Button");
  servo.write(30);
  delay(500);
  servo.write(0);
  delay(500);
}

void tapButton()
{
  Serial.println("Run Run");
  runServoStep();
}

void makeGap()
{
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
