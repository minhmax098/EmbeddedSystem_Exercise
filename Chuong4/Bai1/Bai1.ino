#include <ESP8266WiFi.h> //Thư viện ESP8266
#include<string.h>
int led1 = D0;
int led2 = D1;
int led3 = D2;
char data[20] ={};
void setup() {
  Serial.begin(9600);
  Serial.flush();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
   int index = 0;
   delay(100);
   int numChar = Serial.available();
   if(numChar > 15)
   {
    numChar = 15;
   }
   while(numChar --){
   data[index++] = Serial.read();
   
   }
   Serial.println("In chuoi");
    Serial.println(data);
  }

 
  char *para ;
 para = strtok (data, " ,");
  while(para != NULL){
   setLED(para);
    para = strtok(NULL, " ,");
 }
}

int changeType(char *s)
{
  int r = 0;
  for(int i = 0; i < strlen(s) ; i++)
  {
    r = r*10 + (s[i]);
  }
  return r;
}

void setLED(char * parameter)
{
  char temp[20] = {};
//  strcpy(temp, parameter);
  int j =0;
  for(int i = 1 ; i < strlen(parameter); i++){
    temp[j++] = parameter[i];
   
  }
  int k = changeType(temp);
  if(parameter[0] == 'G'){
    analogWrite(led1, k);
  }
  if(parameter[0] == 'B'){
    analogWrite(led2, k);
   }
 if(parameter[0] == 'R'){
   analogWrite(led3, k);
   } 
}
