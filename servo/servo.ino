#include <Servo.h>

 Servo servo1;
 int PINSERVO = 2;
 int PULSOMIN= 500;
 int PULSOMAX = 2500;
 int VALORPOT;
 int ANGULO;
 int POT=0;//pin Analogico 0

void setup() {
  //servo
  servo1.attach(PINSERVO,PULSOMIN,PULSOMAX);

  //las entradas analogicas no requieren inicializacion
}

void loop() {
  //leer valor de la entrada analogica (analogRead devuelve valores en el rango 0-1023)
  VALORPOT=analogRead(POT);
  
  //map recibe un valor en el rango 0-1023 y devuelve el equivalente en grados 0-180
  ANGULO=map(VALORPOT, 0, 1023, 0, 180);
  servo1.write(ANGULO);
  delay(20);//se le da tiempo al servo para cambiar de pocision
}
