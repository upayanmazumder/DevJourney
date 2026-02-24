#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <ESP32Servo.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

Servo myServo;

const int servoPin = 13;

void setup()
{
  Serial.begin(115200);

  myServo.attach(servoPin);

  if (!accel.begin())
  {
    Serial.println("No ADXL345 detected!");
    while (1)
      ;
  }

  accel.setRange(ADXL345_RANGE_16_G);
}

void loop()
{
  sensors_event_t event;
  accel.getEvent(&event);

  int servoAngle = map(event.acceleration.x, -16, 16, 0, 180);

  servoAngle = constrain(servoAngle, 0, 180);

  myServo.write(servoAngle);

  Serial.print("X: ");
  Serial.print(event.acceleration.x);
  Serial.print(" m/s^2 | Servo Angle: ");
  Serial.println(servoAngle);

  delay(100);
}
