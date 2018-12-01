#include "../include/FlowSensor.hpp"
#include <Arduino.h>

volatile unsigned int pulseCount = 0;

void pulseCounter()
{
  pulseCount++;
}

FlowSensor::FlowSensor()
{

}

void FlowSensor::Setup(int interupt, int sensor)
{
  this->interupt_pin = interupt;
  this->sensor_pin = sensor;
  this->calibrationFactor = 4.5;

  this->flowRate          = 0.0;
  this->flowMilliLitres   = 0;
  this->totalMilliLitres  = 0;
  this->oldTime           = 0;

  pinMode(sensor_pin, INPUT);
  digitalWrite(sensor_pin, HIGH);
}

void FlowSensor::Start()
{
  this->flowRate          = 0.0;
  this->flowMilliLitres   = 0;
  this->totalMilliLitres  = millis();
  pulseCount = 0;

  attachInterrupt(interupt_pin, pulseCounter, FALLING);
}

void FlowSensor::Stop()
{
  detachInterrupt(sensor_pin);
}

void FlowSensor::Getvalue()
{
  detachInterrupt(this->interupt_pin);
  flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
  oldTime = millis();
  flowMilliLitres = flowRate;
  totalMilliLitres += (pulseCount * calibrationFactor);
  //totalMilliLitres += flowMilliLitres;
  pulseCount = 0;
  attachInterrupt(this->interupt_pin, pulseCounter, FALLING);
}

float FlowSensor::GetFlow()
{
  Getvalue();
  return flowMilliLitres;
}

float FlowSensor::GetTotalFlow()
{
  Getvalue();
  return totalMilliLitres;
}