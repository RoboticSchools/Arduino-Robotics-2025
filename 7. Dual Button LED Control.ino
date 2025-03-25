/*
Components Used:
- Arduino Board
- Sensor Shield
- 2 Push Button
- LED
- Breadboard
- Jumper Wires
*/

const int buttonOnPin = 7;  // Button 1 to turn LED ON
const int buttonOffPin = 6; // Button 2 to turn LED OFF
const int ledPin = 8;       // LED connected to Pin 8

void setup() {
  pinMode(buttonOnPin, INPUT_PULLUP);  // Set Button 1 as input with internal pull-up resistor
  pinMode(buttonOffPin, INPUT_PULLUP); // Set Button 2 as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);             // Set LED pin as output
}

void loop() {
  if (digitalRead(buttonOnPin) == 0) {  // If Button 1 is pressed
    digitalWrite(ledPin, HIGH);           // Turn on LED
  }
  if (digitalRead(buttonOffPin) == 0) { // If Button 2 is pressed
    digitalWrite(ledPin, LOW);            // Turn off LED
  }
}
