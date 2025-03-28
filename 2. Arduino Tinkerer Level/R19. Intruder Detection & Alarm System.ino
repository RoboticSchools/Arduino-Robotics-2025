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

// Define pin connections
int pirPin = 2;      // PIR sensor connected to Pin 2
int greenLed = 3;    // Green LED connected to Pin 3 (Safe Mode)
int redLed = 4;      // Red LED connected to Pin 4 (Intruder Alert)
int buzzerPin = 5;   // Buzzer connected to Pin 5 (Alarm)
int buttonPin = 6;   // Push Button connected to Pin 6 (Stop Alarm)

void setup() {
  // Configure pin modes
  pinMode(pirPin, INPUT);           // Set PIR sensor as input
  pinMode(greenLed, OUTPUT);        // Set Green LED as output
  pinMode(redLed, OUTPUT);          // Set Red LED as output
  pinMode(buzzerPin, OUTPUT);       // Set Buzzer as output
  pinMode(buttonPin, INPUT_PULLUP); // Set Button as input with internal pull-up resistor
  
  Serial.begin(9600);  // Start Serial Monitor for debugging
}

void loop() {
  int motionState = digitalRead(pirPin);   // Read PIR sensor value

  if (motionState == 1) {  // If motion is detected (Intruder Alert)
    digitalWrite(greenLed, LOW);   // Turn OFF Green LED (Safe Mode)
    digitalWrite(redLed, HIGH);    // Turn ON Red LED (Intruder Alert)
    digitalWrite(buzzerPin, HIGH); // Turn ON Buzzer (Alarm)
    Serial.println("Intruder Alert! Red LED & Buzzer ON");

    // Wait here until the button is pressed (stop alarm)
    while (digitalRead(buttonPin) == 1); 

    // When button is pressed, stop the alarm
    digitalWrite(buzzerPin, LOW);  // Turn OFF Buzzer
    digitalWrite(redLed, LOW);     // Turn OFF Red LED
    digitalWrite(greenLed, HIGH);  // Turn ON Green LED (Safe Mode)
    Serial.println("Alarm Stopped. System in Safe Mode.");

    while (1); // Halt execution, system stays in safe mode until restarted
  }

  else {  // No motion detected (Safe Mode)
    digitalWrite(greenLed, HIGH);  // Ensure Green LED is ON
    Serial.println("No Motion Detected. Safe Mode.");
  }

  delay(100); // Small delay to reduce unnecessary Serial Monitor output
}
