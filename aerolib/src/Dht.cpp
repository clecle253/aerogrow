#include "../include/Dht.hpp"


void Dht::SetUp(int DataPin)
{
    this->pin = DataPin;
    this->type = DHT11;
}

float Dht::GetTemperature()
{
    DHT control(this->pin, this->type);
    control.begin();
    return control.readTemperature(false);
}

float Dht::GetHumidity()
{
    DHT control(this->pin, this->type);
    control.begin();
    return control.readHumidity();
}