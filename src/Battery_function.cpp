#include <Battery_function.h>

extern uint8_t stateScreen;

uint8_t batteryLevel(){
  analogReadResolution(12);
  uint16_t analogInput = analogRead(BATTERY_PIN);

  float voltageInput = ((float)analogInput / 4096.0) * 3.3;

  float voltageReal = (voltageInput) / (R2_BATTERY * (R1_BATTERY + R1_BATTERY));

  voltageReal = constrain(voltageReal, 3.7, 4.2);
  float percentageBattery = map(voltageReal, 3.7, 4.2, 0.0, 100.0);

  return (uint8_t)percentageBattery;
}

void Init_TaskBattery(){
    lv_task_t *task = lv_task_create(TaskBattery, 1000, LV_TASK_PRIO_MID, NULL);
}

void TaskBattery(lv_task_t* task){
    uint8_t BatteryPercent = batteryLevel();
    
    int charging = digitalRead(BATTERY_CHARGING_PIN);
    

    char strBuffer[8];  
    sprintf(strBuffer, "%d%%", BatteryPercent);

    switch(stateScreen){
        case STATE_SCREEN_HISTORY:
        lv_label_set_text(guider_ui.screen_history_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_history_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_LOGIN:
        lv_label_set_text(guider_ui.screen_Login_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_Login_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_MENU:
        lv_label_set_text(guider_ui.screen_Menu_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_Menu_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_PATROLI:
        lv_label_set_text(guider_ui.screen_menu_patroli_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_menu_patroli_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_RUANGAN:
        lv_label_set_text(guider_ui.screen_menu_ruangan_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_menu_ruangan_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_SCANID:
        lv_label_set_text(guider_ui.screen_set_scanid_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_set_scanid_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_SETTING:
        lv_label_set_text(guider_ui.screen_menu_setting_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_menu_setting_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_WIFI:
        lv_label_set_text(guider_ui.screen_set_wifi_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_set_wifi_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;

    }
}