#include "ESPServer.h"
#include <ArduinoJson.h>


WebServer server(80);
StaticJsonDocument<250> jsonDocument;
char buffer[250];

ESPServer::ESPServer()
{
}

void ESPServer::connectWifi(const char *ssid, const char *pswd)
{
  connect(ssid, pswd);
}

void ESPServer::addRoute(const Uri &uri, WebServer::THandlerFunction fn)
{
  server.on(uri, fn);
}

void ESPServer::start()
{
  server.begin();
}

void ESPServer::createJson(char *tag, float value, char *unit)
{
  jsonDocument.clear();
  jsonDocument["type"] = tag;
  jsonDocument["value"] = value;
  jsonDocument["unit"] = unit;
  serializeJson(jsonDocument, buffer);
}
