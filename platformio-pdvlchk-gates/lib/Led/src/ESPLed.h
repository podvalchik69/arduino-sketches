#ifndef ESPLed_h
#define ESPLed_h

#include <Arduino.h>

class ESPLed
{
public:
    void setup();
    void runLoop();

private:
    void getOn();
    void getOff();
};

#endif