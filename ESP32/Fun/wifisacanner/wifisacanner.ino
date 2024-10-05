#include "WiFi.h"

void setup() {
  Serial.begin(115200);
  
  // Set Wi-Fi mode to station (client)
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(); // Disconnect from any network initially
  
  delay(1000);  // Give the module some time before starting the scan
  
  Serial.println("Starting Wi-Fi scan...");

  int n = WiFi.scanNetworks();  // Scan for available networks

  if (n == 0) {
    Serial.println("No networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found:");
    for (int i = 0; i < n; ++i) {
      // Print SSID, signal strength, and encryption type for each network
      Serial.printf("%d: %s (%ddBm) %s\n", i + 1, WiFi.SSID(i).c_str(), WiFi.RSSI(i),
                    WiFi.encryptionType(i) == WIFI_AUTH_OPEN ? "Open" : "Secured");
      delay(10);
    }
  }
}

void loop() {
  // Nothing to do here, as we are only scanning once during setup
}
