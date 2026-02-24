#define LED_FLASH 4

void setup()
{
  Serial.begin(115200);
  pinMode(LED_FLASH, OUTPUT);
  Serial.println("ESP32-CAM Test Started");
}

void loop()
{
  Serial.println("Turning LED ON");
  digitalWrite(LED_FLASH, HIGH);
  delay(1000);

  Serial.println("Turning LED OFF");
  digitalWrite(LED_FLASH, LOW);
  delay(1000);
}
