#define ledMorse 13

void setup() {
  pinMode(ledMorse, OUTPUT);
  digitalWrite(ledMorse, LOW);

}

void loop() {
  for (int i=0; i<3; i++){ // Phat 3 lan tin hieu tick
    digitalWrite(ledMorse, HIGH);
    delay(150);
    digitalWrite(ledMorse, LOW);
    delay(150);
  }
  delay(500);
  for (int i=0; i<3; i++){ // Phat 3 lan tin hieu te
    digitalWrite(ledMorse, HIGH);
    delay(300);
    digitalWrite(ledMorse, LOW);
    delay(150);
  }
  delay(500);
  for (int i=0; i<3; i++){ // Phat 3 lan tin hieu tick
    digitalWrite(ledMorse, HIGH);
    delay(150);
    digitalWrite(ledMorse, LOW);
    delay(150);
  }
  delay(5000);
}
