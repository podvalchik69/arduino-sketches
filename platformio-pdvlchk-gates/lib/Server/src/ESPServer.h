#ifndef ESPServer_h
#define ESPServer_h

#include <Arduino.h>
#include <WifiClient.h>
#include <WebServer.h>

class ESPServer: public WifiClient
{
public:
    ESPServer();
    void connectWifi(const char *ssid, const char *pswd);
    void addRoute(const Uri &uri, WebServer::THandlerFunction fn);
    void start();
    void createJson(char *tag, float value, char *unit);

private:
};

#endif