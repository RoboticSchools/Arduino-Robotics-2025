
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

int ledPin = 8;      // LED connected to Pin 8

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  BTSerial.begin(9600);    // Start Bluetooth communication
}

void loop() {
  if (BTSerial.available()) { // If data is received from the app
    int command = BTSerial.parseInt(); // Read the received integer

    if (command == 1) {
      digitalWrite(ledPin, HIGH); // Turn LED ON
    } 
    else if (command == 0) {
      digitalWrite(ledPin, LOW);  // Turn LED OFF
    }
  }
}
