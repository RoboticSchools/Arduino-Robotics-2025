/*
Components Used:
- Arduino Board
- Adafruit Motor Shield
- 4 DC Motors
- Breadboard
- Jumper Wires
*/

#include <AFMotor.h>

// Define motor objects
AF_DCMotor right_Front(1);
AF_DCMotor right_Back(2);
AF_DCMotor left_Front(3);
AF_DCMotor left_Back(4);

void setup() {
  // Set motor speed (0-255)
  right_Front.setSpeed(150);
  right_Back.setSpeed(150);
  left_Front.setSpeed(150);
  left_Back.setSpeed(150);
}

void loop() {
  // Move Forward
  right_Front.run(FORWARD);
  right_Back.run(FORWARD);
  left_Front.run(FORWARD);
  left_Back.run(FORWARD);
  delay(2000);

  // Stop
  right_Front.run(RELEASE);
  right_Back.run(RELEASE);
  left_Front.run(RELEASE);
  left_Back.run(RELEASE);
  delay(1000);

  // Move Backward
  right_Front.run(BACKWARD);
  right_Back.run(BACKWARD);
  left_Front.run(BACKWARD);
  left_Back.run(BACKWARD);
  delay(2000);

  // Stop
  right_Front.run(RELEASE);
  right_Back.run(RELEASE);
  left_Front.run(RELEASE);
  left_Back.run(RELEASE);
  delay(1000);

  // Turn Left
  right_Front.run(FORWARD);
  right_Back.run(FORWARD);
  left_Front.run(BACKWARD);
  left_Back.run(BACKWARD);
  delay(1500);

  // Stop
  right_Front.run(RELEASE);
  right_Back.run(RELEASE);
  left_Front.run(RELEASE);
  left_Back.run(RELEASE);
  delay(1000);

  // Turn Right
  right_Front.run(BACKWARD);
  right_Back.run(BACKWARD);
  left_Front.run(FORWARD);
  left_Back.run(FORWARD);
  delay(1500);

  // Stop
  right_Front.run(RELEASE);
  right_Back.run(RELEASE);
  left_Front.run(RELEASE);
  left_Back.run(RELEASE);
  delay(1000);
}
