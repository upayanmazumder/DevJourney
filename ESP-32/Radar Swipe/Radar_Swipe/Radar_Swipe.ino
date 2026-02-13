#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID   "TMPL3Fi31-SEj"
#define BLYNK_TEMPLATE_NAME "Radar Sweep"
#define BLYNK_AUTH_TOKEN    "umXnE9fN8o8eZB7cBsn5pXnBKJOqwVUN"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

// 📶 WiFi
char ssid[] = "Solace";
char pass[] = "damnbrodamn";

// ⚙️ Servo
const int servoPin = 12;
Servo myServo;

int angle = 0;
int step = 2;                      // dynamic now
const int interval = 20;           // FIXED timing
unsigned long prevMillis = 0;

bool radarOn = false;

// 🔘 Button (V0)
BLYNK_WRITE(V0) {
  radarOn = param.asInt();
  Serial.println(radarOn ? "Radar ON" : "Radar OFF");
}

// 🎚️ Slider (V1) → SPEED (natural)
BLYNK_WRITE(V1) {
  int speed = param.asInt();        // 1–10
  step = speed;                    // direct control

  if (step < 1) step = 1;

  Serial.print("Radar speed step: ");
  Serial.println(step);
}

void setup() {
  Serial.begin(9600);

  myServo.attach(servoPin);
  myServo.write(angle);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Radar Sweep online 🛰️");
}

void loop() {
  Blynk.run();

  if (!radarOn) return;

  unsigned long now = millis();
  if (now - prevMillis >= interval) {
    prevMillis = now;

    angle += step;
    if (angle >= 180) {
      angle = 180;
      step = -step;
    }
    else if (angle <= 0) {
      angle = 0;
      step = -step;
    }

    myServo.write(angle);
  }
}
