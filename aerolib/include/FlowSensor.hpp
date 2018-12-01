#ifndef FLOWSENSOR_HPP
#define FLOWSENSOR_HPP
#include <Arduino.h>

class FlowSensor
{
public:
    FlowSensor();
    void Setup(int interupt, int sensor);
    void Start();
    void Stop();
    void Getvalue();
    float GetTotalFlow();
    float GetFlow();

private:
    int interupt_pin;
    int sensor_pin;
    float calibrationFactor;
    float flowRate;
    unsigned int flowMilliLitres;
    unsigned long totalMilliLitres;
    unsigned long oldTime;
};
#endif /*FLOWSENSOR_HPP*/