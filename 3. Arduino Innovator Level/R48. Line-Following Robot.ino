/*
Components Used:
- Arduino Board
- Sensor Shield
- 2 IR Sensors (LDR)
- 4 DC Motors (Motor Shield)
- Breadboard
- Jumper Wires
*/

#include <AFMotor.h>

// Define motor objects connected to motor shield
AF_DCMotor right_Front(1);  // Right front motor
AF_DCMotor right_Back(2);   // Right back motor
AF_DCMotor left_Front(3);   // Left front motor
AF_DCMotor left_Back(4);    // Left back motor

// Define sensor pins for left and right IR sensors
int rightSensor = A0;  // Right light sensor pin
int leftSensor = A5;   // Left light sensor pin

void setup() {
  pinMode(rightSensor, INPUT);  // Set right sensor pin as input
  pinMode(leftSensor, INPUT);   // Set left sensor pin as input

  // Set motor speeds
  right_Front.setSpeed(150);  
  right_Back.setSpeed(150);   
  left_Front.setSpeed(150);   
  left_Back.setSpeed(150);    
}

void loop() {
  // Read values from the right and left sensors
  int rightValue = digitalRead(rightSensor);  
  int leftValue = digitalRead(leftSensor);

  // If both sensors do not detect black line, move forward
  if (leftValue == 0 && rightValue == 0) {
    right_Front.run(FORWARD);
    right_Back.run(FORWARD);
    left_Front.run(FORWARD);
    left_Back.run(FORWARD);
  } 
  // If right sensor detects line, turn left
  else if (leftValue == 0 && rightValue == 1) {
    right_Front.run(FORWARD);
    right_Back.run(FORWARD);
    left_Front.run(BACKWARD);
    left_Back.run(BACKWARD);
  } 
  // If left sensor detects line, turn right
  else if (leftValue == 1 && rightValue == 0) {
    right_Front.run(BACKWARD);
    right_Back.run(BACKWARD);
    left_Front.run(FORWARD);
    left_Back.run(FORWARD);
  } 
  // If both sensors detect the black line, stop the robot
  else {
    right_Front.run(RELEASE);
    right_Back.run(RELEASE);
    left_Front.run(RELEASE);
    left_Back.run(RELEASE);
  }
}
