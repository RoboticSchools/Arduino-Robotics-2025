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

int redLED = 4;    // Red LED connected to Pin 4
int yellowLED = 5; // Yellow LED connected to Pin 5
int greenLED = 6;  // Green LED connected to Pin 6

void setup() {
  pinMode(redLED, OUTPUT);    // Set Red LED pin as output
  pinMode(yellowLED, OUTPUT); // Set Yellow LED pin as output
  pinMode(greenLED, OUTPUT);  // Set Green LED pin as output
}

void loop() {
  digitalWrite(redLED, HIGH);    // Turn on Red LED
  digitalWrite(yellowLED, LOW);  // Ensure Yellow LED is off
  digitalWrite(greenLED, LOW);   // Ensure Green LED is off
  delay(5000);                   // Wait for 5 seconds

  digitalWrite(redLED, LOW);     // Turn off Red LED
  digitalWrite(yellowLED, HIGH); // Turn on Yellow LED
  digitalWrite(greenLED, LOW);   // Ensure Green LED is off
  delay(2000);                   // Wait for 2 seconds

  digitalWrite(redLED, LOW);     // Ensure Red LED is off
  digitalWrite(yellowLED, LOW);  // Turn off Yellow LED
  digitalWrite(greenLED, HIGH);  // Turn on Green LED
  delay(5000);                   // Wait for 5 seconds
}
