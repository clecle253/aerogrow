#ifndef ELECTROVANNE_HPP
#define ELECTROVANNE_HPP

#include <Arduino.h>
class ElectroVanne
{
public:
    void setup(int pin);
    void on();
    void off();
    void on_for(int time);

private:
    int pin;

};

#endif /*ELECTROVANNE_HPP*/