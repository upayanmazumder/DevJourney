#include <WiFi.h>
#include <WebServer.h>

// Wi-Fi network name and password
const char* ssid = "FunESP32";  // AP Name
const char* password = "";      // No password for open network

// Create web server on port 80
WebServer server(80);

void setup() {
  Serial.begin(115200);

  // Start ESP32 as Access Point
  WiFi.softAP(ssid, password);
  Serial.println();
  Serial.print("Access Point started with IP: ");
  Serial.println(WiFi.softAPIP());

  // Define the page to serve on root "/"
  server.on("/", handleRoot);
  
  // Start the web server
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();  // Continuously listen for clients
}

void handleRoot() {
  // Define the content to serve (a fun message!)
  String page = "<html><body><h1>Welcome to FunESP32!</h1>";
  page += "<p>This is a simple web server on an ESP32.</p>";
  page += "<p>Go ahead, try to break it!</p>";
  page += "</body></html>";

  server.send(200, "text/html", page);  // Send HTML response
}
