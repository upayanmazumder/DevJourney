#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

const char *ssid = "Upayan";

const char *weatherApiUrl = "https://wttr.in/Vellore?format=%25C";

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const uint8_t sunnyFrames[3][8] PROGMEM = {
    {0x00, 0x18, 0x24, 0x42, 0x5A, 0x42, 0x24, 0x18},
    {0x18, 0x24, 0x42, 0x5A, 0x42, 0x24, 0x18, 0x00},
    {0x24, 0x42, 0x5A, 0x42, 0x24, 0x18, 0x00, 0x18}};

const uint8_t cloudyFrames[3][8] PROGMEM = {
    {0x30, 0x48, 0x84, 0x04, 0x3C, 0x42, 0x42, 0x3C},
    {0x48, 0x84, 0x04, 0x3C, 0x42, 0x42, 0x3C, 0x48},
    {0x84, 0x04, 0x3C, 0x42, 0x42, 0x3C, 0x48, 0x84}};

const uint8_t rainyFrames[3][8] PROGMEM = {
    {0x30, 0x48, 0x84, 0x04, 0x3C, 0x42, 0x5A, 0x24},
    {0x48, 0x84, 0x04, 0x3C, 0x42, 0x5A, 0x24, 0x30},
    {0x84, 0x04, 0x3C, 0x42, 0x5A, 0x24, 0x30, 0x48}};

static const uint8_t snowyFrames[3][8] PROGMEM = {
    {0x00, 0x00, 0x18, 0x00, 0x3C, 0x00, 0x24, 0x00},
    {0x3C, 0x00, 0x24, 0x00, 0x42, 0x00, 0x81, 0x00},
    {0x42, 0x00, 0x24, 0x00, 0x3C, 0x00, 0x18, 0x00}};

void displayAnimation(const uint8_t frames[][8], int numFrames)
{
  for (int frame = 0; frame < numFrames; frame++)
  {
    display.clearDisplay();
    display.drawBitmap((SCREEN_WIDTH - 8) / 2, (SCREEN_HEIGHT - 8) / 2, frames[frame], 8, 8, SSD1306_WHITE);
    display.display();
    delay(500);
  }
}

void setup()
{

  Serial.begin(115200);

  if (!display.begin(SSD1306_PAGEADDR, 0x3C))
  {
    Serial.println("OLED Init Failed");
    while (1)
      ;
  }

  display.clearDisplay();
  display.display();

  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid);

  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries < 20)
  {
    delay(1000);
    Serial.print(".");
    retries++;
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("\nWiFi Connected!");
    Serial.println("IP: " + WiFi.localIP().toString());
  }
  else
  {
    Serial.println("\nFailed to connect to WiFi.");
  }

  Serial.println("Waiting 15 seconds before fetching weather...");
  delay(15000);
}

void loop()
{
  fetchWeatherData();

  delay(60000);
}

void fetchWeatherData()
{
  HTTPClient http;

  http.begin(weatherApiUrl);
  int httpResponseCode = http.GET();

  if (httpResponseCode == 200)
  {
    String weatherCondition = http.getString();
    weatherCondition.trim();

    weatherCondition.toLowerCase();

    if (weatherCondition.indexOf("sunny") >= 0 || weatherCondition.indexOf("clear") >= 0)
    {
      displayAnimation(sunnyFrames, 3);
      Serial.println("Weather: Sunny or Clear");
    }
    else if (weatherCondition.indexOf("cloud") >= 0 || weatherCondition.indexOf("overcast") >= 0 || weatherCondition.indexOf("fog") >= 0)
    {
      displayAnimation(cloudyFrames, 3);
      Serial.println("Weather: Cloudy or Overcast");
    }
    else if (weatherCondition.indexOf("rain") >= 0 || weatherCondition.indexOf("drizzle") >= 0 || weatherCondition.indexOf("showers") >= 0 || weatherCondition.indexOf("patchy") >= 0)
    {
      displayAnimation(rainyFrames, 3);
      Serial.println("Weather: Rainy or Patchy Rain");
    }
    else if (weatherCondition.indexOf("snow") >= 0 || weatherCondition.indexOf("sleet") >= 0)
    {
      displayAnimation(snowyFrames, 3);
      Serial.println("Weather: Snowy or Sleet");
    }
    else
    {

      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println("Unknown Weather");
      display.println(weatherCondition);
      display.display();
      Serial.println("Weather: Unknown (" + weatherCondition + ")");
    }
  }
  else
  {
    Serial.println("HTTP Error: " + String(httpResponseCode));
  }

  http.end();
}
