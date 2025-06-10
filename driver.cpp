#include "driver.h"
#include <Arduino.h>

MotorDriver::MotorDriver(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4, uint8_t ena, uint8_t enb,
                         int leftSpeed = 255, int rightSpeed = 255,
                         bool leftForward, bool rightForward)
    : in1(in1), in2(in2), in3(in3), in4(in4), ena(ena), enb(enb),
      lspeed(leftSpeed), rspeed(rightSpeed),
      lforward(leftForward), rforward(rightForward) {}

void MotorDriver::begin()
{
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(ena, OUTPUT);
    pinMode(enb, OUTPUT);
    setMotor(lspeed, rspeed, lforward, rforward);
}

void MotorDriver::setMotor(int leftSpeed, int rightSpeed, bool leftForward, bool rightForward)
{
    digitalWrite(in1, leftForward ? HIGH : LOW);
    digitalWrite(in2, leftForward ? LOW : HIGH);
    digitalWrite(in3, rightForward ? HIGH : LOW);
    digitalWrite(in4, rightForward ? LOW : HIGH);

    analogWrite(ena, abs(leftSpeed));
    analogWrite(enb, abs(rightSpeed));
}

void MotorDriver::turnLeft()
{
    setMotor(0, rspeed, false, true); // Stop left motor, run right motor
}

void MotorDriver::turnRight()
{
    setMotor(lspeed, 0, true, false); // Stop right motor, run left motor
}

void MotorDriver::setSpeed(int leftSpeed, int rightSpeed)
{
    lspeed = leftSpeed;
    rspeed = rightSpeed;
    setMotor(lspeed, rspeed, lforward, rforward);
}

void MotorDriver::stop()
{
    setMotor(0, 0, false, false); // Stop both motors
}

void MotorDriver::backward()
{
    setMotor(lspeed, rspeed, false, false); // Run both motors backward
}
