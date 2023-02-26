#include "ESPLed.h"

// MARK: LED (Мигаем встроенным светодиодом на ESP32)
const int LED = 2;

void ESPLed::getOn()
{
    Serial.println("Get Led On");
    digitalWrite(LED, HIGH);
}

void ESPLed::getOff()
{
    Serial.println("Get Led Off");
    digitalWrite(LED, LOW);
}

void ESPLed::runLoop()
{
    delay(1000);
    getOn();
    delay(1000);
    getOff();
}

void ESPLed::setup()
{
    pinMode(LED, OUTPUT);
    runLoop();
}