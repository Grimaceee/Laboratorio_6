#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int poten_1 = 34; 
const int poten_2 = 35; 
const int aumento = 18; 
const int decremento = 19; 
int contador = 0;

