#include <EEPROMex.h>
int address = 0;
String input = " 3 4 ";
byte output = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0; i<input.length(); i++)
  {
    address++;
    EEPROM.write(address, input[i]);
  }
  Serial.begin(9600);
  for(int i =0; i<input.length(); i++){
    address--;
    EEPROM.write(address, input[i]);
  }
  address = 1;
  for(int i= 0; i<input.length(); i++)
  {
    address++;
    output = EEPROM.read(address);
    char a = output;
    Serial.print(a);
  }
  
//  for(int i= 0; i<output.length(); i--)
//  {
//    address--;
//    input = EEPROM.write(address);
//    char b = input;
//    Serial.print(b);
//  }
  Serial.println("Chuoi sau khi read la: ");
  Serial.println("\t");
}

void loop() {
  // put your main code here, to run repeatedly:

}
