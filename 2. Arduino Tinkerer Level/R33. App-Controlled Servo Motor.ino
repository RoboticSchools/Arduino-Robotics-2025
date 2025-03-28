/*
Components Used:
- Arduino Board
- Sensor Shield
- Servo Motor
- Bluetooth Module (HC-05)
- Breadboard
- Jumper Wires
*/

#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX (D2), TX (D3) for Bluetooth module
Servo myServo; 

int servoPin = 9; // Servo connected to pin 9

void setup() {
  myServo.attach(servoPin); // Attach servo to pin
  BTSerial.begin(9600);     // Start Bluetooth communication
  Serial.begin(9600);       // Start Serial Monitor
}

void loop() {
  if (BTSerial.available()) { // If data is received from the Bluetooth module
    int angle = BTSerial.parseInt(); // Read the received integer

    if (angle >= 0 && angle <= 180) { // Validate angle range
      myServo.write(angle); // Move servo to specified angle
      
      // Print received data to Serial Monitor
      Serial.print("Received angle: ");
      Serial.println(angle);
    } else {
      Serial.println("Enter a value between 0 and 180.");
    }
  }
}
