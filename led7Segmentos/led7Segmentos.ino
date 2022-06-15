int pines[7] = {2,3,4,5,6,7,8};

int numeros[10][7]={
 //A B C D E F G
  {1,1,1,0,1,1,1},//0
  {0,0,1,0,0,1,0},//1
  {1,0,1,1,1,0,1},//2
  {1,0,1,1,0,1,1},//3
  {0,1,1,1,0,1,0},//4
  {1,1,0,1,0,1,1},//5
  {1,1,0,1,1,1,1},//6
  {1,0,1,0,0,1,0},//7
  {1,1,1,1,1,1,1},//8
  {1,1,1,1,0,1,1},//9
};


void setup() {
  for(int i=0; i<7; i++){
         pinMode(pines[i], OUTPUT);
  } 
}

void loop() {
  for(int i=0; i<9; i++){
    mostrarNumero(i);
    delay(1000);
  }
}
  
void mostrarNumero(int numValue){
  for(int i = 0;  i < 10; i++){//recorrer filas del array // en lugar de 7: (sizeof(numeros) / sizeof(numeros[0]))
    
    if(numValue==i){//buscar el numero en el array

      
      for(int j = 0; j < 7; j++){//recorrer columnas //en lugar de 10: (sizeof(numeros[i]) / sizeof(numeros[i][0]))

         if(numeros[i][j]==1){
            digitalWrite(pines[j],HIGH);
         }else{
            digitalWrite(pines[j],LOW);
         }
      }
      break;
    }
  }
}
  
  
  
