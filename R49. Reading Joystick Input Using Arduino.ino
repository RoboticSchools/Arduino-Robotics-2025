/*
Components Used:
- Arduino Board
- Joystick Module
- Sensor Shield
- Breadboard
- Jumper Wires
*/

void setup() {
  pinMode(2, INPUT_PULLUP);  // Joystick button pin on sensor shield
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  int xPin = A0;  // Joystick X-axis pin
  int yPin = A1;  // Joystick Y-axis pin
  int buttonPin = 2; // Joystick button pin on sensor shield

  int xValue = analogRead(xPin);  // Read the X-axis value (0-1023)
  int yValue = analogRead(yPin);  // Read the Y-axis value (0-1023)
  int buttonState = digitalRead(buttonPin);  // Read the button state (pressed or not)

  // Print X, Y values and button state to Serial Monitor
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print("\tY: ");
  Serial.print(yValue);
  Serial.print("\tButton: ");
  Serial.println(buttonState == LOW ? "Pressed" : "Not Pressed");

  delay(100);  // Wait for a short period to stabilize the readings
}
