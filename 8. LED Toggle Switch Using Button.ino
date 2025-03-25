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

bool ledState = false; // LED state

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set Button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);          // Set LED pin as output
}

void loop() {
  if (digitalRead(buttonPin) == 0) { // If button is pressed
    delay(200); // Simple debounce
    while (digitalRead(buttonPin) == 0); // Wait for button release
    ledState = !ledState; // Toggle LED state
    digitalWrite(ledPin, ledState); // Update LED
  }
}
