#include <LiquidCrystal.h>

int cont = 0;
int cont1 = 0;

// Criando um objeto do tipo LiquidCrystal e ajustando os pinos de entrada
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd_2(12, 11, 5, 4, 3, 2);


void setup()
{
  // Configurar o tamanho do LCD 16 colunas 2 linhas
  lcd_1.begin(16, 2);

  // Apresentar uma mensagem no LCD

}

void loop()
{
  //
  //

  lcd_1.setCursor(9, 1);
  lcd_1.print(":");
  
  lcd 1.setCursor(10, 1);
  if (cont <10


}
