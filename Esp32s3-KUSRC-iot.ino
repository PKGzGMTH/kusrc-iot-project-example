#include "mylib.h"

// token fkZrxGGBt02wmwjd2Bw1G7t3GKM5T93PSc5yKRQcXsb
const char *ssid = "snakeCase_2G";
const char *password = "passwordFor0x2D6Room";
// const char *ssid      = "PKGzGMTH";
// const char *password  = "pea2226132849";

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
    breathred();
  dht.begin();
  lcd.begin();
  lcd.backlight();
  display.begin(i2c_Address, true);
  display.display();
  blinkrgb(3, 0, 16, 8);
  pinMode(2, INPUT);
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  lcd.setCursor(0, 0);
  if (isnan(h) || isnan(t))
    return (void )lcd.printf("Failed to read from DHT sensor!");
  lcd.printf("%.2f c  %.2f %%\n", t, h);
  lcd.setCursor(0, 1);
  lcd.printf("RAIN: % 6.2f %%", (float)analogRead(2) / 40.96);
  weather_update(t, h, (float)analogRead(2) / 40.96);
  delay(250);
  // looprgb();
}
