#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

// Create display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Character properties
int characterX = 0;   // Character's X position
int characterY = 20;  // Character's Y position
int frame = 0;        // Animation frame counter

void setup() {
  // Initialize the display
  if (!display.begin(SSD1306_PAGEADDR, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.display();
}

void drawHills() {
  // Draw two arcs as hills
  display.drawCircle(40, 32, 30, SSD1306_WHITE);
  display.drawCircle(100, 32, 20, SSD1306_WHITE);
}

void drawCharacter(int x, int y, int frame) {
  // Draw a simple character (circle for head and rectangle for body)
  display.fillCircle(x + 2, y - 5, 3, SSD1306_WHITE); // Head
  display.fillRect(x, y, 4, 8, SSD1306_WHITE);       // Body

  // Animate legs based on the frame
  if (frame % 2 == 0) {
    display.drawLine(x, y + 8, x - 2, y + 12, SSD1306_WHITE); // Left leg
    display.drawLine(x + 4, y + 8, x + 6, y + 12, SSD1306_WHITE); // Right leg
  } else {
    display.drawLine(x, y + 8, x - 2, y + 10, SSD1306_WHITE); // Left leg
    display.drawLine(x + 4, y + 8, x + 6, y + 10, SSD1306_WHITE); // Right leg
  }
}

void loop() {
  // Clear the display
  display.clearDisplay();

  // Draw the hills
  drawHills();

  // Draw the character
  drawCharacter(characterX, characterY, frame);

  // Update display
  display.display();

  // Move the character to the right
  characterX += 2;

  // Reset position when it goes off-screen
  if (characterX > SCREEN_WIDTH) {
    characterX = -10; // Reset position slightly off-screen
  }

  // Increment animation frame
  frame++;

  // Delay for smoother animation
  delay(100);
}
