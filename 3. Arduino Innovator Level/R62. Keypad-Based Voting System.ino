/*
Components used:
- Arduino Board
- Sensor Shield
- 4x4 Keypad
- LCD Display (I2C)
- Jumper Wires
*/

#include <LiquidCrystal_I2C.h>

#include <Keypad.h>

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
int voteA = 0, voteB = 0, voteC = 0, voteD = 0; 

void setup() {
  lcd.init();   // Initialize LCD
  lcd.backlight();    // Turn on backlight
  
  lcd.setCursor(0, 0);
  lcd.print("Get Ready");
  lcd.setCursor(0, 1);
  lcd.print("to Vote!");
  delay(2000);
  lcd.clear();
  
  introVote();
}

void introVote()
{
  lcd.setCursor(0, 0);
  lcd.print("Vote A    Vote B");
  lcd.setCursor(0, 1);
  lcd.print("Vote C    Vote D");
}

void loop() {
  char key = keypad.getKey(); // Read key press

  if (key) {
    lcd.clear();
    lcd.setCursor(0, 0);

    // Record votes based on key press
    if (key == 'A') {
      voteA++;
      lcd.print("Voted A");
    } 
    else if (key == 'B') {
      voteB++;
      lcd.print("Voted B");
    } 
    else if (key == 'C') {
      voteC++;
      lcd.print("Voted C");
    }
    else if (key == 'D') {
      voteD++;
      lcd.print("Voted D");
    }
    
    else if (key == '#') {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("A : " + String(voteA) + "    B : " + String(voteB));
      lcd.setCursor(0, 1);
      lcd.print("C : " + String(voteC) + "    D : " + String(voteD));
      
      delay(3000); 
      
      // Find max vote using max()
      int maxVote = max(max(voteA, voteB), max(voteC, voteD));

      // Check who all have the max vote
      String winner = "";

      if (voteA == maxVote) winner += "A ";
      if (voteB == maxVote) winner += "B ";
      if (voteC == maxVote) winner += "C ";
      if (voteD == maxVote) winner += "D ";

      // Display winner(s)
      lcd.clear();
      lcd.print("Winner(s) : " + winner);

      while (1); // Halt
    }

    delay(3000); // Delay for display
    lcd.clear();
    lcd.setCursor(0, 0);
    introVote();
  }
}
