\\Declaração de variáveis
int bot1 = 0; \\ Variável que armazena o estado do botão
int p_bot1 = 8; \\Pino que irá ser ligado no botão
int rele = 7; \\Pino que irá ser ligado no relé

void setup() {

  \\Funções das portas
  pinMode(p_bot1, INPUT); \\Botão envia sinal para o arduino
  pinMode(rele, OUTPUT); \\Arduino envia ação para relé

}

void loop() {
  bot1 = digitalRead(p_bot1); \\Leitura do estado do botão (pressionado ou não)
  delay(100);
  

  \\Se o botão for pressionao o relé deverá fechar o circuito e acionar a lâmpada
  if(bot1 == 1){
    digitalWrite(rele,LOW); \\Estado LOW pois, o relé é NF
    delay(5000);
  }
  \\Caso botão não seja pressionado, nada acontece, relé fica em seu estado inicial
  else{
    digitalWrite(rele,HIGH);
  }
}
