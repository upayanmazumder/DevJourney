#include <WiFi.h>
#include <WebServer.h>

// Set your Wi-Fi credentials here
const char* ssid = "Upayan"; // Hard-coded SSID
const char* password = "";   // No password for the network
WebServer server(80);

// Welcome page content (HTML and CSS) to be served by ESP32
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

void setup() {
  Serial.begin(115200);
  delay(10);
  
  // Connect to the hard-coded Wi-Fi network
  WiFi.mode(WIFI_STA);
  Serial.print("Connecting to Wi-Fi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // Wait for connection
  waitForConnection();
}

void waitForConnection() {
  Serial.println("Attempting to connect...");
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 30) { // Try for 30 seconds
    delay(1000);
    Serial.print("Attempt ");
    Serial.print(attempts + 1);
    Serial.println("...");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to Wi-Fi!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    server.on("/", handleRoot);
    server.begin();
    Serial.println("Web server started. Open http://<ESP32_IP>/ in your browser.");
  } else {
    Serial.println("\nFailed to connect to Wi-Fi. Please check your credentials.");
  }
}

void handleRoot() {
  if (WiFi.status() == WL_CONNECTED) {
    // Get ESP32 statistics
    float voltage = getSupplyVoltage(); // Read the supply voltage
    String html = welcomePage;
    html.replace("%IP%", WiFi.localIP().toString()); // Insert the device's IP into the HTML page
    html.replace("%VOLTAGE%", String(voltage, 2));   // Insert the voltage into the HTML page
    html.replace("%HEAP%", String(ESP.getFreeHeap())); // Insert free heap memory
    html.replace("%FREQ%", String(ESP.getCpuFreqMHz())); // Insert CPU frequency
    html.replace("%TEMP%", String(temperatureRead()));   // Insert chip temperature

    server.send(200, "text/html", html); // Serve the welcome page with dynamic content
    Serial.println("Served the welcome page.");
  } else {
    server.send(500, "text/plain", "WiFi not connected");
  }
}

// Function to read supply voltage (in volts)
float getSupplyVoltage() {
  // Read the voltage on the ADC (VUSB)
  // Convert the reading to voltage (Assuming a 3.3V reference)
  int adcValue = analogRead(35); // Connect VUSB to GPIO35
  float voltage = (adcValue / 4095.0) * 3.3; // Scale the value to voltage
  return voltage;
}

void loop() {
  server.handleClient();
}
