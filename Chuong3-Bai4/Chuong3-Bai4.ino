//Bai 4

int ledPin[] = {2,3,4,5,6,7,8,9,10,11}; // M?ng luu v? trí các chân Digital mà các dèn LED s? d?ng theo th? t? t? 3->12.
int analogPin = A2;
void setup() {
    
  for (int i=0; i<10; i++) {
    pinMode(ledPin[i],OUTPUT);  //Các chân LED là OUTPUT
    digitalWrite(ledPin[i],LOW); //M?c d?nh các dèn LED s? t?t
  }
}
void loop() {
  for (int i = 0; i < 10; i ++) {
    digitalWrite(ledPin[i],HIGH); // T?t dèn
    delay(analogRead(A2));
  }
  
  //B?t tu?n t? các dèn led
  for (int i=0; i < 10; i++) {
    digitalWrite(ledPin[i],LOW); //B?t dèn
 delay(analogRead(A2)); // D?ng d? các dèn LED sáng d?n
  }
  
}
