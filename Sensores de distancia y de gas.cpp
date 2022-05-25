//SENSOR DE PERSONAS.
#include <Servo.h>  // servo library

Servo puerta;

int trig = 2;
int echo = 3;
int tiempo;
unsigned long distancia; 

//SENSOR DE GAS.
int gas;
int rojo = 13;
int amarillo = 12;
int verde = 11;

void setup()
{
  //SENSOR DE PERSONAS.
  Serial.begin(9600);
  pinMode(trig, OUTPUT); // Envía el sonido.
  pinMode(echo, INPUT); // Escucha el sonido.
  puerta.attach(4);
  
  //SENSOR DE GAS.  
  Serial.begin(9600); // Es para usar el monitor en serie.
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
}


void loop()
{
  //detectarPersonas();
  detectarGas();
}

//FUNCIÓN QUE DETECTA PERSONAS.
void detectarPersonas()
{
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo / 58.2;
  Serial.println(" cm ");
  Serial.print(distancia);
  delay(500);
  
  if (distancia <= 50)
  {
    puerta.write(180);
  }
  else if (distancia > 50)
  {
    puerta.write(0);
  }
}
  //FUNCIÓN DETECTAR GAS.
  void detectarGas()
{
  gas = analogRead(A5);
  Serial.println(gas); // Imprimir los valores.
  delay(500);
  
  if(gas < 930)
  {
    digitalWrite(verde, HIGH); // ENCIENDE EL LED VERDE.
    digitalWrite(amarillo, LOW); // Apaga el led amarillo.
    digitalWrite(rojo, LOW); // Apaga el led rojo.
  }
  else if ((gas > 930) & (gas < 960))
  {
    digitalWrite(verde, LOW); // Apaga el led verde.
    digitalWrite(amarillo, HIGH); // ENCIENDE EL LED AMARILLO.
    digitalWrite(rojo, LOW); // Apaga el led rojo.
  }
  else if (gas > 960)
  {
   digitalWrite(verde, LOW); // Apaga el led verde.
   digitalWrite(amarillo, LOW); // Apaga el led amarillo.
   digitalWrite(rojo, HIGH); // ENCIENDE EL LED ROJO. 
  }
  }
