/*
Components Used:
- Arduino Board
- Sensor Shield
- Ultrasonic Sensor (HC-SR04)
- Red LED
- Green LED
- Buzzer
- Breadboard
- Jumper Wires
*/

int trigPin = 9;      // Trigger pin of HC-SR04
int echoPin = 10;     // Echo pin of HC-SR04
int redLedPin = 3;    // Red LED pin
int greenLedPin = 4;  // Green LED pin
int buzzerPin = 5;    // Buzzer pin

void setup() {
  Serial.begin(9600);     // Start serial communication
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Send a 10µs pulse to trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Convert time to distance (Speed of sound = 343 m/s)
  int distance = (duration * 0.0343) / 2;  // Distance in cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control LEDs and buzzer based on distance
  if (distance < 30) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(buzzerPin, LOW);
  }

  delay(100);  // Update every 100ms
}