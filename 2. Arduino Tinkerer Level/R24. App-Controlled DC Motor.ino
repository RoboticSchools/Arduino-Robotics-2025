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

SoftwareSerial BTSerial(2, 3); // RX, TX
AF_DCMotor motor(1);  // Motor connected to M1 on Motor Shield
int potPin = A5;      // Potentiometer pin

void setup() {
  motor.setSpeed(0);  // Initialize motor speed to 0
  motor.run(RELEASE); // Ensure motor is stopped
  BTSerial.begin(9600); // Start Bluetooth communication
}

void loop() {
  if (BTSerial.available()) { // If data is received from the app
    int command = BTSerial.parseInt(); // Read the received integer

    if (command == 1) {
      motor.run(FORWARD); // Turn motor ON in forward direction
    } 
    else if (command == 0) {
      motor.run(RELEASE); // Stop the motor
    }
  }

  int speedValue = analogRead(potPin);
  motor.setSpeed(speedValue);
}
