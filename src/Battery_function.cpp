#include <Battery_function.h>
//#include <FahmiKalmanFilter.h>

extern uint8_t stateScreen;

 /*FahmiKalmanFilter(e_mea, e_est, q);
    e_mea: Measurement Uncertainty 
    e_est: Estimation Uncertainty 
    q: Process Noise */

//FahmiKalmanFilter Kalman_filter(2, 2, 0.01);
//serial output refresh time pada ambildata
const long SERIAL_REFRESH_TIME = 100;

float map(float x, float in_min, float in_max, float out_min, float out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint8_t batteryLevel(){
  analogReadResolution(12);
  uint16_t analogInput = analogRead(BATTERY_PIN);

  float voltageInput = ((float)analogInput / 4096.0) * 3.3;
  //float voltageReal = (voltageInput) / (R2_BATTERY * (R1_BATTERY + R1_BATTERY));
  float voltageReal = map(voltageInput, 0.0, 3.3, 3.7, 4.2);

  voltageReal = constrain(voltageReal, 3.7, 4.2);
//   float voltageRealkalman = Kalman_filter.updateEstimate(voltageReal);
//   voltageRealkalman = (voltageRealkalman) / (R2_BATTERY * (R1_BATTERY + R1_BATTERY));
  float percentageBattery = map(voltageReal, 3.7, 4.2, 0.0, 100.0);

  return (uint8_t)percentageBattery;
}

void Init_TaskBattery(){
    lv_task_t *task = lv_task_create(TaskBattery, 10000, LV_TASK_PRIO_MID, NULL);
}

void TaskBattery(lv_task_t* task){
    uint8_t BatteryPercent = batteryLevel();
    
    int charging = digitalRead(BATTERY_CHARGING_PIN);
    

    char strBuffer[8];  
    sprintf(strBuffer, "%d%%", BatteryPercent);

    switch(stateScreen){
        case STATE_SCREEN_HISTORY:
        Serial.println("Tampilan History");
        lv_label_set_text(guider_ui.screen_history_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_history_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_LOGIN:
        Serial.println("Login screen");
        lv_label_set_text(guider_ui.screen_Login_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_Login_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_MENU:
        lv_label_set_text(guider_ui.screen_Menu_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_Menu_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_PATROLI:
        Serial.println("Menu patroli");
        lv_label_set_text(guider_ui.screen_menu_patroli_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_menu_patroli_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_RUANGAN:
        Serial.println("List Ruangan");
        lv_label_set_text(guider_ui.screen_menu_ruangan_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_menu_ruangan_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_SCANID:
        Serial.println("Scan ID card");
        lv_label_set_text(guider_ui.screen_set_scanid_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_set_scanid_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_SETTING:
        Serial.println("Setting");
        lv_label_set_text(guider_ui.screen_menu_setting_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_menu_setting_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
        case STATE_SCREEN_WIFI:
        Serial.println("Wifi");
        lv_label_set_text(guider_ui.screen_set_wifi_bat_status, strBuffer);
        lv_bar_set_value(guider_ui.screen_set_wifi_bar_1, BatteryPercent, LV_ANIM_OFF);
        break;
    }
}