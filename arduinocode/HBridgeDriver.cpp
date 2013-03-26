#include "HBridgeDriver.h"

HBridgeDriver::HBridgeDriver()
{
}

HBridgeDriver::HBridgeDriver(int sp)
{
  setSpeed(sp);

}
void HBridgeDriver::setSpeed(int sp){
    if (sp < 0){
        digitalWrite(pinI1, HIGH);
        digitalWrite(pinI2, HIGH);
        delay(50);
        analogWrite(speedpin, 255-abs(sp));
    } else {
        digitalWrite(pinI1, HIGH);
        digitalWrite(pinI2, LOW);
        delay(50);
        analogWrite(speedpin, abs(sp));
    }
}


void HBridgeDriver::setPins(int a, int b, int c)
{
  pinI1=a;
  pinI2=b;
  speedpin=c;
  pinMode(pinI1,OUTPUT);//define this port as output
  pinMode(pinI2,OUTPUT);
  pinMode(speedpin,OUTPUT);
  //Stop();
}
/*
void HBridgeDriver::SetSpeed(int speed)
{
  //Serial.print("setting speed ");
  //Serial.println(speed);
  if (speed>255)
  {
    analogWrite(speedpin, speed-255);
    digitalWrite(pinI1, HIGH);
    digitalWrite(pinI2, LOW);
    analogWrite(speedpin, speed-255);
    Serial.println("HIGH LOW");
  }
  else if (speed<255)
  {
    analogWrite(speedpin, 100);
    digitalWrite(pinI2, LOW);
    digitalWrite(pinI1, HIGH);
    analogWrite(speedpin, 100);
    Serial.println("LOW HIGH");
  }
  else
  {
    Stop();
    Serial.println("stopping");
  }
}

void HBridgeDriver::Stop()
{
  digitalWrite(pinI1, HIGH);
  digitalWrite(pinI2, HIGH);
  analogWrite(speedpin,255);
}*/
