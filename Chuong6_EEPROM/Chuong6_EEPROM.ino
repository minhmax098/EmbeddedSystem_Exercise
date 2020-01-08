#include <EEPROMex.h>
#include <EEPROMVar.h>

int address =0;
byte input =100;
byte output =0;

void setup() {
 
  Serial.begin(9600);

  for(int i=0; i<input.length(); i++){
    address++;
    EEPROM.read(address, input[i]);
   
  }
  address =-1;
  for(int i=0; i<input.length(); i++){
    address++;
    char a = output;
    Serial.print(a);
  }
  Serial.print(a);
}
 
void loop() {
 
}
 
