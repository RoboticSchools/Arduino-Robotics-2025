/*
Components Used:
- Arduino Board
- Sensor Shield
- 2 Push Buttons
- LED
- Breadboard
- Jumper Wires
*/

int buttonOnPin = 6;  // Button 1 to turn LED ON
int buttonOffPin = 7; // Button 2 to turn LED OFF
int ledPin = 8;       // LED connected to Pin 8

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
