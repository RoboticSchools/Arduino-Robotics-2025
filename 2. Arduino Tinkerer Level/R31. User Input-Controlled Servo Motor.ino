/*
Components Used:
- Arduino Board
- Sensor Shield
- Servo Motor
- Jumper Wires
*/

#include <Servo.h> // Include Servo library

Servo myServo; // Create a Servo object to control the servo motor

void setup() {
  myServo.attach(9);  // Attach the servo to pin 9 on the sensor shield
  myServo.write(0);   // Set initial position to 0 degrees
  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  // Check if data is available in the Serial buffer
  if (Serial.available() > 0) { 
    int angle = Serial.parseInt();  // Read the received angle from Serial input

    // Check if the received angle is within the valid range (0 to 180 degrees)
    if (angle >= 0 && angle <= 180) { 
      myServo.write(angle); // Move servo to the specified angle
      Serial.print("Servo moved to: ");
      Serial.println(angle); // Print the new angle to the Serial Monitor
    } else {
      Serial.println("Invalid angle! Enter a value between 0 and 180.");
    }

    // Clear any leftover characters in the Serial buffer to avoid unwanted reads
    Serial.read(); 
  }
}
