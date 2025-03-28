/*
Components Used:
- Arduino Board
- Sensor Shield
- RGB LED (Common Cathode)
- Bluetooth Module (HC-05)
- Breadboard
- Jumper Wires
*/

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX, TX

int redPin = 4;   // Red LED pin
int greenPin = 5; // Green LED pin
int bluePin = 6;  // Blue LED pin

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  BTSerial.begin(9600); // Start Bluetooth communication
  Serial.begin(9600);   // Start Serial Monitor
}

void loop() {
  if (BTSerial.available()) { // If data is received from the app
    int command = BTSerial.read(); // Read the received integer
    Serial.print("Received Command: ");
    Serial.println(command);

    // Red Color
    if (command == 1) {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      Serial.println("Red ON");
    }
    // Green Color
    else if (command == 2) {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
      Serial.println("Green ON");
    }
    // Blue Color
    else if (command == 3) {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
      Serial.println("Blue ON");
    }
    // Yellow Color (Red + Green)
    else if (command == 4) {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
      Serial.println("Yellow ON");
    }
    // Cyan Color (Green + Blue)
    else if (command == 5) {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, HIGH);
      Serial.println("Cyan ON");
    }
    // Magenta Color (Red + Blue)
    else if (command == 6) {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
      Serial.println("Magenta ON");
    }
    // White Color (All ON)
    else if (command == 7) {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, HIGH);
      Serial.println("White ON");
    }
    // OFF (All OFF)
    else if (command == 0) {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      Serial.println("RGB LED OFF");
    }
  }
}
