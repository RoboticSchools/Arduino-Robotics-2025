/*
Components Used:
- Arduino Board
- Sensor Shield
- 2 LDR Sensors (Configured with Pull-down Resistors)
- Servo Motor
- Breadboard
- Jumper Wires
*/

#include <Servo.h>

Servo sunflowerServo;   // Create a Servo object
int servoPin = 9;       // Servo motor connected to Pin 9

int rightSensor = 2;    // Right LDR sensor connected to digital pin 2
int leftSensor = 3;     // Left LDR sensor connected to digital pin 3

int servoAngle = 90;    // Start at the center position (90 degrees)

void setup() {
  pinMode(rightSensor, INPUT); // Set right LDR as input
  pinMode(leftSensor, INPUT);  // Set left LDR as input
  sunflowerServo.attach(servoPin);  // Attach the servo to the pin
  sunflowerServo.write(servoAngle); // Set initial position
  delay(500);
}

void loop() {
  int rightLDR = digitalRead(rightSensor); // Read right LDR sensor
  int leftLDR = digitalRead(leftSensor);   // Read left LDR sensor

  if (rightLDR == 1 && leftLDR == 0 && servoAngle < 180) {  
    // Move right if right sensor detects more light
    servoAngle++;
  } 
  else if (leftLDR == 1 && rightLDR == 0 && servoAngle > 0) {  
    // Move left if left sensor detects more light
    servoAngle--;
  }

  sunflowerServo.write(servoAngle); // Move servo to new position
  delay(50);  // Small delay for smooth movement
}
