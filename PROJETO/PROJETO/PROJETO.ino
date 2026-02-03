//Incluindo as bibliotecas do display LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Definição do endereço do módulo LCD
#define LCD_ADDRESS 0x27

//Definindo o número de colunas e linhas do LCD
#define LCD_COLUNAS 16 //LCD de 16 colunas
#define LCD_LINHAS 2\\E 2 linhas

//Criando um objeto LiquidCrystal LCD
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUNAS, LCD_LINHAS);

//Protótipo da função utilizada para utilizar o sensor ultrassônico
long dist = 0;//Variável que recebe a distância a ser medida

//Protótipo de função
long ler_ultrasom(int pino_trigger, int pino_echo); //Trigger: envia sinal; Echo: recebe sinal

//Declarção das variáveis
int const p_bot1 = 5;//Variável responsável pelo botão
int const led = 11;//Variável responsável pelo led
int bot1 = 0;//Variável responsável por receber o estado do botão

//Configuração
void setup() {

  //Funções das portas utilizadas
  //Utilizamos as portas 2, 0 e 1 como fonte 5V
  pinMode(2, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(led, OUTPUT);
  //Porta que recebe sinal externo e enviar ao Arduino
  pinMode(p_bot1, INPUT);

  // Inicializar a comunicação I2C
  Wire.begin();

  //Inicializando o LCD
  lcd.begin(LCD_COLUNAS, LCD_LINHAS);

  //Limpando o conteúdo do LCD
  lcd.clear();

  //Ligando a luz de fundo
  lcd.backlight();

}

//Repetição
void loop() {
  
  bot1 = digitalRead(p_bot1);//Variável recebe o estado do botão

  //Portas utilizadas como fonte 5V
  digitalWrite(2, HIGH);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  
  dist= ler_ultrasom(8,7);//Medição da distância 


  //Escrevendo no display na linha zero e coluna zero a palavra Distância
  lcd.setCursor(0,0);
  lcd.print("Distancia: ");

  //Apresentando o valor medido pelo sensor na linha 2 e coluna zero
  lcd.setCursor(0,1);
  lcd.print(dist);

  delay(100);//Delay de medida

  //Condição para fixar o valor desejado ao pressionar o botão e acender o led
  if(bot1 == 1){//Se o botão for pressionado (valor lógico = 1)
    digitalWrite(led, HIGH);//O led acende (sáida alta)
    
    //Apresenta no display o valor da distância a ser fixada na segunda linha e primeira coluna
    lcd.setCursor(2,1);
    lcd.print(-dist);
    
  }
  else{//Se o botão não for pressionado, o led não acende e nenhum valor é fixado
    digitalWrite(led, LOW);
  }
 
}
  //Função
  long ler_ultrasom(int pino_trigger, int pino_echo)
 {
  int pulso = 0;
  
  //Definindo o tempo de envio de pulsos do trigger
  pinMode(pino_trigger, OUTPUT);//Configurando o pino trigger como saída
  digitalWrite(pino_trigger, LOW);//Colocando em zero
  delayMicroseconds(2);//Delay de ums

  //Colocando Trigger em alto por 10us
  digitalWrite(pino_trigger, HIGH);//Colocando o trigger em alto 
  delayMicroseconds(10);//Delay de 10us
  digitalWrite(pino_trigger, LOW);//Colocando em zero

  pinMode(pino_echo, INPUT);//Definindo o pino echo como entrada
 
  //Retorna
  pulso = pulseIn(pino_echo, HIGH, 0);
  return pulso*0.01723;//Corrigindo a velocidade do som ao multiplicar o valor do pulso por 0.01723

 }
 
