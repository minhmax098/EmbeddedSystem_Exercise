#define button 3
#define ledBlue1 4
#define ledBlue2 5
#define ledYellow 6
#define ledRed1 7
#define ledRed2 8

unsigned long timeChanged;
int count;

void setup() {
  pinMode(button, INPUT);
  
  pinMode(ledBlue1, OUTPUT);
  pinMode(ledBlue2, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed1, OUTPUT);
  pinMode(ledRed2, OUTPUT);

  digitalWrite(ledBlue1, HIGH);
  digitalWrite(ledBlue2, HIGH);
  
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed1, LOW);
  digitalWrite(ledRed2, LOW);

  timeChanged = millis();
  count = 0;
}

void loop() {
  int state = digitalRead(button);
  if (state == HIGH && (millis() - timeChanged)>5000){
    timeChanged = millis();
    changeLights();
  }

}
