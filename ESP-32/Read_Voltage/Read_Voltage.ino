#include <Arduino.h>

const int adcPin = 34;
const float Vref = 3.3;
const float sensitivity = 50.0 / 1000.0;
const int adcMax = 4095;

const int samples = 500;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  float currentRMS = readCurrent();
  Serial.print("Current RMS: ");
  Serial.print(currentRMS, 3);
  Serial.println(" A");
  delay(1000);
}

float readCurrent()
{
  float sum = 0;
  for (int i = 0; i < samples; i++)
  {
    int raw = analogRead(adcPin);

    float voltage = (raw * Vref / adcMax) - (Vref / 2.0);

    float current = voltage / (68.0 * sensitivity);
    sum += current * current;
    delayMicroseconds(200);
  }
  return sqrt(sum / samples);
}
