int led = 5;
long dist=0;

long ler_ultrasom(int pino_trigger, int pino_echo);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  dist= ler_ultrasom(7,8);

  Serial.print(dist);
  Serial.println("cm");
  delay(100);
}
  long ler_ultrasom(int pino_trigger, int pino_echo)
 {
pinMode(pino_echo, INPUT);
pinMode(pino_trigger, OUTPUT);
int pulso = 0;


digitalWrite(pino_trigger, LOW);
delayMicroseconds(2);

digitalWrite(pino_trigger, HIGH);   
delayMicroseconds(10); 
digitalWrite(pino_trigger, LOW);
 

pulso = pulseIn(pino_echo, HIGH, 0);
 return pulso*0.01723;
 if(pulso < 20){
  digitalWrite(led, HIGH);
 }
 
 }
 
