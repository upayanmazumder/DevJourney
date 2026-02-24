#include <WiFi.h>

const char *ssid = "Upayan";
const char *password = "iloveesp";

const int ldrPin = 34;

int maxLightLevel = 0;
int minLightLevel = 4095;

void setup()
{

  Serial.begin(115200);
  delay(100);

  Serial.println("\n--- ESP32 Light Monitoring System ---");
  Serial.println("Initializing...");

  pinMode(ldrPin, INPUT_PULLUP);

  Serial.println("Scanning for available WiFi networks...");
  int n = WiFi.scanNetworks();

  Serial.printf("Found %d networks:\n", n);
  bool ssidFound = false;

  for (int i = 0; i < n; i++)
  {
    String foundSSID = WiFi.SSID(i);
    Serial.printf(" - Network: %s, Signal Strength: %d dBm\n", foundSSID.c_str(), WiFi.RSSI(i));

    if (foundSSID == ssid)
    {
      ssidFound = true;
      Serial.printf("Network '%s' is within reach. Attempting to connect...\n", ssid);
      break;
    }
  }

  if (ssidFound)
  {
    WiFi.begin(ssid, password);

    int attemptCount = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
      attemptCount++;

      if (attemptCount % 10 == 0)
      {
        Serial.printf("\nStill trying to connect (attempt %d)...\n", attemptCount / 2);
      }
    }

    Serial.println("\nConnected to WiFi!");
    Serial.printf("Network: %s\n", ssid);
    Serial.printf("IP Address: %s\n", WiFi.localIP().toString().c_str());
  }
  else
  {
    Serial.printf("Network '%s' not found. Unable to connect.\n", ssid);
  }

  Serial.println("Setup complete. Beginning light level monitoring...\n");
}

void loop()
{

  int lightLevel = analogRead(ldrPin);

  if (lightLevel > maxLightLevel)
  {
    maxLightLevel = lightLevel;
  }
  if (lightLevel < minLightLevel)
  {
    minLightLevel = lightLevel;
  }

  static unsigned long lastLogTime = 0;
  unsigned long currentMillis = millis();

  if (currentMillis - lastLogTime >= 5000)
  {
    lastLogTime = currentMillis;

    Serial.println("--- Light Level Reading ---");
    Serial.printf("Raw Light Level Value: %d\n", lightLevel);

    if (lightLevel < 500)
    {
      Serial.println("Status: Bright environment detected.");
    }
    else if (lightLevel < 2000)
    {
      Serial.println("Status: Normal lighting.");
    }
    else if (lightLevel < 3500)
    {
      Serial.println("Status: Dim lighting.");
    }
    else
    {
      Serial.println("Status: Dark environment detected.");
    }

    Serial.printf("Max Light Level: %d\n", maxLightLevel);
    Serial.printf("Min Light Level: %d\n", minLightLevel);

    Serial.printf("Timestamp: %lu ms since start\n", millis());
    Serial.println("---------------------------");
  }
}
