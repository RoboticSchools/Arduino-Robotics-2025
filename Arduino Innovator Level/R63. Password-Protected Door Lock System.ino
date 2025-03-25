/*
Components used:
- Arduino Board
- Sensor Shield
- 4x4 Keypad
- Servo Motor
- LCD Display (I2C)
- Jumper Wires
*/

#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Define LCD address and size
LiquidCrystal_I2C lcd(0x27, 16, 2);

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

// Servo motor for locking mechanism
Servo doorLock;
int servoPin = 10; // Servo connected to pin 10

// Password settings
String password = "1234"; // Set password
String inputPassword = ""; // Store entered password

void setup() {
  lcd.begin(16, 2);   // Initialize LCD
  lcd.backlight();    // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");

  doorLock.attach(servoPin); // Attach servo motor
  doorLock.write(0); // Lock position
}

void loop() {
  char key = keypad.getKey(); // Read key press

  if (key) {
    if (key == '#') {
      // Check password when '#' is pressed
      lcd.clear();
      lcd.setCursor(0, 0);
      
      if (inputPassword == password) {
        lcd.print("Access Granted");
        doorLock.write(90); // Unlock door
        delay(3000);
        doorLock.write(0); // Lock again
      } else {
        lcd.print("Access Denied");
      }

      inputPassword = ""; // Reset input
      delay(2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password:");
    } 
    else if (key == '*') {
      // Clear input when '*' is pressed
      inputPassword = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password:");
    } 
    else {
      // Store entered key
      inputPassword += key;
      lcd.setCursor(0, 1);
      lcd.print(inputPassword);
    }
  }
}
