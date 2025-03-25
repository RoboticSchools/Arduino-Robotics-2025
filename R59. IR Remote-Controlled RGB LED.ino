/*
Components used:
- Arduino Board
- Sensor Shield
- IR Receiver Module (Connected to Sensor Shield)
- RGB LED (Common Cathode)
- Remote Control
- Jumper Wires
*/

#include <IRremote.h>

// Define IR receiver pin
#define IR_RECEIVE_PIN 8  

// Define RGB LED pins
#define RED_PIN 6
#define GREEN_PIN 5
#define BLUE_PIN 3

// Define IR remote button codes
#define IR_BUTTON_RED 12       // Button for Red LED
#define IR_BUTTON_GREEN 24     // Button for Green LED
#define IR_BUTTON_BLUE 94      // Button for Blue LED
#define IR_BUTTON_OFF 64       // Button to turn off all LEDs

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(RED_PIN, OUTPUT);   // Set Red LED pin as output
  pinMode(GREEN_PIN, OUTPUT); // Set Green LED pin as output
  pinMode(BLUE_PIN, OUTPUT);  // Set Blue LED pin as output

  IrReceiver.begin(IR_RECEIVE_PIN); // Start IR receiver
}

void loop() {
  // Check if IR signal is received
  if (IrReceiver.decode()) {
    int command = IrReceiver.decodedIRData.command; // Store the received command
    IrReceiver.resume();  // Prepare IR receiver for next signal

    // Check which button was pressed and control the RGB LED accordingly
    if (command == IR_BUTTON_RED) {
      Serial.println("Red LED ON");
      digitalWrite(RED_PIN, HIGH);   // Turn ON Red LED
      digitalWrite(GREEN_PIN, LOW);  // Turn OFF Green LED
      digitalWrite(BLUE_PIN, LOW);   // Turn OFF Blue LED
    } 
    else if (command == IR_BUTTON_GREEN) {
      Serial.println("Green LED ON");
      digitalWrite(RED_PIN, LOW);   // Turn OFF Red LED
      digitalWrite(GREEN_PIN, HIGH); // Turn ON Green LED
      digitalWrite(BLUE_PIN, LOW);  // Turn OFF Blue LED
    } 
    else if (command == IR_BUTTON_BLUE) {
      Serial.println("Blue LED ON");
      digitalWrite(RED_PIN, LOW);   // Turn OFF Red LED
      digitalWrite(GREEN_PIN, LOW);  // Turn OFF Green LED
      digitalWrite(BLUE_PIN, HIGH); // Turn ON Blue LED
    } 
    else if (command == IR_BUTTON_OFF) {
      Serial.println("RGB LED OFF");
      digitalWrite(RED_PIN, LOW);   // Turn OFF Red LED
      digitalWrite(GREEN_PIN, LOW);  // Turn OFF Green LED
      digitalWrite(BLUE_PIN, LOW);  // Turn OFF Blue LED
    } 
    else {
      Serial.println("Button not recognized"); // Handle unknown button presses
    }
  }
}
