/*
Components Used:
- Arduino Board
- Sensor Shield
- LCD 16x2 with I2C Module
- Buzzer
- Breadboard
- Jumper Wires
*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address (0x27 or 0x3F), 16 columns, 2 rows

int buzzer = 8; // Buzzer connected to pin 8

void setup() {
  lcd.init();       // Initialize the LCD
  lcd.backlight();   // Turn on the backlight
  
  pinMode(buzzer, OUTPUT); // Set buzzer pin as output

  lcd.setCursor(0, 0);
  lcd.print("Countdown Timer");
}

void loop() {
  for (int i = 10; i >= 0; i--) {
    lcd.setCursor(0, 1);   // Move to second row
    lcd.print("Time: ");   // Print label
    lcd.print(i);          // Print countdown value
    lcd.print("   ");      // Clear extra digits
    delay(1000);           // Wait 1 second
  }
  
  lcd.setCursor(0, 1);
  lcd.print("Time Up!      "); // Display message after countdown

  // Buzzer beeps 3 times
  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
  }

  while (true); // Stop execution
}
