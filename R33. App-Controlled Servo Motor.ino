/*
Components Used:
- Arduino Board
- Sensor Shield
- Servo Motor
- Bluetooth Module (HC-05 or HC-06)
  - TX to Arduino Pin 2
  - RX to Arduino Pin 3 (with voltage divider if needed)
- Breadboard
- Jumper Wires
*/

#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX
Servo myServo; 

int servoPin = 9; // Servo connected to pin 9
int angle;        // Variable to store servo angle

void setup() {
  myServo.attach(servoPin); // Attach servo to pin
  BTSerial.begin(9600);     // Start Bluetooth communication
}

void loop() {
  if (BTSerial.available()) { // If data is received from the app
    int command = BTSerial.parseInt(); // Read the received integer

    // Map received value (0-100) to servo angle (0-180)
    angle = map(command, 0, 100, 0, 180);
    myServo.write(angle); // Move servo to mapped angle
  }
}
