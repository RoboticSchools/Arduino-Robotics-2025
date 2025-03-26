/*
Components Used:
- Arduino Board
- Sensor Shield
- IR Receiver Module (Connected to Sensor Shield)
- RGB LED (Common Cathode)
- Remote Control
- Jumper Wires
*/

#include <IRremote.h>

// Define IR receiver pin
int irReceivePin = 8;  

// Define RGB LED pins
int redPin = 6;
int greenPin = 5;
int bluePin = 3;

// Define IR remote button codes
int irButtonRed = 12;       // Button for Red LED
int irButtonGreen = 24;     // Button for Green LED
int irButtonBlue = 94;      // Button for Blue LED
int irButtonOff = 64;       // Button to turn off all LEDs

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(redPin, OUTPUT);   // Set Red LED pin as output
  pinMode(greenPin, OUTPUT); // Set Green LED pin as output
  pinMode(bluePin, OUTPUT);  // Set Blue LED pin as output

  IrReceiver.begin(irReceivePin); // Start IR receiver
}

void loop() {
  // Check if IR signal is received
  if (IrReceiver.decode()) {
    int command = IrReceiver.decodedIRData.command; // Store the received command
    Serial.println(command);
    IrReceiver.resume();  // Prepare IR receiver for next signal

    // Check which button was pressed and control the RGB LED accordingly
    if (command == irButtonRed) {
      Serial.println("Red LED ON");
      digitalWrite(redPin, HIGH);   // Turn ON Red LED
      digitalWrite(greenPin, LOW);  // Turn OFF Green LED
      digitalWrite(bluePin, LOW);   // Turn OFF Blue LED
    } 
    else if (command == irButtonGreen) {
      Serial.println("Green LED ON");
      digitalWrite(redPin, LOW);   // Turn OFF Red LED
      digitalWrite(greenPin, HIGH); // Turn ON Green LED
      digitalWrite(bluePin, LOW);  // Turn OFF Blue LED
    } 
    else if (command == irButtonBlue) {
      Serial.println("Blue LED ON");
      digitalWrite(redPin, LOW);   // Turn OFF Red LED
      digitalWrite(greenPin, LOW);  // Turn OFF Green LED
      digitalWrite(bluePin, HIGH); // Turn ON Blue LED
    } 
    else if (command == irButtonOff) {
      Serial.println("RGB LED OFF");
      digitalWrite(redPin, LOW);   // Turn OFF Red LED
      digitalWrite(greenPin, LOW);  // Turn OFF Green LED
      digitalWrite(bluePin, LOW);  // Turn OFF Blue LED
    } 
    else {
      Serial.println("Button not recognized"); // Handle unknown button presses
    }
  }
}
