#include "HBridgeDriver.h"
#include <stdio.h>

HBridgeDriver leftw,rightw;
int left,right;
char command[7];

void setup()
{
  Serial.begin(9600);
  leftw.setPins(52,53,4);
  rightw.setPins(50,51,3);
}
void loop()
{
  
  while(Serial.available()<=0){}
  Serial.readBytesUntil('\n',command, 7);
  Serial.println((char *)&command);
  command[3] = '\0';
  left = atoi(&command[0])-255;
  right = atoi(&command[4])-255; 

      leftw.setSpeed(left);
      rightw.setSpeed(right);

}
