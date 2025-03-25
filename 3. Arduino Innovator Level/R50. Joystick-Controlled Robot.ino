/*
Components Used:
- Arduino Board
- Joystick Module
- Motor Shield
- DC Motors (4)
- Breadboard
*/

#include <AFMotor.h>

// Define motor objects
AF_DCMotor right_Front(1);
AF_DCMotor right_Back(2);
AF_DCMotor left_Front(3);
AF_DCMotor left_Back(4);

int xPin = A0;  // Joystick X-axis pin
int yPin = A1;  // Joystick Y-axis pin

void setup() {
  right_Front.setSpeed(150);
  right_Back.setSpeed(150);
  left_Front.setSpeed(150);
  left_Back.setSpeed(150);
  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(xPin);  // Read the X-axis value (0-1023)
  int yValue = analogRead(yPin);  // Read the Y-axis value (0-1023)

  // Joystick control logic
  if (xValue < 400) {
    // Move Left
    left_Front.run(BACKWARD);
    left_Back.run(BACKWARD);
    right_Front.run(FORWARD);
    right_Back.run(FORWARD);
  }
  else if (xValue > 600) {
    // Move Right
    left_Front.run(FORWARD);
    left_Back.run(FORWARD);
    right_Front.run(BACKWARD);
    right_Back.run(BACKWARD);
  }
  else if (yValue < 400) {
    // Move Backward
    left_Front.run(BACKWARD);
    left_Back.run(BACKWARD);
    right_Front.run(BACKWARD);
    right_Back.run(BACKWARD);
  }
  else if (yValue > 600) {
    // Move Forward
    left_Front.run(FORWARD);
    left_Back.run(FORWARD);
    right_Front.run(FORWARD);
    right_Back.run(FORWARD);
  }
  else {
    // Stop robot if joystick is in the center
    right_Front.run(RELEASE);
    right_Back.run(RELEASE);
    left_Front.run(RELEASE);
    left_Back.run(RELEASE);
  }
}
