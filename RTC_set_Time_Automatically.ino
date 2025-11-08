#include <Wire.h>
#include <RTClib.h>
//Aniket Sahu

//hello from raunak
RTC_DS3231 rtc;

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Wire.begin(21, 22);  // Your I2C pins scl sda
  
  if (!rtc.begin()) {
    Serial.println("RTC not found!");
    while (1);
  }

  // Adjust the time once to the current PC time
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); 

  Serial.println("RTC time set to compile time.");
}

void loop() {}
