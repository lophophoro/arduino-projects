int LED = 3;
int BRILLO;
int POT = 0; // pin analogico A0

void setup()
{
  // los pines analogos no se inician, pues siempre son entradas (INPUTS)
  // pinMode(PULSADOR, INPUT_PULLUP); //INPUT_PULLUP es una resistencia interna del chip ~20k ohm
  pinMode(LED, OUTPUT);
}

void loop()
{
  BRILLO = analogRead(POT) / 4; // analogRead lee valores 0 - 1023 (tiene mas resolucion, hay que dividirla en 4)
  analogWrite(LED, BRILLO);     // analogWrite escribe en el rango 0-255
}
