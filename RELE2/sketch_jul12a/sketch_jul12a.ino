\\Declaração de variáveis
int lamp = 4;
char LIGAR;
char DESLIGAR;

void setup() {

  Serial.begin(9600);
}

void loop() {
  delay(100);
  
  \\Condição para acender a lâmpada
  if(Serial.available()>0){ \\Serial Available retorna a quantidades de bytes disponíveis para leitura no buffer de leitura
    LIGAR = Serial.read(); \\Se for escrito LIGAR no monitor serial, o micro irá ler esta mensagem e acionar a lâmpada
    Serial.print("Comando");
    Serial.println(LIGAR); \\Estado da lâmpada será escrito
    digitalWrite(lamp, HIGH);
    
  }

  }

  \\Condição para apagar a lâmpada
  if(Serial.available()>0){
    DESLIGAR = Serial.read(); \\Se for escrito DESLIGAR no monitor serial, o micro irá ler esta mensagem e desativar a lâmpada
    Serial.print("Comando");
    Serial.println(DESLIGAR); \\Estado da lâmpada será escrito
    digitalWrite(lamp, LOW);
    
  }
}
