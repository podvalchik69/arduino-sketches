#include <WebServer.h>
#include <ArduinoJson.h>
#include "ButtonController.h"

//
// MARK: WIFI
//
const char *SSID = "Podvalchik";
const char *PWD = "43215678";

void setupWIFI()
{
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(SSID, PWD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.print("Connected! IP Address: ");
  Serial.println(WiFi.localIP());
}

//
// MARK: SERVER
//
WebServer server(80);
StaticJsonDocument<250> jsonDocument;
char buffer[250];

void setupRouting()
{
  Serial.println("Setup Server Routing");
  server.on("/hello", getHelloWorld);
  server.on("/ledon", getLedOn);
  server.on("/ledoff", getLedOff);
  server.on("/tapButton", tapButtonImpl);
  server.on("/makeGap", makeGap);
}

void setupServer()
{
  Serial.println("Setup Server");
  setupRouting();
  server.begin();
}

void createJson(char *tag, float value, char *unit)
{
  jsonDocument.clear();
  jsonDocument["type"] = tag;
  jsonDocument["value"] = value;
  jsonDocument["unit"] = unit;
  serializeJson(jsonDocument, buffer);
}

//
// MARK: CORE
//
void setup()
{
  Serial.begin(115200);

  setupLed();
  setupServo();
  setupWIFI();
  setupServer();
}

void loop()
{
  server.handleClient();
}

//
// MARK: Hello World
//
void getHelloWorld()
{
  Serial.println("Hello World");
  createJson("hello", 69, "°C");
  server.send(200, "application/json", buffer);
}

void tapButtonImpl()
{
  createJson("Done", 200, "OK");
  server.send(200, "application/json", buffer);
  tapButton();
}

//
// MARK: LED (Мигаем встроенным светодиодом на ESP32)
//
const int LED = 2;

void setupLed()
{
  pinMode(LED, OUTPUT);
  runLedLoop();
  runLedLoop();
}

void runLedLoop()
{
  delay(1000);
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
}

void getLedOn()
{
  Serial.println("Get Led On");
  digitalWrite(LED, HIGH);
}

void getLedOff()
{
  Serial.println("Get Led Off");
  digitalWrite(LED, LOW);
}
