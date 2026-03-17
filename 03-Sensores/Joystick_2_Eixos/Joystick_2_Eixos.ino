//Entradas digitais do controle: 2,3,4,5,6 e 7
const byte p_digital_a= 2;
const byte p_digital_b= 3;
const byte p_digital_c= 4;
const byte p_digital_d= 5;
const byte p_digital_e= 6;
const byte p_digital_f= 7;
const byte p_digital_k= 8;

//Entradas analógicos são A0 e a1;
const byte p_X = 0;
const byte p_y = 1;

//variáveis auxiliares
int valor_digital_a;
int valor_digital_b;
int valor_digital_c;
int valor_digital_d;
int valor_digital_e;
int valor_digital_f;
int valor_digital_k;
int valor_analogico_x;
int valor_analogico_y;

void setup() 
{  
  Serial.begin(9600);

  pinMode(p_digital_a, INPUT);
  pinMode(p_digital_b, INPUT);
  pinMode(p_digital_c, INPUT);
  pinMode(p_digital_d, INPUT);
  pinMode(p_digital_e, INPUT);
  pinMode(p_digital_f, INPUT);
  pinMode(p_digital_k, INPUT);
}

void loop() 
{
  // aprensentar o valor digital
  valor_digital_a = digitalRead(p_digital_a);
  valor_digital_b = digitalRead(p_digital_b);
  valor_digital_c = digitalRead(p_digital_c);
  valor_digital_d = digitalRead(p_digital_d);
  valor_digital_e = digitalRead(p_digital_e);
  valor_digital_f = digitalRead(p_digital_f);
  valor_digital_k = digitalRead(p_digital_k);
  valor_analogico_x = analogRead(p_X);
  valor_analogico_y = analogRead(p_y);

  //escrevendo o valor digital
    Serial.print("A: ");
  Serial.println(valor_digital_a);
  delay(200);
    Serial.print("B: ");
  Serial.println(valor_digital_b);
  delay(200);
    Serial.print("C: ");
  Serial.println(valor_digital_c);
  delay(200);
    Serial.print("D: ");
  Serial.println(valor_digital_d);
  delay(200);
    Serial.print("E: ");
  Serial.println(valor_digital_e);
  delay(200);
    Serial.print("F: ");
  Serial.println(valor_digital_f);
  delay(200);
    Serial.print("K: ");
  Serial.println(valor_digital_k);
  delay(200);

  // escrevendo o valor analógico
  Serial.print("valor do eixo X: ");
  Serial.println(valor_analogico_x);
  delay(200);
  Serial.print("valor do eixo Y: ");
  Serial.println(valor_analogico_y);
  delay(200);
}
