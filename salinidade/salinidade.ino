int linha = 1;
int LABEL = 1;

void setup() {
  // inicia a comunicacao serial
  Serial.begin(9600);
  // reset da comunicação serial
  Serial.println("CLEARDATA");
  // nomeia as colunas
  Serial.println("LABEL,Hora,valor,linha");
}

void loop() {
  // inicia a impressao de dados, sempre iniciando
  Serial.print("DATA,TIME,");
  Serial.print(analogRead(A0));
  Serial.print(",");
  Serial.println(linha);

  // laco para limitar a quantidade de dados
  if (linha > 100)
  {
    linha = 0;
    // alimentação das linhas com os dados sempre iniciando
    Serial.println("ROW,SET,2");
  }

  // incrementa a linha do excel para que a leitura pule de linha em linha
  linha++;

  // espera 100 milisegundos
  delay(100);
}
