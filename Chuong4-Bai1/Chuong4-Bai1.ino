
char buffer[20];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Thiet lap ket noi tuan tu va co toc do 9600
  Serial.flush();   // Dam bao khong co du lieu ton dong trong kenh tuan tu

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
  int index = 0;
  delay(100); // let the buffer fill up, nhận hết các kí tự trước khi xử lí 
  int numChar = Serial.available();
  if (numChar > 15){
    numChar = 15;
  }
  while(numChar--){
   buffer[index++] = Serial.read();
  }
    //splitString(buffer); //in ra lại
  Serial.println(buffer);
  } 
  

}
