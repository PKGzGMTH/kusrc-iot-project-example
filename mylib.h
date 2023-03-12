#ifndef MYLIB_H
#define MYLIB_H
#include <WiFi.h>
#include <DHT.h>
#include <Wire.h>
#include <HTTPClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <LiquidCrystal_I2C.h>

#define i2c_Address 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define GOOD 0
#define SUNNY 1
#define RAIN 2

Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

DHT dht(1, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

String token[] = {
  "fkZrxGGBt02wmwjd2Bw1G7t3GKM5T93PSc5yKRQcXsb"
};

void  looprgb(void);
void  reathred(void);
void  blinkrgb(int round, int r, int g, int b);
void  line_notify(String token, int weather);
void  weather_update(float temp, float humid, float rain);

const String text[] = {
  "message=ตอนนี้อากาศแจ่มใส่ ย้ำ ตอนนี้อากาศแจ่มใส :D", 
  "message=ตอนนี้แดดร้อนไม่ไหวววว อยากเล่นน้ำจังเลยย",
  "message=ตอนนี้ฝนตกน้าา อยากนอนจังเลยย"
};

const String lineimage[] = {
  "imageThumbnail=https://raw.githubusercontent.com/PKGzGMTH/kusrc-iot-project-example/main/good.png&imageFullsize=https://raw.githubusercontent.com/PKGzGMTH/kusrc-iot-project-example/main/good.png",
  "imageThumbnail=https://raw.githubusercontent.com/PKGzGMTH/kusrc-iot-project-example/main/sunny.png&imageFullsize=https://raw.githubusercontent.com/PKGzGMTH/kusrc-iot-project-example/main/sunny.png",
  "imageThumbnail=https://raw.githubusercontent.com/PKGzGMTH/kusrc-iot-project-example/main/rain.png&imageFullsize=https://raw.githubusercontent.com/PKGzGMTH/kusrc-iot-project-example/main/rain.png"
};

const unsigned char image[][4096] = {
  { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x3f, 0xfe, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xf1, 0xff,
    0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xc3, 0xff,
    0xff, 0xff, 0xff, 0xc7, 0xfc, 0x7f, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xef, 0xe0, 0x0f, 0xcf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x0f, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 0xf8, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0x00, 0x3f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xfe, 0x3f, 0xff,
    0xff, 0xff, 0xf8, 0x00, 0x03, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xc1, 0xff, 0x1f, 0xff,
    0xff, 0xff, 0xe1, 0xff, 0xf0, 0xff, 0x1f, 0x0f, 0xff, 0xff, 0xc3, 0xff, 0xf8, 0x7f, 0x1e, 0x07,
    0xff, 0xff, 0x87, 0xff, 0xfc, 0x3f, 0x1e, 0x07, 0xff, 0xff, 0x8f, 0xff, 0xfc, 0x3f, 0x1f, 0x0f,
    0xff, 0xff, 0x0f, 0xff, 0xfe, 0x1f, 0x1f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x16, 0x1f, 0xff,
    0xff, 0xc0, 0x1f, 0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0x80, 0x1f, 0xff, 0xff, 0x00, 0x3f, 0xff,
    0xff, 0x00, 0x1f, 0xff, 0xff, 0x00, 0x1f, 0xff, 0xfe, 0x1e, 0x1f, 0xff, 0xff, 0x1e, 0x0f, 0xff,
    0xfc, 0x3e, 0x1f, 0xff, 0xff, 0x1f, 0x87, 0xff, 0xfc, 0x7f, 0x3f, 0xff, 0xff, 0x9f, 0x87, 0xff,
    0xf8, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff,
    0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff,
    0xf8, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff,
    0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff,
    0xfe, 0x07, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff,
    0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
  { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7e, 0x3f, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xfc, 0x7e, 0x3e, 0x1f, 0xff, 0xff, 0xff, 0xf8, 0xfc, 0x3e, 0x3e, 0x1f, 0x8f, 0xff,
    0xff, 0xf8, 0x7e, 0x1e, 0x3c, 0x3f, 0x0f, 0xff, 0xff, 0xf8, 0x3e, 0x1e, 0x3c, 0x3e, 0x0f, 0xff,
    0xff, 0xfc, 0x1f, 0x0c, 0x38, 0x7c, 0x1f, 0xff, 0xff, 0xfe, 0x0f, 0x0e, 0x38, 0x78, 0x3f, 0xff,
    0xff, 0xff, 0x07, 0x07, 0xf8, 0xf0, 0x7f, 0xff, 0xff, 0xff, 0x83, 0x8f, 0xf8, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xc1, 0xf8, 0x0f, 0x81, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xe0, 0x01, 0x83, 0xff, 0xff,
    0xff, 0xf7, 0xf1, 0x80, 0x00, 0x87, 0xef, 0xff, 0xff, 0xe1, 0xf3, 0x00, 0x00, 0x7f, 0xc3, 0xff,
    0xff, 0xe0, 0x3e, 0x00, 0x00, 0x3e, 0x03, 0xff, 0xff, 0xf0, 0x1c, 0x00, 0x00, 0x1c, 0x07, 0xff,
    0xff, 0xf0, 0x08, 0x00, 0x00, 0x08, 0x0f, 0xff, 0xff, 0xff, 0x08, 0x00, 0x00, 0x08, 0x7f, 0xff,
    0xff, 0xff, 0x98, 0x00, 0x00, 0x0c, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xf8, 0x00, 0x30, 0x00, 0x00, 0x0c, 0x00, 0x0f,
    0xf8, 0x00, 0x30, 0x00, 0x00, 0x0c, 0x00, 0x0f, 0xf8, 0x00, 0x30, 0x00, 0x00, 0x0c, 0x00, 0x0f,
    0xff, 0xff, 0xf0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x00, 0x00, 0x0d, 0xff, 0xff, 0xff, 0xfe, 0x08, 0x00, 0x00, 0x08, 0x3f, 0xff,
    0xff, 0xf8, 0x08, 0x00, 0x00, 0x18, 0x0f, 0xff, 0xff, 0xe0, 0x1c, 0x00, 0x00, 0x1c, 0x03, 0xff,
    0xff, 0xe0, 0x3e, 0x00, 0x00, 0x3e, 0x03, 0xff, 0xff, 0xe0, 0xf3, 0x00, 0x00, 0x4f, 0xc3, 0xff,
    0xff, 0xf3, 0xf1, 0x80, 0x00, 0x87, 0xef, 0xff, 0xff, 0xff, 0xe1, 0xc0, 0x03, 0x83, 0xff, 0xff,
    0xff, 0xff, 0xc1, 0xf8, 0x1f, 0xc1, 0xff, 0xff, 0xff, 0xff, 0x83, 0xcf, 0xf8, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0x07, 0x07, 0x38, 0xf0, 0x7f, 0xff, 0xff, 0xfe, 0x0f, 0x0e, 0x38, 0x78, 0x3f, 0xff,
    0xff, 0xfc, 0x1f, 0x0c, 0x38, 0x7c, 0x1f, 0xff, 0xff, 0xf8, 0x3e, 0x1e, 0x3c, 0x3e, 0x0f, 0xff,
    0xff, 0xf8, 0x7e, 0x1e, 0x3c, 0x3f, 0x0f, 0xff, 0xff, 0xf8, 0xfc, 0x1e, 0x3e, 0x1f, 0x8f, 0xff,
    0xff, 0xff, 0xfc, 0x7e, 0x3e, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7e, 0x3f, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
  { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xbe, 0xfb, 0xef, 0xbf, 0xff, 0xff, 0xff, 0xff, 0x1c, 0x71, 0xc7, 0x1f,
    0xff, 0xff, 0xff, 0xfe, 0x18, 0xe3, 0x8e, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x3c, 0xe7, 0x9e, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe7, 0x9e, 0x79, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x1c, 0x71, 0xc7, 0xff,
    0xff, 0xff, 0xff, 0xc7, 0x1c, 0x71, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x3c, 0xf7, 0xdf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xf7, 0xdf, 0x7d, 0xff, 0xff,
    0xff, 0xff, 0xf8, 0xe7, 0x9e, 0x71, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xc7, 0x1c, 0x71, 0xff, 0xff,
    0xff, 0xff, 0xf3, 0xcf, 0x3c, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xf8, 0x1f, 0xff, 0xff,
    0xff, 0xff, 0x83, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0xc3, 0xff, 0xff,
    0xff, 0xfc, 0x3f, 0xff, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xf8, 0xff, 0xff,
    0xff, 0xf1, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff,
    0xff, 0xc7, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff,
    0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff,
    0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff,
    0xfe, 0x60, 0x7f, 0xf0, 0x3f, 0xf0, 0x33, 0xff, 0xfe, 0x00, 0x1f, 0xc0, 0x0f, 0xc0, 0x01, 0xff,
    0xfc, 0x07, 0x07, 0x00, 0x07, 0x83, 0x01, 0xff, 0xfc, 0x1f, 0xc2, 0x1c, 0xc3, 0x1f, 0xe1, 0xff,
    0xfc, 0x3f, 0xe0, 0x38, 0xf0, 0x3f, 0xf1, 0xff, 0xfc, 0x7f, 0xf0, 0x78, 0xf0, 0x7f, 0xf8, 0xff,
    0xf8, 0xff, 0xf8, 0xf8, 0xf8, 0x7f, 0xf8, 0xff, 0xf8, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0xfc, 0xff,
    0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xfc, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x78, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x38, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0x38, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x38, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0x38, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x38, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0x38, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff }
};

#endif