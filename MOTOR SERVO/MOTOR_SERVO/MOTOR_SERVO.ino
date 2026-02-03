#include <Servo.h> //Inclusão da biblioteca do servomotor no código

//Declaração das variáveis que se referem aos eixos do joystick
int eixo_x = 0;
int eixo_Y = 0;

//Declaração das variáveis que se referem aos ângulos de giro do servomotor
int angulo_X = 0;
int angulo_Y = 0;

//Declaração dos motores de controle pelo eixo-x e eixo-y
Servo servo_x;
Servo servo_Y;


void setup() 
{
  Serial.begin(9600);//Comunicação serial
  servo_x.attach(9, 500, 2500); //Ligando o servo controlado pelo eixo-x ao pino 9, com 500 o valor mínimo do pulso e 2500 o valor máximo
  servo_Y.attach(10, 500, 2500); //Ligando o servo controlado pelo eixo-y ao pino 10, com 500 o valor mínimo do pulso e 2500 o valor máximo

  //Atribuindo as funções das portas
  pinMode(9, OUTPUT);//Servo-x
  pinMode(10, OUTPUT);//Servo-y
  
}

void loop() {

  eixo_x = analogRead(0);//Leitura das informações analógicas que se referem ao eixo-x
  angulo_X = map(eixo_x,0,1023,0,180);//Mapeamento de valores em um intervalo de tempo, relacionando o ângulo do servomotor-x e o eixo-x do joystick
  
  eixo_Y = analogRead(1);//Leitura das informações analógicas que se referem ao eixo-y
  angulo_Y = map(eixo_Y,0,1023,0,180);//Mapeamento de valores em um intervalo de tempo, relacionando o ângulo do servomotor-y e o eixo-y do joystick

  //Atualizando o servo motor
  //Printando no monitor serial as infomações de ângulo do servo motor relacionado ao eixo-x
  Serial.println(eixo_x);
  servo_x.write(angulo_X);

  //Printando no monitor serial as infomações de posição da chave relacionada ao eixo-x
  Serial.println(0.09775 * eixo_x);
  Serial.print(" %");

  //Printando no monitor serial as infomações de ângulo do servo motor relacionado ao eixo-y  
  Serial.println(eixo_Y);
  servo_Y.write(angulo_Y);

  //Printando no monitor serial as infomações de posição da chave relacionada ao eixo-y
  Serial.println(0.09775 * eixo_y);
  Serial.println(" %");

}
