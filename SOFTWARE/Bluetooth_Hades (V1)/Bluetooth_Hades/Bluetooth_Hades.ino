#include "BluetoothSerial.h"

#define IZQ_VELO 16
#define IZQ_DIR 17
#define DER_VELO 18
#define DER_DIR 19
#define DERR_EN 32
#define DERL_EN 32
#define IZQR_EN 33
#define IZQL_EN 33



int dato = 0;
//La variable que guarda el dato enviado por BT

BluetoothSerial BT;  // Objeto Bluetooth

void setup() {


  Serial.begin(9600);

  
  pinMode(IZQ_VELO, OUTPUT);
  pinMode(IZQ_DIR, OUTPUT);
  pinMode(DER_VELO, OUTPUT);
  pinMode(DER_DIR, OUTPUT);

  pinMode(DERL_EN, OUTPUT);
  pinMode(DERR_EN, OUTPUT);
  pinMode(IZQL_EN, OUTPUT);
  pinMode(IZQR_EN, OUTPUT);

 digitalWrite(DERR_EN, HIGH);
 digitalWrite(DERL_EN, HIGH);
 digitalWrite(IZQR_EN, HIGH);
 digitalWrite(IZQL_EN, HIGH);

  BT.begin("Lol");
  // Nombre de su dispositivo Bluetooth y en modo esclavo

  Serial.println("El dispositivo Bluetooth está listo para emparejarse");
  
             }

void loop() {


  int dato = BT.read();

   Serial.println(dato);

     delay(200);


  if (Serial.available() > 0)
 {
    dato = Serial.read();
    Serial.print("Dato ingresado:");
    Serial.println(dato);

  }
  
  if (dato == 66)

  {
    //atras ();

    digitalWrite (IZQ_VELO, LOW);
    digitalWrite (IZQ_DIR, HIGH);
    digitalWrite (DER_VELO, LOW);
    digitalWrite (DER_DIR, HIGH);
    
  }
  else if (dato == 70)

  { 
     
    //adelante ();
    digitalWrite (IZQ_VELO, HIGH);
    digitalWrite (IZQ_DIR, LOW);
    digitalWrite (DER_VELO, HIGH);
    digitalWrite (DER_DIR, LOW);


  
  }


  else if (dato == -1)

  {
    //Stop ();
    digitalWrite (IZQ_VELO, LOW);
    digitalWrite (IZQ_DIR, LOW);
    digitalWrite (DER_VELO, LOW);
    digitalWrite (DER_DIR, LOW);

    
  }

  else if (dato == 76)

  {
    //izquierda ();

    digitalWrite (IZQ_VELO, LOW);
    digitalWrite (IZQ_DIR, LOW);
    digitalWrite (DER_VELO, HIGH);
    digitalWrite (DER_DIR, LOW);

  }

  else if (dato == 82)

  {
    // derecha ();

    digitalWrite (IZQ_VELO, HIGH);
    digitalWrite (IZQ_DIR, LOW);
    digitalWrite (DER_VELO, LOW);
    digitalWrite (DER_DIR, LOW);
 
  }

  
}






