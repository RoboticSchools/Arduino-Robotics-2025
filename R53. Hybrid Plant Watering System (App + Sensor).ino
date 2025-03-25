

#include <AFMotor.h>
#include <SoftwareSerial.h>

// Motor shield pin for water pump
AF_DCMotor pump(1);

// Soil moisture sensor pin
int moisturePin = A0;

// Bluetooth communication pins
SoftwareSerial BTSerial(10, 11);  // RX, TX for Bluetooth module

// Moisture threshold for watering
int threshold = 500;

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
    else if (receivedData == '0') {
      pump.run(RELEASE);  // Turn off pump (app command)
    }
  }

  // Automatic watering based on soil moisture
  if (moistureValue < threshold) {
    pump.run(FORWARD);  // Turn on pump if soil is dry
    delay(3000);         // Pump for 3 seconds
    pump.run(RELEASE);   // Stop pump
  }

  delay(5000);  // Wait before checking again
}
