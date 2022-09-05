#include <SoftwareSerial.h>  // libreria que permite establecer pines digitales

        // para comunicacion serie
SoftwareSerial miBT(10, 11);   // pin 10 como RX, pin 11 como TX
char DATO = 0;      // variable para almacenar caracter recibido

char  contador = 'x';    // cuenta el nivel del menu en el que se esta

int IN1 = 2;      // IN1 a pin digital 2
int IN2 = 3;      // IN2 a pin digital 3
int ENA = 5;      // ENA a pin digital 5
int IN3 = 7;      // IN3 a pin digital 7
int IN4 = 8;      // IN4 a pin digital 8
int ENB = 9;      // ENA a pin digital 9
int VELOCIDAD;      // variable para almacenar valor de velocidad
int boozer =12;

void setup(){
  Serial.begin(9600);
  miBT.begin(38400);    // comunicacion serie entre Arduino y el modulo a 38400 bps
  pinMode(IN1, OUTPUT);   // IN1 como salida  
  pinMode(IN2, OUTPUT);   // IN2 como salida
  pinMode(ENA, OUTPUT);   // ENA como salida
  pinMode(IN3, OUTPUT);   // IN3 como salida
  pinMode(IN4, OUTPUT);   // IN4 como salida
  pinMode(ENB, OUTPUT);   // ENB como salida
  pinMode(boozer,OUTPUT);  //
}

void loop(){
  if (miBT.available()){      // si hay informacion disponible desde modulo
  DATO = miBT.read();   // almacena en DATO el caracter recibido desde modulo

  }
   control();
}

// funciones 
void automatico(){
    Serial.println(DATO);
  VELOCIDAD = 100;    // valor de velocidad para PWM de ENA y ENB
  digitalWrite(boozer,LOW);  
  M_A_AVANZA(VELOCIDAD);   // funcion de avance del motor A
  M_B_AVANZA(VELOCIDAD);   // funcion de avance del motor B
  delay(700);      // demora de 3 seg.
  digitalWrite(boozer,HIGH);
  detieneAmbos();   // funcion que detiene ambos motores
  delay(700);      // demora de 2 seg.
  digitalWrite(boozer,LOW);
  M_A_AVANZA(VELOCIDAD);   // funcion de avance del motor A (giro a derecha)
  delay(1000);      // demora de 1 seg.
  digitalWrite(boozer,HIGH);
  detieneAmbos();
  delay(700);      // demora de 2 seg.

  digitalWrite(boozer,LOW);  
  M_A_AVANZA(VELOCIDAD);   // funcion de avance del motor A
  M_B_AVANZA(VELOCIDAD);   // funcion de avance del motor B
  delay(700);      // demora de 3 seg.
  digitalWrite(boozer,HIGH);
  detieneAmbos();   // funcion que detiene ambos motores
  delay(700);      // demora de 2 seg.
  digitalWrite(boozer,LOW);
  M_A_AVANZA(VELOCIDAD);   // funcion de avance del motor A (giro a derecha)
  delay(1000);      // demora de 1 seg.
  digitalWrite(boozer,HIGH);
  detieneAmbos();
  delay(700);      // demora de 2 seg.

  digitalWrite(boozer,LOW);  
  M_A_AVANZA(VELOCIDAD);   // funcion de avance del motor A
  M_B_AVANZA(VELOCIDAD);   // funcion de avance del motor B
  delay(700);      // demora de 3 seg.
  digitalWrite(boozer,HIGH);
  detieneAmbos();   // funcion que detiene ambos motores
  delay(700);      // demora de 2 seg.
  digitalWrite(boozer,LOW);
  M_A_AVANZA(VELOCIDAD);   // funcion de avance del motor A (giro a derecha)
  delay(1000);      // demora de 1 seg.
  digitalWrite(boozer,HIGH);
  detieneAmbos();
  delay(700);      // demora de 2 seg.

  digitalWrite(boozer,LOW);  
  M_A_AVANZA(VELOCIDAD);   // funcion de avance del motor A
  M_B_AVANZA(VELOCIDAD);   // funcion de avance del motor B
  delay(700);      // demora de 3 seg.
  digitalWrite(boozer,HIGH);
  detieneAmbos();   // funcion que detiene ambos motores
  delay(700);      // demora de 2 seg.
  digitalWrite(boozer,LOW);
  M_A_AVANZA(VELOCIDAD);   // funcion de avance del motor A (giro a derecha)
  delay(1000);      // demora de 1 seg.
  digitalWrite(boozer,HIGH);
  detieneAmbos();
  delay(700);      // demora de 2 seg.
  digitalWrite(boozer,LOW);  
  }
void control(){
  Serial.println(DATO);
  delay(500);
  if(DATO == '2'){automatico();} // modo automatico
  Serial.println(DATO);
  if(DATO == 'a'){ // AVANCE
    VELOCIDAD = 200;    // valor de velocidad para PWM de ENA y ENB
    M_A_AVANZA(VELOCIDAD+12);   // funcion de avance del motor A
    M_B_AVANZA(VELOCIDAD);   // funcion de avance del motor B
  }
 if(DATO =='r'){//RETROCEDE
  VELOCIDAD = 255;    // valor de velocidad para PWM de ENA y ENB
  M_A_retrocede(VELOCIDAD);   // funcion de avance del motor A
  M_B_retrocede(VELOCIDAD);   // funcion de avance del motor B
 }
 if(DATO=='d'){//DERECHA
  VELOCIDAD = 255;
  avance_derecha(VELOCIDAD);
 }
 if(DATO=='i'){//IZQUIERDA
  VELOCIDAD = 255;
  avance_izquierda(VELOCIDAD);
 }
 if(DATO == 'p'){//detener
  detieneAmbos();
 }

void M_A_retrocede(int veloc){  // funcion para avance de motor B
  analogWrite(ENA, veloc);  // velocidad mediante PWM en ENB
  digitalWrite(IN1, HIGH); // IN3 a cero logico
  digitalWrite(IN2, LOW);  // IN4 a uno logico
}

void M_B_retrocede(int veloc){  // funcion para avance de motor B
  analogWrite(ENB, veloc);  // velocidad mediante PWM en ENB
  digitalWrite(IN3, HIGH); // IN3 a cero logico
  digitalWrite(IN4, LOW);  // IN4 a uno logico
}

void avance_derecha(int veloc){  // funcion para avance de motor B
  analogWrite(ENB, 0);    // deshabilita motor B
  analogWrite(ENA, veloc);  // velocidad mediante PWM en ENA
  digitalWrite(IN1, LOW); // IN1 a cero logico
  digitalWrite(IN2, HIGH);  // IN2 a uno logico
}

void avance_izquierda(int veloc){  // funcion para avance de motor B
  analogWrite(ENA, 0);    // deshabilita motor A
  analogWrite(ENB, veloc);  // velocidad mediante PWM en ENB
  digitalWrite(IN3, LOW); // IN3 a cero logico
  digitalWrite(IN4, HIGH);  // IN4 a uno logico
}

void detieneAmbos(){    // funcion que detiene ambos motores
  analogWrite(ENA, 0);    // deshabilita motor A
  analogWrite(ENB, 0);    // deshabilita motor B
}
 void M_A_AVANZA(int veloc){  // funcion para avance de motor A
  analogWrite(ENA, veloc);  // velocidad mediante PWM en ENA
  digitalWrite(IN1, LOW); // IN1 a cero logico
  digitalWrite(IN2, HIGH);  // IN2 a uno logico
}
void M_B_AVANZA(int veloc){  // funcion para avance de motor B
  analogWrite(ENB, veloc);  // velocidad mediante PWM en ENB
  digitalWrite(IN3, LOW); // IN3 a cero logico
  digitalWrite(IN4, HIGH);  // IN4 a uno logico
}

}
