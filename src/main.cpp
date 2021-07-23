#include <Arduino.h>
#include <TFT_eSPI.h>
#include <Wire.h>
#include <SPIFFS.h>
#include <SPI.h>
#include <SD.h>
#include <FS.h>
#include <string.h>
#include <stdio.h>
#include <Adafruit_PN532.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <lvgl.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include "NFC_function.h"
#include "Task_Clock.h"
#include "Buzzer_function.h"
#include "Battery_function.h"
#include "lcdBrightness.h"
#include "WiFi_function.h"
#include "Time_function.h"
#include "generated/gui_guider.h"

#define SD_CS 5
#define power_off 17
volatile bool BuzzerPrevMillisSet = true;
volatile bool buzzerON = false;
volatile uint32_t BuzzerCurrentMillis = 0;
volatile uint32_t BuzzerPreviousMillis = 0;

lv_ui guider_ui;

Adafruit_PN532 nfc(PN532_PIN_IRQ, PN532_PIN_RESET);

TFT_eSPI tft = TFT_eSPI(); /* TFT instance */
static lv_disp_buf_t disp_buf;
static lv_color_t buf[LV_HOR_RES_MAX * 10];

int screenWidth = 480;
int screenHeight = 320;

volatile uint8_t stateScreen = 0;
volatile bool changeScreen = false;

DynamicJsonDocument doc(1024);
HTTPClient http;
Satpam_t satpam;

#if USE_LV_LOG != 0
/* Serial debugging */
void my_print(lv_log_level_t level, const char * file, uint32_t line, const char * dsc)
{

  Serial.printf("%s@%d->%s\r\n", file, line, dsc);
  delay(100);
}
#endif

void printEvent(String Event, lv_event_t event)
{

  Serial.print(Event);
  printf(" ");

  switch(event) {
      case LV_EVENT_PRESSED:
          printf("Pressed\n");
          break;

      case LV_EVENT_SHORT_CLICKED:
          printf("Short clicked\n");
          break;

      case LV_EVENT_CLICKED:
          printf("Clicked\n");
          break;

      case LV_EVENT_LONG_PRESSED:
          printf("Long press\n");
          break;

      case LV_EVENT_LONG_PRESSED_REPEAT:
          printf("Long press repeat\n");
          break;

      case LV_EVENT_RELEASED:
          printf("Released\n");
          break;
  }
}

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint16_t c;

  tft.startWrite(); /* Start new TFT transaction */
  tft.setAddrWindow(area->x1, area->y1, (area->x2 - area->x1 + 1), (area->y2 - area->y1 + 1)); /* set the working window */
  for (int y = area->y1; y <= area->y2; y++) {
    for (int x = area->x1; x <= area->x2; x++) {
      c = color_p->full;
      tft.writeColor(c, 1);
      color_p++;
    }
  }
  tft.endWrite(); /* terminate TFT transaction */
  lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */
}

bool my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
    uint16_t touchX, touchY;

    bool touched = tft.getTouch(&touchX, &touchY, 600);

    if(!touched)
    {
      return false;
    }

    if(touchX>screenWidth || touchY > screenHeight)
    {
      Serial.println("Y or y outside of expected parameters..");
      Serial.print("y:");
      Serial.print(touchX);
      Serial.print(" x:");
      Serial.print(touchY);
    }
    else
    {

      data->state = touched ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL; 

      /*Save the state and save the pressed coordinate*/
      //if(data->state == LV_INDEV_STATE_PR) touchpad_get_xy(&last_x, &last_y);

      /*Set the coordinates (if released use the last pressed coordinates)*/
      data->point.x = touchX;
      data->point.y = touchY;

      Serial.print("Data x");
      Serial.println(touchX);

      Serial.print("Data y");
      Serial.println(touchY);

    }

    return false; /*Return `false` because we are not buffering and no more data to read*/
}

void setup() {
  // put your setup code here, to run once:
  pinMode(power_off, OUTPUT);
  digitalWrite(power_off, HIGH);
  init_lcd_brightness();
  Serial.begin(115200); /* prepare for possible serial debug */
  lv_init();
  lv_fs_if_init();
  //lv_png_init();

  initBuzzer();

  tft.begin(); /* TFT init */

  tft.setRotation(3);

  uint16_t calData[5] = { 275, 3620, 264, 3532, 1 };
  tft.setTouch(calData);

  if(!SD.begin(SD_CS, SPI, SPI_FREQUENCY)){
	  Serial.println("Gagal memuat kartu SD");
	  return;
  }

  uint8_t cardType = SD.cardType();
  if(cardType == CARD_NONE) {
	  Serial.println("Tidak ada kartu SD");
	  return;
  }

  //_lv_fs_init();
  

  lv_fs_dir_t dir;
  lv_fs_res_t res;
  res = lv_fs_dir_open(&dir, "S:/images");
  if(res != LV_FS_RES_OK) {
	  Serial.println("Gagal 1!");
	  while(1);
  }

  char fn[256];
  while(1) {
    res = lv_fs_dir_read(&dir, fn);
    if(res != LV_FS_RES_OK) {
        Serial.println("Gagal 2");
        break;
    }

    /*fn is empty, if not more files to read*/
    if(strlen(fn) == 0) {
        break;
    }

    //printf("%s\n", fn);
	  Serial.println(fn);
  }

  lv_fs_dir_close(&dir);

  #if USE_LV_LOG != 0
    lv_log_register_print_cb(my_print); /* register print function for debugging */
  #endif

  lv_disp_buf_init(&disp_buf, buf, NULL, LV_HOR_RES_MAX * 10);

  /*Initialize the display*/
  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.buffer = &disp_buf;
  lv_disp_drv_register(&disp_drv);

  /*Initialize the input device driver*/
  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);             /*Descriptor of a input device driver*/
  indev_drv.type = LV_INDEV_TYPE_POINTER;    /*Touch pad is a pointer-like device*/
  indev_drv.read_cb = my_touchpad_read;      /*Set your driver function*/
  lv_indev_drv_register(&indev_drv);         /*Finally register the driver*/

  //Set the theme..
  lv_theme_t * th = lv_theme_material_init(LV_THEME_DEFAULT_COLOR_PRIMARY, LV_THEME_DEFAULT_COLOR_SECONDARY, LV_THEME_DEFAULT_FLAG, LV_THEME_DEFAULT_FONT_SMALL , LV_THEME_DEFAULT_FONT_NORMAL, LV_THEME_DEFAULT_FONT_SUBTITLE, LV_THEME_DEFAULT_FONT_TITLE);     
  lv_theme_set_act(th);

  lv_obj_t * scr = lv_cont_create(NULL, NULL);
  lv_disp_load_scr(scr);

  init_nfc();

  Init_TaskBattery();

  WiFi.mode(WIFI_MODE_STA);
  WiFi.begin("Fahmi", "tanyadulu");
  Serial.print("Connecting.");

  WiFi.scanNetworks();
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println(WiFi.localIP());
  initTime();

  Serial.println("Mulai...");

  setup_ui(&guider_ui);
  Task_Clock_Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  lv_task_handler(); /* let the GUI do its work */
  loop_nfc();
  loop_buzzer();
  delay(5);
}