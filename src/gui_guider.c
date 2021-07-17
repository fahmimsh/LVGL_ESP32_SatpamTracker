/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include <lvgl.h>
#include <stdio.h>
#include "generated/gui_guider.h"

void setup_ui(lv_ui *ui){
	setup_scr_screen_Login(ui);
	lv_scr_load(ui->screen_Login);
}
