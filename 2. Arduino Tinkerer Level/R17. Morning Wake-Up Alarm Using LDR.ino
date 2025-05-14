/*
Components Used:
- Arduino Board
- Sensor Shield
- LDR (Light Dependent Resistor)
- Buzzer
- Start Button (connected to Pin 5)
- Stop Button (connected to Pin 6)
- Breadboard
- Jumper Wires
*/

int ldrPin = 3;         // LDR connected to Pin 3 (Digital)
int buzzerPin = 4;      // Buzzer connected to Pin 4
int startButtonPin = 5; // Start Button connected to Pin 5
int stopButtonPin = 6;  // Stop Button connected to Pin 6

void setup() {
  pinMode(ldrPin, INPUT);                   // LDR input
  pinMode(buzzerPin, OUTPUT);               // Buzzer output
  pinMode(startButtonPin, INPUT_PULLUP);    // Start Button input
  pinMode(stopButtonPin, INPUT_PULLUP);     // Stop Button input

  Serial.begin(9600);
  Serial.println("System Initialized. Waiting for START button...");
}

void loop() {
  // Wait until Start Button is pressed
  while (digitalRead(startButtonPin) == HIGH);
    // Do nothing until button is pressed (LOW = pressed)
  Serial.println("Start button pressed. Waiting for morning light...");

  // Wait until light is detected (LDR goes LOW)
  while (digitalRead(ldrPin) == HIGH);
    // Do nothing until light is detected
  Serial.println("Light detected! Morning has come.");
  digitalWrite(buzzerPin, HIGH); // Turn ON buzzer
  Serial.println("Buzzer ON - Alarm Activated.");

  // Wait until Stop Button is pressed
  Serial.println("Waiting for STOP button...");
  while (digitalRead(stopButtonPin) == HIGH);
    // Do nothing until stop button is pressed
  digitalWrite(buzzerPin, LOW); // Turn OFF buzzer
  Serial.println("Stop button pressed. Buzzer OFF.");

  // System will reset and wait again from start
  Serial.println("System resetting. Waiting for next START...");
  delay(1000); // small pause before looping again
}
