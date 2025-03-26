/*
Components Used:
- Arduino Board
- Motor Shield
- Ultrasonic Sensor (HC-SR04)
- DC Motors (4) connected to Motor Shield
- Breadboard
- Jumper Wires
*/

#include <AFMotor.h>

int trigPin = A4;  // Trigger pin of HC-SR04 (Connected to A4)
int echoPin = A5;  // Echo pin of HC-SR04 (Connected to A5)

// Motor shield motor objects
AF_DCMotor rightFront(1);  // Right Front Motor (M1)
AF_DCMotor rightBack(2);   // Right Back Motor (M2)
AF_DCMotor leftFront(3);   // Left Front Motor (M3)
AF_DCMotor leftBack(4);    // Left Back Motor (M4)

void setup() {
  Serial.begin(9600);  // Start serial communication

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialize all motors to forward movement
  rightFront.setSpeed(150);  
  rightBack.setSpeed(150);
  leftFront.setSpeed(150);   
  leftBack.setSpeed(150);  
}

void loop() {
  int distance = getUltrasonicDistance(); // Get distance from ultrasonic sensor

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If the object is closer than 30 cm, avoid obstacle
  if (distance < 30) {
    moveBackwards();  
    delay(500);  
    stopMotors();  
    delay(100); 
    turnRight();      
    delay(500);  
    stopMotors();  
    delay(100);
  } else {
    moveForward();    
  }

  delay(100);  // Short delay before next check
}

// Function to get the distance from the ultrasonic sensor
int getUltrasonicDistance() {
  // Send a 10µs pulse to trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Convert time to distance (Speed of sound = 343 m/s)
  return (duration * 0.0343) / 2;  // Distance in cm
}

void moveForward() {
  rightFront.run(FORWARD);
  rightBack.run(FORWARD);
  leftFront.run(FORWARD);
  leftBack.run(FORWARD);
}

void moveBackwards() {
  rightFront.run(BACKWARD);
  rightBack.run(BACKWARD);
  leftFront.run(BACKWARD);
  leftBack.run(BACKWARD);
}

void turnRight() {
  rightFront.run(FORWARD);
  rightBack.run(FORWARD);
  leftFront.run(BACKWARD);
  leftBack.run(BACKWARD);
}

void stopMotors() {
  rightFront.run(RELEASE);  
  rightBack.run(RELEASE); 
  leftFront.run(RELEASE); 
  leftBack.run(RELEASE); 
}
