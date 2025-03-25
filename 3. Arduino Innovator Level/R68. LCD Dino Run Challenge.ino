/*
Components Used:
- Arduino Board
- I2C LCD Display
- Push Button (Jump)
- Sensor Shield
- Jumper Wires
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDR 0x27  // LCD I2C address
#define LCD_COLS 16
#define LCD_ROWS 2
#define BUTTON_PIN 2   // Jump button

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

bool isJumping = false;
int obstaclePos = LCD_COLS - 1;
int score = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Dino: ");
  lcd.setCursor(6, 1);
  lcd.print(isJumping ? " " : "O"); // Dino on the ground or jumping

  lcd.setCursor(obstaclePos, 1);
  lcd.print("#"); // Obstacle

  if (digitalRead(BUTTON_PIN) == LOW) {
    isJumping = true;
  } else {
    isJumping = false;
  }

  if (obstaclePos == 6 && !isJumping) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Game Over!");
    delay(2000);
    obstaclePos = LCD_COLS - 1;
    score = 0;
  } else {
    score++;
  }

  lcd.setCursor(0, 0);
  lcd.print("Score: ");
  lcd.print(score);

  obstaclePos--;
  if (obstaclePos < 0) {
    obstaclePos = LCD_COLS - 1;
  }

  delay(300);
}
