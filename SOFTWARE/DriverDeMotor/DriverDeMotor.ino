
#define IZQ_VELO 16
#define IZQ_DIR 17
#define DER_VELO 18
#define DER_DIR 19





void setup() {
  
  pinMode(IZQ_VELO, OUTPUT);
  pinMode(IZQ_DIR, OUTPUT);
  pinMode(DER_VELO, OUTPUT);
  pinMode(DER_DIR, OUTPUT);


}

void loop() {
  

   digitalWrite (IZQ_VELO, LOW);
   digitalWrite (IZQ_DIR, HIGH);
   digitalWrite (DER_VELO, LOW);
    digitalWrite (DER_DIR, HIGH);

}
