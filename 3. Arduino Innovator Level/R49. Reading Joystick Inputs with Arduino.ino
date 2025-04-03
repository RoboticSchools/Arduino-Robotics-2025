/*
Components Used:
- Arduino Board
- Joystick Module
- Sensor Shield
- Breadboard
- Jumper Wires
*/

int xPin = A0;  // Joystick X-axis connected to Analog Pin A0
int yPin = A1;  // Joystick Y-axis connected to Analog Pin A1
int buttonPin = 2; // Joystick button connected to Digital Pin 2

void setup() {
  pinMode(xPin, INPUT);  // Set X-axis pin as input
  pinMode(yPin, INPUT);  // Set Y-axis pin as input
  pinMode(buttonPin, INPUT_PULLUP);  // Enable internal pull-up resistor for button
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  int xValue = analogRead(xPin);  // Read joystick X-axis (0-1023)
  int yValue = analogRead(yPin);  // Read joystick Y-axis (0-1023)
  int buttonState = digitalRead(buttonPin);  // Read button state (0 = pressed, 1 = not pressed)

  // Print joystick values and button state to Serial Monitor
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  Serial.print(" | Button: ");
  Serial.println(buttonState == 0 ? "Pressed" : "Not Pressed");

  delay(100);  // Short delay to stabilize readings
}
