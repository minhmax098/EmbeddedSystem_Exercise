byte ledPin[] = {2,3,4,5,6,7,8,9,10,11}; // Mảng lưu vị trí các chân Digital mà các đèn LED sử dụng theo thứ tự từ 2->5.
byte pinCount; // Khai báo biến pinCount dùng cho việc lưu tổng số chân LED
void setup() {
  pinCount = sizeof(ledPin);  
  for (int i=0;i<pinCount;i++) {
    pinMode(ledPin[i],OUTPUT);  //Các chân LED là OUTPUT
    digitalWrite(ledPin[i],LOW); //Mặc định các đèn LED sẽ tắt
  }
}
void loop() {
  //Bật tuần tự các đèn led
  for (int i=0; i < pinCount; i++) {
    digitalWrite(ledPin[i],HIGH); //Bật đèn
    delay(500); // Dừng để các đèn LED sáng dần
  }
  //Tắt tuần tự các đèn led
  for (int i = 0;i < pinCount; i += 1) {
    digitalWrite(ledPin[i],LOW); // Tắt đèn
    delay(500); // Dừng để các đèn LED tắt dần
  }
}
