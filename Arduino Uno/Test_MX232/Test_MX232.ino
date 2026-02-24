#include <SoftwareSerial.h>

SoftwareSerial rs232(10, 11);

void setup()
{
  Serial.begin(9600);
  rs232.begin(9600);
}

void loop()
{
  rs232.println("Hello from SoftwareSerial RS-232");
  Serial.println("Message sent via RS-232");
  delay(1000);
}
