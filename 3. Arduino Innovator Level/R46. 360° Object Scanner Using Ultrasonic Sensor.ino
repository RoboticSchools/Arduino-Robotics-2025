// https://robu.in/arduino-radar-project-ultrasonic-based-radar-connection-and-code/

/*
Components Used:
- Arduino Board
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- Breadboard
- Jumper Wires
*/

#include <Servo.h>  // Include the Servo library

// Define Ultrasonic Sensor pins
int trigPin = 10;
int echoPin = 11;

long duration;
int distance;

Servo myServo;  // Servo object for motor control

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(12);  // Attach servo to pin 12
}

void loop() {
  for (int angle = 15; angle <= 165; angle++) {  
    myServo.write(angle);
    delay(30);
    distance = calculateDistance();
    
    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }

  for (int angle = 165; angle > 15; angle--) {  
    myServo.write(angle);
    delay(30);
    distance = calculateDistance();
    
    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance() { 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
