/*
Components Used:
- Arduino Board
- Sensor Shield
- Servo Motor
- Jumper Wires
*/

#include <Servo.h>

Servo myServo; // Create a Servo object

void setup() {
  myServo.attach(9);  // Attach the servo to pin 9 on the sensor shield
  myServo.write(0);
  Serial.begin(9600); // Start serial communication
}

void loop() {
  if (Serial.available() > 0) { // Check if data is received
    int angle = Serial.parseInt();  // Read the received angle

    if (angle >= 0 && angle <= 180) { // Validate angle range
      myServo.write(angle); // Move servo to the given angle
      Serial.print("Servo moved to: ");
      Serial.println(angle);
    } else {
      Serial.println("Invalid angle! Enter a value between 0 and 180.");
    }

    // Clear Serial buffer to avoid accidental reads
    while (Serial.available() > 0) Serial.read(); 
  }
}
