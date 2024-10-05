#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>

const char* ssid = "FunESP32";  // Access Point Name
const char* password = "";      // Open network
const int ledPin = 2;           // Onboard LED pin (ESP32)

WebServer server(80);
DNSServer dnsServer;            // Create a DNS server

// Variable to store LED state
bool ledState = false;
int currentFrequency = 1000;  // Default frequency in milliseconds

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Turn LED off initially

  // Start Access Point
  WiFi.softAP(ssid, password);
  Serial.print("AP IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Start DNS server to redirect all requests to the ESP32 IP address
  dnsServer.start(53, "*", WiFi.softAPIP());

  // Define routes
  server.on("/", handleRoot);
  server.on("/setLed", handleSetLed); 
  server.on("/setFrequency", handleSetFrequency);
  server.onNotFound(handleNotFound); // Redirect all other requests to the root

  // Start server
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  dnsServer.processNextRequest(); // Handle DNS requests
  server.handleClient();           // Handle incoming requests

  // Flash the LED based on the current frequency if it's on
  if (ledState) {
    digitalWrite(ledPin, HIGH); // Turn LED ON
    delay(currentFrequency / 2); // Wait for half the frequency duration
    digitalWrite(ledPin, LOW);   // Turn LED OFF
    delay(currentFrequency / 2); // Wait for the other half
  } else {
    digitalWrite(ledPin, LOW); // Ensure LED is OFF if ledState is false
  }
}

void handleRoot() {
  String html = "<html><body><h1>ESP32 LED Control</h1>";
  
  // Slider for LED control
  html += "<h2>LED Control</h2>";
  html += "<input type='range' min='0' max='1' step='1' value='" + String(ledState) + "' onchange='updateLed(this.value)'><br>";
  
  // Slider for flash frequency
  html += "<h2>Flash Frequency (ms)</h2>";
  html += "<input type='range' min='100' max='2000' step='100' value='" + String(currentFrequency) + "' onchange='updateFrequency(this.value)'><br>";
  html += "<span id='frequencyDisplay'>" + String(currentFrequency) + " ms</span><br>";

  // Chip and environment details
  html += "<h2>Chip Details</h2>";
  html += "<p>Chip Model: " + String(ESP.getChipModel()) + "</p>";
  html += "<p>Chip Revision: " + String(ESP.getChipRevision()) + "</p>"; // Get chip revision
  html += "<p>Free Heap Size: " + String(ESP.getFreeHeap()) + " bytes</p>";
  html += "<p>CPU Frequency: " + String(ESP.getCpuFreqMHz()) + " MHz</p>";
  html += "<p>Flash Chip Size: " + String(ESP.getFlashChipSize()) + " bytes</p>";
  html += "<p>Flash Chip Speed: " + String(ESP.getFlashChipSpeed()) + " Hz</p>";

  // Temperature reading
  float temperature = getTemperature(); // Get temperature reading
  html += "<h2>Temperature</h2>";
  html += "<p>Temperature: " + String(temperature) + " °C</p>";

  // Voltage reading
  float voltage = getVoltage(); // Get supply voltage reading
  html += "<h2>Supply Voltage</h2>";
  html += "<p>Voltage: " + String(voltage) + " V</p>";

  // Wi-Fi Signal Strength
  int32_t rssi = WiFi.RSSI(); // Get Wi-Fi signal strength
  html += "<h2>Wi-Fi Signal Strength</h2>";
  html += "<p>Signal Strength (RSSI): " + String(rssi) + " dBm</p>";

  html += "<script>";
  html += "function updateLed(value) { fetch('/setLed?state=' + value); }";
  html += "function updateFrequency(value) { fetch('/setFrequency?freq=' + value); document.getElementById('frequencyDisplay').innerText = value + ' ms'; }";
  html += "</script>";
  
  html += "</body></html>";
  server.send(200, "text/html", html);
}

float getTemperature() {
  // Use the built-in function for temperature reading
  return temperatureRead(); // This function directly returns the temperature in Celsius
}

float getVoltage() {
  // Read the supply voltage (VCC)
  // VCC = 1.1 * 4096 / ADC; where ADC is the ADC reading from GPIO 34
  int adcValue = analogRead(34); // Read from GPIO 34 (or any other GPIO configured for ADC)
  return (1.1 * 4096) / adcValue; // Voltage calculation (V)
}

void handleNotFound() {
  // Redirect all non-defined routes to the root page
  server.sendHeader("Location", "/");  // Redirect to the root
  server.send(302, "text/plain", "Redirecting...");  // Send a 302 redirect response
}

void handleSetLed() {
  if (server.hasArg("state")) {
    ledState = server.arg("state") == "1"; // Update LED state based on the slider value
    if (ledState) {
      Serial.println("LED ON");
    } else {
      Serial.println("LED OFF");
    }
  }
  server.send(200, "text/plain", "LED state updated");
}

void handleSetFrequency() {
  if (server.hasArg("freq")) {
    currentFrequency = server.arg("freq").toInt(); // Update frequency based on slider value
    Serial.print("Flash Frequency set to: ");
    Serial.println(currentFrequency);
  }
  server.send(200, "text/plain", "Frequency updated");
}
