#include <ESPServer.h>

const char *SSID = "Podvalchik";
const char *PWD = "43215678";

ESPServer espserver;

void setup()
{
  espserver.connectWifi(SSID, PWD);
  // connect(SSID, PWD);
}

//   Serial.println("Setup Server Routing");

// wifi.setupWifi();

// Serial.begin(115200);

// setupLed();
// setupServo();
// setupWIFI();
// setupServer();


void loop()
{
  // server.handleClient();
}