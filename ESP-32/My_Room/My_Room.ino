#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char *ssid = "Upayan";
const char *webhookUrl = "https://discord.com/api/webhooks/1297230486061453400/UyLrW8xUwTysF5-r8ACi2EEYdxGukCgUrCwo6smlTm0N8Z0MUe5SQe13fbTzOdHhc_hk";
const int ldrPin = 23;
const int onboardLedPin = 2;

void setup()
{
  Serial.begin(115200);
  pinMode(ldrPin, INPUT);
  pinMode(onboardLedPin, OUTPUT);
  connectToWiFi();
}

void loop()
{

  int ldrValue = digitalRead(ldrPin);

  Serial.print("Current LDR Reading (Digital): ");
  Serial.println(ldrValue);

  if (ldrValue == HIGH)
  {
    digitalWrite(onboardLedPin, HIGH);
  }
  else
  {
    digitalWrite(onboardLedPin, LOW);
  }

  sendStatsToDiscord(ldrValue);
  delay(5000);
}

void connectToWiFi()
{
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi");
}

void sendStatsToDiscord(int ldrValue)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    http.begin(webhookUrl);
    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<512> jsonDoc;
    JsonArray embeds = jsonDoc.createNestedArray("embeds");
    JsonObject embed = embeds.createNestedObject();

    embed["title"] = "ESP32 LDR Stats";
    embed["description"] = "Light status from the ESP32 LDR module.";
    embed["color"] = 7506394;

    JsonArray fields = embed.createNestedArray("fields");

    JsonObject field1 = fields.createNestedObject();
    field1["name"] = "LDR Reading (Digital)";
    field1["value"] = ldrValue == HIGH ? "Light Detected" : "Dark";
    field1["inline"] = true;

    String jsonString;
    serializeJson(jsonDoc, jsonString);

    int httpResponseCode = http.POST(jsonString);

    if (httpResponseCode > 0)
    {
      Serial.printf("POST successful: %d\n", httpResponseCode);
    }
    else
    {
      Serial.printf("POST failed: %s\n", http.errorToString(httpResponseCode).c_str());
    }
    http.end();
  }
  else
  {
    Serial.println("WiFi not connected!");
  }
}
