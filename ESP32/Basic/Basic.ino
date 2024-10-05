#include <dummy.h>

#include <ESP32Servo.h>

#define SENSOR_PIN 13  // Pin for the sensor
const int servoPin = 12;  // Pin for the servo motor

Servo myServo;  // Create a Servo object

int currentAngle = 0;  // Initial servo position
int step = 15;  // Step size for the servo rotation (15 degrees)
unsigned long previousMillis = 0;  // Store the last time the servo angle was updated
const long interval = 1000;  // Interval at which to update servo position (1000ms for 1 second)

bool obstaclePresent = false;  // Track the obstacle's presence

void setup() {
  Serial.begin(9600);  // Initialize serial communication at a baud rate of 9600
  pinMode(SENSOR_PIN, INPUT);  // Set SENSOR_PIN (pin 18) as input

  // Attach the servo to the defined pin
  myServo.attach(servoPin);
  
  // Start with the servo in the 0-degree position
  myServo.write(currentAngle);
  Serial.println("Servo initialized at 0 degrees");
}

void loop() {
  // Check for obstacle presence
  int state = digitalRead(SENSOR_PIN);  // Read the value from SENSOR_PIN

  // Detect changes in obstacle presence
  if (state == LOW && !obstaclePresent) {
    obstaclePresent = true;  // Obstacle detected
    Serial.println("Obstacle detected, starting servo movement.");
  } else if (state == HIGH && obstaclePresent) {
    obstaclePresent = false;  // Obstacle no longer present
    Serial.println("Obstacle removed, stopping servo.");
  }

  // Asynchronous servo movement when obstacle is present
  if (obstaclePresent) {
    unsigned long currentMillis = millis();

    // Update the servo position every `interval` milliseconds (1 second)
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      // Move the servo in steps of 15 degrees
      currentAngle += step;

      // Reverse direction when limits are reached (0 to 180 degrees)
      if (currentAngle >= 180 || currentAngle <= 0) {
        step = -step;  // Reverse the step direction
      }

      // Move the servo to the updated position
      myServo.write(currentAngle);
      Serial.print("Servo position: ");
      Serial.print(currentAngle);
      Serial.println(" degrees");
    }
  }
}