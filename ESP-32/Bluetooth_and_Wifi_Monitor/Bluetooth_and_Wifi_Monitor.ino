#include <WiFi.h>
#include <BluetoothSerial.h>

const char *ssid = "Solace";
const char *password = "damnbrodamn";

BluetoothSerial SerialBT;

void connectToWiFi()
{
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected to WiFi, IP address: ");
  Serial.println(WiFi.localIP());
}

void connectToBluetooth()
{

  if (!SerialBT.begin("ESP32_BT_Device"))
  {
    Serial.println("Bluetooth initialization failed!");
    while (1)
      ;
  }

  Serial.println("Bluetooth started!");

  Serial.println("Searching for Bluetooth devices...");
  if (SerialBT.connect("Upayan's Realme"))
  {
    Serial.println("Connected to Bluetooth device!");
  }
  else
  {
    Serial.println("Failed to connect to Bluetooth device.");
  }
}

void setup()
{

  Serial.begin(115200);

  connectToWiFi();

  connectToBluetooth();
}

void loop()
{

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("WiFi is connected.");
  }
  else
  {
    Serial.println("WiFi connection lost.");
    connectToWiFi();
  }

  if (SerialBT.hasClient())
  {
    Serial.println("Bluetooth client is connected.");
  }
  else
  {
    Serial.println("Bluetooth client is disconnected.");
    connectToBluetooth();
  }

  delay(5000);
}
