/*
Components used:
- Arduino Board
- Sensor Shield
- 4x4 Keypad
- LCD Display (I2C)
- Jumper Wires
*/

#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

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

// Voting counters
int voteA = 0, voteB = 0, voteC = 0;

void setup() {
  lcd.begin(16, 2);   // Initialize LCD
  lcd.backlight();    // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.print("Vote: 1-A 2-B 3-C");
}

void loop() {
  char key = keypad.getKey(); // Read key press

  if (key) {
    lcd.clear();
    lcd.setCursor(0, 0);

    // Record votes based on key press
    if (key == '1') {
      voteA++;
      lcd.print("Vote A: ");
      lcd.print(voteA);
    } 
    else if (key == '2') {
      voteB++;
      lcd.print("Vote B: ");
      lcd.print(voteB);
    } 
    else if (key == '3') {
      voteC++;
      lcd.print("Vote C: ");
      lcd.print(voteC);
    } 
    else if (key == '#') {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("A:");
      lcd.print(voteA);
      lcd.print(" B:");
      lcd.print(voteB);
      lcd.setCursor(0, 1);
      lcd.print("C:");
      lcd.print(voteC);
    }

    delay(1000); // Delay for display
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vote: 1-A 2-B 3-C");
  }
}
