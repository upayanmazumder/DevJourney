#include "BluetoothSerial.h"
#include <EEPROM.h>  // Add EEPROM for saving settings

// Define the onboard LED pin (on ESP32, it's usually GPIO 2)
#define LED_PIN 2

// Create a BluetoothSerial object
BluetoothSerial SerialBT;

// Define EEPROM addresses for storing settings
#define EEPROM_BLINK_INTERVAL_ADDR 0
#define EEPROM_LED_STATE_ADDR 4
#define EEPROM_MANUAL_CONTROL_ADDR 8

// Initialize variables for blink intervals
int blinkInterval = 500;  // Start with 500ms delay
int blinkStep = 100;      // Change the interval by 100ms each cycle

bool ledState = false;      // Tracks manual LED state (ON/OFF)
bool manualControl = false; // Tracks if the LED is manually controlled
int ledBrightness = 255;    // Add variable to track LED brightness (PWM)

// Define constants for advanced commands
#define MAX_COMMAND_SIZE 50

void setup() {
  // Initialize the onboard LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Start Bluetooth Serial with a device name
  SerialBT.begin("Upayan's ESP32");  
  Serial.println("Bluetooth device is ready to pair.");

  // Initialize EEPROM with a specific size
  EEPROM.begin(512);

  // Restore settings from EEPROM
  blinkInterval = EEPROM.readInt(EEPROM_BLINK_INTERVAL_ADDR);
  ledState = EEPROM.readBool(EEPROM_LED_STATE_ADDR);
  manualControl = EEPROM.readBool(EEPROM_MANUAL_CONTROL_ADDR);
  
  // Apply saved LED state
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);

  // Provide feedback through Bluetooth
  SerialBT.println("Settings restored. Ready for commands.");
}

void loop() {
  // If there is data from the Bluetooth connection
  if (SerialBT.available()) {
    String input = SerialBT.readString();
    handleBluetoothCommand(input);
  }

  // If manual control is disabled, proceed with automatic blinking
  if (!manualControl) {
    // Blink the LED with the current interval
    digitalWrite(LED_PIN, HIGH);
    delay(blinkInterval);
    digitalWrite(LED_PIN, LOW);
    delay(blinkInterval);
  }
}

// Function to handle Bluetooth commands
void handleBluetoothCommand(String command) {
  command.trim(); // Remove any extra spaces or newlines

  // Help command to list all available commands
  if (command.equals("HELP")) {
    SerialBT.println("Available Commands:");
    SerialBT.println("1. INTERVAL <value>   - Set LED blink interval (100-5000 ms).");
    SerialBT.println("2. LED ON            - Turn the LED on manually.");
    SerialBT.println("3. LED OFF           - Turn the LED off manually.");
    SerialBT.println("4. BRIGHTNESS <0-255> - Set LED brightness (0-255).");
    SerialBT.println("5. AUTO ON           - Enable automatic blinking.");
    SerialBT.println("6. AUTO OFF          - Disable automatic blinking.");
    SerialBT.println("7. STATUS            - Get the current system status.");
    SerialBT.println("8. HELP              - List all available commands.");
  }

  // Set blink interval (e.g., "INTERVAL 1000")
  else if (command.startsWith("INTERVAL ")) {
    String intervalStr = command.substring(9);
    int interval = intervalStr.toInt();
    if (interval > 100 && interval <= 5000) {  // Extended range
      blinkInterval = interval;
      manualControl = false; // Return to automatic control
      EEPROM.writeInt(EEPROM_BLINK_INTERVAL_ADDR, blinkInterval); // Save to EEPROM
      EEPROM.commit();
      SerialBT.println("Blink interval set to: " + String(blinkInterval) + "ms");
    } else {
      SerialBT.println("Invalid interval value. Please use between 100 and 5000 ms.");
    }
  }
  
  // Turn LED ON or OFF manually (e.g., "LED ON" or "LED OFF")
  else if (command.equals("LED ON")) {
    manualControl = true;  // Disable automatic blinking
    ledState = true;
    digitalWrite(LED_PIN, HIGH);
    EEPROM.writeBool(EEPROM_LED_STATE_ADDR, ledState); // Save state
    EEPROM.commit();
    SerialBT.println("LED turned ON.");
  } 
  else if (command.equals("LED OFF")) {
    manualControl = true;  // Disable automatic blinking
    ledState = false;
    digitalWrite(LED_PIN, LOW);
    EEPROM.writeBool(EEPROM_LED_STATE_ADDR, ledState); // Save state
    EEPROM.commit();
    SerialBT.println("LED turned OFF.");
  } 
  
  // Set LED brightness (e.g., "BRIGHTNESS 128")
  else if (command.startsWith("BRIGHTNESS ")) {
    String brightnessStr = command.substring(11);
    int brightness = brightnessStr.toInt();
    if (brightness >= 0 && brightness <= 255) {
      ledBrightness = brightness;
      analogWrite(LED_PIN, ledBrightness);  // Set LED brightness with PWM
      SerialBT.println("LED brightness set to: " + String(ledBrightness));
    } else {
      SerialBT.println("Invalid brightness value. Use 0 to 255.");
    }
  }
  
  // Enable or disable automatic mode (e.g., "AUTO ON" or "AUTO OFF")
  else if (command.equals("AUTO ON")) {
    manualControl = false;
    EEPROM.writeBool(EEPROM_MANUAL_CONTROL_ADDR, manualControl);
    EEPROM.commit();
    SerialBT.println("Automatic blinking enabled.");
  } 
  else if (command.equals("AUTO OFF")) {
    manualControl = true;
    EEPROM.writeBool(EEPROM_MANUAL_CONTROL_ADDR, manualControl);
    EEPROM.commit();
    SerialBT.println("Manual control enabled.");
  } 
  
  // Query current system status (e.g., "STATUS")
  else if (command.equals("STATUS")) {
    String status = "Current status:\n";
    status += "Blink Interval: " + String(blinkInterval) + "ms\n";
    status += "LED State: " + String(ledState ? "ON" : "OFF") + "\n";
    status += "Brightness: " + String(ledBrightness) + "\n";
    status += "Manual Control: " + String(manualControl ? "Enabled" : "Disabled");
    SerialBT.println(status);
  } 
  
  else {
    SerialBT.println("Unknown command. Type 'HELP' for a list of available commands.");
  }
}
