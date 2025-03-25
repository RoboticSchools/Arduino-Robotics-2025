/*
Components used:
- Arduino Board
- Sensor Shield
- 4x4 Keypad
- LED
- Jumper Wires
*/

#include <Keypad.h>

// Define keypad rows and columns
const byte ROWS = 4;  
const byte COLS = 4;  

// Define the key layout
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define keypad row and column pins (connected to sensor shield)
byte rowPins[ROWS] = {9, 8, 7, 6};  
byte colPins[COLS] = {5, 4, 3, 2};  

// Initialize the Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int ledPin = 13; // LED connected to pin 13

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  Serial.begin(9600);       // Initialize serial communication
}

void loop() {
  char key = keypad.getKey(); // Read key press

  if (key) { 
    Serial.print("Key Pressed: ");
    Serial.println(key);

    // Turn LED ON if '1' is pressed
    if (key == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    } 
    // Turn LED OFF if '0' is pressed
    else if (key == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
  }
}
