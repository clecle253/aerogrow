#include "../include/Pulverisateur.hpp"

void Pulverisateur::setup(int pin)
{
    this->pin = pin;
	this->status = false;
    pinMode(pin, OUTPUT);
}

void Pulverisateur::on()
{
	this->status = true;
 	digitalWrite(pin, HIGH);
}

void Pulverisateur::off()
{
	this->status = false;
 	digitalWrite(pin, LOW);
}

bool Pulverisateur::GetStatus()
{return this->status;}

void Pulverisateur::on_off()
{
	if (this->status == true)
		off();
	else
		on();
}

void Pulverisateur::on_for(int time)
{
	on();
	delay(time);
    off();
}