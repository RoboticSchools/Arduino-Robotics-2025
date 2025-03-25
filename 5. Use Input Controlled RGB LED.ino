/*
Components Used:
- Arduino Board
- Sensor Shield
- RGB LED (Common Cathode)
- Breadboard
- Jumper Wires
*/

int redPin = 4;   // Red pin connected to Pin 4
int greenPin = 5; // Green pin connected to Pin 5
int bluePin = 6;  // Blue pin connected to Pin 6

void setup() {
  pinMode(redPin, OUTPUT);   // Set Red pin as output
  pinMode(greenPin, OUTPUT); // Set Green pin as output
  pinMode(bluePin, OUTPUT);  // Set Blue pin as output
  Serial.begin(9600);        // Start serial communication
}

void loop() {
  if (Serial.available() > 0) {  // Check if data is received
    char input = Serial.read();  // Read the input character

    // Turn off all LEDs first
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);

    // Check input and turn on corresponding color
    if (input == 'R' || input == 'r') {
      digitalWrite(redPin, HIGH);  // Red
      Serial.println("Red ON");
    } 
    else if (input == 'G' || input == 'g') {
      digitalWrite(greenPin, HIGH);  // Green
      Serial.println("Green ON");
    } 
    else if (input == 'B' || input == 'b') {
      digitalWrite(bluePin, HIGH);  // Blue
      Serial.println("Blue ON");
    } 
    else if (input == 'Y' || input == 'y') {
      digitalWrite(redPin, HIGH);  // Yellow (Red + Green)
      digitalWrite(greenPin, HIGH);
      Serial.println("Yellow ON");
    } 
    else if (input == 'C' || input == 'c') {
      digitalWrite(greenPin, HIGH);  // Cyan (Green + Blue)
      digitalWrite(bluePin, HIGH);
      Serial.println("Cyan ON");
    } 
    else if (input == 'M' || input == 'm') {
      digitalWrite(redPin, HIGH);  // Magenta (Red + Blue)
      digitalWrite(bluePin, HIGH);
      Serial.println("Magenta ON");
    } 
    else if (input == 'W' || input == 'w') {
      digitalWrite(redPin, HIGH);  // White (Red + Green + Blue)
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, HIGH);
      Serial.println("White ON");
    } 
    else {
      Serial.println("Invalid Input! Use R, G, B, Y, C, M, W.");
    }
  }
}
