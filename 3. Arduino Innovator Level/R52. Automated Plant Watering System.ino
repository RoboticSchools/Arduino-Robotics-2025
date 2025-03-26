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

// Motor shield pin for water pump
AF_DCMotor pump(1);  

// Soil moisture sensor pin
int moisturePin = A0;  

void setup() {
  pinMode(moisturePin, INPUT);  // Soil moisture sensor input
  pump.setSpeed(150);           // Set pump speed
  Serial.begin(9600);           // Serial monitor for moisture values
}

void loop() {
  int moistureValue = analogRead(moisturePin);  // Read soil moisture level
  Serial.print("Soil Moisture: ");
  Serial.println(moistureValue);

  if (moistureValue < 500) {
    pump.run(FORWARD);  // Turn on pump if soil is dry
    delay(3000);        // Pump for 3 seconds
    pump.run(RELEASE);  // Stop pump
  }

  delay(5000);  // Wait before checking again
}
