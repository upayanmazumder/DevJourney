#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <ESP32Servo.h>  // Use ESP32Servo library instead of Servo

// Create an instance of the ADXL345
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

// Create an instance of the Servo
Servo myServo;

// Define the servo pin
const int servoPin = 13;

// Setup accelerometer and servo
void setup() {
  Serial.begin(115200);

  // Initialize the servo
  myServo.attach(servoPin);
  
  // Initialize the accelerometer
  if (!accel.begin()) {
    Serial.println("No ADXL345 detected!");
    while (1);
  }

  // Set the range to +/- 16g
  accel.setRange(ADXL345_RANGE_16_G);
}

void loop() {
  sensors_event_t event;
  accel.getEvent(&event);

  // Calculate the servo angle based on the X-axis acceleration
  int servoAngle = map(event.acceleration.x, -16, 16, 0, 180);
  
  // Constrain the servo angle to valid range
  servoAngle = constrain(servoAngle, 0, 180);
  
  // Set the servo position
  myServo.write(servoAngle);

  // Print the values to the Serial Monitor
  Serial.print("X: ");
  Serial.print(event.acceleration.x);
  Serial.print(" m/s^2 | Servo Angle: ");
  Serial.println(servoAngle);

  delay(100); // Update every 100 ms
}
