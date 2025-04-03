/*
Components Used:
- Arduino Board
- Adafruit Motor Shield
- DC Motor
- Bluetooth Module (HC-05)
- Potentiometer
- Breadboard
- Jumper Wires
*/

#include <SoftwareSerial.h>
#include <AFMotor.h>

SoftwareSerial BTSerial(2, 3); // RX, TX for Bluetooth communication
AF_DCMotor motor(1);  // Motor connected to M1 on Motor Shield
int potPin = A5;      // Potentiometer pin

// Default speed variable
int speedValue = 150;

void setup() {
  motor.setSpeed(speedValue);  // Initialize motor speed to 150
  motor.run(RELEASE);   // Ensure motor is stopped
  
  BTSerial.begin(9600); // Start Bluetooth communication
  Serial.begin(9600);   // Start Serial Monitor
}

void loop() {
  if (BTSerial.available()) { // If data is received from the app
    int command = BTSerial.read(); // Read the received integer

    if (command == 1) {
      motor.run(FORWARD); // Turn motor ON in forward direction
      Serial.println("Motor Running FORWARD");
    } 
    else if (command == 0) {
      motor.run(RELEASE); // Stop the motor
      Serial.println("Motor STOPPED");
    }
    else if (command >= 2 && command <= 255) { // If command is speed value
      speedValue = command;
      motor.setSpeed(speedValue);
      Serial.print("Motor Speed Set To: ");
      Serial.println(speedValue);
    }
  }
}
