#pragma once

class HBridgeDriver
{
  private:
    int pins[3];
  public:
    HBridgeDriver();
    HBridgeDriver(int a, int b, int signal);
    void SetPins(int a, int b, int signal);
    void SetSpeed(int speed); //0 to 510
};
