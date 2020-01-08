#include <Wire.h>
#include <RTClib.h>
#include <SD.h>
#include<SPI.h>

File myFile;
RTC_DS1307 rtc;
byte pinTemp = A0;

void setup () 
{
  Serial.begin(9600);
  pinMode(pinTemp, INPUT);
  if (SD.begin(4))
    Serial.println("SD is ready");
    else
    {
      Serial.println("SD is not found");
      //while (1);
    }
  while(SD.exists("Data.txt")) SD.remove("Data.txt");  
  if ( !rtc.begin()) 
  {
    Serial.print("RTC is not found");
    //while (1);
  }
  else
  {
    Serial.println("RCT is ready");
  }

  if (!rtc.isrunning()) 
  {
    Serial.print("RTC khong chay!");
  }
  
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//tự động cập nhật ngày giừo theo máy
    //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));//cài ngày giờ tùy chọn 
}
void  getTime()
{
  DateTime now = rtc.now();
  Serial.print(now.hour());
  myFile.print(now.hour());
  Serial.print(':');
  myFile.print(':');
  Serial.print(now.minute());
  myFile.print(now.minute());
  Serial.print(':');
  myFile.print(':');
  Serial.print(now.second());
  myFile.print(now.second());
  myFile.print("   ");
}
void getTemp()
{
  int temp = (5.0*analogRead(A0)*100.0/1024.0);
  Serial.print("Nhiet do: ");
  myFile.print("Nhiet do: ");
  Serial.print(temp);
  myFile.print(temp);
  myFile.println();
  myFile.print("\n");
}

void loop () 
{
   myFile=SD.open("Data.txt", FILE_WRITE);
   if(myFile)
   {
     Serial.print("Viet vao Data.txt...");
     getTime();
     getTemp();
   }
   else
   {
    Serial.println("Loi");
   }
   myFile.close();
   Serial.println("Xong!");
   delay(5000);
}
