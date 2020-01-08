
int latchPin = 12; //pin connetd to pin 12
int clockPin = 10;
int dataPin = 11;
byte anode[8];
byte kathode[8];
void setup() {
  pinMode (10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
//  anode[0] = B01000100;
//  anode[1] = B11101110;
//  anode[2] = B11111110;
//  anode[3] = B11111110;
//  anode[4] = B11111110;
//  anode[5] = B01111100;
//  anode[6] = B00111000;
//  anode[7] = B00010000;
  
//  kathode[7] = B11111110;
//  kathode[6] = B11111101;
//  kathode[5] = B11111011;
//  kathode[4] = B11110111;
//  kathode[3] = B11101111;
//  kathode[2] = B11011111;
//  kathode[1] = B10111111;
//  kathode[0] = B01111111;
//anode[0]=B11111111;
//1
 anode[0]= B00011000;
  anode[1]=B01000010;
  anode[2]=B10100101;
  anode[3]=B10000001;
  anode[4]=B10100101;
  anode[5]=B01011010;
  anode[6]=B00100100;
  anode[7]=B00011000;

//2
//    anode[0]=B00000000;
//  anode[1]=B00111000;
//  anode[2]=B01111100;
//  anode[3]=B10111010;
//  anode[4]=B10010010;
//  anode[5]=B10000010;
//  anode[6]=B01000100;
//  anode[7]=B00111000;
   //3
//  anode[0]=B00000000;
//  anode[1]=B00111000;
//  anode[2]=B01110100;
//  anode[3]=B11110010;
//  anode[4]=B11110010;
//  anode[5]=B10000010;
//  anode[6]=B01000100;
//  anode[7]=B00111000; 
  //4
//  anode[0]=B00000000;
//  anode[1]=B00111000;
//  anode[2]=B01000100;
//  anode[3]=B11100010;
//  anode[4]=B11110010;
//  anode[5]=B11100010;
//  anode[6]=B01000100;
//  anode[7]=B00111000; 
  //5
//  anode[0]=B00000000;
//  anode[1]=B00111000;
//  anode[2]=B01000100;
//  anode[3]=B10000010;
//  anode[4]=B11110010;
//  anode[5]=B11110010;
//  anode[6]=B01110100;
//  anode[7]=B00111000; 
  //6
//  anode[0]=B00000000;
//  anode[1]=B00111000;
//  anode[2]=B01000100;
//  anode[3]=B10000010;
//  anode[4]=B10010010;
//  anode[5]=B10111010;
//  anode[6]=B01111100;
//  anode[7]=B00111000; 
  //7
//  anode[0]=B00000000;
//  anode[1]=B00111000;
//  anode[2]=B01000100;
//  anode[3]=B10000010;
//  anode[4]=B10011110;
//  anode[5]=B10011110;
//  anode[6]=B01011100;
//  anode[7]=B00111000; 
  //8
//  anode[0]=B00000000;
//  anode[1]=B00111000;
//  anode[2]=B01000100;
//  anode[3]=B10001110;
//  anode[4]=B100111110;
//  anode[5]=B10001110;
//  anode[6]=B01000100;
//  anode[7]=B00111000; 


 }
 //Trong lần dịch bit thứ nhất của IC lần dịch bit này sẽ điều khiển các chân row
 //vậy sau khi dịch các dòng row đang có giá tri là 1. 
 //Những vị trí có số 1 trên đèn LED matrix sẽ là những ô sáng.
 void loop(){
  for (int i = 0; i<8; i++){
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,MSBFIRST,kathode[i]);
    shiftOut(dataPin,clockPin,MSBFIRST,anode[i]);
  delay(15);
    digitalWrite(latchPin,HIGH);
  }

 }
