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
  Serial.begin(9600);                  // Initialize Serial Monitor at 9600 baud
}

void loop() {
  if (digitalRead(buttonOnPin) == LOW) {  // If Button 1 is pressed
    digitalWrite(ledPin, HIGH);            // Turn on LED
    Serial.println("Button ON Pressed - LED ON");
    delay(200);  // Debounce delay
  }
  
  if (digitalRead(buttonOffPin) == LOW) { // If Button 2 is pressed
    digitalWrite(ledPin, LOW);             // Turn off LED
    Serial.println("Button OFF Pressed - LED OFF");
    delay(200);  // Debounce delay
  }
}
