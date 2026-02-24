#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <ESP32Servo.h>

const char *ssid = "FunESP32";
const char *password = "";
const int ledPin = 2;
const int servoPin = 15;

WebServer server(80);
DNSServer dnsServer;

bool ledState = false;
int currentFrequency = 1000;
Servo myServo;

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.softAP(ssid, password);
  Serial.print("AP IP Address: ");
  Serial.println(WiFi.softAPIP());

  dnsServer.start(53, "*", WiFi.softAPIP());

  myServo.attach(servoPin);

  server.on("/", handleRoot);
  server.on("/setLed", handleSetLed);
  server.on("/setFrequency", handleSetFrequency);
  server.on("/setServoSpeed", handleSetServoSpeed);
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("Web server started");
}

void loop()
{
  dnsServer.processNextRequest();
  server.handleClient();

  if (ledState)
  {
    digitalWrite(ledPin, HIGH);
    delay(currentFrequency / 2);
    digitalWrite(ledPin, LOW);
    delay(currentFrequency / 2);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}

void handleRoot()
{
  String html = "<html><head>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<style>";
  html += "body { font-family: Arial, sans-serif; margin: 0; padding: 20px; background-color: #e0f7fa; }";
  html += ".container { max-width: 600px; margin: auto; background: white; padding: 20px; border-radius: 8px; box-shadow: 0 0 10px rgba(0,0,0,0.1); }";
  html += "h1 { color: #00796b; }";
  html += "h2 { color: #00796b; margin-top: 20px; }";
  html += "input[type='range'] { width: 100%; margin: 10px 0; }";
  html += "p { font-size: 14px; color: #555; }";
  html += "button { background-color: #00796b; color: white; border: none; padding: 10px 15px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer; border-radius: 5px; }";
  html += "button:hover { background-color: #004d40; }";
  html += "@keyframes fadeIn { from { opacity: 0; } to { opacity: 1; } }";
  html += "div { animation: fadeIn 0.5s; }";
  html += "</style>";
  html += "</head><body><div class='container'>";
  html += "<h1>ESP32 Control</h1>";

  html += "<h2>LED Control</h2>";
  html += "<input type='range' min='0' max='1' step='1' value='" + String(ledState) + "' onchange='updateLed(this.value)'>";

  html += "<h2>Flash Frequency (ms)</h2>";
  html += "<input type='range' min='100' max='2000' step='100' value='" + String(currentFrequency) + "' onchange='updateFrequency(this.value)'><br>";
  html += "<span id='frequencyDisplay'>" + String(currentFrequency) + " ms</span><br>";

  html += "<h2>Servo Speed Control</h2>";
  html += "<input type='range' min='0' max='100' step='1' value='50' onchange='updateServoSpeed(this.value)'><br>";
  html += "<span id='servoSpeedDisplay'>50</span>%</span><br>";

  html += "<h2>Chip Details</h2>";
  html += "<p>Chip Model: " + String(ESP.getChipModel()) + "</p>";
  html += "<p>Chip Revision: " + String(ESP.getChipRevision()) + "</p>";
  html += "<p>Free Heap Size: " + String(ESP.getFreeHeap()) + " bytes</p>";
  html += "<p>CPU Frequency: " + String(ESP.getCpuFreqMHz()) + " MHz</p>";
  html += "<p>Flash Chip Size: " + String(ESP.getFlashChipSize()) + " bytes</p>";
  html += "<p>Flash Chip Speed: " + String(ESP.getFlashChipSpeed()) + " Hz</p>";

  float temperature = getTemperature();
  html += "<h2>Temperature</h2>";
  html += "<p>Temperature: " + String(temperature) + " °C</p>";

  float voltage = getVoltage();
  html += "<h2>Supply Voltage</h2>";
  html += "<p>Voltage: " + String(voltage) + " V</p>";

  int32_t rssi = WiFi.RSSI();
  html += "<h2>Wi-Fi Signal Strength</h2>";
  html += "<p>Signal Strength (RSSI): " + String(rssi) + " dBm</p>";

  html += "<script>";
  html += "function updateLed(value) { fetch('/setLed?state=' + value); }";
  html += "function updateFrequency(value) { fetch('/setFrequency?freq=' + value); document.getElementById('frequencyDisplay').innerText = value + ' ms'; }";
  html += "function updateServoSpeed(value) { fetch('/setServoSpeed?speed=' + value); document.getElementById('servoSpeedDisplay').innerText = value; }";
  html += "</script>";

  html += "</div></body></html>";
  server.send(200, "text/html", html);
}

float getTemperature()
{

  return temperatureRead();
}

float getVoltage()
{

  int adcValue = analogRead(34);
  return (1.1 * 4096) / adcValue;
}

void handleNotFound()
{

  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "Redirecting...");
}

void handleSetLed()
{
  if (server.hasArg("state"))
  {
    ledState = server.arg("state") == "1";
    if (ledState)
    {
      Serial.println("LED ON");
    }
    else
    {
      Serial.println("LED OFF");
    }
  }
  server.send(200, "text/plain", "LED state updated");
}

void handleSetFrequency()
{
  if (server.hasArg("freq"))
  {
    currentFrequency = server.arg("freq").toInt();
    Serial.print("Flash Frequency set to: ");
    Serial.println(currentFrequency);
  }
  server.send(200, "text/plain", "Frequency updated");
}

void handleSetServoSpeed()
{
  if (server.hasArg("speed"))
  {
    int speedValue = server.arg("speed").toInt();
    int servoPosition;

    if (speedValue <= 50)
    {
      servoPosition = map(speedValue, 0, 50, 180, 90);
    }
    else
    {
      servoPosition = map(speedValue, 51, 100, 90, 0);
    }

    myServo.write(servoPosition);
    Serial.print("Servo Speed set to: ");
    Serial.println(servoPosition);
  }
  server.send(200, "text/plain", "Servo speed updated");
}
