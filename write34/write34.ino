#include <EEPROM.h>
#include <string.h>
//bắt đầu đọc tại ô nhớ thứ 0
int address = 0;
byte input = 0;
byte output = 0;
String st;

void setup()
{
  Serial.begin(9600);
  EEPROM.write(address, input);
  output = EEPROM.read(address);
  Serial.print(address);
  Serial.print("\t");
  Serial.print(output);
  Serial.println();
}

void loop()
{
  while (Serial.available()) {
    delay(2);  //delay to allow byte to arrive in input buffer
    char c = Serial.read();
    st += c;
  }
  if (st.length() >0)
  {
    Serial.println(st);
  }
  String n1,n2;
  int t=0;
  if (st.substring(0,5) == "write")
  {
    for (int i=6; i<st.length(); i++)
    {
      n1 += st[i];
      if (st[i+1] == ' ')
      {
        t=i+2;
        break;
      }
    }
    for (int i=t; i<st.length(); i++)
    {
      n2 += st[i];
      if (st[i+1] == ' ')
      {
        break;
      }
    }
    address=atoi(n1.c_str());
    input=atoi(n2.c_str());
    EEPROM.write(address, input);
    st="";
  }
  if (st.substring(0,4) == "read")
  {
    for (int i=5; i<st.length(); i++)
    {
      n1 += st[i];
    }
    address=atoi(n1.c_str());
    output = EEPROM.read(address);
    Serial.print(address);
    Serial.print("\t");
    Serial.println(output);
    st="";
  }
  delay(1000);
}
