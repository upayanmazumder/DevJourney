#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "Upayan";  // Your WiFi SSID
const char* webhookUrl = "https://discord.com/api/webhooks/1297230486061453400/UyLrW8xUwTysF5-r8ACi2EEYdxGukCgUrCwo6smlTm0N8Z0MUe5SQe13fbTzOdHhc_hk";  // Discord webhook URL
const int ldrPin = 23;  // Pin for LDR
const int onboardLedPin = 2;  // Pin for onboard LED

void setup() {
  Serial.begin(115200);
  pinMode(ldrPin, INPUT);  // Set the LDR pin as input
  pinMode(onboardLedPin, OUTPUT);  // Set the onboard LED pin as output
  connectToWiFi();
}

void loop() {
  // Read LDR value as digital input (HIGH or LOW)
  int ldrValue = digitalRead(ldrPin);

  // Log the current LDR reading to console
  Serial.print("Current LDR Reading (Digital): ");
  Serial.println(ldrValue);

  // Activate onboard LED when it's bright
  if (ldrValue == HIGH) { // Now HIGH indicates light detected
    digitalWrite(onboardLedPin, HIGH);  // Turn on the onboard LED
  } else {
    digitalWrite(onboardLedPin, LOW);   // Turn off the onboard LED
  }

  // Send stats every 5 seconds
  sendStatsToDiscord(ldrValue);
  delay(5000);  // Delay for 5 seconds
}

void connectToWiFi() {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi");
}

void sendStatsToDiscord(int ldrValue) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(webhookUrl);
    http.addHeader("Content-Type", "application/json");

    // Create JSON object
    StaticJsonDocument<512> jsonDoc;
    JsonArray embeds = jsonDoc.createNestedArray("embeds");
    JsonObject embed = embeds.createNestedObject();

    // Fill in the embed details
    embed["title"] = "ESP32 LDR Stats";
    embed["description"] = "Light status from the ESP32 LDR module.";
    embed["color"] = 7506394; // Example color (RGB format)

    // Create fields array
    JsonArray fields = embed.createNestedArray("fields");

    JsonObject field1 = fields.createNestedObject();
    field1["name"] = "LDR Reading (Digital)";
    field1["value"] = ldrValue == HIGH ? "Light Detected" : "Dark";
    field1["inline"] = true;

    // Serialize the JSON object to string
    String jsonString;
    serializeJson(jsonDoc, jsonString);
    
    // Send the request
    int httpResponseCode = http.POST(jsonString);

    // Check response
    if (httpResponseCode > 0) {
      Serial.printf("POST successful: %d\n", httpResponseCode);
    } else {
      Serial.printf("POST failed: %s\n", http.errorToString(httpResponseCode).c_str());
    }
    http.end();
  } else {
    Serial.println("WiFi not connected!");
  }
}
