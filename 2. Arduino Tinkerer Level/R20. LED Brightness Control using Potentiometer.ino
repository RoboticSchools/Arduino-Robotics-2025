/*
Components Used:
- Arduino Board
- Sensor Shield
- LED
- Potentiometer
- Breadboard
- Jumper Wires
*/

int ledPin = 9;          // LED connected to PWM Pin 9
int potPin = A0;         // Potentiometer connected to Analog Pin A0

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
}

void loop() {
  int potValue = analogRead(potPin);       // Read potentiometer value (0-1023)
  int brightness = map(potValue, 0, 1023, 0, 255); // Map value to PWM range (0-255)
  
  analogWrite(ledPin, brightness); // Adjust LED brightness
}
