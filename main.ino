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


// motors

void atras()
{
analogWrite(MI_pwm,v1);digitalWrite(MI_A,HIGH);digitalWrite(MI_B,LOW);analogWrite(MD_pwm,v2);digitalWrite(MD_A,HIGH);digitalWrite(MD_B,LOW);digitalWrite(stby,HIGH);
}

void avanzar()
{
analogWrite(MI_pwm,v1);digitalWrite(MI_A,LOW);digitalWrite(MI_B,HIGH);analogWrite(MD_pwm,v2);digitalWrite(MD_A,LOW);digitalWrite(MD_B,HIGH);digitalWrite(stby,HIGH);
}


void rotarIzq()
{
 analogWrite(MI_pwm,v1);digitalWrite(MI_A,HIGH);digitalWrite(MI_B,LOW);analogWrite(MD_pwm,v2);digitalWrite(MD_A,LOW);digitalWrite(MD_B,HIGH);digitalWrite(stby,HIGH);
}


void rotarDer()
{ 
 analogWrite(MI_pwm,v1);digitalWrite(MI_A,LOW);digitalWrite(MI_B,HIGH);analogWrite(MD_pwm,v2);digitalWrite(MD_A,HIGH);digitalWrite(MD_B,LOW);digitalWrite(stby,HIGH);
}

 void alto()
{
 analogWrite(MI_pwm,v1);digitalWrite(MI_A,LOW);digitalWrite(MI_B,LOW);analogWrite(MD_pwm,v2);digitalWrite(MD_A,LOW);digitalWrite(MD_B,LOW);digitalWrite(stby,HIGH);  
}




void hayalgo(){
  e =sonar.ping_cm();
  if(e<15 ){f=0;}
  else{f=1;}
  
  }
void loop() {

  
  
v1=120;
v2=120;
//1 significa no hay nada 
// 0 encontre algo 
  

  a=digitalRead(ladoIzq);
  b=digitalRead(ladoDer);
  c=digitalRead(lineaA);
  d=digitalRead(lineaB);
  

   digitalWrite(ledAzul,HIGH);
 

Serial.print(a);Serial.print(b);Serial.print("\n \n");
hayalgo();
if(c==1)   // Si la lectura del infrarrojo #1 es 0, entonces se cumplira una de las siguientes condiciones:
{
  if(d==1)  // Si la lectura del infrarrojo #2 es 0, es decir los dos sensores estan sobre la linea negra, entonces los dos motores avanzaran en linea recta.
      {
        //algo enfrente = algo izquierda = algo derecha 
        if      (f ==0 && a==0 && b==0){avanzar();}
        //algo enfrente = algo izquierda = nada derecha
        else if (f ==0 && a==0 && b==1){v1=200;v2=200;rotarDer();delay(250);v1=255;v2=255;avanzar();}
        //algo enfrente = nada izquierda = algo derecha
        else if (f ==0 && a==1 && b==0){v1=200;v2=200;rotarIzq();delay(250);v1=255;v2=255;avanzar();}
        //algo enfrente = nada izquierda = nada derecha
        else if (f ==0 && a==1 && b==1){v1=255;v2=255; avanzar();}
        //nada enfrente = algo izquierda = algo derecha
        else if (f ==1 && a==0 && b==0){avanzar();}
        //nada enfrente = algo izquierda = nada derecha
        else if (f ==1 && a==0 && b==1){v1=200;v2=200;rotarDer();}
        //nada enfrente = nada izquierda = algo derecha
        else if (f ==1 && a==1 && b==0){v1=200;v2=200;rotarIzq();}
        //nada enfrente = nada izquierda = nada derecha
        else if (f ==1 && a==1 && b==1){avanzar();}
        
      }
  else // Si la lectura del infrarrojo #2 es 1, el sensor#1 esta sobre la linea negra y el sensor#2 esta fuera de la linea negra, entonces solo una rueda gira y esto causara el giro.
      {
        atras();
        delay(500);
        rotarIzq(); 
        delay(350);
      }
}
else // Si la lectura del infrarrojo #1 no es 0, sera 1, se daran las siguientes posibilidades:
{
  if(d==0)  // Como el sensor#1 esta fuera de la linea negra y el sensor#2 esta sobre la linea negra, entonces solo una rueda gira y esto causara el giro.
      {
      atras();
      delay(500);
      rotarDer();
      delay(350);
      }
   else
   { // si ambos sensores dan lectura 1, los dos estan fuera de la linea negra, para que vuelva a su trayectoria tiene que retroceder.
      atras();
      delay(500);
      rotarDer();
      delay(250);
  } 
} 


  

}
  
 
