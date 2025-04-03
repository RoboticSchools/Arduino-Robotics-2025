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
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Enter text:");
}

void loop() {
  if (Serial.available()) {
    lcd.clear();
    delay(100); 

    String text = Serial.readStringUntil('\n'); // Read input until newline

    if (text.length() <= 16) {
      lcd.setCursor(0, 0);
      lcd.print(text); // Display on row 1 only if ≤ 16 characters
    }
  }
}
