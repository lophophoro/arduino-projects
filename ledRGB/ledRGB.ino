int red_light_pin= 6;
int green_light_pin = 5;
int blue_light_pin = 3;
void setup() {//No es necesario llamar a pinMode () para configurar el pin como salida antes de llamar analogWrite().
//  pinMode(red_light_pin, OUTPUT);
//  pinMode(green_light_pin, OUTPUT);
//  pinMode(blue_light_pin, OUTPUT);
}
void loop() {
  RGB_color(255, 0, 0); // Red
  delay(1000);
  RGB_color(0, 255, 0); // Green
  delay(1000);
  RGB_color(0, 0, 255); // Blue
  delay(1000);
  RGB_color(255, 255, 125); // Raspberry
  delay(1000);
  RGB_color(0, 255, 255); // Cyan
  delay(1000);
  RGB_color(255, 0, 255); // Magenta
  delay(1000);
  RGB_color(255, 255, 0); // Yellow
  delay(1000);
  RGB_color(255, 255, 255); // White
  delay(1000);
}
//common anode
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, 255-red_light_value);
  analogWrite(green_light_pin, 255-green_light_value);
  analogWrite(blue_light_pin, 255-blue_light_value);
}

//common cathode
//void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
// {
//  analogWrite(red_light_pin, red_light_value);
//  analogWrite(green_light_pin, green_light_value);
//  analogWrite(blue_light_pin, blue_light_value);
//}
