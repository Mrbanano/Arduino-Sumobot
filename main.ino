#include <NewPing.h>

#define TRIGGER_PIN  A3// Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A3  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int distancia;

int  ladoIzq=A0;
int  ladoDer=A1;
int  lineaA=11;
int  lineaB=12;

//Motores 
int stby=7;
// motores Izquierda
int MI_pwm=3;
int MI_A=5;
int MI_B=6;

// motores Derecha

int MD_pwm=10;
int MD_A=8;
int MD_B=9;



int v1,v2;
int ledRojo=4;
int ledAzul=2;
int iniciar=A4;
int a,b,c,d,e,f;

void setup() {
  
Serial.begin(9600);

  pinMode(ladoIzq,INPUT);
  pinMode(ladoDer,INPUT);
  pinMode(lineaA,INPUT);
  pinMode(lineaB,INPUT);
  pinMode(iniciar,INPUT);
  pinMode(ledRojo,OUTPUT);
  pinMode(ledAzul,OUTPUT);

  //pinMode(ultrasonico,INPUT);
  pinMode(MI_pwm,OUTPUT);
  pinMode(MI_A,OUTPUT);
  pinMode(MI_B,OUTPUT);
  pinMode(MD_pwm,OUTPUT);
  pinMode(MD_A,OUTPUT);
  pinMode(MD_B,OUTPUT);
  pinMode(stby,OUTPUT);
  pinMode(ledRojo,OUTPUT);
  pinMode(ledAzul,OUTPUT);


  digitalWrite(ledRojo,HIGH);
  delay(3000);
  digitalWrite(ledRojo,LOW);
  
}
