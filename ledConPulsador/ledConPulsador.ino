#define LED 2
#define PUSH 3

int pushvalue = 0;

Void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(PUSH, INPUT);
}

Void loop()
{
  pushvalue = digitalRead(PUSH);
  If(pushvalue == 1)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}