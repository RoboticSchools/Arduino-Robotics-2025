/*
Components used:
- Arduino Board
- Adafruit Motor Shield
- Water pump
- Soil moisture sensor
- Bluetooth HC05
*/

#include <AFMotor.h>
#include <SoftwareSerial.h>

// Motor shield pin for water pump
AF_DCMotor pump(1);

// Soil moisture sensor pin
int moisturePin = A0;

// Bluetooth communication pins
SoftwareSerial BTSerial(9, 10);  // RX, TX for Bluetooth module

// Variables for reading sensor and controlling pump
int moistureValue = 0;
char receivedData;  // For Bluetooth data

void setup() {
  pinMode(moisturePin, INPUT);  // Soil moisture sensor input
  pump.setSpeed(150);           // Set pump speed
  BTSerial.begin(9600);         // Bluetooth serial communication
  Serial.begin(9600);           // Serial monitor for moisture values
}

void loop() {
  // Read soil moisture value
  moistureValue = analogRead(moisturePin);  
  Serial.print("Soil Moisture: ");
  Serial.println(moistureValue);

  // Send sensor value to app
  BTSerial.print("Moisture: ");
  BTSerial.println(moistureValue);

  // Check if app sends control command (example: '1' for ON, '0' for OFF)
  if (BTSerial.available()) {
    receivedData = BTSerial.read();
    if (receivedData == '1') {
      pump.run(FORWARD);  // Turn on pump (app command)
    }
      while(receivedData != '0');
      pump.run(RELEASE);
  }

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
