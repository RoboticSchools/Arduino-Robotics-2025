/*
Components Used:
- Arduino Board
- Motor Shield
- DC Motor (Connected via Motor Shield)
- Servo Motor
- 3 Push Buttons (DC Motor ON, DC Motor OFF, Servo Start/Stop)
- Breadboard
- Jumper Wires
*/

#include <AFMotor.h>
#include <Servo.h>

Servo fanServo;  // Create a Servo object
int servoPin = 9;  // Servo connected to Pin 9

AF_DCMotor fanMotor(1); // DC Motor connected to M1 on Motor Shield

// Button pins
int buttonOn = A0;     // DC Motor ON button
int buttonOff = A1;    // DC Motor OFF button

bool servoRunning = false; // Flag to control servo movement

void setup() {
  pinMode(buttonOn, INPUT_PULLUP);
  pinMode(buttonOff, INPUT_PULLUP);
  fanServo.attach(servoPin); // Attach servo
}

void loop() {
  // DC Motor Control
  if (digitalRead(buttonOn) == 0) {
    fanMotor.setSpeed(255);  // Set speed to max (0-255)
    fanMotor.run(FORWARD);   // Turn DC Motor ON
    servoRunning = true;
  }
  if (digitalRead(buttonOff) == 0) {
    fanMotor.run(RELEASE);   // Turn DC Motor OFF
  }

  // If servo is running, rotate from 0 to 180 and back
  if (servoRunning) {
    for (int angle = 0; angle <= 180; angle++) {
      fanServo.write(angle);
      delay(10);
    }
    for (int angle = 180; angle >= 0; angle--) {
      fanServo.write(angle);
      delay(10);
    }
  }
}
