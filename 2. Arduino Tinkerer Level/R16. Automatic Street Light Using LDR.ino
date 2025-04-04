/*
Components Used:
- Arduino Board
- Sensor Shield
- LDR (Light Dependent Resistor)
- LED
- Breadboard
- Jumper Wires
*/

int ldrPin = 3;  // LDR connected to Pin 3 (Digital)
int ledPin = 4;  // LED connected to Pin 4

void setup() {
  pinMode(ldrPin, INPUT);   // Set LDR pin as input
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  Serial.begin(9600);       // Start Serial Monitor
}

void loop() {
  int ldrState = digitalRead(ldrPin); // Read LDR value

  if (ldrState == 1) {  // If it's dark
    digitalWrite(ledPin, HIGH); // Turn on the LED (Street Light)
    Serial.println("Dark Detected - LED ON");
  } else {  // If there's light
    digitalWrite(ledPin, LOW);  // Turn off the LED
    Serial.println("Light Detected - LED OFF");
  }

  delay(100); // Small delay for readability
}
