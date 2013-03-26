#include "HBridgeDriver.h"

HBridgeDriver::HBridgeDriver()
{
}

HBridgeDriver::HBridgeDriver(int a, int b, int signal)
{
  SetPins(a,b,signal);
}

void HBridgeDriver::SetPins(int a, int b, int c)
{
  pins[0]=a;
  pins[1]=b;
  pins[2]=c;
  for (int i=0; i<3; ++i)
  {
    pinMode(pins[i], OUTPUT);
  }
}

void HBridgeDriver::SetSpeed(int speed)
{
  if (speed>0)
  {
    digitalWrite(pins[0], HIGH);
    digitalWrite(pins[1], LOW);
    analogWrite(pins[3], abs(speed));
  }
  else if (speed<0)
  {
    digitalWrite(pins[0], LOW);
    digitalWrite(pins[1], HIGH);
    analogWrite(pins[3], abs(speed));
  }
  else
  {
    digitalWrite(pins[0], HIGH);
    digitalWrite(pins[1], HIGH);
    analogWrite(pins[3], 0);
  }
}
