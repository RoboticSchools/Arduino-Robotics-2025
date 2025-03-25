/*
Components Used:
- Arduino Board
- Sensor Shield
- LED
- Breadboard
- Jumper Wires
*/

void setup() {
  pinMode(13, OUTPUT);  // Set LED pin as output
  Serial.begin(9600);   // Start serial communication
}

void loop() {
  if (Serial.available() > 0) {  // Check if data is received
    char input = Serial.read();  // Read the input character

    if (input == '1') {          
      digitalWrite(13, HIGH);    // Turn on LED (Pin 13)
      Serial.println("LED ON");
    } 
    else if (input == '0') {     
      digitalWrite(13, LOW);     // Turn off LED (Pin 13)
      Serial.println("LED OFF");
    }
  }
}
