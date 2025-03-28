/*
Components Used:
- Arduino Board
- Sensor Shield
- LCD 16x2 with I2C Module
- Jumper Wires
*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address (0x27 or 0x3F), 16 columns, 2 rows

void setup() {
  lcd.init();       // Initialize the LCD
  lcd.backlight();   // Turn on the backlight

  lcd.setCursor(0, 0);   // Set cursor to first row
  lcd.print("Hello");    // Display "Hello"

  lcd.setCursor(0, 1);   // Set cursor to second row
  lcd.print("RoboticSchools"); // Display "RoboticSchools"
}

void loop() {
  // No repeated actions needed
}
