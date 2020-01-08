//Bài tập 5: thay đổi bài tập 3 sao cho đèn sáng ở cả hai đầu
//Gặp nhau ở giữa và quay ngược lại
// 2 đầu sáng, tiếp đến giữa sáng rồi tắt và ngược lại

int ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
void setup() 
{
  for (int i=0; i<10; i++) 
  {
    pinMode(ledPin[i],OUTPUT);  //Các chân LED là OUTPUT
    digitalWrite(ledPin[i],LOW); //M?c d?nh các dèn LED s? t?t
  }
  
}
void loop() {
  digitalWrite(ledPin[0], HIGH);
  digitalWrite(ledPin[9], HIGH);
  delay(500);
  digitalWrite(ledPin[1], HIGH);
  digitalWrite(ledPin[8], HIGH);
  delay(500);
  digitalWrite(ledPin[2], HIGH);
  digitalWrite(ledPin[7], HIGH);
  delay(500);
  digitalWrite(ledPin[3], HIGH);
  digitalWrite(ledPin[6], HIGH);
  delay(500);
  digitalWrite(ledPin[4], HIGH);
  digitalWrite(ledPin[5], HIGH);
  delay(500);
  digitalWrite(ledPin[4], LOW);
  digitalWrite(ledPin[5], LOW);
  delay(500);
  digitalWrite(ledPin[3], LOW);
  digitalWrite(ledPin[6], LOW);
  delay(500);
  digitalWrite(ledPin[2], LOW);
  digitalWrite(ledPin[7], LOW);
  delay(500);
  digitalWrite(ledPin[1], LOW);
  digitalWrite(ledPin[8], LOW);
  delay(500);
  digitalWrite(ledPin[0],LOW);
  digitalWrite(ledPin[9], LOW);
  delay(500);
}
