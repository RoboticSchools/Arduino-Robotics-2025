/*
Components Used:
- Arduino Board
- Sensor Shield
- IR Receiver Module
- LED
- Remote Control
- Jumper Wires
*/

#include <IRremote.h>

int irReceivePin = 8;  // IR receiver connected to Sensor Shield
int ledPin = 6;        // LED connected to Sensor Shield

// IR remote button codes
int irButtonOn = 12;
int irButtonOff = 24;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  IrReceiver.begin(irReceivePin);  // Start IR receiver
}

void loop() {
  if (IrReceiver.decode()) {
    int command = IrReceiver.decodedIRData.command;
    Serial.println(command);
    IrReceiver.resume();  // Continue receiving IR signals

    if (command == irButtonOn) {
      Serial.println("LED ON");
      digitalWrite(ledPin, HIGH);  // Turn LED on
    } 
    else if (command == irButtonOff) {
      Serial.println("LED OFF");
      digitalWrite(ledPin, LOW);   // Turn LED off
    } 
    else {
      Serial.println("Button not recognized");
    }
  }
}
