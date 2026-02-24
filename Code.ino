#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// Change to 0x3F if 0x27 doesn't work
LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;

void setup() {
  Serial.begin(115200);
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Initialize RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    lcd.print("RTC Error!");
    while (1);
  }

  // Check if the RTC lost power and set the time
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting the time!");
    // Sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("I2C Lab Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  DateTime now = rtc.now();

  // 1. Print to Serial Monitor (For Lab Requirement 3)
  Serial.print("Date: ");
  Serial.print(now.year(), DEC); Serial.print('/');
  Serial.print(now.month(), DEC); Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" | Time: ");
  Serial.print(now.hour(), DEC); Serial.print(':');
  Serial.print(now.minute(), DEC); Serial.print(':');
  Serial.println(now.second(), DEC);

  // 2. Display on LCD
  // Top Row: Date
  lcd.setCursor(0, 0);
  lcd.print("D:"); lcd.print(now.month()); 
  lcd.print("/"); lcd.print(now.day()); 
  lcd.print("/"); lcd.print(now.year());

  // Bottom Row: Time
  lcd.setCursor(0, 1);
  lcd.print("T: ");
  if(now.hour() < 10) lcd.print('0'); lcd.print(now.hour());
  lcd.print(":");
  if(now.minute() < 10) lcd.print('0'); lcd.print(now.minute());
  lcd.print(":");
  if(now.second() < 10) lcd.print('0'); lcd.print(now.second());

  delay(1000); // Update every second
}