int const p_vermelho = 9; // pino vermelho
int const p_verde = 10; // pino verde
int const p_azul = 11; // pino azul
int p_pot1 = A0; // pino analogico

int pot1 = 0;

void setup() 
{
  // configurando os pinos
  pinMode(p_vermelho, OUTPUT);
  pinMode(p_verde, OUTPUT);
  pinMode(p_azul, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  // lendo o potenciometro
  pot1 = analogRead(p_pot1);

  // led
  if (pot1 > 337)
  {
    
    digitalWrite(p_azul, HIGH);
  }
  
  else
  {
    
    digitalWrite(p_azul, LOW);
  }

    if (pot1 > 675)
  {
  
    digitalWrite(p_verde, HIGH);

  }
  
  else
  {
   
    digitalWrite(p_verde, LOW);

  }

    if (pot1 > 1000)
  {
    digitalWrite(p_vermelho, HIGH);

  }
  
  else
  {
    digitalWrite(p_vermelho, LOW);

  }
  // enviando a mensagem pela portsa serial
  Serial.println(0.00487 * pot1);
}
