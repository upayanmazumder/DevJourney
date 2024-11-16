#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <HTTPClient.h>

// OLED display width and height
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32 // For 0.91" displays

// Wi-Fi credentials (No password)
const char* ssid = "Upayan";  // Wi-Fi SSID with no password

// API URL for wttr.in (weather service)
const char* weatherApiUrl = "https://wttr.in/Vellore?format=%25C+%25t";  // Format to get condition and temperature

// Create an SSD1306 display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Function to log to both the Serial Monitor and the OLED display
void logToDisplayAndSerial(String message) {
  Serial.println(message);  // Log to Serial Monitor

  display.clearDisplay();   // Clear display before printing new message
  display.setTextSize(1);   // Set text size to small
  display.setTextColor(SSD1306_WHITE); // Set text color to white
  display.setCursor(0, 0);  // Set cursor at the top-left corner
  display.println(message); // Display message on OLED
  display.display();        // Update the display
}

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Initialize the OLED display
  if (!display.begin(SSD1306_PAGEADDR, 0x3C)) {  // Correct initialization for the SSD1306 display
    logToDisplayAndSerial("OLED Init Failed");
    while (1);  // Stay here forever if the display fails
  }

  // Clear display buffer
  display.clearDisplay();
  logToDisplayAndSerial("OLED Initialized");

  // Connect to Wi-Fi
  logToDisplayAndSerial("Connecting to WiFi...");
  WiFi.begin(ssid);  // No password required

  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries < 20) {
    delay(1000);
    retries++;
    logToDisplayAndSerial(".");  // Update the display with dots while connecting
  }

  if (WiFi.status() == WL_CONNECTED) {
    logToDisplayAndSerial("WiFi Connected!");
    logToDisplayAndSerial("IP: " + WiFi.localIP().toString());
  } else {
    logToDisplayAndSerial("Failed to connect");
  }

  // Wait for 15 seconds after connecting to WiFi
  logToDisplayAndSerial("Waiting 15 seconds...");
  delay(15000);  // Wait for 15 seconds before fetching weather
}

void loop() {
  // Continuously update the display
  logToDisplayAndSerial("Fetching weather...");
  fetchWeatherData();

  // Wait 60 seconds before fetching weather again
  delay(60000); // Fetch weather data every 60 seconds
}

void fetchWeatherData() {
  HTTPClient http;

  // Make HTTP GET request to wttr.in
  http.begin(weatherApiUrl);
  int httpResponseCode = http.GET();

  if (httpResponseCode == 200) { // Success
    String payload = http.getString();

    // Display weather data on OLED
    String weatherMessage = "Weather: " + payload;
    logToDisplayAndSerial(weatherMessage);
  } else {
    // Log full error response
    String errorMessage = "HTTP Error: " + String(httpResponseCode);
    errorMessage += "\n" + http.errorToString(httpResponseCode);  // Convert error code to string
    String headers = http.getString(); // Get the HTTP response headers (if any)

    // Log detailed error to both the Serial Monitor and OLED
    logToDisplayAndSerial(errorMessage);
    logToDisplayAndSerial("Response Headers: " + headers);  // Full error message
    if (httpResponseCode == 301) {
      // Capture and log the "Location" header for a 301 redirect
      String location = http.header("Location");
      logToDisplayAndSerial("Redirected to: " + location);
    }
  }

  http.end();
}
