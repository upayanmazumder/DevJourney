#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <ESP32Servo.h>

const char *ssid = "ESP32-Access-Point";
const char *password = "12345678";

DNSServer dnsServer;
const byte DNS_PORT = 53;

const int LDRPin = 34;
const int IRPin = 14;
const int trigPin = 12;
const int echoPin = 13;
const int servoPin = 15;

long duration;
int distance;

WebServer server(80);

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

Servo myServo;

void setup()
{
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Access Point IP Address: ");
  Serial.println(IP);

  dnsServer.start(DNS_PORT, "*", IP);

  server.on("/", handleRoot);
  server.on("/servo", handleServoControl);
  server.onNotFound(handleRoot);

  server.begin();
  Serial.println("Web server started");

  pinMode(IRPin, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(servoPin);

  if (!accel.begin())
  {
    Serial.println("Failed to find ADXL345 chip");
    while (1)
      ;
  }
  accel.setRange(ADXL345_RANGE_16_G);

  Serial.println("Setup complete");
}

void loop()
{

  dnsServer.processNextRequest();
  server.handleClient();

  readAndDisplaySensorData();
}

void readAndDisplaySensorData()
{

  int ldrValue = analogRead(LDRPin);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  int irValue = digitalRead(IRPin);
  Serial.print("IR Sensor: ");
  Serial.println(irValue ? "No Object" : "Object Detected");

  distance = getUltrasonicDistance();
  Serial.print("Ultrasonic Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  sensors_event_t event;
  accel.getEvent(&event);
  Serial.print("Accelerometer X: ");
  Serial.println(event.acceleration.x);
  Serial.print("Accelerometer Y: ");
  Serial.println(event.acceleration.y);
  Serial.print("Accelerometer Z: ");
  Serial.println(event.acceleration.z);

  delay(1000);
}

int getUltrasonicDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

void handleRoot()
{
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

void handleServoControl()
{
  if (server.hasArg("angle"))
  {
    int angle = server.arg("angle").toInt();
    if (angle >= 0 && angle <= 360)
    {
      myServo.write(angle);
      server.send(200, "text/html", "<html><body><h1>Servo moved to " + String(angle) + " degrees</h1></body></html>");
    }
    else
    {
      server.send(400, "text/html", "<html><body><h1>Invalid angle</h1></body></html>");
    }
  }
  else
  {
    server.send(400, "text/html", "<html><body><h1>Angle not provided</h1></body></html>");
  }
}
