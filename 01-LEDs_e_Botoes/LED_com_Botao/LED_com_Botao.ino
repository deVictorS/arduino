int const p_azul = 12;
int const p_verde = 13;

int const p_chave1 = 2;
int const p_chave2 = 3;

int CH1 = 0;
int CH2 = 0;

void setup()
{
   //entradas
   pinMode(p_chave1, INPUT);
   pinMode(p_chave2, INPUT);

   //saida
   pinMode(p_verde, OUTPUT);
   pinMode(p_azul, OUTPUT);

   Serial.beggin(9600);
}

void loop()
{
   //lendo as chaves e armazenando as variaveis
   CH1 = digitalRead(p_chave1);
   CH2 = digitalRead(p_chave2);

   Serial.print

   // Acendendo os Leds
   //chave 1
   if (CH1 == 1)
   {
    digitalWrite(p_azul, HIGH);
   }
   else
   {
    digitalWrite(p_azul,LOW);
   }
   
   //chave 1
   if (CH2 == 1)
   {
    digitalWrite(p_verde, HIGH);
   }
   else
   {
    digitalWrite(p_verde,LOW);
   }
}
