/*
Components Used:
- Arduino Board
- Sensor Shield
- Red LED 
- Yellow LED
- Green LED
- Breadboard
- Jumper Wires
*/

void setup() {
  pinMode(4, OUTPUT); // Set Red LED pin as output
  pinMode(5, OUTPUT); // Set Yellow LED pin as output
  pinMode(6, OUTPUT); // Set Green LED pin as output
}

void loop() {
  digitalWrite(4, HIGH); // Turn on Red LED (Pin 4)
  digitalWrite(5, LOW);  // Ensure Yellow LED (Pin 5) is off
  digitalWrite(6, LOW);  // Ensure Green LED (Pin 6) is off
  delay(5000);           // Wait for 5 seconds

  digitalWrite(4, LOW);  // Turn off Red LED (Pin 4)
  digitalWrite(5, HIGH); // Turn on Yellow LED (Pin 5)
  digitalWrite(6, LOW);  // Ensure Green LED (Pin 6) is off
  delay(2000);           // Wait for 2 seconds

  digitalWrite(4, LOW);  // Ensure Red LED (Pin 4) is off
  digitalWrite(5, LOW);  // Turn off Yellow LED (Pin 5)
  digitalWrite(6, HIGH); // Turn on Green LED (Pin 6)
  delay(5000);           // Wait for 5 seconds
}
