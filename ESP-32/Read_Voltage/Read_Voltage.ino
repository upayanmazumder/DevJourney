#include <Arduino.h>

const int adcPin = 34;       // ADC pin
const float Vref = 3.3;      // ESP32 ADC reference voltage
const float sensitivity = 50.0 / 1000.0; // 50mA full scale => in amps
const int adcMax = 4095;     // 12-bit ADC

const int samples = 500;     // number of samples per read

void setup() {
  Serial.begin(115200);
}

void loop() {
  float currentRMS = readCurrent();
  Serial.print("Current RMS: ");
  Serial.print(currentRMS, 3); // 3 decimal places
  Serial.println(" A");
  delay(1000);
}

// Read RMS current
float readCurrent() {
  float sum = 0;
  for (int i = 0; i < samples; i++) {
    int raw = analogRead(adcPin);
    // Convert ADC value to voltage
    float voltage = (raw * Vref / adcMax) - (Vref / 2.0); // remove bias
    // Convert voltage to current
    float current = voltage / (68.0 * sensitivity); // V = I*R * scaling
    sum += current * current; // sum of squares
    delayMicroseconds(200); // ~5 kHz sampling
  }
  return sqrt(sum / samples); // RMS
}
