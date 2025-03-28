/*
Components Used:
- Arduino Board
- Sensor Shield
- Push Button
- LED
- Breadboard
- Jumper Wires
*/

int buttonPin = 7; // Button connected to Pin 7
int ledPin = 8;    // LED connected to Pin 8

bool ledState = false; // LED state

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set Button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);          // Set LED pin as output
  Serial.begin(9600);               // Initialize Serial Monitor at 9600 baud
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // If button is pressed
    delay(100); // Simple debounce
    while (digitalRead(buttonPin) == LOW); // Wait for button release
    ledState = !ledState; // Toggle LED state
    digitalWrite(ledPin, ledState); // Update LED

    // Print LED state to Serial Monitor
    if (ledState) {
      Serial.println("LED ON");
    } else {
      Serial.println("LED OFF");
    }
  }
}
