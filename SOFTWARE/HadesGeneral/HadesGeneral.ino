#include <NewPing.h>



//Sensores Ultrasonicos

#define TRIG_IZQ 34
#define ECHO_IZQ 35
#define TRIG_DER 33
#define ECHO_DER 32

//Lectura de sensores maxima distancia de lectura = 200
NewPing sonar1(TRIG_IZQ, ECHO_IZQ, 200);
NewPing sonar2(TRIG_DER, ECHO_DER, 200);

//Driver De Motor

#define IZQ_VELO 19
#define IZQ_DIR 18
#define DER_VELO 17
#define DER_DIR 16

//Sensores Sharp
long suma1=0;
long suma2=0;
int i;
int n;
int SHARP_DER;
int SHARP_IZQ;

//Estado

//Sensores Ultrasonicos
unsigned int distance1 = sonar1.ping_cm();
unsigned int distance2 = sonar2.ping_cm();
int dato;
int blanco;
int negro;
int linea;

enum ESTADOS_H
{
BUSQUEDA1,
ATAQUE1,
LIMITE1,
DETENIDO1
};
ESTADOS_H ESTADOS;



void setup()
{
Serial.begin(115200);

  pinMode(TRIG_IZQ, INPUT);
  pinMode(ECHO_IZQ, INPUT);
  pinMode(TRIG_DER, INPUT);
  pinMode(ECHO_DER, INPUT);
  pinMode(IZQ_VELO, OUTPUT);
  pinMode(IZQ_DIR, OUTPUT);
  pinMode(DER_VELO, OUTPUT);
  pinMode(DER_DIR, OUTPUT);

}

void loop() {
 INI_SENSORES();
 delay(5000);


if(distance1<25||distance2<25){
  ADELANTE();
}
else if(SHARP_IZQ<300){
  IZQUIERDA();
}
else if(SHARP_DER<2000){
  DERECHA();
}
else if (distance1>25 && distance2>25 && SHARP_IZQ>300 && SHARP_DER>2000){
  BUS_IZQ();
}
}


void INI_SENSORES()
{
  

 //Sensores Ultrasonicos
delay (50);


Serial.print("Sensor 1: ");
Serial.print(distance1);
Serial.print(" cm\tSensor 2: ");
Serial.print(distance2);
Serial.println(" cm");

//Sensores SHARP

int SHARP_DER=SHDER_PROMEDIO(20);
int SHARP_IZQ=SHIZQ_PROMEDIO(20);

 if(SHARP_DER<2000)
  {

    Serial.print("DER Detectado: ");
  }
  else
  {

    Serial.println("DER ausente: ");
  }

  if(SHARP_IZQ<300)
  {

    Serial.print("IZQ Detectado: ");
  }
  else
  {

    Serial.println("IZQ ausente: ");
  }
  
  Serial.println(SHARP_DER);
  Serial.println(SHARP_IZQ);
  delay(300);
}
int SHDER_PROMEDIO(int n)
{
  long suma1=0;
  for(int i=0;i<n;i++)
  {
    suma1=suma1+analogRead(14);
  }  
  return(suma1/n);
}


int SHIZQ_PROMEDIO(int n)
{
  long suma2=0;
  for(int i=0;i<n;i++)
  {
    suma2=suma2+analogRead(27);
  }  
  return(suma2/n);
}

void ADELANTE()
{
    digitalWrite (DER_DIR, HIGH);
    digitalWrite (IZQ_VELO, LOW);
    digitalWrite (IZQ_DIR, HIGH);
    digitalWrite (DER_VELO, LOW); 
}
void ATRAS()
{
    digitalWrite (IZQ_VELO, LOW);
    digitalWrite (IZQ_DIR, HIGH);
    digitalWrite (DER_VELO, LOW);
    digitalWrite (DER_DIR, HIGH); 
}
void DERECHA()
{
    digitalWrite (IZQ_VELO, HIGH);
    digitalWrite (IZQ_DIR, LOW);
    digitalWrite (DER_VELO, LOW);
    digitalWrite (DER_DIR, LOW);
}
void IZQUIERDA()
{
    digitalWrite (IZQ_VELO, LOW);
    digitalWrite (IZQ_DIR, LOW);
    digitalWrite (DER_VELO, HIGH);
    digitalWrite (DER_DIR, LOW);
}
void STOP()
{
    digitalWrite (IZQ_VELO, LOW);
    digitalWrite (IZQ_DIR, LOW);
    digitalWrite (DER_VELO, LOW);
    digitalWrite (DER_DIR, LOW);
}

void BUS_DER()
{
    digitalWrite (IZQ_VELO, HIGH);
    digitalWrite (IZQ_DIR, LOW);
    digitalWrite (DER_VELO, LOW);
    digitalWrite (DER_DIR, HIGH);

}
void BUS_IZQ()
{
    digitalWrite (IZQ_VELO, LOW);
    digitalWrite (IZQ_DIR, LOW);
    digitalWrite (DER_VELO, HIGH);
    digitalWrite (DER_DIR, LOW);

}
