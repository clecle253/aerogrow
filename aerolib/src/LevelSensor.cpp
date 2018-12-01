#include "../include/LevelSensor.hpp"

void LevelSensor::Setup(int s0, int s1, int s2, int s3, int sig, int enable)
{
    this->sA = s0;
    this->sB = s1;
    this->sC = s2;
    this->sD = s3;
    this->enable = enable;
    this->sig = sig;

    pinMode(this->enable, OUTPUT);
    pinMode(this->sA, OUTPUT);
    pinMode(this->sB, OUTPUT);
    pinMode(this->sC, OUTPUT);
    pinMode(this->sD, OUTPUT);
}

void LevelSensor::EnableCom()
{
  digitalWrite(this->enable, HIGH);
}

void LevelSensor::DisableCom()
{
  digitalWrite(this->enable, LOW);
}

void LevelSensor::SelectChan(int chan)
{
  int chanCode[16][4] {
     {0,0,0,0}, // 0
     {0,0,0,1}, // 1
     {0,0,1,0}, // 2
     {0,0,1,1}, // 3
     {0,1,0,0}, // 4
     {0,1,0,1}, // 5
     {0,1,1,0}, // 6
     {0,1,1,1}, // 7
     {1,0,0,0}, // 8
     {1,0,0,1}, // 9
     {1,0,1,0}, // 10
     {1,0,1,1}, // 11
     {1,1,0,0}, // 12
     {1,1,0,1}, // 13
     {1,1,1,0}, // 14
     {1,1,1,1}, // 15
     };

     if (chan >= 0 && chan <= 15)
     {
      digitalWrite(sA,chanCode[chan][3]);
      digitalWrite(sB,chanCode[chan][2]);
      digitalWrite(sC,chanCode[chan][1]);
      digitalWrite(sD,chanCode[chan][0]);
     }
     EnableCom();
}

int LevelSensor::ReadValue(int channel)
{
  int tmp;
  
  SelectChan(channel);
  tmp = analogRead(sig);
  DisableCom();
  return tmp;
}

int LevelSensor::getLevel(int alert)
{
    int i = 0;
    int total = 0;

    while (i <= 15)
    {
        if (ReadValue(i) > alert)
            total++;
        i++;
    }
    return total;
}

void LevelSensor::Write(int chan, int value)
{
  SelectChan(chan);
  analogWrite(sig, value);
  DisableCom();
}