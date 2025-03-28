/*
Components Used:
- Arduino Board
- Sensor Shield
- Servo Motor
- Potentiometer
- Jumper Wires
*/

#include <Servo.h> // Include Servo library

Servo myServo; // Create a Servo object
int potPin = A0;  // Potentiometer connected to A0
int servoPin = 9; // Servo connected to pin 9

void setup() {
  myServo.attach(servoPin); // Attach the servo to the sensor shield
  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  int potValue = analogRead(potPin); // Read potentiometer value (0-1023)
  int angle = map(potValue, 0, 1023, 0, 180); // Map value to servo angle (0-180)
  
  myServo.write(angle); // Move servo to the mapped angle
  
  // Print values to Serial Monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" | Servo Angle: ");
  Serial.println(angle);

  delay(10); // Small delay to make Serial Monitor readable
}
