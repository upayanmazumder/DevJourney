#include <Wire.h>
#include <U8g2lib.h>
#include <SoftwareSerial.h>

// OLED Display: Use hardware I2C (SCL/SDA)
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0); 

// RS232 via SoftwareSerial: RX = D10, TX = D11
SoftwareSerial rs232Serial(10, 11);

String incoming = "";
unsigned long lastSend = 0;
unsigned long lastReceive = 0;
bool connected = false;
String lastDisplay = "";

void setup() {
  u8g2.begin();
  Serial.begin(9600);              
  rs232Serial.begin(9600);        

  displayMessage("Starting...");
  delay(1000);

  rs232Serial.println(">>> RS232 Test <<<");
  Serial.println("RS232 test message sent.");
}

void loop() {
  // Check for RS232 incoming
  while (rs232Serial.available()) {
    char c = rs232Serial.read();
    incoming += c;
    lastReceive = millis();
    connected = true;

    if (c == '\n' || incoming.length() >= 40) {
      incoming.trim(); // remove newline
      Serial.print("Received: ");
      Serial.println(incoming);
      lastDisplay = "Received:\n" + incoming;
      displayMessage(lastDisplay);
      incoming = "";
    }
  }

  // If more than 10s since last receive, mark as disconnected
  if (connected && millis() - lastReceive > 10000) {
    connected = false;
    displayMessage("Waiting for RS232...");
  }

  // Send RS232 message every 5 seconds
  if (millis() - lastSend > 5000) {
    String msg = "Hello from Arduino\n";
    rs232Serial.print(msg);
    Serial.print("Sent: ");
    Serial.println(msg);
    lastSend = millis();
  }
}

// Function to display multiline message
void displayMessage(const String& msg) {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB08_tr);
    int y = 12;
    int lineStart = 0;
    for (int i = 0; i < msg.length(); i++) {
      if (msg[i] == '\n' || i == msg.length() - 1) {
        String line = msg.substring(lineStart, i + 1);
        u8g2.drawStr(0, y, line.c_str());
        y += 12;
        lineStart = i + 1;
      }
    }
  } while (u8g2.nextPage());
}
