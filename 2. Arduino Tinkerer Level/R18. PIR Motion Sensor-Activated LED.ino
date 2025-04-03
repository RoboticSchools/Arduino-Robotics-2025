/*
Components Used:
- Arduino Board
- Sensor Shield
- PIR Motion Sensor
- LED
- Breadboard
- Jumper Wires
*/

int pirPin = 3;  // PIR sensor connected to Pin 3 (Digital)
int ledPin = 4;  // LED connected to Pin 4

void setup() {
  pinMode(pirPin, INPUT);   // Set PIR sensor pin as input
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  Serial.begin(9600);       // Start Serial Monitor
}

void loop() {
  int motionState = digitalRead(pirPin); // Read PIR sensor value

  if (motionState == 1) {  // If motion is detected
    digitalWrite(ledPin, HIGH); // Turn ON LED
    Serial.println("Motion Detected - LED ON");
  } else {  // If no motion
    digitalWrite(ledPin, LOW);  // Turn OFF LED
    Serial.println("No Motion - LED OFF");
  }

  delay(100); // Small delay to avoid excessive serial output
}
