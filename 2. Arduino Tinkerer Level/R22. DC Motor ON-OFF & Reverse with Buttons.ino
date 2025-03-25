/*
Components Used:
- Arduino Board
- Adafruit Motor Shield
- DC Motor
- 3 Push Buttons (ON, OFF, REVERSE)
- Breadboard
- Jumper Wires
*/

#include <AFMotor.h>

AF_DCMotor motor(1);  // Motor connected to M1 on the shield

int buttonOn = A0;      // ON button pin
int buttonOff = A1;     // OFF button pin
int buttonRev = A2;     // REVERSE button pin

void setup() {
  pinMode(buttonOn, INPUT_PULLUP);
  pinMode(buttonOff, INPUT_PULLUP);
  pinMode(buttonRev, INPUT_PULLUP);
  motor.setSpeed(255);  // Set maximum speed (0-255)
}

void loop() {
  if (digitalRead(buttonOn) == 0) {
    motor.run(FORWARD);  // Run motor forward
  } 
  else if (digitalRead(buttonOff) == 0) {
    motor.run(RELEASE);  // Stop motor
  } 
  else if (digitalRead(buttonRev) == 0) {
    motor.run(BACKWARD);  // Run motor in reverse
  }
}
