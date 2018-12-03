#ifndef DHT_HPP
#define DHT_HPP
#include <DHt.h>

class Dht
{
public:
    void SetUp(int DataPin);
    float GetTemperature();
    float GetHumidity();
private:
    int pin;
    int type;

};

#endif /*DHT_HPP*/