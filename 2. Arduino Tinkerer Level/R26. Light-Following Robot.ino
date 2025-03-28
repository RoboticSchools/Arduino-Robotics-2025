/*
Components Used:
- Arduino Board
- Adafruit Motor Shield
- 2 Light Sensors (LDR)
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

// Define sensor pins
int rightSensor = A0;
int leftSensor = A5;

void setup() {
  pinMode(rightSensor, INPUT);
  pinMode(leftSensor, INPUT);

  right_Front.setSpeed(150);
  right_Back.setSpeed(150);
  left_Front.setSpeed(150);
  left_Back.setSpeed(150);
}

void loop() {
  int rightValue = digitalRead(rightSensor);
  int leftValue = digitalRead(leftSensor);

  if (leftValue == 0 && rightValue == 0) {
    // Move Forward
    right_Front.run(FORWARD);
    right_Back.run(FORWARD);
    left_Front.run(FORWARD);
    left_Back.run(FORWARD);
  } 
  else if (leftValue == 0 && rightValue == 1) {
    // Turn Left
    right_Front.run(FORWARD);
    right_Back.run(FORWARD);
    left_Front.run(BACKWARD);
    left_Back.run(BACKWARD);
  } 
  else if (leftValue == 1 && rightValue == 0) {
    // Turn Right
    right_Front.run(BACKWARD);
    right_Back.run(BACKWARD);
    left_Front.run(FORWARD);
    left_Back.run(FORWARD);
  } 
  else {
    // Stop
    right_Front.run(RELEASE);
    right_Back.run(RELEASE);
    left_Front.run(RELEASE);
    left_Back.run(RELEASE);
  }
}
