/*
Components Used:
- Arduino Board
- Sensor Shield
- Ultrasonic Sensor (HC-SR04)
- Breadboard
- Jumper Wires
*/

int trigPin = 9;  // Trigger pin of HC-SR04 (Connected to D9 on Sensor Shield)
int echoPin = 10; // Echo pin of HC-SR04 (Connected to D10 on Sensor Shield)

void setup() {
  Serial.begin(9600);    // Start serial communication
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Send a 10µs pulse to trigger the sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the echo pin
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Convert time to distance (Speed of sound = 343 m/s)
  int distance = (duration * 0.0343) / 2; // Distance in cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100); // Update every 500ms
}
