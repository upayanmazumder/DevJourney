#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>  // For DNS redirection for captive portal
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <ESP32Servo.h>  // Use ESP32Servo library for ESP32

// Access Point credentials
const char* ssid = "ESP32-Access-Point";
const char* password = "12345678"; // Optional password (at least 8 characters)

// DNS server for captive portal
DNSServer dnsServer;
const byte DNS_PORT = 53;

// Pin Definitions
const int LDRPin = 34;   // Analog pin for LDR
const int IRPin = 14;    // Digital pin for IR sensor
const int trigPin = 12;  // Ultrasonic Trigger
const int echoPin = 13;  // Ultrasonic Echo
const int servoPin = 15; // Servo PWM pin

// Ultrasonic Sensor Variables
long duration;
int distance;

// Create Web Server on port 80
WebServer server(80);

// ADXL Accelerometer object
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

// Servo object
Servo myServo;

void setup() {
  Serial.begin(115200);

  // Start ESP32 in Access Point mode
  WiFi.softAP(ssid, password);  // Create Access Point
  IPAddress IP = WiFi.softAPIP();  // Get ESP32's IP address in AP mode
  Serial.print("Access Point IP Address: ");
  Serial.println(IP);

  // Start DNS server for captive portal (redirect all domains to the ESP32's IP)
  dnsServer.start(DNS_PORT, "*", IP); // Catch-all DNS to the ESP32 IP

  // Initialize Web Server
  server.on("/", handleRoot);  // Main portal page
  server.on("/servo", handleServoControl);  // Servo control
  server.onNotFound(handleRoot); // Redirect any unknown route to the root

  server.begin();
  Serial.println("Web server started");

  // LDR and IR setup
  pinMode(IRPin, INPUT);
  
  // Ultrasonic setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Servo setup
  myServo.attach(servoPin);

  // Initialize Accelerometer
  if (!accel.begin()) {
    Serial.println("Failed to find ADXL345 chip");
    while (1);
  }
  accel.setRange(ADXL345_RANGE_16_G);

  Serial.println("Setup complete");
}

void loop() {
  // Handle DNS and web server clients
  dnsServer.processNextRequest();
  server.handleClient();

  // Read sensor data and display
  readAndDisplaySensorData();
}

void readAndDisplaySensorData() {
  // Read LDR value
  int ldrValue = analogRead(LDRPin);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Read IR sensor value
  int irValue = digitalRead(IRPin);
  Serial.print("IR Sensor: ");
  Serial.println(irValue ? "No Object" : "Object Detected");

  // Read Ultrasonic sensor distance
  distance = getUltrasonicDistance();
  Serial.print("Ultrasonic Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Read accelerometer data
  sensors_event_t event;
  accel.getEvent(&event);
  Serial.print("Accelerometer X: "); Serial.println(event.acceleration.x);
  Serial.print("Accelerometer Y: "); Serial.println(event.acceleration.y);
  Serial.print("Accelerometer Z: "); Serial.println(event.acceleration.z);

  delay(1000);  // Delay for readability
}

int getUltrasonicDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

// Web Server Handlers
void handleRoot() {
  String html = "<html><body>";
  html += "<h1>ESP32 Sensor Data</h1>";
  html += "<p>LDR: " + String(analogRead(LDRPin)) + "</p>";
  html += "<p>IR Sensor: " + String(digitalRead(IRPin) ? "Object Detected" : "No Object") + "</p>";
  html += "<p>Ultrasonic Distance: " + String(getUltrasonicDistance()) + " cm</p>";

  sensors_event_t event;
  accel.getEvent(&event);
  html += "<p>Accelerometer X: " + String(event.acceleration.x) + "</p>";
  html += "<p>Accelerometer Y: " + String(event.acceleration.y) + "</p>";
  html += "<p>Accelerometer Z: " + String(event.acceleration.z) + "</p>";

  html += "<h3>Servo Control</h3>";
  html += "<form action=\"/servo\"><input type=\"range\" name=\"angle\" min=\"0\" max=\"360\">";
  html += "<input type=\"submit\" value=\"Move Servo\"></form>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void handleServoControl() {
  if (server.hasArg("angle")) {
    int angle = server.arg("angle").toInt();
    if (angle >= 0 && angle <= 360) {
      myServo.write(angle);
      server.send(200, "text/html", "<html><body><h1>Servo moved to " + String(angle) + " degrees</h1></body></html>");
    } else {
      server.send(400, "text/html", "<html><body><h1>Invalid angle</h1></body></html>");
    }
  } else {
    server.send(400, "text/html", "<html><body><h1>Angle not provided</h1></body></html>");
  }
}
