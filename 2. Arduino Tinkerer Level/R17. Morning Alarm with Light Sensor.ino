/*
Components Used:
- Arduino Board
- Sensor Shield
- LDR (Light Dependent Resistor)
- Buzzer
- Push Button
- Breadboard
- Jumper Wires
*/

int ldrPin = 3;      // LDR connected to Pin 3 (Digital)
int buzzerPin = 4;   // Buzzer connected to Pin 4
int buttonPin = 5;   // Push Button connected to Pin 5

void setup() {
  pinMode(ldrPin, INPUT);    // Set LDR pin as input
  pinMode(buzzerPin, OUTPUT); // Set Buzzer pin as output
  pinMode(buttonPin, INPUT_PULLUP); // Set Button pin as input with internal pull-up
}

void loop() {
  int ldrState = digitalRead(ldrPin); // Read LDR value
  int buttonState = digitalRead(buttonPin); // Read Button state

  if (ldrState == 1) {  // If light is detected (Morning)
    digitalWrite(buzzerPin, HIGH); // Turn ON Buzzer (Alarm)
  }

  if (buttonState == 0) {  // If button is pressed
    digitalWrite(buzzerPin, LOW); // Turn OFF Buzzer (Stop Alarm)
  }
}
