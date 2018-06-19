float aRef = 5;
float relacaoA0 = 11;
float relacaoA2 = 11;
float tensaoA0;
#define AMOSTRAS 12

void setup() {
  Serial.begin(9600);
}

float lePorta(uint8_t portaAnalogica) {
  float total = 0;
  for (int i = 0; i < AMOSTRAS; i++) {
    total += 1.0 * analogRead(portaAnalogica);
    delay(5);
  }
  return total / (float)AMOSTRAS;
}

void mostraTensoes() {
  Serial.print("Tensão em A0: ");
  Serial.print(tensaoA0 * relacaoA0);
  Serial.println ("V");
}

void loop() {
  tensaoA0 = (lePorta(A0) * aRef) / 1024.0;
  mostraTensoes();
  delay(500);
}
