/*
Components Used:
- Arduino Board
- Sensor Shield
- IR Sensor
- Servo Motor
- Breadboard
- Jumper Wires
*/

#include <Servo.h>

Servo doorServo;  // Servo object for door control

int irSensorPin = 2;   // IR sensor connected to Digital Pin 2
int servoPin = 9;      // Servo motor connected to PWM Pin 9

void setup() {
  doorServo.attach(servoPin);  // Attach servo motor to pin
  pinMode(irSensorPin, INPUT); // Set IR sensor as input

  doorServo.write(0);  // Start with the door closed
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  int sensorValue = digitalRead(irSensorPin);  // Read IR sensor state

  if (sensorValue == 0) {  // If object detected
    Serial.println("Object Detected - Opening Door");
    doorServo.write(90);  // Open door
  } else {
    Serial.println("No Object - Closing Door");
    doorServo.write(0);   // Close door
  }

  delay(500);  // Short delay to prevent rapid changes
}
