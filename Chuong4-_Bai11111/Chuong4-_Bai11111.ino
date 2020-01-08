char buffer[17]; //16 ky tu va 1 ky tu enter
int redLED = 9;
int greenLED = 10;
int blueLED = 11;
void setup()
{
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}
//Ham substring tu viet
void substring(char string[], char subString[], int position, int stringLength) 
{
   int i = 0;
   while (i < stringLength) 
   {
      subString[i] = string[position + i];
      i++;
   }
   subString[i] = '\0'; //Ky tu ket thuc
}
void setLed(char parameter[])
{
  char value[4];
  substring(parameter, value, 1, 3);
  int lightValue = atoi(value);
  if(parameter[0] == 'R')
    analogWrite(redLED, lightValue);
  else if(parameter[0] == 'G')
    analogWrite(greenLED, lightValue);
  else if(parameter[0] == 'B')
    analogWrite(blueLED, lightValue);
}
void splitString(char buffer[])
{
  char *parameter;
  parameter = strtok(buffer, ", ");
  while(parameter != NULL)
  {
    setLed(parameter);
    parameter = strtok(NULL, ", ");
  }
  Serial.println(parameter);
}
void allLedOff()
{
  analogWrite(redLED, 0);
  analogWrite(greenLED, 0);
  analogWrite(blueLED, 0);
}
  
void loop()
{
  int validFlag = 1;
  if(Serial.available() > 0)
  {
    allLedOff();
    int index = 0;
    delay(100);
    int numChar = Serial.available();
    if(numChar > 17)
    { 
      numChar = 17;
      Serial.println("Nhap sai cu phap!");
      validFlag = 0;
    }
    while(numChar--)
    {
      buffer[index++] = Serial.read();
    }
  }
  if(isAlpha(buffer[0]))
  {
    splitString(buffer);
  }
  //Code de in lenh ra xem ------
  if(validFlag == 1)
  {
    for(int a = 0;a < 16; a++)
    { 
      Serial.print(buffer[a]);
    }
    Serial.println();
  }
  //Code de in lenh ra xem ------
  memset(buffer, 0, sizeof(buffer)); //Xoa string buffer sau moi lan lap
  delay(1000);
}
