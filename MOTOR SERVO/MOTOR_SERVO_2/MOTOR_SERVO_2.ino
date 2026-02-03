#include <Servo.h>

int eixo_x = 0;
int eixo_Y = 0;

int angulo_X = 0;
int angulo_Y = 0;


Servo servo_x;
Servo servo_Y;


void setup() 
{
  Serial.begin(9600);
  servo_x.attach(9, 500, 2500);
  servo_Y.attach(10, 500, 2500);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT); 
  // ligando o servo ao pino 3
  // 500 valor mínimo pulso 
  // 2500 valor máximo do pulso
  
}

void loop() {

  eixo_x = analogRead(0);
  angulo_X = map(eixo_x,0,1023,0,180);
  
  eixo_Y = analogRead(1);
  angulo_Y = map(eixo_Y,0,1023,0,180); 

  // atualizando o servo motor 
  Serial.println(eixo_x);
  servo_x.write(angulo_X);

  Serial.println(eixo_Y);
  servo_Y.write(angulo_Y);

}
