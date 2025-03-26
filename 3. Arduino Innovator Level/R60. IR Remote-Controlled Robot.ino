/*
Components Used:
- Arduino Board
- IR Receiver Module (Connected to Sensor Shield)
- Adafruit Motor Shield
- 4 DC Motors
*/

#include <IRremote.h>
#include <AFMotor.h>

// Define IR receiver pin
int irReceivePin = 8;  

// Define motor connections
AF_DCMotor rightFront(1);
AF_DCMotor rightBack(2);
AF_DCMotor leftFront(3);
AF_DCMotor leftBack(4);

// Define IR remote button codes
int irForward = 12;    // Button for moving forward
int irBackward = 24;   // Button for moving backward
int irLeft = 94;       // Button for turning left
int irRight = 8;       // Button for turning right
int irStop = 64;       // Button to stop the robot

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  IrReceiver.begin(irReceivePin); // Start IR receiver

  // Set motor speed
  rightFront.setSpeed(150);
  rightBack.setSpeed(150);
  leftFront.setSpeed(150);
  leftBack.setSpeed(150);
}

void loop() {
  // Check if IR signal is received
  if (IrReceiver.decode()) {
    int command = IrReceiver.decodedIRData.command; // Store received command
    Serial.println(command);
    IrReceiver.resume();  // Prepare IR receiver for next signal

    // Check which button was pressed and move the robot accordingly
    if (command == irForward) {
      Serial.println("Moving Forward");
      rightFront.run(FORWARD);
      rightBack.run(FORWARD);
      leftFront.run(FORWARD);
      leftBack.run(FORWARD);
    } 
    else if (command == irBackward) {
      Serial.println("Moving Backward");
      rightFront.run(BACKWARD);
      rightBack.run(BACKWARD);
      leftFront.run(BACKWARD);
      leftBack.run(BACKWARD);
    } 
    else if (command == irLeft) {
      Serial.println("Turning Left");
      rightFront.run(FORWARD);
      rightBack.run(FORWARD);
      leftFront.run(BACKWARD);
      leftBack.run(BACKWARD);
    } 
    else if (command == irRight) {
      Serial.println("Turning Right");
      rightFront.run(BACKWARD);
      rightBack.run(BACKWARD);
      leftFront.run(FORWARD);
      leftBack.run(FORWARD);
    } 
    else if (command == irStop) {
      Serial.println("Stopping");
      rightFront.run(RELEASE);
      rightBack.run(RELEASE);
      leftFront.run(RELEASE);
      leftBack.run(RELEASE);
    } 
    else {
      Serial.println("Button not recognized"); // Handle unknown button presses
    }
  }
}
