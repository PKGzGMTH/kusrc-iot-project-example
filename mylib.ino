#include "mylib.h"

void breathred(void)
{
  char R;
  for (R = 0; R < 32; R++) {
    neopixelWrite(RGB_BUILTIN, R, 0, 0);
    delay(30);
  }
  for (R = 32; R > 0; R) {
    neopixelWrite(RGB_BUILTIN, --R, 0, 0);
    delay(30);
  }
}

void looprgb(void) {
  char R = 0, G = 0, B = 0;
  for (R = 16; R > 0; R--) {
    neopixelWrite(RGB_BUILTIN, R, G++, B);
    delay(8);
  }
  for (G = 16; G > 0; G--) {
    neopixelWrite(RGB_BUILTIN, R, G, B++);
    delay(8);
  }
  for (B = 16; B > 0; B--) {
    neopixelWrite(RGB_BUILTIN, R++, G, B);
    delay(8);
  }
}

void blinkrgb(int round, int r, int g, int b)
{
  for (char i = 0; i < round; i++) {
    neopixelWrite(RGB_BUILTIN, r, g, b);
    delay(250);
    neopixelWrite(RGB_BUILTIN, 0, 0, 0);
    delay(250);
  }
}

void line_notify(String token, int weather) {
  HTTPClient http;
  http.begin("https://notify-api.line.me/api/notify");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.addHeader("Authorization", "Bearer " + token);
  int status = http.POST(lineimage[weather] + (String)"&" + (String)text[weather]);
  Serial.printf("status = %d\n", status);
  Serial.println(http.getString());
  http.end();
  blinkrgb(1, 0, 6, 6);
}

void  weather_update(float temp, float humid, float rain)
{
  static char last_weather = -1;
  char current_weather;

  if (temp > 40.00)
    current_weather = SUNNY;
  else if (humid > 75.00 || rain > 30)
    current_weather = RAIN;
  else
    current_weather = GOOD;
  if (current_weather != last_weather)
  {
    last_weather = current_weather;
    display.clearDisplay();
    display.fillRect(32, 0, 64, 64, SH110X_WHITE);
    display.drawBitmap(32, 0, image[current_weather], 64, 64, SH110X_BLACK);
    display.display();
    line_notify("fkZrxGGBt02wmwjd2Bw1G7t3GKM5T93PSc5yKRQcXsb", current_weather);
  }
}




