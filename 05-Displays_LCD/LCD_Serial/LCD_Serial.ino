#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Definir o endereço I2C do módulo ICD
#define LCD_ADDRESS 0x27

// Definir o número de colunas e linhas do ICD
#define LCD_COLUNAS 20 
#define LCD_LINHAS 4

// Criar um objeto LiquidCrystal I2C
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUNAS, LCD_LINHAS);


int p_pot1 = A0;
int pot1 = 0;

int ang = 0;


Servo serv;

void setup () {

serv.attach(9, 500, 2500);
pinMode(9, OUTPUT);
  
// Inicializar a comunicação I2C
Wire.begin();

// Inicializar o ICD
lcd.begin(LCD_COLUNAS, LCD_LINHAS);

// Limpar o conteúdo do ICD
lcd.clear();

// Ligar a luz de fundo
lcd.backlight();
}
void loop ()
{

pot1 = analogRead(p_pot1);
ang = map(pot1,0,1023,0,180);

  
lcd.setCursor(0,0);
lcd.print("Angulo do servo: ");

lcd.setCursor(0,1);
lcd.print(ang);

Serial.println(pot1);
serv.write(ang);



delay (20);
}
