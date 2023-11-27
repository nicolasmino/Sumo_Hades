#include "BluetoothSerial.h"
#define IN4 18
#define IN3 19
#define IN2 21
#define IN1 22
#define ENA 23
#define ENB 17
#define DEBUG 0
//char incoming[2];

// nuevo: 
int dif=0;
int dif_prop(int vel){
  return map(vel, 0, 255, 0,255);
}
int CT1;
int CT2;
const int canalPWM0 = 0;
const int canalPWM1 = 1;
const int frecuencia = 10000;
const int resolucion = 8; // Ciclo de trabajo de 0 a 255

String incoming, angulo;
char angulo1;
int modulo, boton;
BluetoothSerial BT; // Objeto Bluetooth
void setup() {
  Serial.begin(9600); // Inicialización de la conexión en serie para la depuración
  BT.begin("ESP32_bender"); // Nombre de su dispositivo Bluetooth y en modo esclavo
  //Serial.println("El dispositivo Bluetooth está listo para emparejarse");
  pinMode (IN4, OUTPUT); // Cambie el pin LED a OUTPUT
  pinMode (IN3, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);

  //nuevo:
  ledcAttachPin (ENA, canalPWM0); // hasta aca decia el video
  ledcAttachPin(ENB, canalPWM1);
  ledcSetup(canalPWM0, frecuencia, resolucion);
  ledcSetup(canalPWM1, frecuencia, resolucion);
}

void loop() 
{
  if (BT.available())
  {
    incoming = BT.readStringUntil('#');
    angulo = incoming.substring(0,1);
    angulo1 = angulo[0];
    boton = incoming.substring(1,2).toInt();
  }
  Serial.println(incoming); 
    //Serial.print("Recibido: ");
   if(DEBUG)BT.println(incoming);
   switch (angulo1)
         {
          case 'F':{
              digitalWrite (IN4, LOW);
              digitalWrite (IN3, HIGH);
              digitalWrite (IN2, LOW);
              digitalWrite (IN1, HIGH);
              if(DEBUG)BT.println("Adelante");
          }
          break;
          case 'B':{
              digitalWrite (IN4, HIGH);
              digitalWrite (IN3, LOW);
              digitalWrite (IN2, HIGH);
              digitalWrite (IN1, LOW);
               if(DEBUG)BT.println("Atras");
               }
          break;
            case 'L':{
               digitalWrite (IN4, LOW);
              digitalWrite (IN3, HIGH);
             (IN2, HIGH);
              digitalWrite (IN1, LOW);
              if(DEBUG)BT.println("Giro Derecha");
            }
            break;
          case 'R':{
              digitalWrite (IN4, HIGH);
              digitalWrite (IN3, LOW);
              digitalWrite (IN2, LOW);
              digitalWrite (IN1, HIGH);
              if(DEBUG)BT.println("Giro Izquierda");
              }
          break;
          case 'Z':
          {
               digitalWrite (IN4, LOW);
              digitalWrite (IN3, HIGH);
              digitalWrite (IN2, LOW);
              digitalWrite (IN1, LOW);
              if(DEBUG)BT.println("PARA ATRAS A LA DERECHA");
            }
            break;          
          case 'C':
          {
               digitalWrite (IN4, HIGH);
              digitalWrite (IN3, HIGH);
              digitalWrite (IN2, LOW);
              digitalWrite (IN1, HIGH);
              if(DEBUG)BT.println("PARA ATRAS A LA IZQUIERDA");
            }
            break;
            case 'A':
          {
               digitalWrite (IN4, HIGH);
              digitalWrite (IN3, LOW);
              digitalWrite (IN2, HIGH);
              digitalWrite (IN1, HIGH);
              if(DEBUG)BT.println("PARA ADELANTE A LA DERECHA");
            }
            break;
            case 'D':
          {
               digitalWrite (IN4, LOW);
              digitalWrite (IN3, LOW);
              digitalWrite (IN2, HIGH);
              digitalWrite (IN1, LOW);
              if(DEBUG)BT.println("PARA ADELANTE A LA IZQUIERDA");
            }
            break;
            case '0':
          {
               digitalWrite (IN4, LOW);
              digitalWrite (IN3, LOW);
              digitalWrite (IN2, LOW);
              digitalWrite (IN1, LOW);
              if(DEBUG)BT.println("FRENA");
            }
            break;
         }
            switch (boton) // vamos a darle velocidad con esto.
            {
            case 3:
            {
            CT1 = 255;
            CT2 = dif_prop(255);
            ledcWrite (canalPWM0, CT2);
            ledcWrite (canalPWM1, CT1);
            }
            break; 
            case 4: 
            { 
              CT1= 216;
              CT2 = dif_prop(216);
            ledcWrite (canalPWM0, CT2);
            ledcWrite (canalPWM1, CT1);  
            }
            break;
            case 2: 
            { 
              CT1 = 192;
              CT2 = dif_prop(192);
              ledcWrite (canalPWM0, CT2);
              ledcWrite (canalPWM1, CT1);
            }
            break; 
            case 1: 
            {
              CT1 = 175;
              CT2 = dif_prop(175); 
              ledcWrite (canalPWM0, CT2);
              ledcWrite (canalPWM1, CT1);
            }
            break; 
            case 0:
            { 
            CT1 = 0;
              CT2 = 0; 
            ledcWrite (canalPWM0, CT2);
            ledcWrite (canalPWM1, CT1);
            }
            break;
            }
}
