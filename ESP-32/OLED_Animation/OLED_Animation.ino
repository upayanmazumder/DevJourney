#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int characterX = 0;
int characterY = 20;
int frame = 0;

void setup()
{

  if (!display.begin(SSD1306_PAGEADDR, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  display.clearDisplay();
  display.display();
}

void drawHills()
{

  display.drawCircle(40, 32, 30, SSD1306_WHITE);
  display.drawCircle(100, 32, 20, SSD1306_WHITE);
}

void drawCharacter(int x, int y, int frame)
{

  display.fillCircle(x + 2, y - 5, 3, SSD1306_WHITE);
  display.fillRect(x, y, 4, 8, SSD1306_WHITE);

  if (frame % 2 == 0)
  {
    display.drawLine(x, y + 8, x - 2, y + 12, SSD1306_WHITE);
    display.drawLine(x + 4, y + 8, x + 6, y + 12, SSD1306_WHITE);
  }
  else
  {
    display.drawLine(x, y + 8, x - 2, y + 10, SSD1306_WHITE);
    display.drawLine(x + 4, y + 8, x + 6, y + 10, SSD1306_WHITE);
  }
}

void loop()
{

  display.clearDisplay();

  drawHills();

  drawCharacter(characterX, characterY, frame);

  display.display();

  characterX += 2;

  if (characterX > SCREEN_WIDTH)
  {
    characterX = -10;
  }

  frame++;

  delay(100);
}
