int botao = 3;
int botao2 = 6;
int led = 7;
int led2 = 8;
int led3 = 9;
int estado;
int estado2;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);

  pinMode(led2, OUTPUT);
  pinMode(botao2, INPUT);

  pinMode(led3, OUTPUT);


  

}

void loop() {

  estado = digitalRead(botao);

  if(estado == HIGH){
    digitalWrite(led, HIGH );
    
    
  }

  else{
    digitalWrite(led, LOW);
  }

  estado2 = digitalRead(botao2);

  if(estado2 == HIGH){
    digitalWrite(led2, LOW);
    
    
    
  }

  else{
    digitalWrite(led2, HIGH);
    
  }

  if(estado == HIGH && estado2 == HIGH){
    digitalWrite(led3, HIGH);
    
  }

  else{
    digitalWrite(led3, LOW);
  }
  
  

}
