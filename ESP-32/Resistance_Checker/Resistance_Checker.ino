int analogPin = 34;
float R_known = 10000.0;
float V_supply = 3.3;

void setup()
{
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop()
{
  int adcValue = analogRead(analogPin);
  float V_measured = adcValue * (V_supply / 4095.0);

  float R_unknown = R_known * ((V_measured / V_supply) / (1 - (V_measured / V_supply)));

  Serial.print("Measured Voltage: ");
  Serial.print(V_measured, 3);
  Serial.print("V, Unknown Resistance: ");
  Serial.print(R_unknown);
  Serial.println(" ohms");

  delay(1000);
}
