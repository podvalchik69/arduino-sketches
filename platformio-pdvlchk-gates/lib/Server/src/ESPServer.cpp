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

void ESPServer::run()
{
  server.handleClient();
}

void ESPServer::sendResponse(char *status, char *description)
{
  jsonDocument["status"] = status;
  jsonDocument["description"] = description;
  serializeJson(jsonDocument, buffer);
  server.send(200, "application/json", buffer);
  jsonDocument.clear();
}
