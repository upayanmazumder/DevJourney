#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ArduinoJson.h> // Include the ArduinoJson library

// WiFi credentials
const char* ssid = "Upayan's Pavillion Plus";
const char* password = "1234567890";

// Server URL
const char* serverURL = "http://192.168.67.9:5000/connect";

// OLED display configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Initialize OLED display
  if (!display.begin(SSD1306_PAGEADDR, 0x3C)) { // 0x3C is the default I2C address
    Serial.println("SSD1306 allocation failed");
    for (;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Connecting to WiFi...");
  display.display();

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
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

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverURL);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Server response: " + response);

      // Parse the JSON response
      StaticJsonDocument<512> doc; // Adjust the size as per your response
      DeserializationError error = deserializeJson(doc, response);

      if (!error) {
        const char* message = doc["message"]; // Extract the "message" key

        // Display the "message" value on OLED
        display.clearDisplay();
        display.setCursor(0, 0);
        if (message) {
          display.println(message);
        } else {
          display.println("Key not found");
        }
        display.display();
      } else {
        Serial.println("JSON parsing failed");

        // Display JSON error on OLED
        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("JSON error");
        display.display();
      }
    } else {
      Serial.println("Error in HTTP request");

      // Display error on OLED
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("HTTP request error");
      display.display();
    }
    http.end();
  } else {
    Serial.println("WiFi not connected");

    // Display WiFi error on OLED
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("WiFi not connected");
    display.display();
  }

  delay(5000);
}
