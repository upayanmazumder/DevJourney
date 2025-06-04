// Simple ESP32-CAM Test
// Blinks the flash LED and prints to Serial

#define LED_FLASH 4  // Onboard flash LED on ESP32-CAM (AI Thinker)

void setup() {
  Serial.begin(115200);
  pinMode(LED_FLASH, OUTPUT);
  Serial.println("ESP32-CAM Test Started");
}

void loop() {
  Serial.println("Turning LED ON");
  digitalWrite(LED_FLASH, HIGH);
  delay(1000);

  Serial.println("Turning LED OFF");
  digitalWrite(LED_FLASH, LOW);
  delay(1000);
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
