/*
Components Used:
- Arduino Board
- Motor Shield
- Soil Moisture Sensor
- Water Pump
- Breadboard
- Jumper Wires
*/

#include <AFMotor.h>

AF_DCMotor pump(1);  // Water pump connected to Motor Shield
int moisturePin = A0;  // Soil moisture sensor connected to Analog Pin A0

void setup() {
  pinMode(moisturePin, INPUT);  // Set moisture sensor as input
  pump.setSpeed(150);           // Set pump speed
  Serial.begin(9600);           // Initialize serial communication
}

void loop() {
  int moistureValue = analogRead(moisturePin);  // Read soil moisture level
  Serial.print("Soil Moisture: ");
  Serial.println(moistureValue);

  // Run pump until moisture level exceeds 500
  while (moistureValue < 500) {
    pump.run(FORWARD);  // Start pump
    Serial.println("Pump ON");
    delay(200);  // Short delay to avoid rapid sensor reads
    moistureValue = analogRead(moisturePin);  // Read updated sensor value
  }

  pump.run(RELEASE);  // Stop pump when moisture level is sufficient
  Serial.println("Pump OFF");

  delay(1000);  // Wait before next check
}
