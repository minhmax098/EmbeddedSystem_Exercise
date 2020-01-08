led = 13;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  blink();
}

void blink() {
  digitalWrite(led, LOW);
  delay(1000);
  digitalWrite(led, HIGH);
  delay(1000);
}
