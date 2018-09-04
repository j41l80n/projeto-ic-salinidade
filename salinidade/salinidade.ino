const float ArduinoVoltage = 5.00; // CHANGE THIS FOR 3.3v Arduinos
const float ArduinoResolution = ArduinoVoltage / 1024;


const float resistorValue = 10000.0;
int threshold = 10;


int inputPin = A0;
int ouputPin = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(ouputPin, OUTPUT);
  pinMode(inputPin, INPUT);
}

void loop()
{
  int analogValue = 0;
  int oldAnalogValue = 1000;
  float returnVoltage = 0.0;
  float resistance = 0.0;
  double Siemens;
  float TDS = 0.0;

  Serial.print("oldAnalogValue: ");
  Serial.println(oldAnalogValue);
  Serial.print("analogValue: ");
  Serial.println(analogValue);
  Serial.print("threshold: ");
  Serial.println(threshold);

  analogValue = analogRead( inputPin );

  Serial.print("Return voltage = ");
  returnVoltage = analogValue * ArduinoResolution;
  Serial.print(returnVoltage);
  Serial.println(" volts");


  Serial.print("That works out to a resistance of ");
  resistance = ((5.00 * resistorValue) / returnVoltage) - resistorValue;
  Serial.print(resistance);
  Serial.println(" Ohms.");


  Serial.print("Which works out to a conductivity of ");
  Siemens = 1.0 / (resistance / 1000000);
  Serial.print(Siemens);
  Serial.println(" microSiemens.");
  Serial.print("We can estimate Total Dissolved Solids to be on the order of ");
  TDS = 500 * (Siemens / 1000);
  Serial.print(TDS);
  Serial.println(" PPM.");
  if (returnVoltage > 4.9) Serial.println("Are you sure this isn't metal?");

  delay(2000);
  Serial.println("CLEARDATA");
}
