#ifndef ServoButton_h
#define ServoButton_h

#include <Arduino.h>

class ServoButton
{
public:
    void setup(int pin);
    void tapButton();
    void makeGap();

private:
    void runStep();
};

#endif