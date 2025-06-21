#include <ESP32Servo.h>  // Include the ESP32Servo library

// Declare a Servo object
Servo servo;

// Define pin mappings
const int trigPin = 32;  // Ultrasonic sensor TRIG pin
const int echoPin = 33;  // Ultrasonic sensor ECHO pin
const int irPin = 34;    // IR sensor pin
const int ledPin = 2;    // Onboard LED pin

// Variable to track door position
int doorPosition = 0; // Start with the door closed (0 degrees)

// Function to initialize components
void setup() {
  Serial.begin(9600);
  delay(3000); // Allow time for serial monitor to initialize

  // Attach the servo and set pin modes
  servo.attach(12);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.println("System initialized. Components ready.");
}

// Function to measure distance using the ultrasonic sensor
int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2; // Return distance in cm
}

// Function to read the IR sensor
bool isIRObjectDetected() {
  return digitalRead(irPin) == LOW; // Return true if an object is detected
}

// Function to open the door gradually
void openDoor() {
  if (doorPosition == 90) {
    Serial.println("Door is already fully open.");
    return; // No need to open if the door is already open
  }

  Serial.println("Opening door slowly...");
  for (int pos = doorPosition; pos <= 90; pos++) {
    servo.write(pos);
    doorPosition = pos; // Update the door position
    delay(15); // Adjust delay for speed of opening
  }
}

// Function to check sensor states before closing the door
bool canCloseDoor() {
  int distance = measureDistance();
  bool irDetected = isIRObjectDetected();
  
  return (distance >= 30 && !irDetected); // Return true if no object is detected
}

// Function to close the door gradually
void closeDoor() {
  if (doorPosition == 0) {
    Serial.println("Door is already fully closed.");
    return; // No need to close if the door is already closed
  }

  if (canCloseDoor()) {
    Serial.println("Closing door slowly...");
    for (int pos = doorPosition; pos >= 0; pos--) {
      servo.write(pos);
      doorPosition = pos; // Update the door position
      delay(15); // Adjust delay for speed of closing
    }
  } else {
    Serial.println("Cannot close door: Object detected or distance is too close.");
  }
}

// Function to check sensor states and control the door
void checkSensorsAndControlDoor() {
  int distance = measureDistance();
  bool irDetected = isIRObjectDetected();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | IR Detected: ");
  Serial.println(irDetected ? "Yes" : "No");

  // Logic to open or close the door based on sensor readings
  if (distance < 30 && irDetected) {
    Serial.println("Both sensors triggered. Opening door fully.");
    openDoor();
    delay(5000); // Keep the door open for 5 seconds
    closeDoor(); // Close the door immediately after
  } 
  else if (distance < 30 || irDetected) {
    Serial.println("Only one sensor triggered. Opening door slowly.");
    openDoor();
    
    // Wait before checking again
    delay(5000); // Keep the door open for 5 seconds
    distance = measureDistance();
    irDetected = isIRObjectDetected();

    // Check sensor states before closing
    closeDoor(); // Call the modified closeDoor function
  } 
  else {
    Serial.println("No sensors triggered. Waiting...");
  }
}

void loop() {
  checkSensorsAndControlDoor(); // Run the sensor check and control logic
  delay(100); // Wait before the next check
}
