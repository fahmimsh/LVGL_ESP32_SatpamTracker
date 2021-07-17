#ifndef __BATTERY_FUNCTION_H__
#define __BATTERY_FUNCTION_H__

#define BATTERY_PIN 35
#define BATTERY_CHARGING_PIN 26
#define R1_BATTERY 330
#define R2_BATTERY 1200

#include <Arduino.h>
#include <generated/gui_guider.h>
#include <lvgl.h>

uint8_t batteryLevel();
void Init_TaskBattery();
void TaskBattery(lv_task_t* task);

#endif