//Entradas digitais do controle: 2,3,4,5,6 e 7
const byte p_digital = 8;

//Entradas analógicos são A0 e a1;
const byte p_X = 1;

//variáveis auxiliares
int valor_digital;
int valor_analogico;

void setup() 
{  
  Serial.begin(9600);

  pinMode(p_digital, INPUT);
}

void loop() 
{
  // aprensentar o valor digital
  valor_digital = digitalRead(p_digital);
  valor_analogico = analogRead(p_X);

  //escrevendo o valor digital
  if (valor_digital)
  {
    Serial.println("BOTAO LIBERADO");
  }
  else
  {
    Serial.println("BOTAO PESSIONADO");
  }
  // escrevendo o valor analógico
  Serial.print("valor do eixo: ");
  Serial.println(valor_analogico);
  delay(200);
}
