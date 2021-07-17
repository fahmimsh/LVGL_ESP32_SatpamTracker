#include "Task_Clock.h"
#include <Time_function.h>

extern uint8_t stateScreen;
static tm time_info;
static void Task_Clock(lv_task_t *task);
static void Task_Date(lv_task_t *task);

void Task_Clock_Init()
{
    static lv_task_t *task_clock;
    task_clock = lv_task_create(Task_Clock, 1000, LV_TASK_PRIO_HIGH, NULL);

    static lv_task_t *task_date;
    task_date = lv_task_create(Task_Date, 1000, LV_TASK_PRIO_LOW, NULL);
}

static void Task_Clock(lv_task_t *task)
{
    static char timeBuf[10];

    getTime_tm(&time_info);

    strftime(timeBuf, 10, "%R", &time_info);

    switch (stateScreen)
    {
    case STATE_SCREEN_LOGIN:
        lv_label_set_text(guider_ui.screen_Login_label_jam, timeBuf);
        break;
    case STATE_SCREEN_MENU:
        lv_label_set_text(guider_ui.screen_Menu_label_jam, timeBuf);
        break;
    case STATE_SCREEN_HISTORY:
        lv_label_set_text(guider_ui.screen_history_label_jam, timeBuf);
        break;
    case STATE_SCREEN_RUANGAN:
        lv_label_set_text(guider_ui.screen_menu_ruangan_label_jam, timeBuf);
        break;
    case STATE_SCREEN_PATROLI:
        lv_label_set_text(guider_ui.screen_menu_patroli_label_jam, timeBuf);
        break;
    case STATE_SCREEN_SETTING:
        lv_label_set_text(guider_ui.screen_menu_setting_label_jam, timeBuf);
        break;
    case STATE_SCREEN_WIFI:
        lv_label_set_text(guider_ui.screen_set_wifi_label_jam, timeBuf);
        break;
    case STATE_SCREEN_SCANID:
        lv_label_set_text(guider_ui.screen_set_scanid_label_jam, timeBuf);
        break;
    }
}

static void Task_Date(lv_task_t *task)
{
    static char dateBuf[20];
    strftime(dateBuf, 20, "%d %B %G", &time_info);

    switch (stateScreen)
    {
    case STATE_SCREEN_LOGIN:
        lv_label_set_text(guider_ui.screen_Login_label_tanggal, dateBuf);
        break;
    case STATE_SCREEN_MENU:
        lv_label_set_text(guider_ui.screen_Menu_label_tanggal, dateBuf);
        break;
    case STATE_SCREEN_HISTORY:
        lv_label_set_text(guider_ui.screen_history_label_tanggal, dateBuf);
        break;
    case STATE_SCREEN_RUANGAN:
        lv_label_set_text(guider_ui.screen_menu_ruangan_label_tanggal, dateBuf);
        break;
    case STATE_SCREEN_PATROLI:
        lv_label_set_text(guider_ui.screen_menu_patroli_label_tanggal, dateBuf);
        break;
    case STATE_SCREEN_SETTING:
        lv_label_set_text(guider_ui.screen_menu_setting_label_tanggal, dateBuf);
        break;
    case STATE_SCREEN_WIFI:
        lv_label_set_text(guider_ui.screen_set_wifi_label_tanggal, dateBuf);
        break;
    case STATE_SCREEN_SCANID:
        lv_label_set_text(guider_ui.screen_set_scanid_label_tanggal, dateBuf);
        break;
    }
}