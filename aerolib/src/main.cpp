#include "../include/aerogrowlib.hpp"
#include <Arduino.h>

int dht_pin = 6;
int watersolenoid_pin = 4;
int nutrientsolenoid_pin = 5;
int waterflowsensor_pin = 2;  // interupt
int nutrientflowsensor_pin = 3; // interupt
int mixtanksensor_pin[6] = {20, 21, 22, 23, A0, 24};
int mixpump_pin = 25;
int waterpump_pin = 26;
int nutrientpump_pin = 27;
int pulv_pin = 27;

Dht dhtsensor;
ElectroVanne watersolenoid;
ElectroVanne nutrientsolenoid;
FlowSensor  waterflowsensor;
FlowSensor  nutrientflowsensor;
LevelSensor mixtanklevelsensor;
MixPump  mixpump;
Pump waterpump;
Pump nutrientpump;
Pulverisateur pulv;

void setup() {
  // connecting sensor and controll
  dhtsensor.SetUp(dht_pin);
  watersolenoid.setup(watersolenoid_pin);
  nutrientsolenoid.setup(nutrientsolenoid_pin);
  waterflowsensor.Setup(waterflowsensor_pin, waterflowsensor_pin - 2);
  nutrientflowsensor.Setup(nutrientflowsensor_pin, nutrientflowsensor_pin - 2);
  mixtanklevelsensor.Setup(mixtanksensor_pin[0], mixtanksensor_pin[1], mixtanksensor_pin[2], mixtanksensor_pin[3], mixtanksensor_pin[4], mixtanksensor_pin[5]);
  mixpump.setup(mixpump_pin);
  waterpump.setup(waterpump_pin);
  nutrientpump.setup(nutrientpump_pin);
  pulv.setup(pulv_pin);

  //serial.begin(9600);
}

void loop() {
  // basic survie le code suivant sera un code de merde servant uniquement pour
  // un premier test general
  int time = millis();
  bool refueled = false;

  while (true)
  {
    pulvroutine(pulv);
    refueled = Refuelroutine(mixtanklevelsensor, watersolenoid, waterflowsensor, mixpump, 14);
    if (refueled = true)
      mixpumproutine(mixpump, 40000);
    
    // inserer ici l'interpreteur de commande
  }
}