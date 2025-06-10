# Motor Driver Library

A simple Arduino library for controlling motor drivers like L298N, L293D, and other similar H-bridge drivers. This library makes it easy to control the direction and speed of two DC motors for robotics and automation projects.

## Features

- Easy-to-use API for controlling two DC motors
- Set speed and direction independently for each motor
- Simple functions for forward, backwards, left, right, and stop
- Designed for Arduino-compatible boards

## Supported Drivers

- L298N
- L293D
- Other similar dual H-bridge motor drivers

## Installation

1. Download or clone this repository:
   ```sh
   git clone https://github.com/HarikeshopGCEK/motorDriverLibrary.git
   ```
2. Copy the `motorDriverLibrary` folder to your Arduino `libraries` directory.
3. Restart the Arduino IDE.

## Usage

### Wiring

Connect your motor driver module to your Arduino as follows (example pins):

| Motor Driver Pin | Arduino Pin |
| ---------------- | ----------- |
| IN1              | 2           |
| IN2              | 3           |
| IN3              | 4           |
| IN4              | 5           |
| ENA              | 6           |
| ENB              | 7           |

### Example Code

```cpp
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

MotorDriver motor(LEFT_IN1, LEFT_IN2, RIGHT_IN1, RIGHT_IN2, LEFT_ENA, RIGHT_ENB);
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
```

## API Reference

- `MotorDriver(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4, uint8_t ena, uint8_t enb)`
- `void begin()`
- `void setMotor(int leftSpeed, int rightSpeed, bool leftForward, bool rightForward)`
- `void setSpeed(int leftSpeed, int rightSpeed)`
- `void turnLeft()`
- `void turnRight()`
- `void stop()`
- `void backward()`

## License

MIT License

## Author

HARIKESH O P  
[23b472@gcek.ac.in](mailto:23b472@gcek.ac.in)
