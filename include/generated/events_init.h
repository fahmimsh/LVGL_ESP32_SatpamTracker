/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */


#ifndef EVENTS_INIT_H_
#define EVENTS_INIT_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "generated/gui_guider.h"

void events_init(lv_ui *ui);
void events_init_screen_Menu(lv_ui *ui);
void events_init_screen_menu_ruangan(lv_ui *ui);
void events_init_screen_history(lv_ui *ui);
void events_init_screen_menu_patroli(lv_ui *ui);
void events_init_screen_menu_setting(lv_ui *ui);
void events_init_screen_set_scanid(lv_ui *ui);
void events_init_screen_set_wifi(lv_ui *ui);


#ifdef __cplusplus
}
#endif

#endif /* EVENT_CB_H_ */