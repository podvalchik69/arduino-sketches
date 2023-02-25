#include <Arduino.h>

//
// MARK: LED (Мигаем встроенным светодиодом на ESP32)
//
const int LED = 2;

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

void setupLed()
{
    pinMode(LED, OUTPUT);
    runLedLoop();
}
