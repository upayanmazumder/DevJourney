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

// API URL for wttr.in
const char* weatherApiUrl = "https://wttr.in/Vellore?format=%25C";  // Weather condition only

// Create an SSD1306 display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Animation frames for different weather conditions
// (Each array represents one frame of the animation)

const uint8_t sunnyFrames[3][8] PROGMEM = {
  { 0x00, 0x18, 0x24, 0x42, 0x5A, 0x42, 0x24, 0x18 },  // Frame 1: Sun (still)
  { 0x18, 0x24, 0x42, 0x5A, 0x42, 0x24, 0x18, 0x00 },  // Frame 2: Sun (slightly rotated)
  { 0x24, 0x42, 0x5A, 0x42, 0x24, 0x18, 0x00, 0x18 }   // Frame 3: Sun (further rotated)
};

const uint8_t cloudyFrames[3][8] PROGMEM = {
  { 0x30, 0x48, 0x84, 0x04, 0x3C, 0x42, 0x42, 0x3C },  // Frame 1: Clouds
  { 0x48, 0x84, 0x04, 0x3C, 0x42, 0x42, 0x3C, 0x48 },  // Frame 2: Clouds moving
  { 0x84, 0x04, 0x3C, 0x42, 0x42, 0x3C, 0x48, 0x84 }   // Frame 3: Clouds continue moving
};

const uint8_t rainyFrames[3][8] PROGMEM = {
  { 0x30, 0x48, 0x84, 0x04, 0x3C, 0x42, 0x5A, 0x24 },  // Frame 1: Raindrops
  { 0x48, 0x84, 0x04, 0x3C, 0x42, 0x5A, 0x24, 0x30 },  // Frame 2: Raindrops moving down
  { 0x84, 0x04, 0x3C, 0x42, 0x5A, 0x24, 0x30, 0x48 }   // Frame 3: Raindrops continue
};

static const uint8_t snowyFrames[3][8] PROGMEM = {
  { 0x00, 0x00, 0x18, 0x00, 0x3C, 0x00, 0x24, 0x00 },  // Frame 1: Snowflakes
  { 0x3C, 0x00, 0x24, 0x00, 0x42, 0x00, 0x81, 0x00 },  // Frame 2: Snowflakes falling
  { 0x42, 0x00, 0x24, 0x00, 0x3C, 0x00, 0x18, 0x00 }   // Frame 3: Snowflakes continue falling
};

// Function to display an animation sequence for weather conditions
void displayAnimation(const uint8_t frames[][8], int numFrames) {
  for (int frame = 0; frame < numFrames; frame++) {
    display.clearDisplay();
    display.drawBitmap((SCREEN_WIDTH - 8) / 2, (SCREEN_HEIGHT - 8) / 2, frames[frame], 8, 8, SSD1306_WHITE);
    display.display();
    delay(500);  // Delay between frames (500ms for animation speed)
  }
}

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Initialize the OLED display
  if (!display.begin(SSD1306_PAGEADDR, 0x3C)) {
    Serial.println("OLED Init Failed");
    while (1);  // Stay here forever if the display fails
  }

  // Clear display buffer
  display.clearDisplay();
  display.display();

  // Connect to Wi-Fi
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid);

  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries < 20) {
    delay(1000);
    Serial.print(".");
    retries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi Connected!");
    Serial.println("IP: " + WiFi.localIP().toString());
  } else {
    Serial.println("\nFailed to connect to WiFi.");
  }

  // Wait 15 seconds before the first fetch
  Serial.println("Waiting 15 seconds before fetching weather...");
  delay(15000);  // Wait for 15 seconds
}

void loop() {
  fetchWeatherData();

  delay(60000);  // Wait 60 seconds before fetching weather again
}

void fetchWeatherData() {
  HTTPClient http;

  // Make HTTP GET request to wttr.in
  http.begin(weatherApiUrl);
  int httpResponseCode = http.GET();

  if (httpResponseCode == 200) { // Success
    String weatherCondition = http.getString();
    weatherCondition.trim();

    // Convert weatherCondition to lowercase for case-insensitive matching
    weatherCondition.toLowerCase();

    // Match weather keywords and display corresponding animations
    if (weatherCondition.indexOf("sunny") >= 0 || weatherCondition.indexOf("clear") >= 0) {
      displayAnimation(sunnyFrames, 3);  // Show sunny animation
      Serial.println("Weather: Sunny or Clear");
    } else if (weatherCondition.indexOf("cloud") >= 0 || weatherCondition.indexOf("overcast") >= 0 || weatherCondition.indexOf("fog") >= 0) {
      displayAnimation(cloudyFrames, 3);  // Show cloudy animation
      Serial.println("Weather: Cloudy or Overcast");
    } else if (weatherCondition.indexOf("rain") >= 0 || weatherCondition.indexOf("drizzle") >= 0 || weatherCondition.indexOf("showers") >= 0 || weatherCondition.indexOf("patchy") >= 0) {
      displayAnimation(rainyFrames, 3);  // Show rainy animation
      Serial.println("Weather: Rainy or Patchy Rain");
    } else if (weatherCondition.indexOf("snow") >= 0 || weatherCondition.indexOf("sleet") >= 0) {
      displayAnimation(snowyFrames, 3);  // Show snowy animation
      Serial.println("Weather: Snowy or Sleet");
    } else {
      // Unknown condition - display text
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println("Unknown Weather");
      display.println(weatherCondition);  // Show raw condition
      display.display();
      Serial.println("Weather: Unknown (" + weatherCondition + ")");
    }
  } else {
    Serial.println("HTTP Error: " + String(httpResponseCode));
  }

  http.end();
}
