/*
Components Used:
- Arduino Board
- Sensor Shield
- LED
- Bluetooth Module (HC-05 or HC-06)
- Breadboard
- Jumper Wires
*/

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX, TX

int ledPin = 9; // LED connected to PWM Pin 9

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  BTSerial.begin(9600);    // Start Bluetooth communication
}

void loop() {
  if (BTSerial.available()) { // If data is received from the app
    int command = BTSerial.parseInt(); // Read the received integer

    if (command == 1) {
      analogWrite(ledPin, 255); // Turn LED ON (Full Brightness)
    } 
    else if (command == 0) {
      analogWrite(ledPin, 0);  // Turn LED OFF
    } 
    else if (command >= 2 && command <= 255) { 
      analogWrite(ledPin, command); // Adjust LED brightness (2-255)
    }
  }
}
