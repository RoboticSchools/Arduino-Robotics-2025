/*
Components used:
- Arduino Board
- Sensor Shield
- 8x8 Dot Matrix Display (MAX7219)
- Jumper Wires
*/

#include <MD_Parola.h>
#include <MD_MAX72XX.h>
#include <SPI.h>

// Define hardware type and number of devices
#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 1 // Number of 8x8 matrix modules

// Define SPI pins for MAX7219 (connected to Sensor Shield)
#define DATA_PIN 12
#define CLK_PIN  11
#define CS_PIN   10

// Initialize Parola display
MD_Parola matrix = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  matrix.begin();  // Initialize display
  matrix.setIntensity(5); // Set brightness (0-15)
  matrix.displayClear();  // Clear display
}

void loop() {
  // Scroll text on the matrix
  if (matrix.displayAnimate() == true) {
    matrix.displayText("HELLO", PA_CENTER, 100, 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
  }
}
