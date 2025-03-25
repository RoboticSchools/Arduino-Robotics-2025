/*
Components Used:
- Arduino Board
- Sensor Shield
- Bluetooth HC-05 / ESP8266
- DHT11 Sensor (Temperature & Humidity)
- LCD Display (I2C)
- LDR Sensor (Automatic Light)
- Keypad (4x4) (Password Door Lock)
- Relay Module (For AC appliances)
- PIR Motion Sensor
- Gas Sensor (MQ-2)
- Buzzer
- LED & Servo Motor (For door lock)
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Keypad.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define DHTPIN A0
#define DHTTYPE DHT11
#define LDR A1
#define GAS_SENSOR A2
#define PIR_SENSOR 7
#define BUZZER 6
#define RELAY 8
#define SERVO_PIN 9

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo doorLock;
SoftwareSerial BTSerial(10, 11);  // RX, TX for Bluetooth

// Keypad Setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {A3, A4, A5, A6};
byte colPins[COLS] = {A7, 2, 3, 4};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "1234";
String inputPassword = "";
bool doorOpen = false;

void setup() {
  lcd.begin();
  lcd.backlight();
  dht.begin();
  doorLock.attach(SERVO_PIN);
  pinMode(LDR, INPUT);
  pinMode(GAS_SENSOR, INPUT);
  pinMode(PIR_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RELAY, OUTPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);
  doorLock.write(0);  // Lock door
}

// Function to read and display temperature & humidity
void readTemperatureHumidity() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  lcd.setCursor(0, 0);
  lcd.print("T: "); lcd.print(temp); lcd.print("C ");
  lcd.print("H: "); lcd.print(humidity); lcd.print("%");
}

// Function to control lights using LDR
void controlLights() {
  int lightValue = analogRead(LDR);
  if (lightValue < 500) {
    digitalWrite(RELAY, HIGH); // Turn on light
  } else {
    digitalWrite(RELAY, LOW); // Turn off light
  }
}

// Function to monitor gas sensor and trigger alert
void monitorGasSensor() {
  int gasValue = analogRead(GAS_SENSOR);
  if (gasValue > 600) {
    digitalWrite(BUZZER, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Gas Alert!     ");
  } else {
    digitalWrite(BUZZER, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Safe           ");
  }
}

// Function to detect motion and trigger buzzer
void detectMotion() {
  int motionDetected = digitalRead(PIR_SENSOR);
  if (motionDetected) {
    digitalWrite(BUZZER, HIGH);
    delay(2000);
    digitalWrite(BUZZER, LOW);
  }
}

// Function to handle keypad input for door lock
void handleKeypadInput() {
  char key = keypad.getKey();
  if (key) {
    if (key == '#') {
      if (inputPassword == password) {
        doorOpen = !doorOpen;
        doorLock.write(doorOpen ? 90 : 0);  // Open/Close Door
      }
      inputPassword = "";
    } else {
      inputPassword += key;
    }
  }
}

// Function to handle Bluetooth commands
void handleBluetooth() {
  if (BTSerial.available()) {
    char command = BTSerial.read();
    if (command == '1') {
      digitalWrite(RELAY, HIGH);  // Turn on appliances
    } else if (command == '0') {
      digitalWrite(RELAY, LOW);   // Turn off appliances
    } else if (command == 'D') {
      doorOpen = !doorOpen;
      doorLock.write(doorOpen ? 90 : 0);
    }
  }
}

void loop() {
  readTemperatureHumidity();
  controlLights();
  monitorGasSensor();
  detectMotion();
  handleKeypadInput();
  handleBluetooth();
  delay(500);
}
