//Bài 3:
int ledPin[] = {2,3,4,5,6,7,8,9,10,11}; // Mảng lưu vị trí các chân Digital mà các đèn LED sử dụng theo thứ tự từ 3->12.
void setup() {
    
  for (int i=0; i<10; i++) {
    pinMode(ledPin[i],OUTPUT);  //Các chân LED là OUTPUT
    digitalWrite(ledPin[i],LOW); //Mặc định các đèn LED sẽ tắt
  }
}
void loop() {
  for (int i = 0; i < 10; i ++) {
    digitalWrite(ledPin[i],LOW); // Tắt đèn
  }
  
  //Bật tuần tự các đèn led
  for (int i=0; i < 10; i++) {
    digitalWrite(ledPin[i],HIGH); //Bật đèn
    delay(1000); // Dừng để các đèn LED sáng dần
  }
  
}
