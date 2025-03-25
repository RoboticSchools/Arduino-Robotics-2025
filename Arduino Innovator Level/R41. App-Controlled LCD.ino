/*
Components Used:
- Arduino Board
- Sensor Shield
- LCD 16x2 with I2C Module
- Bluetooth Module (HC-05 or HC-06) or Serial Monitor
- Breadboard
- Jumper Wires
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address (0x27 or 0x3F), 16 columns, 2 rows

String receivedText = ""; // Store received text

void setup() {
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600); // Start Serial Communication (for Bluetooth or Serial Monitor)

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Waiting for text...");
}

void loop() {
  if (Serial.available()) {  // Check if data is received
    receivedText = Serial.readStringUntil('\n'); // Read input until newline
    
    receivedText.trim(); // Remove leading/trailing spaces

    if (receivedText.length() <= 16) { // Display only if <= 16 characters
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(receivedText);
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Text too long!");
    }
  }
}
