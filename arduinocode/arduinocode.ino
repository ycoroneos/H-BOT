#include <stdio.h>
#include <Servo.h>
#include "HBridgeDriver.h"

HBridgeDriver leftWheel, rightWheel;

void setup(){
   Serial.begin(9600);
   leftWheel.SetPins(4,5,0);
   rightWheel.SetPins(6,7,1);
}

void loop()
{
  char command[7];
  Serial.readBytesUntil('\n', command,7);
  command[3] = '\0'; // replace # with \0 and effectively 2 strings
  int left = atoi(&command[0]);
  int right = atoi(&command[4]);
  leftWheel.SetSpeed(left);
  rightWheel.SetSpeed(right);
  delay(15);
}
