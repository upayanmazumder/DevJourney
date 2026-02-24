#include "esp_camera.h"
#include "FS.h"
#include "SD_MMC.h"

#define CAMERA_MODEL_AI_THINKER
#include "camera_pins.h"

#define FRAME_INTERVAL_MS 200
unsigned long last_capture_time = 0;
int frame_id = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("🚴 BicycleCam starting...");

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  if (psramFound())
  {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  }
  else
  {
    config.frame_size = FRAMESIZE_VGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

  if (esp_camera_init(&config) != ESP_OK)
  {
    Serial.println("❌ Camera init failed");
    while (true)
      ;
  }

  sensor_t *s = esp_camera_sensor_get();
  s->set_brightness(s, 1);
  s->set_contrast(s, 1);
  s->set_saturation(s, 0);
  s->set_special_effect(s, 0);

  if (!SD_MMC.begin())
  {
    Serial.println("❌ SD Card Mount Failed");
    while (true)
      ;
  }

  uint64_t cardSize = SD_MMC.cardSize() / (1024 * 1024);
  Serial.printf("✅ SD Card Size: %llu MB\n", cardSize);
}

void loop()
{
  if (millis() - last_capture_time >= FRAME_INTERVAL_MS)
  {
    last_capture_time = millis();

    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb)
    {
      Serial.println("❌ Frame capture failed");
      return;
    }

    char path[32];
    snprintf(path, sizeof(path), "/frame_%05d.jpg", frame_id++);
    File file = SD_MMC.open(path, FILE_WRITE);

    if (!file)
    {
      Serial.printf("❌ Failed to save %s\n", path);
    }
    else
    {
      file.write(fb->buf, fb->len);
      Serial.printf("✅ Saved %s (%d bytes)\n", path, fb->len);
    }

    file.close();
    esp_camera_fb_return(fb);
  }
}
