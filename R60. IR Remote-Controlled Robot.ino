/*
Components used:
- Arduino Board
- IR Receiver Module (Connected to Sensor Shield)
- Adafruit Motor Shield
- 4 DC Motors
*/

#include <IRremote.h>
#include <AFMotor.h>

// Define IR receiver pin
#define IR_RECEIVE_PIN 8  

// Define motor connections
AF_DCMotor right_Front(1);
AF_DCMotor right_Back(2);
AF_DCMotor left_Front(3);
AF_DCMotor left_Back(4);

// Define IR remote button codes
#define IR_FORWARD 12    // Button for moving forward
#define IR_BACKWARD 24   // Button for moving backward
#define IR_LEFT 94       // Button for turning left
#define IR_RIGHT 8       // Button for turning right
#define IR_STOP 64       // Button to stop the robot

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  IrReceiver.begin(IR_RECEIVE_PIN); // Start IR receiver

  // Set motor speed
  right_Front.setSpeed(150);
  right_Back.setSpeed(150);
  left_Front.setSpeed(150);
  left_Back.setSpeed(150);
}

void loop() {
  // Check if IR signal is received
  if (IrReceiver.decode()) {
    int command = IrReceiver.decodedIRData.command; // Store received command
    IrReceiver.resume();  // Prepare IR receiver for next signal

    // Check which button was pressed and move the robot accordingly
    if (command == IR_FORWARD) {
      Serial.println("Moving Forward");
      right_Front.run(FORWARD);
      right_Back.run(FORWARD);
      left_Front.run(FORWARD);
      left_Back.run(FORWARD);
    } 
    else if (command == IR_BACKWARD) {
      Serial.println("Moving Backward");
      right_Front.run(BACKWARD);
      right_Back.run(BACKWARD);
      left_Front.run(BACKWARD);
      left_Back.run(BACKWARD);
    } 
    else if (command == IR_LEFT) {
      Serial.println("Turning Left");
      right_Front.run(FORWARD);
      right_Back.run(FORWARD);
      left_Front.run(BACKWARD);
      left_Back.run(BACKWARD);
    } 
    else if (command == IR_RIGHT) {
      Serial.println("Turning Right");
      right_Front.run(BACKWARD);
      right_Back.run(BACKWARD);
      left_Front.run(FORWARD);
      left_Back.run(FORWARD);
    } 
    else if (command == IR_STOP) {
      Serial.println("Stopping");
      right_Front.run(RELEASE);
      right_Back.run(RELEASE);
      left_Front.run(RELEASE);
      left_Back.run(RELEASE);
    } 
    else {
      Serial.println("Button not recognized"); // Handle unknown button presses
    }
  }
}
