#ifndef __LCDBRIGHTNESS_H__
#define __LCDBRIGHTNESS_H__

#ifdef __cplusplus
extern "C"{
#endif
#define PWM_CHANNEL_LCD 10
#define LCD_LED_PIN 32

void init_lcd_brightness();
void lcd_setBrightness(uint32_t val);
int lcd_getBrightness();
#ifdef __cplusplus
}
#endif

#endif