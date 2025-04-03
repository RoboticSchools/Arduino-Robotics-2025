/*
Components Used:
- Arduino Board
- MAX7219 Dot Matrix Display
- Bluetooth Module (HC-05)
- Sensor Shield
- Jumper Wires
*/

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SoftwareSerial.h>

#define MAX_DEVICES 4  // Number of cascaded LED matrix modules
#define CS_PIN 10       // Chip Select pin for MAX7219
#define DATA_PIN 11     // Data pin for MAX7219
#define CLK_PIN 13      // Clock pin for MAX7219

SoftwareSerial BTSerial(2, 3);  // Bluetooth module RX, TX

MD_Parola display = MD_Parola(MD_MAX72XX::FC16_HW, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  
  display.begin();
  display.setIntensity(5);  // Adjust brightness (0-15)
  display.displayClear();
  display.displayText("READY", PA_CENTER, 50, 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}

void loop() {
  if (BTSerial.available()) {
    String message = BTSerial.readStringUntil('\n');  // Read input from app
    
    if (message.length() > 0) {
      display.displayClear();
      display.displayText(message.c_str(), PA_CENTER, 50, 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
    }
  }
}
