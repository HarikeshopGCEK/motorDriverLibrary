#ifndef DRIVER_H
#define DRIVER_H
#include <Arduino.h>
#include "driver.h"

class MotorDriver
{
private:
    uint8_t in1, in2, in3, in4, ena, enb; // Motor control pins
    int lspeed, rspeed;                   // Motor speeds
    bool lforward, rforward;              // Motor directions

public:
    MotorDriver(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4, uint8_t ena, uint8_t enb,
                int leftSpeed = 0, int rightSpeed = 0,
                bool leftForward = true, bool rightForward = true);
    void setMotor(int leftSpeed = 255, int rightSpeed = 255, bool leftForward, bool rightForward);
    void begin();
    void setSpeed(int leftSpeed, int rightSpeed);
    void turnLeft();
    void stop();
    void turnRight();
    void backward();
};

#endif