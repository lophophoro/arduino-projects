int PULSADOR = 2;
int LED = 3;
int ESTADO = LOW;

void setup() {
 pinMode(PULSADOR, INPUT);//pin 2 como entrada
 pinMode(LED, OUTPUT);    //pin 3 como salida
}

void loop() {
  while(digitalRead(PULSADOR)== LOW){ //esperar que se presione el pulsador
    
  }
  
  ESTADO=digitalRead(LED); //leer estado del LED
  digitalWrite(LED,!ESTADO);  //escribir el valor opuesto
  
  while(digitalRead(PULSADOR)== HIGH){//antirrebote
    
  }
}
