#include <SPI.h>

const int switchPin = 6;
int switchState = 0;
int condVal = 0;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  pinMode(switchPin, INPUT);
}

void loop() {
  condVal = analogRead(A0);
  float voltage = condVal * (5.0 / 1023.0); //calcula a condutividade
  Serial.print("Valor da tensão :");
  Serial.println(voltage);
  delay(50); //delay before looping
}
