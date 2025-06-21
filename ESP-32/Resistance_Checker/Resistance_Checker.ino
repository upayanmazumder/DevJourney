int analogPin = 34;    // Pin for ADC reading
float R_known = 10000.0;  // Known resistor (10kΩ)
float V_supply = 3.3;     // ESP32 supply voltage (3.3V)

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);  // Set ADC resolution to 12 bits (0-4095)
}

void loop() {
  int adcValue = analogRead(analogPin);   // Read ADC value (0-4095)
  float V_measured = adcValue * (V_supply / 4095.0); // Convert ADC value to voltage
  
  // Calculate the unknown resistance using Ohm's Law
  float R_unknown = R_known * ((V_measured / V_supply) / (1 - (V_measured / V_supply)));
  
  Serial.print("Measured Voltage: ");
  Serial.print(V_measured, 3);
  Serial.print("V, Unknown Resistance: ");
  Serial.print(R_unknown);
  Serial.println(" ohms");
  
  delay(1000);  // Wait for 1 second before measuring again
}
