int RELE = 2;


void setup() {
pinMode(RELE, OUTPUT);
}

void loop() {
  digitalWrite(RELE,HIGH);
  delay(5000);
  digitalWrite(RELE, LOW);
  delay(5000);
}
