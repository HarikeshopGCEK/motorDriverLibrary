#include <Arduino.h>
#include "driver.h"

#define LEFT_IN1 2
#define LEFT_IN2 3
#define RIGHT_IN1 4
#define RIGHT_IN2 5
#define LEFT_ENA 6
#define RIGHT_ENB 7
#define LEFT_SPEED 255
#define RIGHT_SPEED 255

MotorDriver motor(LEFT_IN1, LEFT_IN2, RIGHT_IN1, RIGHT_IN2, LEFT_ENA, RIGHT_ENB, LEFT_SPEED, RIGHT_SPEED);
void setup()
{
    Serial.begin(9600);
    motor.begin();
}
void loop()
{
    // Check the direction of the motors
    motor.setMotor(LEFT_SPEED, RIGHT_SPEED, true, true); // Set both motors to forward
    Serial.println("Motors set to forward");
    delay(2000);      // Wait for 2 seconds
    motor.turnLeft(); // Turn left
    Serial.println("Turning left");
    delay(2000);       // Wait for 2 seconds
    motor.turnRight(); // Turn right
    Serial.println("Turning right");
    delay(2000);      // Wait for 2 seconds
    motor.backward(); // Move backward
    Serial.println("Moving backward");

    // You can edit the motor.setMotor() to acces different motor functons
    //  For example, you can set the speed and direction of the motors
}