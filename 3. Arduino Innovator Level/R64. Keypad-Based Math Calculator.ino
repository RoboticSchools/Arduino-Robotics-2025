#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// Define LCD address and size
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define keypad rows and columns
const byte ROWS = 4;
const byte COLS = 4;

// Define the key layout
char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};

// Define keypad row and column pins (connected to sensor shield)
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// Initialize the Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Variables for calculations
String input = "";
char operation;
int num1 = 0, num2 = 0;

void setup() {
  lcd.init();   // Initialize LCD
  lcd.backlight();    // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey(); // Read key press

  if (key) {
    if (key >= '0' && key <= '9') {
      // Store numbers
      lcd.print(key);
      input += key;
    } 
    else if (key == '+' || key == '-' || key == '*' || key == '/') {
      // Store first number and operation
      num1 = input.toInt();
      operation = key;
      input = "";
      lcd.print(operation);
    } 
    else if (key == '=') {
      // Store second number and perform calculation
      num2 = input.toInt();
      float result = 0;
      
      if (operation == '+') result = num1 + num2;
      else if (operation == '-') result = num1 - num2;
      else if (operation == '*') result = num1 * num2;
      else if (operation == '/' && num2 != 0) result = num1 / num2;

      lcd.setCursor(0, 1);
      lcd.print("= ");
      lcd.print(result);
      
      input = "";
      delay(3000);
      lcd.clear();
    } 
    else if (key == 'C') {
      // Clear input and reset
      input = "";
      lcd.clear();
    }
  }
}
