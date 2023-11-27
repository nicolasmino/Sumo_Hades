#define SH_DER 27
#define SH_IZQ 14

float medirDistancia(int PIN_SH)
{
pinMode(PIN_SH, INPUT);
int tiempoRetardo = pulseIn(PIN_SH, HIGH);
float distancia = tiempoRetardo / 29.0 / 2.0;
return distancia;
}

void setup() {
Serial.begin(9600); 

}

void loop() {
float distancia1= medirDistancia(SH_DER); 
float distancia2= medirDistancia(SH_IZQ); 

Serial.print("Distancia 1: ");
Serial.print(distancia1);
Serial.print(" cm, Distancia 2: ");
Serial.print(distancia2);
Serial.println(" cm");

delay(1000);

}
