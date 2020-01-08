#include <deprecated.h>
#include <MFRC522.h>
//#include <MFRC522Extended.h>
#include <require_cpp11.h>

#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
#define OUT_PIN_GREEN 6
#define OUT_PIN_RED 7
#define NUMBER_OF_KEYS 2

MFRC522 mfrc522(SS_PIN, RST_PIN);

// Mảng có UID RFID được phép
static unsigned short code[NUMBER_OF_KEYS][4] = { {100, 200, 300, 400},{111, 222, 333, 444} };

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode (OUT_PIN_GREEN, OUTPUT);
  pinMode (OUT_PIN_RED, OUTPUT);

}
void loop()
{
  // Nếu thẻ RFID ở gần
  if (mfrc522.PICC_IsNewCardPresent())
  {
    unsigned short doOpen = checkID();
    if (doOpen != 0) {
      digitalWrite (OUT_PIN_GREEN, HIGH);
      delay (2000);
      digitalWrite (OUT_PIN_GREEN, LOW);
    }
    else {
      digitalWrite (OUT_PIN_RED, HIGH);
      delay (2000);
 
      digitalWrite (OUT_PIN_RED, LOW);
    }
  }
}

/**
   mfrc522.PICC_IsNewCardPftime() phải được kiểm tra trước.
    return 0 nếu sai, 1 nếu đúng
*/
unsigned short checkID() {
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return 0;
  }

  Serial.print("Groesse: "); Serial.println(mfrc522.uid.size);
  Serial.print("UID 1: "); Serial.println( mfrc522.uid.uidByte[0]);
  Serial.print("UID 2: "); Serial.println( mfrc522.uid.uidByte[1]);
  Serial.print("UID 3: "); Serial.println( mfrc522.uid.uidByte[2]);
  Serial.print("UID 4: "); Serial.println( mfrc522.uid.uidByte[3]);

  short doOpen = 0, i;
  for(i=0; i<NUMBER_OF_KEYS; i++){
    if(mfrc522.uid.uidByte[0]==code[i][0] && mfrc522.uid.uidByte[1]==code[i][1] && mfrc522.uid.uidByte[2]==code[i][2] && mfrc522.uid.uidByte[3]==code[i][3])
    {
      delay(2000);
      doOpen = 1;
      Serial.println("Code được chấp nhận!");
      break;
    }
   if(mfrc522.uid.uidByte[0] != code[i][0] && mfrc522.uid.uidByte[1] != code[i][1] && mfrc522.uid.uidByte[2] != code [i][2] && mfrc522.uid.uidByte[3] != code[i][3])
    {
      delay(2000);
      doOpen = 2;
      Serial.println("Code: ");
      break;
   }
   if(mfrc522.uid.uidByte[1] == code[i][0] && mfrc522.uid.uidByte[2] == code[i][1] && mfrc522.uid.uidByte[3] == code[i][2] && mfrc522.uid.uidByte[3] == code[i][3])
      {
        delay(2000);
        doOpen != 2;
        Serial.println("Tắt rồi bật 2 lần: ");
        break;
      }
    }
 
  
  mfrc522.PICC_HaltA(); // Dừng việc đọc
  return doOpen;
}
