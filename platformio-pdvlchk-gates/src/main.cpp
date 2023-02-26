#include <ESPServer.h>
#include <ESPLed.h>
#include <ServoButton.h>

// const char *SSID = "Podvalchik";
// const char *PWD = "43215678";

const char *SSID = "QinAlLife";
const char *PWD = "12348765";

ESPServer espserver;
ESPLed espled;

const int SERVO_PIN = 25;
ServoButton servoButton;

void sendSuccess(char *msg)
{
  char status[] = "Success";
  espserver.sendResponse(status, msg);
}

void getHello()
{
  // Serial.println("Get: Hello");

  char status[] = "Success";
  char description[] = "Methods: /hello, /status, /ledblink, /tap, /gap, /photo";

  espserver.sendResponse(status, description);
}

void getStatus()
{
  // Serial.println("Get: Status");

  char description[] = "All Working";
  sendSuccess(description);
}

void getLedBlink()
{
  // Serial.println("Get: Led Blink");

  espled.runLoop();

  char description[] = "Led Blinked";
  sendSuccess(description);
}

void getTap()
{
  // Serial.println("Get: Tap");

  servoButton.tapButton();

  char description[] = "Servo Tapped";
  sendSuccess(description);
}

void getGap()
{
  servoButton.makeGap();

  char description[] = "Gap Created";
  sendSuccess(description);
}

void getPhoto()
{
  // espled.runLoop();

  char description[] = "No Photo";
  sendSuccess(description);
}

void setup()
{
  Serial.begin(115200);

  espserver.connectWifi(SSID, PWD);

  servoButton.setup(SERVO_PIN);
  espled.setup();

  espserver.addRoute("/hello", getHello);
  espserver.addRoute("/status", getStatus);
  espserver.addRoute("/ledblink", getLedBlink);
  espserver.addRoute("/tap", getTap);
  espserver.addRoute("/gap", getGap);
  espserver.addRoute("/photo", getPhoto);

  espserver.start();
}

void loop()
{
  espserver.run();
}