#include <LiquidCrystal.h>
const int en = 11, rs = 12, d7 = 2, d4 = 5, d2 = 7, d1 = 8;
LiquidCrystal lcd(rs, en, d1, d2, d4, d7);

float ResistRef = 1000.0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  //pinMode (A7, OUTPUT);
  pinMode (7, OUTPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(9600);
  
// REFERENCIA
  // read the input on analog pin 0:
  int SensorRef = analogRead(A2);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float TensaoRef = SensorRef * (5.0 / 1023.0);
  float CorrenteRef = TensaoRef / 1000; 
  // print out the value you read:
  Serial.println("Tensao Ref:");
  Serial.println(TensaoRef);
  delay(1000);

// CARGA
  // read the input on analog pin 0:
  int SensorMedicao = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float TensaoCarga = SensorMedicao * (5.0 / 1023.0);
  float ResistCarga = TensaoCarga / CorrenteRef;
  // print out the value you read:
  Serial.println("Tensao Carga:");
  Serial.println(TensaoCarga);
  delay(1000);
  //float ValorResist = analogWrite(3, ResistCarga);
}
