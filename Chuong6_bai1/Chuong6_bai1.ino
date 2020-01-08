#include <DHT.h>

/*
 * Program to demonstrate Data Logging/Visualisation using Arduino
 * 
 * ###Connection with SD card module###
 * Vcc->5V
 * Gnd->Gnd
 * MISO->pin 12
 * MOSI->pin 11
 * SCK-> pin 13
 * CS-> pin 4
 * 
 * ###Connection with DS3231###
 * Vcc->5V
 * Gns->Gnd
 * SCL->pin A5
 * SDA-> pin A4
 * 
 * ###Connection with DT11###
 * Vcc->5V
 * Gnd->Gnd
 * Out-> pin 7
 * 
 * 
 */

#include <DS3231.h> //Library for RTC module (Download from Link in article)
#include <SPI.h> //Library for SPI communication (Pre-Loaded into Arduino)
#include <SD.h> //Library for SD card (Pre-Loaded into Arduino)
#include <DHT.h> //Library for dht11 Temperature and Humidity sensor (Download from Link in article)

#define DHT11_PIN 7 //Sensor output pin is connected to pin 7
dht DHT; //Sensor object named as DHT

const int chipSelect = 4; //SD card CS pin connected to pin 4 of Arduino

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

void setup()
{
  // Setup Serial connection
  Serial.begin(9600);
  Initialize_SDcard();
  Initialize_RTC();
  Initialize_PlxDaq();
}

void loop()
{
  Read_DHT11();
  Write_SDcard();
  Write_PlxDaq();
  delay(5000); //Wait for 5 seconds before writing the next data 
}

void Write_PlxDaq()
  {
    Serial.print("DATA"); //always write "DATA" to Indicate the following as Data
    Serial.print(","); //Move to next column using a ","

    Serial.print("DATE"); //Store date on Excel
    Serial.print(","); //Move to next column using a ","

    Serial.print("TIME"); //Store date on Excel
    Serial.print(","); //Move to next column using a ","

    Serial.print(DHT.temperature); //Store date on Excel
    Serial.print(","); //Move to next column using a ","

    Serial.print(DHT.humidity); //Store date on Excel
    Serial.print(","); //Move to next column using a ","

    Serial.println(); //End of Row move to next row
  }

void Initialize_PlxDaq()
{
Serial.println("CLEARDATA"); //clears up any data left from previous projects
Serial.println("LABEL,Date,Time,Temperature,Humidity"); //always write LABEL, to indicate it as first line
}

void Write_SDcard()
{
    // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("LoggerCD.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.print(rtc.getDateStr()); //Store date on SD card
    dataFile.print(","); //Move to next column using a ","

    dataFile.print(rtc.getTimeStr()); //Store date on SD card
    dataFile.print(","); //Move to next column using a ","

    dataFile.print(DHT.temperature); //Store date on SD card
    dataFile.print(","); //Move to next column using a ","

    dataFile.print(DHT.humidity); //Store date on SD card
    dataFile.print(","); //Move to next column using a ","

    dataFile.println(); //End of Row move to next row
    dataFile.close(); //Close the file
  }
  else
  Serial.println("OOPS!! SD card writing failed");
}

void Initialize_SDcard()
{
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
   // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("LoggerCD.txt", FILE_WRITE);
  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println("Date,Time,Temperature,Humidity"); //Write the first row of the excel file
    dataFile.close();
  }
}

void Initialize_RTC()
{
   // Initialize the rtc object
  rtc.begin();

//#### The following lines can be uncommented to set the date and time for the first time###  
/*
rtc.setDOW(FRIDAY);     // Set Day-of-Week to SUNDAY
rtc.setTime(18, 46, 45);     // Set the time to 12:00:00 (24hr format)
rtc.setDate(6, 30, 2017);   // Set the date to January 1st, 2014 
*/
}

void Read_DHT11()
{
int chk = DHT.read11(DHT11_PIN);
}

/*void Read_DateTime()
{  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
}*/

/*void Read_TempHum()
{
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
 // delay(1000);
}*/
