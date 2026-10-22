#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int pinoA0 = A0; 
const int pinoA1 = A1; 
const int pino1k = 5; 
const int pino10k = 6;
bool escala10kAtiva = false;
bool escala1kAtiva = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(pino1k, OUTPUT);
  pinMode(pino10k, OUTPUT);
  
  //Inicia na escala de 1k
  digitalWrite(pino1k, HIGH);
  digitalWrite(pino10k, LOW);
  escala10kAtiva = false;
  escala1kAtiva = true;
}

void loop() {
  
  if (escala1kAtiva) {
    digitalWrite(pino1k, HIGH);
    digitalWrite(pino10k, LOW);
    escala10kAtiva = false;

  } else if (escala10kAtiva) {
    digitalWrite(pino10k, HIGH);
    digitalWrite(pino1k, LOW);
    escala1kAtiva = false;
  }
  delay(35);
  
  analogRead(pinoA0);
  analogRead(pinoA1);
  delay(5);

  long somaA0 = 0, somaA1 = 0;
  for (int i = 0; i < 50; i++) {
    somaA0 += analogRead(pinoA0);
    somaA1 += analogRead(pinoA1);
    delay(2);
  }
  
  float adcA0 = somaA0 / 50.0;
  float adcA1 = somaA1 / 50.0;

  float VA0 = (adcA0 * 5.0) / 1023.0;
  float VA1 = (adcA1 * 5.0) / 1023.0;

  //Seleciona a resistência de referência
  float resistenciaReferencia = escala10kAtiva ? 10000.0 : 1000.0;

  float I_circuito = VA0 / resistenciaReferencia; 

  float VRx = 5.0 - VA1; 
  if (VRx < 0) VRx = 0;

  float Rx = 0;
  if (I_circuito > 0.00001) {
    Rx = VRx / I_circuito;
  }

  if (escala10kAtiva == false && Rx >= 4000.0 ) {
    escala10kAtiva = true;
    escala1kAtiva = false;
    return;
  } 
  else if (escala1kAtiva == false && Rx < 4000.0) {
    escala1kAtiva = true;
    escala10kAtiva = false;
    return; 
  }

  lcd.setCursor(0, 0);
  lcd.print("Resistance     ");
  lcd.setCursor(0, 1);

    if (Rx >= 1000.0) {
      lcd.print(Rx / 1000.0, 2);
      lcd.print(" kOhms        ");
    } 
    else {
      lcd.print(Rx, 1);
      lcd.print(" Ohms          ");
    }

  delay(400);
}
