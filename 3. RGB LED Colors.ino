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
}

void loop() {
  // Red
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  delay(1000);

  // Green
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW);
  delay(1000);

  // Blue
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH);
  delay(1000);

  // Yellow (Red + Green)
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW);
  delay(1000);

  // Cyan (Green + Blue)
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
  delay(1000);

  // Magenta (Red + Blue)
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH);
  delay(1000);

  // White (Red + Green + Blue)
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
  delay(1000);
}
