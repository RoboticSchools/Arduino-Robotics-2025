/*
Components Used:
- Arduino Board
- Sensor Shield
- 6 LEDs
- Potentiometer
- Breadboard
- Jumper Wires
*/

int led1 = 3, led2 = 4, led3 = 5, led4 = 6, led5 = 7, led6 = 8;
int potPin = A0; // Potentiometer pin

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin); // Read potentiometer value (0-1023)
  int delayTime = map(potValue, 0, 1023, 50, 500); // Map value to delay range

  digitalWrite(led1, HIGH); delay(delayTime); digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH); delay(delayTime); digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH); delay(delayTime); digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH); delay(delayTime); digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH); delay(delayTime); digitalWrite(led5, LOW);
  digitalWrite(led6, HIGH); delay(delayTime); digitalWrite(led6, LOW);
}
