/*
Components Used:
- Arduino Board
- Adafruit Motor Shield
- DC Motor
- Bluetooth Module (HC-05 or HC-06)
- Potentiometer (A5 for Speed Control)
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

  // Read speed from potentiometer and map it to 0-255 range
  int speedValue = analogRead(potPin);
  speedValue = map(speedValue, 0, 1023, 0, 255);
  motor.setSpeed(speedValue); // Adjust motor speed
}
