#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int pinoA0 = A0; 
const int pinoA1 = A1; 

const int pinoEscala1k  = 7;
const int pinoEscala10k = 8;

void setup() {
  lcd.begin(16, 2);
  pinMode(pinoEscala1k, OUTPUT);
  digitalWrite(pinoEscala1k, LOW);
  pinMode(pinoEscala10k, INPUT);
}

void loop() {
  
  pinMode(pinoEscala1k, OUTPUT);
  digitalWrite(pinoEscala1k, LOW);
  pinMode(pinoEscala10k, INPUT);
  delay(15);
  
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

  
  float I_circuito = VA0 / 1000.0;
  float VRx = 5.0 - VA1; 
  if (VRx < 0) VRx = 0;

  float Rx = 0;
  if (I_circuito > 0.00005) {
    Rx = VRx / I_circuito;
  }

  if (Rx > 1800.0 || VRx > 4.2) {
    
    pinMode(pinoEscala1k, INPUT);
    pinMode(pinoEscala10k, OUTPUT);
    digitalWrite(pinoEscala10k, LOW);
    delay(15); 

    somaA0 = 0;
    somaA1 = 0;
    for (int i = 0; i < 50; i++) {
      somaA0 += analogRead(pinoA0);
      somaA1 += analogRead(pinoA1);
      delay(2);
    }
    
    adcA0 = somaA0 / 50.0;
    adcA1 = somaA1 / 50.0;

    VA0 = (adcA0 * 5.0) / 1023.0;
    VA1 = (adcA1 * 5.0) / 1023.0;

    I_circuito = VA0 / 10000.0;
    VRx = 5.0 - VA1;
    if (VRx < 0) VRx = 0;

    if (I_circuito > 0.00005) {
      Rx = VRx / I_circuito;
    }
  }


  lcd.setCursor(0, 0);
  lcd.print("Resistance     ");
  lcd.setCursor(0, 1);

  if (I_circuito < 0.00005 && Rx == 0) {
    lcd.print("Ajuste o Pot.   ");
  } 
  else {
    if (Rx >= 1000.0) {
      lcd.print(Rx / 1000.0, 2);
      lcd.print(" kOhms        ");
    } 
    else {
      lcd.print(Rx, 1);
      lcd.print(" Ohms         ");
    }
  }

  delay(400);
}
