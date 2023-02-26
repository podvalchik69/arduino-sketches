#include "ServoButton.h"

#include <Servo.h>
#include <mutex>
#include <unistd.h>

Servo servo;

std::mutex m;

void ServoButton::setup(int pin)
{
  servo.attach(pin);
}

void ServoButton::runStep()
{
  std::lock_guard<std::mutex> lg(m);
  Serial.println("Run Servo Step");
  servo.write(30);
  delay(500);
  servo.write(0);
  delay(500);
}

void ServoButton::tapButton()
{
  runStep();
}

void ServoButton::makeGap()
{
  runStep();
  delay(1000);
  runStep();
  delay(4000);
  runStep();
  delay(1000);
  runStep();
  delay(2000);
  runStep();
}
