#include <dummy.h>

#include <ESP32Servo.h>

#define SENSOR_PIN 13
const int servoPin = 12;

Servo myServo;

int currentAngle = 0;
int step = 15;
unsigned long previousMillis = 0;
const long interval = 1000;

bool obstaclePresent = false;

void setup()
{
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);

  myServo.attach(servoPin);

  myServo.write(currentAngle);
  Serial.println("Servo initialized at 0 degrees");
}

void loop()
{

  int state = digitalRead(SENSOR_PIN);

  if (state == LOW && !obstaclePresent)
  {
    obstaclePresent = true;
    Serial.println("Obstacle detected, starting servo movement.");
  }
  else if (state == HIGH && obstaclePresent)
  {
    obstaclePresent = false;
    Serial.println("Obstacle removed, stopping servo.");
  }

  if (obstaclePresent)
  {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval)
    {
      previousMillis = currentMillis;

      currentAngle += step;

      if (currentAngle >= 180 || currentAngle <= 0)
      {
        step = -step;
      }

      myServo.write(currentAngle);
      Serial.print("Servo position: ");
      Serial.print(currentAngle);
      Serial.println(" degrees");
    }
  }
}