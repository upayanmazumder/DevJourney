#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "FunESP32";
const char *password = "";

WebServer server(80);

void setup()
{
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  Serial.println();
  Serial.print("Access Point started with IP: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);

  server.begin();
  Serial.println("Web server started");
}

void loop()
{
  server.handleClient();
}

void handleRoot()
{

  String page = "<html><body><h1>Welcome to FunESP32!</h1>";
  page += "<p>This is a simple web server on an ESP32.</p>";
  page += "<p>Go ahead, try to break it!</p>";
  page += "</body></html>";

  server.send(200, "text/html", page);
}
