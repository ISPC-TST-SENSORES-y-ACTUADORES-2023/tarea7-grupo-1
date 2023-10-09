#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2    // Pin D2 conectado al DHT22
#define DHTTYPE DHT22   // Tipo de sensor DHT
#define LCD_ADDR 0x27  // Dirección I2C del LCD 1602

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.init();
  lcd.backlight();

}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  lcd.setCursor(9, 0);
  lcd.print(temperature);
  lcd.print(" C");
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  

  lcd.setCursor(9, 1);
  lcd.print(humidity);
  lcd.print(" %");
  lcd.setCursor(0, 1);
  lcd.print("Hume: ");
  

  delay(2000);
  
}
