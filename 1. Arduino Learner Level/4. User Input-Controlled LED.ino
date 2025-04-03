/*
Components Used:
- Arduino Board
- Sensor Shield
- LED
- Breadboard
- Jumper Wires
*/

int ledPin = 7; // LED connected to Pin 7

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600);      // Start serial communication
}

void loop() {
  if (Serial.available() > 0) {  // Check if data is received
    char input = Serial.read();  // Read the input character

    if (input == '1') {          
      digitalWrite(ledPin, HIGH); // Turn on LED
      Serial.println("LED ON");
    } 
    else if (input == '0') {     
      digitalWrite(ledPin, LOW);  // Turn off LED
      Serial.println("LED OFF");
    }
  }
}
