#include "ButtonController.h"

#include <Servo.h>
#include <mutex>
#include <unistd.h>

//
// MARK: SERVO
//

Servo servo;

//bool ignoreApi = true;

std::mutex m;

void setupServo()
{
  servo.attach(13);
}

void runServoStep()
{
  std::lock_guard<std::mutex> lg(m);
  Serial.println("Before ignore api");
 // if (ignoreApi)
  //{
   // ignoreApi = false;
    Serial.println("Run Button");
    //sleep(5);
    servo.write(30);
    delay(500);
    servo.write(0);
    delay(500);
  //  ignoreApi = true;
 // }
}

void tapButton()
{
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
