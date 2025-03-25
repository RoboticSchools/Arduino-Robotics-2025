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

Servo doorServo;  // Create a Servo object to control the door

int irSensorPin = 2;   // IR sensor connected to Pin 2 on the Sensor Shield (Digital Pin 2)
int servoPin = 9;      // Servo motor connected to Pin 9 on the Sensor Shield (PWM Pin)

void setup() {
  doorServo.attach(servoPin);  // Attach the servo to the specified pin
  pinMode(irSensorPin, INPUT); // Set IR sensor pin as input

  doorServo.write(0);  // Close the door initially (0 degrees)
  Serial.begin(9600);  // Start serial communication (optional for debugging)
}

void loop() {
  int sensorValue = digitalRead(irSensorPin);  // Read the IR sensor's value

  // If object is detected (sensor value is LOW, as most IR sensors give LOW output when detecting)
  if (sensorValue == LOW) {
    Serial.println("Object Detected - Opening Door");
    doorServo.write(90);  // Open the door (90 degrees)
  } else {
    Serial.println("No Object - Closing Door");
    doorServo.write(0);   // Close the door (0 degrees)
  }

  delay(500);  // Small delay to avoid constant opening/closing
}
