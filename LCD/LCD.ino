#include <LiquidCrystal.h>

//indicar a que pines se conectan rs e d3 d2 d1 d0
LiquidCrystal lcd(7,6,5,4,3,2); 

void setup() {
  //indicar tamaño de la pantalla. columnas por lineas, en ese orden
  lcd.begin(16,2);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("hola, han pasado");
  //poner el curson en la segunda linea
  lcd.setCursor(0,1);
  lcd.print(millis() / 1000);
  lcd.print(" seg");
}
