#include <Arduino.h>
#include <lcdBrightness.h>

void init_lcd_brightness(){
  ledcSetup(PWM_CHANNEL_LCD, 5000/*freq*/, 12 /*resolution*/);
  ledcAttachPin(LCD_LED_PIN, 10);
  analogReadResolution(12);
  ledcWrite(PWM_CHANNEL_LCD, 819);
}

void lcd_setBrightness(uint32_t val){
    uint32_t pwmduty = (uint32_t)map(val, 0, 100, 3200, 500);
    ledcWrite(PWM_CHANNEL_LCD, pwmduty);
}

int lcd_getBrightness(){
    return (uint16_t)(((float)ledcRead(PWM_CHANNEL_LCD) / 4095.0) * 100.0);
}