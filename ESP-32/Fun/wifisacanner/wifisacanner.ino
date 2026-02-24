#include "WiFi.h"

void setup()
{
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  delay(1000);

  Serial.println("Starting Wi-Fi scan...");

  int n = WiFi.scanNetworks();

  if (n == 0)
  {
    Serial.println("No networks found");
  }
  else
  {
    Serial.print(n);
    Serial.println(" networks found:");
    for (int i = 0; i < n; ++i)
    {

      Serial.printf("%d: %s (%ddBm) %s\n", i + 1, WiFi.SSID(i).c_str(), WiFi.RSSI(i),
                    WiFi.encryptionType(i) == WIFI_AUTH_OPEN ? "Open" : "Secured");
      delay(10);
    }
  }
}

void loop()
{
}
