/*
Components Used:
- Arduino Board
- Sensor Shield
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- Breadboard
- Jumper Wires
*/

int trigPin = 9;     // Trigger pin of HC-SR04
int echoPin = 10;    // Echo pin of HC-SR04
int servoPin = 3;    // Servo Motor pin

#include <Servo.h>

Servo dustbinServo;  // Create a Servo object for controlling the dustbin lid

void setup() {
  Serial.begin(9600);   // Start serial communication
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  dustbinServo.attach(servoPin);  // Attach the servo motor to the servo pin
  dustbinServo.write(0);   // Close the lid initially
}

void loop() {
  long duration;
  float distance;

  // Send a 10µs pulse to trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Convert time to distance (Speed of sound = 343 m/s)
  distance = (duration * 0.0343) / 2;  // Distance in cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If the object is closer than 20 cm, open the dustbin lid
  if (distance < 20) {
    dustbinServo.write(90);   // Open the lid (90 degrees)
  } else {
    dustbinServo.write(0);    // Close the lid (0 degrees)
  }

  delay(100);  // Update every 100ms
}
