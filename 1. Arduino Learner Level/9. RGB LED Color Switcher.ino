/*
Components Used:
- Arduino Board
- Sensor Shield
- Push Button
- RGB LED (Common Cathode)
- Breadboard
- Jumper Wires
*/

int redPin = 4;     // Red LED pin
int greenPin = 5;   // Green LED pin
int bluePin = 6;    // Blue LED pin
int buttonPin = 7;  // Button connected to Pin 7

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set button as input with internal pull-up resistor
  pinMode(redPin, OUTPUT);   // Set Red pin as output
  pinMode(greenPin, OUTPUT); // Set Green pin as output
  pinMode(bluePin, OUTPUT);  // Set Blue pin as output
  randomSeed(analogRead(0)); // Seed the random function
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // If button is pressed
    delay(100); // Simple debounce
    while (digitalRead(buttonPin) == LOW); // Wait for button release
    
    int redState = random(2);   // Random 0 or 1 for Red
    int greenState = random(2); // Random 0 or 1 for Green
    int blueState = random(2);  // Random 0 or 1 for Blue

    digitalWrite(redPin, redState);
    digitalWrite(greenPin, greenState);
    digitalWrite(bluePin, blueState);
  }
}
