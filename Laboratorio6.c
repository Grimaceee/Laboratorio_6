#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#define I2C_SDA 21
#define I2C_SCL 22

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int poten_1 = 34; 
const int poten_2 = 35; 
const int aumento = 18; 
const int decremento = 19; 
int contador = 0;

void setup() {
  lcd.init(I2C_SDA, I2C_SCL);
  lcd.begin(16, 2); 
  lcd.backlight(); 
  lcd.clear();
  pinMode(poten_1, INPUT);
  pinMode(poten_2, INPUT);
  pinMode(aumento, INPUT_PULLUP);
  pinMode(decremento, INPUT_PULLUP);
}

void loop() {
  
  int analog_1 = analogRead(poten_1);
  int analog_2 = analogRead(poten_2);
  
  float medicion_1 = analog_1 * (3.3 / 4095.0); 
  float medicion_2 = analog_2 * (3.3 / 4095.0); 
  

  int boton1 = digitalRead(aumento);
  int boton2 = digitalRead(decremento);

  if (boton1 == LOW) {
    contador++;
    if (contador > 255) contador = 255; 
    delay(200); 
  }
  
  if (boton2 == LOW) {
    contador--;
    if (contador < 0) contador = 0; 
    delay(200); 
  }
  
  // Mostrar datos en el LCD
  
  lcd.setCursor(0, 0);
  lcd.print("V1:");
  lcd.print(medicion_1, 2); 
  lcd.print(" V2:");
  lcd.print(medicion_2, 2); 
  
  lcd.setCursor(0, 1);
  lcd.print("Count:");
  lcd.print(contador);
  
  delay(1); 
}
