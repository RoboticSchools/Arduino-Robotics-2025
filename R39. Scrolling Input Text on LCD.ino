/*
Components Used:
- Arduino Board
- Sensor Shield
- LCD 16x2 with I2C Module
- Breadboard
- Jumper Wires
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address (0x27 or 0x3F), 16 columns, 2 rows

void setup() {
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Enter text:");
}

void loop() {
  if (Serial.available()) {
    String text = Serial.readStringUntil('\n'); // Read input text
    text.trim(); // Remove extra spaces

    lcd.clear();
    lcd.setCursor(16, 0); // Start from the rightmost position
    lcd.print(text);

    // Scroll text from right to left
    for (int i = 0; i < text.length() + 16; i++) {
      lcd.scrollDisplayLeft();
      delay(300);
    }
  }
}
