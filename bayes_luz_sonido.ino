int LDR_Pin = A0; // Entrada al LDR
int LDR_Value = 0; // Lectura del LDR
int KY_Pin = 2; // Entrada al LDR
int KY_Value = 0; // Lectura del LDR
int t1=0;
int t2=0;

void setup() {
  Serial.begin(9600); // Velocidad y puerto
  pinMode( LDR_Pin, INPUT) ;
  pinMode( KY_Pin, INPUT) ;

}

void loop() {
  KY_Value = digitalRead(KY_Pin); // Lectura analógica de LDR
  if (KY_Value==HIGH){//Si detectamos sonido
    t1=millis();
    t2=millis();
    
    while (t2-t1<3000){//Vamos a ver por 3 segs
      LDR_Value = analogRead(LDR_Pin); // Lectura analógica de LDR
      Serial.println(LDR_Value); //Impresión de las lecturas
      t2=millis();//Actualizamos t2
    }
  }
  delay(100); //100 ms
  
}
