int retardo=5; // tiempo de retardo en milisegundos (Velocidad del motor)
int dato_rx; // valor recibido en grados

#define in1 2
#define in2 3
#define in3 4
#define in4 5 

#define ledAmarillo 13
#define ledRojo     12
#define ledVerde    11

long distancia;
long tiempo;

#define trig 8
#define echo 9

void setup() {
   Serial.begin(9600);  //inicializamos el puerto serie a 9600 baudios
   pinMode(in4, OUTPUT); // Pin 11 conectar a IN4
   pinMode(in3, OUTPUT);// pin 10 conectar a IN3
   pinMode(in2, OUTPUT); // pin 9 conectar  a IN2
   pinMode(in1, OUTPUT); // pin 8 conectar  a IN1
   pinMode(ledAmarillo, OUTPUT);
   pinMode(ledRojo, OUTPUT);
   pinMode(ledVerde, OUTPUT);
   pinMode(trig, OUTPUT);
   pinMode(echo, INPUT);
}

void loop() {
 digitalWrite(trig,0);
 delayMicroseconds(5);
 digitalWrite(trig,HIGH); 
 tiempo=pulseIn(echo,HIGH); 
   tiempo=tiempo/2;
   distancia=int (0.034*tiempo);
   digitalWrite(ledRojo, LOW);
   digitalWrite(ledAmarillo,LOW);
   digitalWrite(ledVerde, LOW);

   if(distancia>=20 && distancia<30){
    digitalWrite(ledAmarillo,HIGH);
   }
   if(distancia<20 && distancia>0){
    digitalWrite(ledRojo,HIGH);
    for(int i=0;i<20;i++){
      paso_izq();
    }
    
   }
   if(distancia>=30){
    digitalWrite(ledVerde,HIGH);
    for(int i=0;i<20;i++){
      paso_der();
    }

   }
   apagado();
   Serial.print("Distancia: ");
   Serial.print(distancia);
   Serial.println(" cm");
   delay(500);
}

void paso_der(){
  digitalWrite(in4, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
  delay(retardo);
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  delay(retardo);
  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in1, HIGH);
  delay(retardo);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
  delay(retardo);
}

void paso_izq(){
  digitalWrite(in4, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
  delay(retardo);
  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  delay(retardo);
  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in1, HIGH);
  delay(retardo);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
  delay(retardo);
}

void apagado(){
  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
}
