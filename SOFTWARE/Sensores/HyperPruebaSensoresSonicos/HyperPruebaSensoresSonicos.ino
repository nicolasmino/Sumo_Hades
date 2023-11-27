#include <NewPing.h>

#define TRIG_IZQ 35
#define ECHO_IZQ 34
#define TRIG_DER 32
#define ECHO_DER 33



NewPing sonar1(TRIG_IZQ, ECHO_IZQ, 200);
NewPing sonar2(TRIG_DER, ECHO_DER, 200);

void setup() {
  
  Serial.begin(115200);
  
}

void loop() {
  
delay (50);

unsigned int distance1 = sonar1.ping_cm();
delay (10);
unsigned int distance2 = sonar2.ping_cm();

Serial.print("Sensor 1: ");
Serial.print(distance1);
Serial.print(" cm\tSensor 2: ");
Serial.print(distance2);
Serial.println(" cm");
}
