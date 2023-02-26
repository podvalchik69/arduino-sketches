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
    void run();
    void sendResponse(char *status, char description[]);

private:
};

#endif