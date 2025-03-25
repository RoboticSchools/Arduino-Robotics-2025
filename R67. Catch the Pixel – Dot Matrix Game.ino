/*
Components Used:
- Arduino Board
- MAX7219 Dot Matrix Display
- Push Button
- Sensor Shield
- Jumper Wires
*/

#include <MD_Parola.h>
#include <MD_MAX72xx.h>

#define MAX_DEVICES 1  // Single dot matrix display
#define CS_PIN 10      // Chip Select pin
#define DATA_PIN 11    // Data pin
#define CLK_PIN 13     // Clock pin

#define BUTTON_PIN 2   // Button to catch the pixel

MD_Parola display = MD_Parola(MD_MAX72XX::FC16_HW, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

int position = 0;
int direction = 1;
int score = 0;
int mistakes = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  display.begin();
  display.setIntensity(5);
  display.displayClear();
}

void loop() {
  display.displayClear();
  display.setPoint(3, position, true);  // Middle row pixel
  display.displayAnimate();

  if (digitalRead(BUTTON_PIN) == LOW) {
    if (position == 3) {  // Middle position
      score++;
    } else {
      mistakes++;
    }
  }

  if (mistakes >= 3) {
    display.displayClear();
    display.print("LOSE ");
    delay(2000);
    mistakes = 0;
    score = 0;
  }

  position += direction;
  if (position == 7 || position == 0) direction = -direction;

  delay(200); // Adjust speed
}
