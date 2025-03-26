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
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
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
  int distance = (duration * 0.0343) / 2;  // Distance in cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control LEDs and buzzer based on distance
  if (distance < 30) {
    // If distance is less than 30cm, turn on red LED and buzzer
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    // If distance is greater than 30cm, turn on green LED only
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(100);  // Update every 100ms
}
