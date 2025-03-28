/*
Components Used:
- Arduino Board
- Sensor Shield
- RGB LED (Common Cathode)
- Breadboard
- Jumper Wires
*/

// Define RGB LED pins
int redPin = 4;    // Red pin connected to digital pin 4
int greenPin = 5;  // Green pin connected to digital pin 5
int bluePin = 6;   // Blue pin connected to digital pin 6

void setup() {
  // Configure RGB LED pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Check if data is available in the serial buffer
  if (Serial.available() > 0) {  
    char input = Serial.read();  // Read the received character

    // Control RGB LED based on received input character
    if (input == 'R' || input == 'r') {
      digitalWrite(redPin, HIGH);  // Turn on Red LED
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      Serial.println("Red ON");
    } else if (input == 'G' || input == 'g') {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);  // Turn on Green LED
      digitalWrite(bluePin, LOW);
      Serial.println("Green ON");
    } else if (input == 'B' || input == 'b') {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);  // Turn on Blue LED
      Serial.println("Blue ON");
    } else if (input == 'Y' || input == 'y') {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, HIGH);  // Turn on Yellow (Red + Green)
      digitalWrite(bluePin, LOW);
      Serial.println("Yellow ON");
    } else if (input == 'C' || input == 'c') {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);  // Turn on Cyan (Green + Blue)
      digitalWrite(bluePin, HIGH);
      Serial.println("Cyan ON");
    } else if (input == 'M' || input == 'm') {
      digitalWrite(redPin, HIGH);  // Turn on Magenta (Red + Blue)
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
      Serial.println("Magenta ON");
    } else if (input == 'W' || input == 'w') {
      digitalWrite(redPin, HIGH);  // Turn on White (Red + Green + Blue)
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, HIGH);
      Serial.println("White ON");
    }
  }
}
