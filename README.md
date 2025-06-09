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
|------------------|-------------|
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

// Define motor driver pins
const uint8_t IN1 = 2;
const uint8_t IN2 = 3;
const uint8_t IN3 = 4;
const uint8_t IN4 = 5;
const uint8_t ENA = 6;
const uint8_t ENB = 7;

// Create the MotorDriver object
MotorDriver motor(IN1, IN2, IN3, IN4, ENA, ENB);

void setup() {
    motor.begin();
}

void loop() {
    // Forward
    motor.setMotor(255, 255, true, true);
    delay(1000);

    // Left
    motor.turnLeft();
    delay(1000);

    // Right
    motor.turnRight();
    delay(1000);

    // Backward
    motor.setMotor(255, 255, false, false);
    delay(1000);

    // Stop
    motor.stop();
    delay(500);
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

## License

MIT License

## Author

HARIKESH O P  
[23b472@gcek.ac.in](mailto:23b472@gcek.ac.in)
