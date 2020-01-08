//bÀI 6:
byte ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
void setup() 
{
 for (int i=0; i<10; i++) 
 {
    pinMode(ledPin[i],OUTPUT);  //Các chân LED là OUTPUT
    digitalWrite(ledPin[i],LOW); //M?c d?nh các dèn LED s? t?t
  }
}
void loop() 
{
  for (int x = 0; x <= 4; x++)
  {
    digitalWrite(ledPin[x], HIGH);
    int y = 100;
    y++;
    delay(500 - y);
  }
  delay(200);
  for (int x = 5; x <= 9; x++) 
  {
    digitalWrite(ledPin[x], HIGH);
    int z = 100;
    z++;
    delay(500 + z);
  }
  
  for (int x = 9; x >= 5; x--) 
  {
    digitalWrite(ledPin[x], LOW);
    int y = 100;
    y++;
    delay(500 - y);
  }

  for (int x =4 ; x >= 0; x--)
  {
    digitalWrite(ledPin[x], LOW);
    int z = 100;
    z++;
    delay(500 + z);
  }
}
