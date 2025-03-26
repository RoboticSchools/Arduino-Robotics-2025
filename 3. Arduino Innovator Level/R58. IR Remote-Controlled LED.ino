/*
Components used:
- Arduino Board
- Sensor Shield
- IR Receiver Module
- LED
- Remote Control
- Jumper Wires
*/

#include <IRremote.h>

#define IR_RECEIVE_PIN 8  // IR receiver connected to Sensor Shield
#define LED_PIN 6         // LED connected to Sensor Shield

// IR remote button codes
#define IR_BUTTON_ON 12
#define IR_BUTTON_OFF 24

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output
  IrReceiver.begin(IR_RECEIVE_PIN);  // Start IR receiver
}

void loop() {
  if (IrReceiver.decode()) {
    int command = IrReceiver.decodedIRData.command;
    Serial.println(command);
    IrReceiver.resume();  // Continue receiving IR signals

    if (command == IR_BUTTON_ON) {
      Serial.println("LED ON");
      digitalWrite(LED_PIN, HIGH);  // Turn LED on
    } 
    else if (command == IR_BUTTON_OFF) {
      Serial.println("LED OFF");
      digitalWrite(LED_PIN, LOW);   // Turn LED off
    } 
    else {
      Serial.println("Button not recognized");
    }
  }
}
