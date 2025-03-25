/*
Components Used:
- Arduino Board
*/

void setup() {
  Serial.begin(9600);  // Start serial communication
  pinMode(13, OUTPUT); // LED on pin 13
}

void loop() {
  if (Serial.available()) {
    char receivedChar = Serial.read(); // Read the received character

    if (receivedChar == '1') {
      digitalWrite(13, HIGH); // Turn LED ON
      Serial.println("LED ON");
    } 
    else if (receivedChar == '0') {
      digitalWrite(13, LOW); // Turn LED OFF
      Serial.println("LED OFF");
    }
  }
}
