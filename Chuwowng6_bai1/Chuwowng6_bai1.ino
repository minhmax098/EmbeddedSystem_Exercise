#include <Wire.h>
#include <RTClib.h>
#include <SD.h>
#include <SPI.h>

File myFile;
RTC_DS1307 rtc;
byte pinTemp = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinTemp, INPUT);
  if(SD.begin(4))
    Serial.println("SD is already");
  else 
  {
    Serial.println("SD is not found);
    while(1);
  }
while(SD.exits("Data.txt")) SD.remove("Data.txt")
if( !rtc.begin())
{
  Serial.print("RTC not found");
}
if( !rtc.isbeginning())
{
  Serial.print("RTC khong chay");
  
}
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)); //TỰ ĐỘNG CẬP NHẬT NGÀY GIỜ THEO MÁY
}
void getTemp()
{
    int temp = (5.0 * analogRead(AO)*100.0/1024.0);
    myFile.print("Nhiệt độ:");
    myFile.print("temp ");
    myFile.print(" \n");
}
void loop() {
  // put your main code here, to run repeatedly:

}
