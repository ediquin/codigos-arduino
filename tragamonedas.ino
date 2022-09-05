
 
int motor_on = 3;      // salida para activar motor
int valvula = 2;      // entrada para recibir indicación
unsigned long periodo = 120000;
int periodo_osc = 500;
int segundo = 1000;
int buttonState = 0; 
int Start = 9; 
int aire = 10;
int llenado_aire;
int salida_aire=11;
int contador = 120;
unsigned long tiempoahora = 0;
unsigned long TiempoAuxiliar1 = 0;
unsigned long TiempoAuxiliar2 = 0;
unsigned long TiempoAuxiliar = 0;
int contadorPines=0;

int Num_moneda = 0;
int tragamonedas = 0;
int tragamonedasPin = 8;
void setup(){ 
  pinMode(motor_on, OUTPUT);   // IN1 como salida   
  Serial.begin(9600);
  pinMode(tragamonedasPin, INPUT);
  pinMode(Start, INPUT);
  pinMode(valvula, OUTPUT);
  pinMode(aire, INPUT);
  pinMode(salida_aire, OUTPUT);
} 
int binario(int numero){
  digitalWrite(A0,bitRead(numero, 0));
  digitalWrite(A1,bitRead(numero, 1));
  digitalWrite(A2,bitRead(numero, 2));
  digitalWrite(A3,bitRead(numero, 3));
  digitalWrite(A4,bitRead(numero, 4));
  digitalWrite(A5,bitRead(numero, 5));
  digitalWrite(6,bitRead(numero, 6));
  }

void loop(){ 
   
   tragamonedas = digitalRead(tragamonedasPin);
   if(tragamonedas == HIGH){
    TiempoAuxiliar = millis();
    while(TiempoAuxiliar+periodo > millis()){
    if((millis()-TiempoAuxiliar)%1000 == 0){contador = contador - 1;
    delayMicroseconds(5000);
    Serial.println(contador);
    binario(contador);
    }
    llenado_aire = digitalRead(aire);
    if(llenado_aire == HIGH){digitalWrite(salida_aire, HIGH);}
    else{digitalWrite(salida_aire,LOW);}
    buttonState = digitalRead(Start);
    if(buttonState == HIGH){digitalWrite(motor_on, HIGH);
    TiempoAuxiliar1 = millis();
    while(TiempoAuxiliar1+periodo_osc> millis()){
      if((millis()-TiempoAuxiliar)%1000 == 0){contador = contador - 1;    // contador desplegado en pantalla
      delayMicroseconds(5000);
      Serial.println(contador);
      binario(contador);
      }
      digitalWrite(valvula, HIGH);
      }
    TiempoAuxiliar2 = millis();
    while(TiempoAuxiliar2+periodo_osc> millis()){
      if((millis()-TiempoAuxiliar)%1000 == 0){contador = contador - 1;
      delayMicroseconds(5000);
      Serial.println(contador);
      binario(contador);
      }
      digitalWrite(valvula, LOW);
      }
    }
    else{digitalWrite(motor_on, LOW);}
    }
    digitalWrite(motor_on, LOW);
    contador = 120;
    tragamonedas = LOW;
  }
  
}
