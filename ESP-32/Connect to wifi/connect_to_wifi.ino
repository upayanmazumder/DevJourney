#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "Solace";
const char *password = "damnbro";
WebServer server(80);

const char welcomePage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Welcome to ESP32</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      background-color: #f0f0f0;
      text-align: center;
      padding: 20px;
    }
    h1 {
      color: #333;
    }
    p {
      color: #666;
    }
    .box {
      background-color: #fff;
      padding: 20px;
      border-radius: 8px;
      box-shadow: 0 4px 10px rgba(0, 0, 0, 0.1);
      display: inline-block;
      margin-top: 20px;
      width: 300px;
      text-align: left;
    }
  </style>
</head>
<body>
  <h1>Welcome to your ESP32 Server</h1>
  <p>You are successfully connected to the ESP32's Wi-Fi network!</p>
  <div class="box">
    <p><strong>Device IP Address:</strong> %IP%</p>
    <p><strong>Supply Voltage:</strong> %VOLTAGE% V</p>
    <p><strong>Free Heap:</strong> %HEAP% bytes</p>
    <p><strong>CPU Frequency:</strong> %FREQ% MHz</p>
    <p><strong>Chip Temperature:</strong> %TEMP% °C</p>
  </div>
</body>
</html>
)rawliteral";

void setup()
{
  Serial.begin(115200);
  delay(10);

  WiFi.mode(WIFI_STA);
  Serial.print("Connecting to Wi-Fi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  waitForConnection();
}

void waitForConnection()
{
  Serial.println("Attempting to connect...");
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 30)
  {
    delay(1000);
    Serial.print("Attempt ");
    Serial.print(attempts + 1);
    Serial.println("...");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("\nConnected to Wi-Fi!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    server.on("/", handleRoot);
    server.begin();
    Serial.println("Web server started. Open http://<ESP32_IP>/ in your browser.");
  }
  else
  {
    Serial.println("\nFailed to connect to Wi-Fi. Please check your credentials.");
  }
}

void handleRoot()
{
  if (WiFi.status() == WL_CONNECTED)
  {

    float voltage = getSupplyVoltage();
    String html = welcomePage;
    html.replace("%IP%", WiFi.localIP().toString());
    html.replace("%VOLTAGE%", String(voltage, 2));
    html.replace("%HEAP%", String(ESP.getFreeHeap()));
    html.replace("%FREQ%", String(ESP.getCpuFreqMHz()));
    html.replace("%TEMP%", String(temperatureRead()));

    server.send(200, "text/html", html);
    Serial.println("Served the welcome page.");
  }
  else
  {
    server.send(500, "text/plain", "WiFi not connected");
  }
}

float getSupplyVoltage()
{

  int adcValue = analogRead(35);
  float voltage = (adcValue / 4095.0) * 3.3;
  return voltage;
}

void loop()
{
  server.handleClient();
}
