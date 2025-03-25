/*
Components Used:
- Arduino Board
- Sensor Shield
- DC Motor (Controlled via Motor Driver)
- Servo Motor
- 3 Push Buttons (DC Motor ON, DC Motor OFF, Servo Start/Stop)
- Breadboard
- Jumper Wires
*/

#include <Servo.h>

Servo fanServo;  // Create a Servo object
int servoPin = 9;  // Servo connected to Pin 9
int motorPin = 6;  // DC Motor connected to Pin 6

// Button pins
int buttonOn = 2;     // DC Motor ON button
int buttonOff = 3;    // DC Motor OFF button
int buttonServo = 4;  // Servo Start/Stop button

bool servoRunning = false; // Flag to control servo movement

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(buttonOn, INPUT_PULLUP);
  pinMode(buttonOff, INPUT_PULLUP);
  pinMode(buttonServo, INPUT_PULLUP);
  
  fanServo.attach(servoPin); // Attach servo
}

void loop() {
  // DC Motor Control
  if (digitalRead(buttonOn) == LOW) {
    digitalWrite(motorPin, HIGH); // Turn DC Motor ON
  } 
  if (digitalRead(buttonOff) == LOW) {
    digitalWrite(motorPin, LOW); // Turn DC Motor OFF
  }

  // Toggle Servo Rotation on Button Press
  if (digitalRead(buttonServo) == LOW) {
    delay(200); // Debounce delay
    while (digitalRead(buttonServo) == LOW); // Wait for button release
    servoRunning = !servoRunning; // Toggle servo state
  }

  // If servo is running, rotate from 0 to 180 and back
  if (servoRunning) {
    for (int angle = 0; angle <= 180; angle++) {
      fanServo.write(angle);
      delay(10);
    }
    for (int angle = 180; angle >= 0; angle--) {
      fanServo.write(angle);
      delay(10);
    }
  }
}
