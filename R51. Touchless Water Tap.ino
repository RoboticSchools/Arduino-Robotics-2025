/*
Components Used:
- Arduino Board
- Adafruit Motor Shield
- IR Sensor
- Water Pump
- Breadboard
- Jumper Wires
*/

#include <AFMotor.h>

// Define motor and pump objects
AF_DCMotor waterPump(1);  // Motor connected to port 1 of the motor shield

int irSensorPin = 3;  // IR Sensor connected to pin 3
int irSensorValue = 0;  // Variable to store IR sensor reading

void setup() {
  waterPump.setSpeed(150);  // Set speed of the water pump
  pinMode(irSensorPin, INPUT);  // Set IR sensor pin as input
}

void loop() {
  irSensorValue = digitalRead(irSensorPin);  // Read the value from IR sensor

  if (irSensorValue == HIGH) {
    // If IR sensor detects an object, turn on the water pump for 3 seconds
    waterPump.run(FORWARD);  // Activate water pump
    delay(3000);  // Keep pump on for 3 seconds
    waterPump.run(RELEASE);  // Stop water pump
  }
  else {
    // If no object is detected, ensure the water pump is off
    waterPump.run(RELEASE);  // Stop water pump
  }
}
