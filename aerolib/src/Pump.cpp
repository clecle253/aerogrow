#include "../include/aerogrowlib.hpp"

void Pump::setup(int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void Pump::on()
{
    digitalWrite(pin, HIGH);
}

void Pump::off()
{
    digitalWrite(pin,LOW);
}

void Pump::on_for(int time)
{
    on();
    delay(time);
    off();
}