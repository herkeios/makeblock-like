//Programa : Controle 2 motores DC usando Ponte H L298N
//Autor : FILIPEFLOP
 
//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

//int velocidadeA = 12;
//int velocidadeB = 13;

#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 8
#define pino_echo 9
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup()
{
  //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 //pinMode(velocidadeA,OUTPUT);
 //pinMode(velocidadeB,OUTPUT);
 Serial.begin(9600);
 Serial.println("Lendo dados do sensor...");
}
  
void loop()
{
 float cmMsec, inMsec;
 long microsec = ultrasonic.timing();
 cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
 Serial.print("Distancia em cm: ");
 Serial.print(cmMsec);
 Serial.print(" - Distancia em polegadas: ");
 Serial.println(inMsec);
  
 if (cmMsec > 40.0) { 
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
 }
 else {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

   //delay(500);

}
