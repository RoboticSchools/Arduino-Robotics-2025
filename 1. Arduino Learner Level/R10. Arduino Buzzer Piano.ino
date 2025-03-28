/*
Components Used:
- Arduino Board
- Sensor Shield
- Buzzer
- 5 Push Buttons
- Breadboard
- Jumper Wires
*/

int buzzerPin = 9; // Buzzer connected to Pin 9

int button1 = 4; // Button 1 (C)
int button2 = 5; // Button 2 (D)
int button3 = 6; // Button 3 (E)
int button4 = 7; // Button 4 (F)
int button5 = 8; // Button 5 (G)

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  
  Serial.begin(9600); // Start Serial Monitor
}

void loop() {
  if (digitalRead(button1) == 0) {
    tone(buzzerPin, 262, 200); // C note
    Serial.println("Button 1 Pressed");
  } 
  else if (digitalRead(button2) == 0) {
    tone(buzzerPin, 294, 200); // D note
    Serial.println("Button 2 Pressed");
  } 
  else if (digitalRead(button3) == 0) {
    tone(buzzerPin, 330, 200); // E note
    Serial.println("Button 3 Pressed");
  } 
  else if (digitalRead(button4) == 0) {
    tone(buzzerPin, 349, 200); // F note
    Serial.println("Button 4 Pressed");
  } 
  else if (digitalRead(button5) == 0) {
    tone(buzzerPin, 392, 200); // G note
    Serial.println("Button 5 Pressed");
  } 
  else {
    noTone(buzzerPin); // Stop buzzer when no button is pressed
  }

  delay(100); // Small delay for better serial readability
}
