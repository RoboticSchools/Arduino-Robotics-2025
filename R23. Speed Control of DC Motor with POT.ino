/*
Components Used:
- Arduino Board
- Sensor Shield
- Adafruit Motor Shield
- DC Motor
- Potentiometer (A5)
- 3 Push Buttons (Forward, Reverse, Stop)
- Breadboard
- Jumper Wires
*/

#include <AFMotor.h>

AF_DCMotor motor(1);  // Motor connected to M1 on the shield

int potPin = A5;      // Potentiometer connected to A5
int forwardButton = 2; // Forward button
int reverseButton = 3; // Reverse button
int stopButton = 4;    // Stop button

void setup() {
  pinMode(forwardButton, INPUT_PULLUP);
  pinMode(reverseButton, INPUT_PULLUP);
  pinMode(stopButton, INPUT_PULLUP);

  motor.setSpeed(0);   // Initialize motor speed to 0
  motor.run(RELEASE);  // Start with motor stopped
}

void loop() {
  int potValue = analogRead(potPin);      // Read potentiometer value (0-1023)
  int motorSpeed = map(potValue, 0, 1023, 0, 255); // Convert to motor speed (0-255)

  if (digitalRead(forwardButton) == LOW) {
    motor.setSpeed(motorSpeed); // Set motor speed
    motor.run(FORWARD);         // Run motor forward
  } 
  else if (digitalRead(reverseButton) == LOW) {
    motor.setSpeed(motorSpeed); // Set motor speed
    motor.run(BACKWARD);        // Run motor in reverse
  } 
  else if (digitalRead(stopButton) == LOW) {
    motor.setSpeed(0);  // Stop motor
    motor.run(RELEASE);
  }
}
