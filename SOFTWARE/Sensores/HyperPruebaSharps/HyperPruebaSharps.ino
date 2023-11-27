  int ADC_SHARP ;
  int ADC_SHARP_2; 
float i;

void setup() {
  // Comunicación seria a 115200 baudios
  Serial.begin(115200);
}

void loop() {
  // Leemos la entrada analógica 0 :
  ADC_SHARP = analogRead(27);
  ADC_SHARP_2 = analogRead(14);
  

Serial.print("Distancia 1: ");
Serial.println(ADC_SHARP);
Serial.print(" Distancia 2: ");
Serial.println(ADC_SHARP_2);
i=ADC_SHARP_2*0.000805;

Serial.println(i);



  delay(300);
}

