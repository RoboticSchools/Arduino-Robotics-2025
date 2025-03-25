/*
Components Used:
- Arduino Board
- Sensor Shield
- PIR Motion Sensor
- Green LED (Safe Mode)
- Red LED (Intruder Alert)
- Buzzer (Alarm)
- Push Button (Stop Alarm)
- Breadboard
- Jumper Wires
*/

int pirPin = 2;      // PIR sensor connected to Pin 2
int greenLed = 3;    // Green LED connected to Pin 3
int redLed = 4;      // Red LED connected to Pin 4
int buzzerPin = 5;   // Buzzer connected to Pin 5
int buttonPin = 6;   // Push Button connected to Pin 6

void setup() {
  pinMode(pirPin, INPUT);      // Set PIR sensor as input
  pinMode(greenLed, OUTPUT);   // Set Green LED as output
  pinMode(redLed, OUTPUT);     // Set Red LED as output
  pinMode(buzzerPin, OUTPUT);  // Set Buzzer as output
  pinMode(buttonPin, INPUT_PULLUP); // Set Button as input with internal pull-up
}

void loop() {
  int motionState = digitalRead(pirPin);   // Read PIR sensor value
  int buttonState = digitalRead(buttonPin); // Read Button state

  if (motionState == HIGH) {  // If motion is detected (Intruder Alert)
    digitalWrite(greenLed, LOW);   // Turn OFF Green LED
    digitalWrite(redLed, HIGH);    // Turn ON Red LED
    digitalWrite(buzzerPin, HIGH); // Turn ON Buzzer (Alarm)
  }

  if (buttonState == LOW) {  // If button is pressed (Stop Alarm)
    digitalWrite(buzzerPin, LOW);  // Turn OFF Buzzer
    digitalWrite(redLed, LOW);     // Turn OFF Red LED
    digitalWrite(greenLed, HIGH);  // Turn ON Green LED (Safe Mode)
  }

  if (motionState == LOW) {  // No motion detected (Safe Mode)
    digitalWrite(greenLed, HIGH);  // Turn ON Green LED
  }
}
