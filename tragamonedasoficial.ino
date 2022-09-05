
#include <Wire.h> // 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int Centena, Decena, Unidad;
int motor_on = 3;      // salida para activar motor
int valvula = 8;      // entrada para recibir indicación
unsigned long periodo = 120000;
int periodo_osc = 500;
int segundo = 1000;
int buttonState = 0; 
int Start = 9; 
int aire = 10;
int llenado_aire;
int salida_aire=11;
int contador = 121;
unsigned long tiempoahora = 0;
unsigned long TiempoAuxiliar1 = 0;
unsigned long TiempoAuxiliar2 = 0;
unsigned long TiempoAuxiliar = 0;
int contadorPines=0;
int led = 4;
int Num_moneda = 0;
int tragamonedas = 0;
int tragamonedasPin = 2;
void setup(){
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(motor_on, OUTPUT);   // pin 3   
  pinMode(tragamonedasPin, INPUT); // pin 2
  pinMode(Start, INPUT);      // pin 9
  pinMode(valvula, OUTPUT);   //pin 8
  pinMode(aire, INPUT);       //pin 10
  pinMode(salida_aire, OUTPUT);   //pin 11
  pinMode(led, OUTPUT);
} 


void loop(){ 
   lcd.setCursor(0,0);
   lcd.print("  Machucadora   "); 
   lcd.setCursor (0,1);
   lcd.print("  Inserte Bs 1  "); 
   lcd.display();
   tragamonedas = digitalRead(tragamonedasPin);
   digitalWrite(led,HIGH);
   if(tragamonedas == HIGH){
    digitalWrite(motor_on, HIGH);
    digitalWrite(led,LOW);
    lcd.setCursor (0,1);
    String texto = (String) contador;
    lcd.print(" Tiempo:  120s  ");
    TiempoAuxiliar = millis();
    while(TiempoAuxiliar+periodo > millis()){
    if((millis()-TiempoAuxiliar)%1000 == 0){contador = contador - 1;
    delayMicroseconds(5000);
    Centena = contador/100;
    Decena = (contador - Centena*100)/10;
    Unidad = (contador - Centena*100 - Decena*10);
    lcd.setCursor (10,1);
    lcd.print(Centena);
    lcd.setCursor (11,1);
    lcd.print(Decena);
    lcd.setCursor (12,1);
    lcd.print(Unidad);
    }
    llenado_aire = digitalRead(aire);
    if(llenado_aire == HIGH){digitalWrite(salida_aire, HIGH);}
    else{digitalWrite(salida_aire,LOW);}
    buttonState = digitalRead(Start);
    if(buttonState == HIGH){
    TiempoAuxiliar1 = millis();
    while(TiempoAuxiliar1+periodo_osc> millis()){
      if((millis()-TiempoAuxiliar)%1000 == 0){contador = contador - 1;    // contador desplegado en pantalla
      delayMicroseconds(5000);
      Centena = contador/100;
    Decena = (contador - Centena*100)/10;
    Unidad = (contador - Centena*100 - Decena*10);
    lcd.setCursor (10,1);
    lcd.print(Centena);
    lcd.setCursor (11,1);
    lcd.print(Decena);
    lcd.setCursor (12,1);
    lcd.print(Unidad);
      }
      digitalWrite(valvula, HIGH);
      }
    TiempoAuxiliar2 = millis();
    while(TiempoAuxiliar2+periodo_osc> millis()){
      if((millis()-TiempoAuxiliar)%1000 == 0){contador = contador - 1;
      delayMicroseconds(5000);
      Centena = contador/100;
    Decena = (contador - Centena*100)/10;
    Unidad = (contador - Centena*100 - Decena*10);
    lcd.setCursor (10,1);
    lcd.print(Centena);
    lcd.setCursor (11,1);
    lcd.print(Decena);
    lcd.setCursor (12,1);
    lcd.print(Unidad);
      }
      digitalWrite(valvula, LOW);
      }
    }
    else{digitalWrite(valvula, LOW);}
    }
    digitalWrite(motor_on, LOW);
    contador = 121;
    tragamonedas = LOW;
  }
  
}
