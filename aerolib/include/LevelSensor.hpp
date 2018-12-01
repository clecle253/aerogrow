#ifndef LEVELSENSOR_HPP
#define LEVELSENSOR_HPP

#include <Arduino.h>
class LevelSensor
{
  private:
  int sA;
  int sB;
  int sC;
  int sD;
  int sig;
  int enable;
  
  void SelectChan(int chan);
  
  public:
  void Setup(int s0, int s1, int s2, int s3, int sig, int enable);
  void EnableCom();
  void DisableCom();
  int ReadValue(int channel);
  void Write(int chan, int value);
  int getLevel(int alert);
};


#endif /*LEVELSENSOR_HPP*/