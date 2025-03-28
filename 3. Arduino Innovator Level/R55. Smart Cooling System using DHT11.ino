/*
Components Used:
- Arduino Board
- DHT11 Temperature Sensor
- Adafruit Motor Shield
- DC Motor (Fan)
- Red LED (High Temperature Warning)
- Green LED (Normal Temperature Indicator)
- Jumper Wires
*/

#include <AFMotor.h>
#include <DHT.h>

#define DHTPIN 2       // DHT11 data pin connected to D2
#define DHTTYPE DHT11  // Define sensor type

#define RED_LED 6      // Red LED for high temperature
#define GREEN_LED 5    // Green LED for normal temperature

AF_DCMotor fan(1);     // DC Motor connected to Motor 1 on Motor Shield
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  fan.setSpeed(150); // Set motor speed (0-255)
}

void loop() {
  float temperature = dht.readTemperature(); // Read temperature in Celsius

  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  if (temperature > 27) {
    fan.run(FORWARD);  // Turn ON fan
    digitalWrite(RED_LED, HIGH);   // Turn ON red LED
    digitalWrite(GREEN_LED, LOW);  // Turn OFF green LED
    Serial.println("Fan ON - High Temperature!");
  } else {
    fan.run(RELEASE);   // Turn OFF fan
    digitalWrite(RED_LED, LOW);    // Turn OFF red LED
    digitalWrite(GREEN_LED, HIGH); // Turn ON green LED
    Serial.println("Fan OFF - Temperature Normal.");
  }

  delay(1000); // Wait before next reading
}
