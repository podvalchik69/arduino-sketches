#ifndef WifiClient_h
#define WifiClient_h

#include <Arduino.h>

class WifiClient
{
  public:
    void connect(const char *ssid, const char *pswd);
  private:
};

#endif