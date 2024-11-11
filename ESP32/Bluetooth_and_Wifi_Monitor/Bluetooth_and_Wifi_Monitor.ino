#include <WiFi.h>
#include <BluetoothSerial.h>

// Wi-Fi credentials
const char* ssid = "Upayan";
const char* password = "iloveesp";

// Bluetooth Serial object
BluetoothSerial SerialBT;

// Function to connect to Wi-Fi
void connectToWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  
  // Attempt to connect to Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected to WiFi, IP address: ");
  Serial.println(WiFi.localIP());
}

// Function to initialize Bluetooth and connect to the device
void connectToBluetooth() {
  // Initialize Bluetooth with a name for this ESP32 device
  if (!SerialBT.begin("ESP32_BT_Device")) {  // Can be any name for the ESP32
    Serial.println("Bluetooth initialization failed!");
    while (1);  // Infinite loop to stop the program
  }

  Serial.println("Bluetooth started!");

  // Attempt to connect to Bluetooth device by name
  Serial.println("Searching for Bluetooth devices...");
  if (SerialBT.connect("Upayan's Realme")) {
    Serial.println("Connected to Bluetooth device!");
  } else {
    Serial.println("Failed to connect to Bluetooth device.");
  }
}

void setup() {
  // Start the serial monitor for debugging
  Serial.begin(115200);

  // Connect to Wi-Fi
  connectToWiFi();

  // Connect to Bluetooth
  connectToBluetooth();
}

void loop() {
  // Handle Wi-Fi connection status
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi is connected.");
  } else {
    Serial.println("WiFi connection lost.");
    connectToWiFi();  // Reconnect to Wi-Fi if lost
  }

  // Handle Bluetooth connection status
  if (SerialBT.hasClient()) {
    Serial.println("Bluetooth client is connected.");
  } else {
    Serial.println("Bluetooth client is disconnected.");
    connectToBluetooth();  // Attempt reconnection to Bluetooth device if disconnected
  }

  delay(5000);  // Delay to prevent overwhelming the serial monitor
}
