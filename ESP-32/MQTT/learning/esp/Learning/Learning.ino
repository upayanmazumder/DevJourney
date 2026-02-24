#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ArduinoJson.h>

const char *ssid = "Upayan's Pavillion Plus";
const char *password = "1234567890";

const char *serverURL = "http://127.0.0.1:5000/connect";

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Serial.begin(115200);

  if (!display.begin(SSD1306_PAGEADDR, 0x3C))
  {
    Serial.println("SSD1306 allocation failed");
    for (;;)
      ;
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Connecting to WiFi...");
  display.display();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    display.print(".");
    display.display();
  }

  Serial.println("\nWiFi connected.");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("WiFi connected.");
  display.display();
}

void loop()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    http.begin(serverURL);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0)
    {
      String response = http.getString();
      Serial.println("Server response: " + response);

      StaticJsonDocument<512> doc;
      DeserializationError error = deserializeJson(doc, response);

      if (!error)
      {
        const char *message = doc["message"];

        display.clearDisplay();
        display.setCursor(0, 0);
        if (message)
        {
          display.println(message);
        }
        else
        {
          display.println("Key not found");
        }
        display.display();
      }
      else
      {
        Serial.println("JSON parsing failed");

        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("JSON error");
        display.display();
      }
    }
    else
    {
      Serial.println("Error in HTTP request");

      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("HTTP request error");
      display.display();
    }
    http.end();
  }
  else
  {
    Serial.println("WiFi not connected");

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("WiFi not connected");
    display.display();
  }

  delay(5000);
}
