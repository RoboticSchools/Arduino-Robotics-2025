/*
Components used:
- Arduino Board
- Sensor Shield
- DHT11 Temperature and Humidity Sensor
- LCD Display (16x2 with I2C)
*/

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin configuration
#define DHTPIN 2          // Pin for DHT11 sensor
#define DHTTYPE DHT11     // DHT11 sensor type

DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set LCD I2C address and size

void setup() {
  lcd.begin();            // Initialize the LCD
  lcd.backlight();        // Turn on the LCD backlight
  dht.begin();            // Start DHT11 sensor

  lcd.setCursor(0, 0);    // Set cursor to the first row, first column
  lcd.print("Weather Station");
  delay(2000);            // Display message for 2 seconds
}

void loop() {
  float temperature = dht.readTemperature();  // Read temperature in Celsius
  float humidity = dht.readHumidity();        // Read humidity

  if (isnan(temperature) || isnan(humidity)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    return;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");

  delay(2000);  // Update readings every 2 seconds
}
