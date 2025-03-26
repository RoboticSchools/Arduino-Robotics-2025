
#include <LiquidCrystal_I2C.h>

#define BUTTON1 7  // Button for Option A
#define BUTTON2 6  // Button for Option B

LiquidCrystal_I2C lcd(0x27, 16, 2);

int correctAnswer;
int optionA, optionB;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  randomSeed(analogRead(0));
  generateQuestion();  // Start with the first question
}

void loop() {
  if (digitalRead(BUTTON1) == LOW) checkAnswer(optionA);
  if (digitalRead(BUTTON2) == LOW) checkAnswer(optionB);
}

// Function: Generate a random addition question
void generateQuestion() {
  int num1 = random(1, 10);
  int num2 = random(1, 10);
  correctAnswer = num1 + num2;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(num1);
  lcd.print(" + ");
  lcd.print(num2);
  lcd.print(" = ?");

  generateOptions();  // Show answer options
}

// Function: Generate and display two answer options
void generateOptions() {
  int wrongAnswer;

  do {
    wrongAnswer = correctAnswer + random(-5, 6);  // Ensure it's not same
  } while (wrongAnswer == correctAnswer);

  if (random(2) == 0) {
    optionA = correctAnswer;
    optionB = wrongAnswer;
  } else {
    optionA = wrongAnswer;
    optionB = correctAnswer;
  }

  lcd.setCursor(0, 1);
  lcd.print("A:");
  lcd.print(optionA);
  lcd.print("    B:");
  lcd.print(optionB);
}

// Function: Check selected answer and display result
void checkAnswer(int selected) {
  lcd.clear();
  lcd.setCursor(0, 0);

  if (selected == correctAnswer) {
    lcd.print("Correct!");
  } else {
    lcd.print("Wrong!");
  }

  delay(2000);  // Pause before next question
  generateQuestion();
}
