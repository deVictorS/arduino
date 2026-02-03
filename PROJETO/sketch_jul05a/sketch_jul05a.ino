int const p_chave1 = 5;
int const led = 11;
int CH1 = 0;


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Definir o endereço I2C do módulo ICD
#define LCD_ADDRESS 0x27

// Definir o número de colunas e linhas do ICD
#define LCD_COLUNAS 16 
#define LCD_LINHAS 2

// Criar um objeto LiquidCrystal I2C
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUNAS, LCD_LINHAS);


//////////////////////////////////////////////////////////////////
//Protótipo da função utilizada para utilizar o sensor ultrassônico
long dist = 0;

//Prototipo de funcao
long ler_ultrasom(int pino_trigger, int pino_echo); //Trigger: envia sinal; Echo: recebe sinal

//Configuração
void setup() {

  pinMode(2, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(p_chave1, INPUT);
  pinMode(led, OUTPUT);

// Inicializar a comunicação I2C
Wire.begin();

// Inicializar o ICD
lcd.begin(LCD_COLUNAS, LCD_LINHAS);

// Limpar o conteúdo do ICD
lcd.clear();

// Ligar a luz de fundo
lcd.backlight();

  
  Serial.begin(9600);//Comunicação serial
}

//Loop Principal
void loop() {
  CH1 = digitalRead(p_chave1);

  digitalWrite(2, HIGH);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  
  dist= ler_ultrasom(8,7);//Medição da distância 

  Serial.print(dist);//Printar no monitor serial a distância medida
  Serial.println(" cm");//Unidade de medida
  
  lcd.setCursor(0,0);
  lcd.print("Distancia: ");

  lcd.setCursor(0,1);
  lcd.print(dist);

  delay(100);// aguardar 100ms

  if(CH1 == 1){
    digitalWrite(led, HIGH);
    lcd.setCursor(2,1);
    lcd.print(-dist);
    
    
  }
  else{
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
  delayMicroseconds(2);//Delay de 2ms

  //Colocando Trigger em alto por 10ms
  digitalWrite(pino_trigger, HIGH);//Colocando o trigger em alto por 10ms  
  delayMicroseconds(10); 
  digitalWrite(pino_trigger, LOW);

  pinMode(pino_echo, INPUT);//Definindo o pino echo como entrada
 
  //Retorna
  pulso = pulseIn(pino_echo, HIGH, 0);
  return pulso*0.01723;//Corrigindo a velocidade do som ao multiplicar o valor do pulso por 0.01723

   

 }
 
