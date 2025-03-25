/*
Components Used:
- Arduino Board
- Sensor Shield
- Push Button
- LED
- Breadboard
- Jumper Wires
*/

const int buttonPin = 7; // Button connected to Pin 7
const int ledPin = 8;    // LED connected to Pin 8

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set Button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);          // Set LED pin as output
}

void loop() {
  if (digitalRead(buttonPin) == 0) {  // Check if button is pressed (Active LOW)
    digitalWrite(ledPin, HIGH);         // Turn on LED
  } else {
    digitalWrite(ledPin, LOW);          // Turn off LED
  }
}
