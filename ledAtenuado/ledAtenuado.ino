int LED = 3;
int BRILLO;

void setup() {
 //pinMode(PULSADOR, INPUT_PULLUP); //INPUT_PULLUP es una resistencia interna del chip ~20k ohm
 pinMode(LED, OUTPUT);
}

void loop() {
  for(BRILLO = 0; BRILLO<256; BRILLO++){
    //el segundo parametro de analogWrite corresponde a que porcentaje activar de la onda. 255 = 5 volts, 0 = 0 volts
    analogWrite(LED, BRILLO);
    delay(15);
  }
  for(BRILLO = 255; BRILLO >= 0; BRILLO--){
    //el segundo parametro de analogWrite corresponde a que porcentaje activar de la onda. 255 = 5 volts, 0 = 0 volts
    analogWrite(LED, BRILLO);
    delay(15);
  }
}
