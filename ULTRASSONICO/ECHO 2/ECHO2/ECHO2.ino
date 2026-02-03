//Declaração  das variáveis e pinos utilizados;
int led = 12;//Led  
int p_pot1 = A0;//Potênciometro
int pot1 = 0;//Variável analógica a ser lida pelas informações do potênciometro
int led_1 = 0;//Variável digital a ser lida pelas informações do led

//Protótipo da função utilizada para utilizar o sensor ultrassônico
long dist = 0;
long ler_ultrasom(int pino_trigger, int pino_echo); //Trigger: envia sinal; Echo: recebe sinal

//Configuração
void setup() {
  
  Serial.begin(9600);//Comunicação serial
  pinMode(led, OUTPUT);//Atribuindo o modo do led
}

//Loop Principal
void loop() {

  dist= ler_ultrasom(8,7);//Medição da distância

  pot1 = analogRead(p_pot1);//Leitura dos valores analógicos relacionados ao potênciometro
  led_1 = digitalRead(led);//Leitura dos valores digitais relacionados ao led
  

  Serial.print(dist);//Printar no monitor serial a distância medida
  Serial.println(" cm");//Unidade de medida
  Serial.print(pot1 /34.13);//Printar no monitor serial a distância estabelecida pelo potênciometro. A divisão por 34.13 é para realizar o ajuste da unidade de medida
  Serial.println("Pot ");
  delay(500);

//Condição para que o led acenda de acordo com o valor pré-estabelecido pelo potênciometro
   if(dist >  pot1/34.13){
  digitalWrite(led, HIGH);
  
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

  digitalWrite(pino_trigger, HIGH);//Colocando o trigger em alto por 10ms  
  delayMicroseconds(10); 
  digitalWrite(pino_trigger, LOW);

  pinMode(pino_echo, INPUT);//Definindo o pino echo como entrada
 
  //Retorna
  pulso = pulseIn(pino_echo, HIGH, 0);
  return pulso*0.01723;//Corrigindo a velocidade do som ao multiplicar o valor do pulso por 0.01723

 
 }
 
