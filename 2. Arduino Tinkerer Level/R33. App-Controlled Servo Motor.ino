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

void setup() {
  myServo.attach(servoPin); // Attach servo to pin
  BTSerial.begin(9600);     // Start Bluetooth communication
}

void loop() {
  if (BTSerial.available()) { // If data is received from the app
    int angle = BTSerial.parseInt(); // Read the received integer
    myServo.write(angle); // Move servo to mapped angle
  }
}
