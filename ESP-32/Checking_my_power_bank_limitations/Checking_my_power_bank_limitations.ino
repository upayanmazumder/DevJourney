#include <WiFi.h>
#include <HTTPClient.h>
#include <TimeLib.h>

const char *ssid = "Upayan";
const char *discordWebhookURL = "https://discord.com/api/webhooks/1297230486061453400/UyLrW8xUwTysF5-r8ACi2EEYdxGukCgUrCwo6smlTm0N8Z0MUe5SQe13fbTzOdHhc_hk";

const int measurementInterval = 60000;

const int timeZoneOffset = 19800;

void setup()
{
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  setTimeOffset(timeZoneOffset);
}

void loop()
{
  unsigned long startTime = millis();

  int hour = hourFormat12(now());
  int minute = minute();
  int second = second();
  String timeString = String(hour) + ":" + String(minute, DEC) + ":" + String(second, DEC);

  String message = "Time in IST: " + timeString;

  if (WiFi.isConnected())
  {
    HTTPClient http;
    http.begin(discordWebhookURL);
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.POST("{\"content\": \"" + message + "\"}");

    if (httpResponseCode > 0)
    {
      Serial.print("HTTP request successful, code: ");
      Serial.println(httpResponseCode);
    }
    else
    {
      Serial.print("HTTP request failed, code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
  else
  {
    Serial.println("Failed to connect to WiFi for sending message");
  }

  Serial.println("Entering deep sleep...");
  esp_deep_sleep(measurementInterval * 1000);

  unsigned long wakeupTime = millis();
  Serial.println("Woke up from deep sleep");
  Serial.print("Deep sleep duration: ");
  Serial.print(wakeupTime - startTime);
  Serial.println(" ms");
}