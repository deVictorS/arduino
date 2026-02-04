int lamp = 4;
char LIGAR;
char DESLIGAR;
char BALADA;

void setup() {

  pinMode(lamp, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(100);
  
  if(Serial.available()>0){
    LIGAR = Serial.read();
    Serial.print(LIGAR);
    digitalWrite(lamp, HIGH);
    
  }

    
  
  if(Serial.available()>0){
    DESLIGAR = Serial.read();
    Serial.print(DESLIGAR);
    digitalWrite(lamp, LOW);
    
  }


    
}
