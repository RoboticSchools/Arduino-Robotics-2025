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
  Serial.begin(9600); // Start serial communication
}

void loop() {
  if (Serial.available() > 0) {  // Check if data is received
    char input = Serial.read();  // Read the input character

    // Turn off all LEDs first
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);

    // Check input and turn on corresponding color
    if (input == 'R' || input == 'r') {
      digitalWrite(4, HIGH);  // Red
      Serial.println("Red ON");
    } 
    else if (input == 'G' || input == 'g') {
      digitalWrite(5, HIGH);  // Green
      Serial.println("Green ON");
    } 
    else if (input == 'B' || input == 'b') {
      digitalWrite(6, HIGH);  // Blue
      Serial.println("Blue ON");
    } 
    else if (input == 'Y' || input == 'y') {
      digitalWrite(4, HIGH);  // Yellow (Red + Green)
      digitalWrite(5, HIGH);
      Serial.println("Yellow ON");
    } 
    else if (input == 'C' || input == 'c') {
      digitalWrite(5, HIGH);  // Cyan (Green + Blue)
      digitalWrite(6, HIGH);
      Serial.println("Cyan ON");
    } 
    else if (input == 'M' || input == 'm') {
      digitalWrite(4, HIGH);  // Magenta (Red + Blue)
      digitalWrite(6, HIGH);
      Serial.println("Magenta ON");
    } 
    else if (input == 'W' || input == 'w') {
      digitalWrite(4, HIGH);  // White (Red + Green + Blue)
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      Serial.println("White ON");
    } 
    else {
      Serial.println("Invalid Input! Use R, G, B, Y, C, M, W.");
    }
  }
}
