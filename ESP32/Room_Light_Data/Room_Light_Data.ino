#include <WiFi.h>

// WiFi credentials
const char* ssid = "Upayan";
const char* password = "iloveesp";

// Define the analog pin for the LDR
const int ldrPin = 34; // Adjust this pin based on your setup

// Variables to track the maximum and minimum light levels
int maxLightLevel = 0;
int minLightLevel = 4095; // Maximum possible value for 12-bit ADC on ESP32

void setup() {
  // Start serial communication for logging
  Serial.begin(115200);
  delay(100);

  // Log setup start
  Serial.println("\n--- ESP32 Light Monitoring System ---");
  Serial.println("Initializing...");

  // Set the LDR pin as an input with internal pull-up resistor
  pinMode(ldrPin, INPUT_PULLUP);

  // Scan for available WiFi networks
  Serial.println("Scanning for available WiFi networks...");
  int n = WiFi.scanNetworks();

  // Log scan results
  Serial.printf("Found %d networks:\n", n);
  bool ssidFound = false;

  for (int i = 0; i < n; i++) {
    String foundSSID = WiFi.SSID(i);
    Serial.printf(" - Network: %s, Signal Strength: %d dBm\n", foundSSID.c_str(), WiFi.RSSI(i));

    // Check if the desired SSID is in range
    if (foundSSID == ssid) {
      ssidFound = true;
      Serial.printf("Network '%s' is within reach. Attempting to connect...\n", ssid);
      break;
    }
  }

  // Attempt connection only if the SSID is found
  if (ssidFound) {
    WiFi.begin(ssid, password);

    // Attempt to connect with logging for each attempt
    int attemptCount = 0;
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
      attemptCount++;

      // Check if it's taking too long to connect
      if (attemptCount % 10 == 0) {
        Serial.printf("\nStill trying to connect (attempt %d)...\n", attemptCount / 2);
      }
    }

    // WiFi connected
    Serial.println("\nConnected to WiFi!");
    Serial.printf("Network: %s\n", ssid);
    Serial.printf("IP Address: %s\n", WiFi.localIP().toString().c_str());
  } else {
    Serial.printf("Network '%s' not found. Unable to connect.\n", ssid);
  }

  Serial.println("Setup complete. Beginning light level monitoring...\n");
}

void loop() {
  // Read the light level from the LDR
  int lightLevel = analogRead(ldrPin);

  // Update maximum and minimum light levels
  if (lightLevel > maxLightLevel) {
    maxLightLevel = lightLevel;
  }
  if (lightLevel < minLightLevel) {
    minLightLevel = lightLevel;
  }

  // Log the reading every 5 seconds
  static unsigned long lastLogTime = 0;
  unsigned long currentMillis = millis();

  if (currentMillis - lastLogTime >= 5000) { // Log every 5 seconds
    lastLogTime = currentMillis;

    // Log the light level reading
    Serial.println("--- Light Level Reading ---");
    Serial.printf("Raw Light Level Value: %d\n", lightLevel);

    // Log interpreted light level (brightness)
    if (lightLevel < 500) {
      Serial.println("Status: Bright environment detected.");
    } else if (lightLevel < 2000) {
      Serial.println("Status: Normal lighting.");
    } else if (lightLevel < 3500) {
      Serial.println("Status: Dim lighting.");
    } else {
      Serial.println("Status: Dark environment detected.");
    }

    // Log the maximum and minimum light levels
    Serial.printf("Max Light Level: %d\n", maxLightLevel);
    Serial.printf("Min Light Level: %d\n", minLightLevel);

    // Provide a timestamp
    Serial.printf("Timestamp: %lu ms since start\n", millis());
    Serial.println("---------------------------");
  }
}
