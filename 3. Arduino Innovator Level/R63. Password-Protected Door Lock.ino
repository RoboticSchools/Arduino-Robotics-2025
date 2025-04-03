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

// Define keypad row and column pins
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// Initialize keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Servo motor for locking mechanism
Servo doorLock;
int servoPin = 10;

// Password variables
String password = "1234";
String inputPassword = "";

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");

  doorLock.attach(servoPin);
  doorLock.write(0); // Lock position
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    // 1. Add key to input and show on LCD
    if (key != '#' && key != '*') {
      inputPassword += key;
      lcd.setCursor(0, 1);
      lcd.print(inputPassword);
    }

    // 2. Submit password
    else if (key == '#') {
      lcd.clear();
      lcd.setCursor(0, 0);

      if (inputPassword == password) {
        lcd.print("Access Granted");
        doorLock.write(90); // Unlock
        delay(3000);
        doorLock.write(0);  // Lock again
      } else {
        lcd.print("Access Denied");
      }

      inputPassword = ""; // Reset
      delay(2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password:");
    }

    // 3. Clear input
    else if (key == '*') {
      inputPassword = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password:");
    }
  }
}

