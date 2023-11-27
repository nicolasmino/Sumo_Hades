void setup() {
  // Comunicación seria a 9600 baudios
  Serial.begin(115200);

}


void loop() {
  // Leemos el promedio de la entrada analógica 0 :
  int SHARP_DER=SHDER_PROMEDIO(20);
  int SHARP_IZQ=SHIZQ_PROMEDIO(20);


  if(SHARP_DER>777)
  {

    Serial.print("DER Detectado: ");
  }
  else
  {

    Serial.println("DER ausente: ");
  }

  if(SHARP_IZQ>1000)
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







