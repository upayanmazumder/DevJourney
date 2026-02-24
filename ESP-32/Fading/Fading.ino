#include "BluetoothSerial.h"
#include <EEPROM.h>

#define LED_PIN 2

BluetoothSerial SerialBT;

#define EEPROM_BLINK_INTERVAL_ADDR 0
#define EEPROM_LED_STATE_ADDR 4
#define EEPROM_MANUAL_CONTROL_ADDR 8

int blinkInterval = 500;
int blinkStep = 100;

bool ledState = false;
bool manualControl = false;
int ledBrightness = 255;

#define MAX_COMMAND_SIZE 50

void setup()
{

  pinMode(LED_PIN, OUTPUT);

  SerialBT.begin("Upayan's ESP32");
  Serial.println("Bluetooth device is ready to pair.");

  EEPROM.begin(512);

  blinkInterval = EEPROM.readInt(EEPROM_BLINK_INTERVAL_ADDR);
  ledState = EEPROM.readBool(EEPROM_LED_STATE_ADDR);
  manualControl = EEPROM.readBool(EEPROM_MANUAL_CONTROL_ADDR);

  digitalWrite(LED_PIN, ledState ? HIGH : LOW);

  SerialBT.println("Settings restored. Ready for commands.");
}

void loop()
{

  if (SerialBT.available())
  {
    String input = SerialBT.readString();
    handleBluetoothCommand(input);
  }

  if (!manualControl)
  {

    digitalWrite(LED_PIN, HIGH);
    delay(blinkInterval);
    digitalWrite(LED_PIN, LOW);
    delay(blinkInterval);
  }
}

void handleBluetoothCommand(String command)
{
  command.trim();

  if (command.equals("HELP"))
  {
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

  else if (command.startsWith("INTERVAL "))
  {
    String intervalStr = command.substring(9);
    int interval = intervalStr.toInt();
    if (interval > 100 && interval <= 5000)
    {
      blinkInterval = interval;
      manualControl = false;
      EEPROM.writeInt(EEPROM_BLINK_INTERVAL_ADDR, blinkInterval);
      EEPROM.commit();
      SerialBT.println("Blink interval set to: " + String(blinkInterval) + "ms");
    }
    else
    {
      SerialBT.println("Invalid interval value. Please use between 100 and 5000 ms.");
    }
  }

  else if (command.equals("LED ON"))
  {
    manualControl = true;
    ledState = true;
    digitalWrite(LED_PIN, HIGH);
    EEPROM.writeBool(EEPROM_LED_STATE_ADDR, ledState);
    EEPROM.commit();
    SerialBT.println("LED turned ON.");
  }
  else if (command.equals("LED OFF"))
  {
    manualControl = true;
    ledState = false;
    digitalWrite(LED_PIN, LOW);
    EEPROM.writeBool(EEPROM_LED_STATE_ADDR, ledState);
    EEPROM.commit();
    SerialBT.println("LED turned OFF.");
  }

  else if (command.startsWith("BRIGHTNESS "))
  {
    String brightnessStr = command.substring(11);
    int brightness = brightnessStr.toInt();
    if (brightness >= 0 && brightness <= 255)
    {
      ledBrightness = brightness;
      analogWrite(LED_PIN, ledBrightness);
      SerialBT.println("LED brightness set to: " + String(ledBrightness));
    }
    else
    {
      SerialBT.println("Invalid brightness value. Use 0 to 255.");
    }
  }

  else if (command.equals("AUTO ON"))
  {
    manualControl = false;
    EEPROM.writeBool(EEPROM_MANUAL_CONTROL_ADDR, manualControl);
    EEPROM.commit();
    SerialBT.println("Automatic blinking enabled.");
  }
  else if (command.equals("AUTO OFF"))
  {
    manualControl = true;
    EEPROM.writeBool(EEPROM_MANUAL_CONTROL_ADDR, manualControl);
    EEPROM.commit();
    SerialBT.println("Manual control enabled.");
  }

  else if (command.equals("STATUS"))
  {
    String status = "Current status:\n";
    status += "Blink Interval: " + String(blinkInterval) + "ms\n";
    status += "LED State: " + String(ledState ? "ON" : "OFF") + "\n";
    status += "Brightness: " + String(ledBrightness) + "\n";
    status += "Manual Control: " + String(manualControl ? "Enabled" : "Disabled");
    SerialBT.println(status);
  }

  else
  {
    SerialBT.println("Unknown command. Type 'HELP' for a list of available commands.");
  }
}
