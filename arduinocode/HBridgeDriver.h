#pragma once
#include "Arduino.h"

class HBridgeDriver
{
  private:
    int pinI1;
    int pinI2;
    int speedpin;
  public:
    HBridgeDriver();
    HBridgeDriver(int sp);
    void setPins(int a, int b, int signal);
    //void SetSpeed(int speed); //0 to 510
    //void Stop();
     void setSpeed(int sp);
   
 };
