/*
Components Used:
- Arduino Board
- Sensor Shield
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- Breadboard
- Jumper Wires
*/

#define TRIG_PIN 9     // Trigger pin of HC-SR04 (Connected to D9 on Sensor Shield)
#define ECHO_PIN 10    // Echo pin of HC-SR04 (Connected to D10 on Sensor Shield)
#define SERVO_PIN 3    // Servo Motor pin (Connected to D3 on Sensor Shield)

#include <Servo.h>

Servo dustbinServo;  // Create a Servo object for controlling the dustbin lid

void setup() {
  Serial.begin(9600);   // Start serial communication
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  dustbinServo.attach(SERVO_PIN);  // Attach the servo motor to the servo pin
  dustbinServo.write(0);   // Close the lid initially
}

void loop() {
  long duration;
  float distance;

  // Send a 10µs pulse to trigger the sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the echo pin
  duration = pulseIn(ECHO_PIN, HIGH);

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

  delay(500);  // Update every 500ms
}
