#include <EEPROM.h>


char example_string[] = "New String";

const int eeprom_size = 500; // values saved in eeprom should never exceed 500 bytes
char eeprom_buffer[eeprom_size];

char first_eeprom_value;



void setup() {
 
  Serial.begin(9600); // serial communication initialize
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
 
}

void loop() {
 
  delay(2000);
 
  first_eeprom_value = EEPROM.read(0);
 
  if(first_eeprom_value != '~'){
 
    Serial.println("No value saved in EEPROM... ");
  
    save_string_to_eeprom(example_string);
  
 
  } else {
   
    Serial.println("EEPROM value exists... Dishing it out");
   
    read_string_from_eeprom(eeprom_buffer);
   
    Serial.println(eeprom_buffer);
 
  }
 
}

void save_string_to_eeprom(char* stringIn){
 
  for(int i = 0; i < (strlen(stringIn) - 1); i++){
   
      EEPROM.write(i, stringIn[i]);
   
  }

}

void read_string_from_eeprom(char* theBuffer){
 
  for(int i = 0; i < (strlen(theBuffer) - 1); i++){
  
    theBuffer[i] = EEPROM.read(i);
  
  }

}
