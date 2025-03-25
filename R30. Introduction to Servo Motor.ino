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
  myServo.attach(9); // Attach the servo to pin 9 on the sensor shield
}

void loop() {
  myServo.write(0);   // Rotate to 0 degrees
  delay(1000);        // Wait for 1 second
  
  myServo.write(90);  // Rotate to 90 degrees
  delay(1000);        // Wait for 1 second
  
  myServo.write(180); // Rotate to 180 degrees
  delay(1000);        // Wait for 1 second
}
