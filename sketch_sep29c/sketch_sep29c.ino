int led = 13;
boolean led_status;

void setup() {                
  pinMode(led, OUTPUT);   
  led_status = true;     // led ở trạng thái bật
}

void loop() {
  digitalWrite(led, led_status);     // bật đèn, led_status = 1
  delay(1000);              
  digitalWrite(led, !led_status);    // tắt đèn, !led_status = 0
  delay(1000);          
}
