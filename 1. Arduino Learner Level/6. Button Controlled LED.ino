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

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set Button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);          // Set LED pin as output
  Serial.begin(9600);               // Initialize Serial Monitor at 9600 baud
}

void loop() {
  int buttonState = digitalRead(buttonPin); // Read button state
  
  if (buttonState == LOW) {  // Check if button is pressed (Active LOW)
    digitalWrite(ledPin, HIGH);  // Turn on LED
    Serial.println("Button Pressed - LED ON");
  } else {
    digitalWrite(ledPin, LOW);   // Turn off LED
    Serial.println("Button Released - LED OFF");
  }
  
  delay(100); // Add slight delay to avoid excessive serial output
}
