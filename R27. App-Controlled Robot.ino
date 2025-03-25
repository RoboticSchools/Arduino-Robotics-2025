/*
Components Used:
- Arduino Board
- Adafruit Motor Shield
- Bluetooth Module (HC-05 or HC-06)
- 4 DC Motors
- Breadboard
- Jumper Wires
*/

#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX

// Define motor objects
AF_DCMotor right_Front(1);
AF_DCMotor right_Back(2);
AF_DCMotor left_Front(3);
AF_DCMotor left_Back(4);

// Default speed variable
int speedValue = 150;

void setup() {
  BTSerial.begin(9600); // Start Bluetooth communication

  right_Front.setSpeed(speedValue);
  right_Back.setSpeed(speedValue);
  left_Front.setSpeed(speedValue);
  left_Back.setSpeed(speedValue);
}

void loop() {
  if (BTSerial.available()) {
    int command = BTSerial.parseInt(); // Read the received integer

    if (command == 1) {
      // Move Forward
      right_Front.run(FORWARD);
      right_Back.run(FORWARD);
      left_Front.run(FORWARD);
      left_Back.run(FORWARD);
    } 
    else if (command == 2) {
      // Move Backward
      right_Front.run(BACKWARD);
      right_Back.run(BACKWARD);
      left_Front.run(BACKWARD);
      left_Back.run(BACKWARD);
    } 
    else if (command == 3) {
      // Turn Left
      right_Front.run(FORWARD);
      right_Back.run(FORWARD);
      left_Front.run(RELEASE);
      left_Back.run(RELEASE);
    } 
    else if (command == 4) {
      // Turn Right
      right_Front.run(RELEASE);
      right_Back.run(RELEASE);
      left_Front.run(FORWARD);
      left_Back.run(FORWARD);
    } 
    else if (command == 0) {
      // Stop
      right_Front.run(RELEASE);
      right_Back.run(RELEASE);
      left_Front.run(RELEASE);
      left_Back.run(RELEASE);
    } 
    else if (command >= 10 && command <= 255) {
      // Adjust Speed directly
      speedValue = command;
      right_Front.setSpeed(speedValue);
      right_Back.setSpeed(speedValue);
      left_Front.setSpeed(speedValue);
      left_Back.setSpeed(speedValue);
    }
  }
}
