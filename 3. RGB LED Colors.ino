/*
Components Used:
- Arduino Board
- Sensor Shield
- RGB LED (Common Cathode)
- Breadboard
- Jumper Wires
*/

void setup() {
  pinMode(4, OUTPUT); // Set Red pin as output
  pinMode(5, OUTPUT); // Set Green pin as output
  pinMode(6, OUTPUT); // Set Blue pin as output
}

void loop() {
  // Red
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(1000);

  // Green
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(1000);

  // Blue
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(1000);

  // Yellow (Red + Green)
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(1000);

  // Cyan (Green + Blue)
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  delay(1000);

  // Magenta (Red + Blue)
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(1000);

  // White (Red + Green + Blue)
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  delay(1000);
}
