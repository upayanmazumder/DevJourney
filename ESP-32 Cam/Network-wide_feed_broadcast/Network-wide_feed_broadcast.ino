#include "esp_camera.h"
#include <WiFi.h>
#include <WebServer.h>

// Wi-Fi credentials
const char* ssid = "Upayan";
const char* password = "damnbrodamn";

// Flash LED pin (for visual feedback)
#define LED_FLASH 4

// Camera pin definitions for AI Thinker ESP32-CAM
#define PWDN_GPIO_NUM     -1
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

WebServer server(80);

void startCameraServer();

void setup() {
  Serial.begin(115200);
  pinMode(LED_FLASH, OUTPUT);

  // Flash LED once for feedback
  digitalWrite(LED_FLASH, HIGH);
  delay(300);
  digitalWrite(LED_FLASH, LOW);

  // Connect to Wi-Fi
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi connected!");
  Serial.print("Stream available at: http://");
  Serial.println(WiFi.localIP());

  // Camera configuration
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer   = LEDC_TIMER_0;
  config.pin_d0       = Y2_GPIO_NUM;
  config.pin_d1       = Y3_GPIO_NUM;
  config.pin_d2       = Y4_GPIO_NUM;
  config.pin_d3       = Y5_GPIO_NUM;
  config.pin_d4       = Y6_GPIO_NUM;
  config.pin_d5       = Y7_GPIO_NUM;
  config.pin_d6       = Y8_GPIO_NUM;
  config.pin_d7       = Y9_GPIO_NUM;
  config.pin_xclk     = XCLK_GPIO_NUM;
  config.pin_pclk     = PCLK_GPIO_NUM;
  config.pin_vsync    = VSYNC_GPIO_NUM;
  config.pin_href     = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;  // ✅ Updated name
  config.pin_sccb_scl = SIOC_GPIO_NUM;  // ✅ Updated name
  config.pin_pwdn     = PWDN_GPIO_NUM;
  config.pin_reset    = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  config.frame_size = FRAMESIZE_QVGA;   // 320x240
  config.jpeg_quality = 12;
  config.fb_count = 2;

  // Initialize camera
  if (esp_camera_init(&config) != ESP_OK) {
    Serial.println("❌ Camera init failed");
    return;
  }

  // Start web server
  startCameraServer();
}

void handleRoot() {
  server.send(200, "text/html", R"rawliteral(
    <html>
      <head><title>ESP32-CAM: Upayan</title></head>
      <body style="background-color: #111; color: #fff; text-align: center;">
        <h1>ESP32-CAM Stream</h1>
        <h2>User: Upayan</h2>
        <img src="/stream" width="100%">
      </body>
    </html>
  )rawliteral");
}

void handleStream() {
  WiFiClient client = server.client();

  String response = "HTTP/1.1 200 OK\r\n";
  response += "Content-Type: multipart/x-mixed-replace; boundary=frame\r\n\r\n";
  server.sendContent(response);

  while (true) {
    camera_fb_t* fb = esp_camera_fb_get();
    if (!fb) break;

    server.sendContent("--frame\r\n");
    server.sendContent("Content-Type: image/jpeg\r\n\r\n");
    server.sendContent((const char*)fb->buf, fb->len);
    server.sendContent("\r\n");

    esp_camera_fb_return(fb);
    if (!client.connected()) break;
    delay(50);
  }
}

void startCameraServer() {
  server.on("/", handleRoot);
  server.on("/stream", HTTP_GET, handleStream);
  server.begin();
}

void loop() {
  server.handleClient();
}
