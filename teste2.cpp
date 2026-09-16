#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int pinoA0 = A0; 
const int pinoA1 = A1; 

const float R_ref = 1000.0; 

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  
  // Média para estabilizar a leitura no ADC
  long somaA0 = 0, somaA1 = 0;
  for (int i = 0; i < 10; i++) {
    somaA0 += analogRead(pinoA0);
    somaA1 += analogRead(pinoA1);
    delay(5);
    
  }
  
  float adcA0 = somaA0 / 10.0;
  float adcA1 = somaA1 / 10.0;

  // Converter leituras do ADC para Volts
  float VA0 = (adcA0 * 5.0) / 1023.0;
  float VA1 = (adcA1 * 5.0) / 1023.0;

  // 1. Corrente gerada no circuito (I = V_A0 / 1000)
  float I_circuito = VA0 / R_ref;

  // 2. Tensão REAL sobre o resistor desconhecido (Diferença de Potencial)
  float VRx = 5.0 - VA1; 

  // Tratamento de valores negativos/ruídos
  if (VRx < 0) VRx = 0;

  lcd.setCursor(0, 0);
  lcd.print("Resistance   ");

  lcd.setCursor(0, 1);

  if (I_circuito < 0.00005) { 
    lcd.print("Ajuste o Pot.   ");
  } 
  else {
    // 3. Cálculo da Resistência (R = Delta_V / I)
    float Rx = VRx / I_circuito;

    // Exibição no display
    if (Rx >= 1000.0) {
      lcd.print(Rx / 1000.0, 2);
      lcd.print(" kOhms       ");
    } else {
      lcd.print(Rx, 1);
      lcd.print(" Ohms        "); // Agora exibirá ~220.0 Ohms!
    }
  }

  delay(400);
}
