  

#include <SoftwareSerial.h>  // libreria que permite establecer pines digitales 
  
        // para comunicacion serie 

SoftwareSerial miBT(10, 11);   // pin 10 como RX a TX de modulo, pin 11 como TX a rx de arduino 
char DATO = 0;      // variable para almacenar caracter recibido 
 

int izq = 2;      // IN1 a pin digital 2 

void setup(){ 
  Serial.begin(9600); 
  miBT.begin(38400);    // comunicacion serie entre Arduino y el modulo a 38400 bps 
  pinMode(izq, OUTPUT);   // IN1 como salida   
} 
 
void loop(){ 
  if (miBT.available()){      // si hay informacion disponible desde modulo 
  DATO = miBT.read();   // almacena en DATO el caracter recibido desde modulo 
  } 
  control(); 
       // funcion que devuelve fecha y horario en formato
            // DateTime y asigna a variable fecha

} 

// funciones  
void control(){
  if(DATO == 'o'){
    digitalWrite(izq,HIGH);
      Serial.println(DATO); 

  }
    if(DATO == 'p'){
    digitalWrite(izq,LOW);
      Serial.println(DATO); 

  }
}
