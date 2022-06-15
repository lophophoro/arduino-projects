int TRIG = 10;
int ECO = 9;
int LED = 3;
int DURACION;
int DISTANCIA;


void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600); //comunicacion por usb con el pc, donde 9600 es la velocidad (bit/sec) de la conexion
}

void loop() {
  digitalWrite(TRIG, HIGH);//emite sonido
  delay(1);
  digitalWrite(TRIG, LOW);//deja de emitir
  DURACION = pulseIn(ECO, HIGH); //justo al apagarse TRIG, pulseIn empieza a escuchar y devuelve la duracion del rebote.
  DISTANCIA = DURACION / 58.2; //58.2 es un valor especificado por el fabricante del sensor.
  Serial.println(DISTANCIA);
  delay(200);

  if(DISTANCIA <= 30 && DISTANCIA >=0){
      digitalWrite(LED, HIGH);
      delay(DISTANCIA*6);
      digitalWrite(LED, LOW);
    }
}
