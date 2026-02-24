#include <ESP32Servo.h>

Servo servo;

const int trigPin = 32;
const int echoPin = 33;
const int irPin = 34;
const int ledPin = 2;

int doorPosition = 0;

void setup()
{
  Serial.begin(9600);
  delay(3000);

  servo.attach(12);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.println("System initialized. Components ready.");
}

int measureDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

bool isIRObjectDetected()
{
  return digitalRead(irPin) == LOW;
}

void openDoor()
{
  if (doorPosition == 90)
  {
    Serial.println("Door is already fully open.");
    return;
  }

  Serial.println("Opening door slowly...");
  for (int pos = doorPosition; pos <= 90; pos++)
  {
    servo.write(pos);
    doorPosition = pos;
    delay(15);
  }
}

bool canCloseDoor()
{
  int distance = measureDistance();
  bool irDetected = isIRObjectDetected();

  return (distance >= 30 && !irDetected);
}

void closeDoor()
{
  if (doorPosition == 0)
  {
    Serial.println("Door is already fully closed.");
    return;
  }

  if (canCloseDoor())
  {
    Serial.println("Closing door slowly...");
    for (int pos = doorPosition; pos >= 0; pos--)
    {
      servo.write(pos);
      doorPosition = pos;
      delay(15);
    }
  }
  else
  {
    Serial.println("Cannot close door: Object detected or distance is too close.");
  }
}

void checkSensorsAndControlDoor()
{
  int distance = measureDistance();
  bool irDetected = isIRObjectDetected();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | IR Detected: ");
  Serial.println(irDetected ? "Yes" : "No");

  if (distance < 30 && irDetected)
  {
    Serial.println("Both sensors triggered. Opening door fully.");
    openDoor();
    delay(5000);
    closeDoor();
  }
  else if (distance < 30 || irDetected)
  {
    Serial.println("Only one sensor triggered. Opening door slowly.");
    openDoor();

    delay(5000);
    distance = measureDistance();
    irDetected = isIRObjectDetected();

    closeDoor();
  }
  else
  {
    Serial.println("No sensors triggered. Waiting...");
  }
}

void loop()
{
  checkSensorsAndControlDoor();
  delay(100);
}
