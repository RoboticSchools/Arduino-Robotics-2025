/*
Components Used:
- Arduino Board
- Sensor Shield
- Servo Motor
- Potentiometer
- Jumper Wires
*/

#include <Servo.h>

Servo myServo; // Create a Servo object
int potPin = A0;  // Potentiometer connected to A0
int servoPin = 9; // Servo connected to pin 9

void setup() {
  myServo.attach(servoPin); // Attach the servo to the sensor shield
}

void loop() {
  int potValue = analogRead(potPin); // Read potentiometer value (0-1023)
  int angle = map(potValue, 0, 1023, 0, 180); // Map value to servo angle (0-180)
  myServo.write(angle); // Move servo to the mapped angle
}
