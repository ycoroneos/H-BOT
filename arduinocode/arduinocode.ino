
#include <stdio.h>
#include <Servo.h>

Servo leftWheel, rightWheel;

void setup(){
   Serial.begin(9600);
   leftWheel.attach(9);
   rightWheel.attach(8);
}

void loop()
{
  char command[7];
  Serial.readBytesUntil('\n', command,7);
  command[3] = '\0'; // replace # with \0 and effectively 2 strings
  int left = atoi(&command[0]);
  int right = atoi(&command[4]);
  leftWheel.write(left);
  rightWheel.write(right);
  delay(15);
}
