#include <RTClib.h>
#include <SD.h>
#include<SPI.h>
#include <Wire.h>
//#include "RTClib.h"
//RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
File myFile;
RTC_DS1307 rtc;
byte pinTemp = A3;

void setup ()
{
  Serial.begin(9600);
  pinMode(pinTemp, INPUT);
  if (SD.begin(10))
    Serial.println("SD is ready");
  else
  {
    Serial.println("SD is not found");
    //while (1);
  }
  while (SD.exists("Data.txt")) SD.remove("Data.txt");

  
  while (!Serial); // for Leonardo/Micro/Zero
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(F(_DATE_), F(_TIME_)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}
void  getTime()
{
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  myFile.print(now.year(), DEC);
  Serial.print('/');
  myFile.print('/');
  Serial.print(now.month(), DEC);
  myFile.print(now.month(), DEC);
  Serial.print('/');
  myFile.print('/');
  Serial.print(now.day(), DEC);
  myFile.print(now.day(), DEC);
  Serial.print(" (");
  myFile.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  myFile.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  myFile.print(") ");
  Serial.print(now.hour(), DEC);
  myFile.print(now.hour(), DEC);
  Serial.print(':');
  myFile.print(':');
  Serial.print(now.minute(), DEC);
  myFile.print(now.minute(), DEC);
  Serial.print(':');
  myFile.print(':');
  Serial.print(now.second(), DEC);
  myFile.print(now.second(), DEC);
  myFile.println();
  
////  DateTime now = rtc.now();
//  Serial.print(now.hour());
//  myFile.print(now.hour());
//  Serial.print(':');
//  myFile.print(':');
//  Serial.print(now.minute());
//  myFile.print(now.minute());
//  Serial.print(':');
//  myFile.print(':');
//  Serial.println(now.second());
//  myFile.print(now.second());
//  myFile.print("   ");
}
void getTemp()
{
  //đọc giá trị từ cảm biến LM35
  int reading = analogRead(pinTemp);

  //tính ra giá trị hiệu điện thế (đơn vị Volt) từ giá trị cảm biến
  float voltage = reading * 5.0 / 1024.0;

  // ở trên mình đã giới thiệu, cứ mỗi 10mV = 1 độ C.
  // Vì vậy nếu biến voltage là biến lưu hiệu điện thế (đơn vị Volt)
  // thì ta chỉ việc nhân voltage cho 100 là ra được nhiệt độ!

  float temp = voltage * 100.0;
  Serial.print(" \n Nhiet do: ");
  myFile.print(" \n Nhiet do: ");
  Serial.println(temp);
  myFile.print(temp);
  myFile.println();
  myFile.print("\n");
}

void loop ()
{
  myFile = SD.open("Data.txt", FILE_WRITE);
  if (myFile)
  {
    Serial.println("Viet vao Data.txt...");
    getTime();
    myFile.println();
    getTemp();
  }
  else
  {
    Serial.println("Loi");
  }
  myFile.close();
  Serial.println("Xong!");
  Serial.println();
  delay(5000);
}
