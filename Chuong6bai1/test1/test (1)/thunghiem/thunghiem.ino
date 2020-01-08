/*
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */
#include <SPI.h> //thư viện chuẩn giao tiếp Serial Peripheral Bus
#include <MFRC522.h> //khai báo thư viện của RFID
#define SS_PIN 10 //SDA pin
#define RST_PIN 9 //Reset pin
#define LED_B 4 //Led xanh duong
#define LED_R 5 //Led đỏ
#define BUZZER 3 //Chân buzzer
MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup() 
{
  Serial.begin(9600);
  SPI.begin(); // khởi tạo SPI bus
  mfrc522.PCD_Init(); // khởi tạo MFRC522
  pinMode(LED_B, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  Serial.println();
}

void getInfo()
{
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

void loop() 
{
// Tìm thẻ mới
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Đọc UID của thẻ
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  //getInfo();
  //Show UID on serial monitor
  Serial.print("UID tag: ");
  String content= "";
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i],HEX));
  }
  Serial.println();
  Serial.print("Message: ");
  content.toUpperCase();
  if (content.substring(1) == "9A 21 95 02") //Cấp UID quyền truy cập cho thẻ
  {
    Serial.println("Có Quyền truy cập");
    Serial.println("--------------------");
    digitalWrite(LED_B, HIGH);
    tone(BUZZER, 600);
    delay(500);
    digitalWrite(LED_B, LOW);
    noTone(BUZZER);       
   }
   else 
   {
    Serial.println("Truy cập bị từ chối"); 
    Serial.println("--------------------");     
    digitalWrite(LED_R, HIGH);      
    tone(BUZZER, 300);    
    delay(700);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
    }
    delay(1000);
}
