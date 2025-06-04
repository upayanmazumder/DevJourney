#include <Wire.h>

#define SDA_PIN 26  // Or your actual SIOD pin
#define SCL_PIN 27  // Or your actual SIOC pin

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nSCCB (I2C-like) Camera Bus Scan");
  Wire.begin(SDA_PIN, SCL_PIN);
  scanI2CDevices();
}

void loop() {
  // required even if unused
}

void scanI2CDevices() {
  byte error, address;
  int count = 0;

  Serial.println("Scanning for I2C/SCCB devices...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Device found at address 0x");
      Serial.print(address, HEX);
      Serial.println(" !");
      count++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      Serial.println(address, HEX);
    }
  }

  if (count == 0)
    Serial.println("No I2C/SCCB devices found. Check wiring and power.");
  else
    Serial.println("Scan complete.");
}
