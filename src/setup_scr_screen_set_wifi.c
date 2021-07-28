/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl.h"
#include <stdio.h>
#include "generated/gui_guider.h"
#include "generated/events_init.h"
#include "custom/custom.h"
#include "WiFi_function.h"

extern void screen_set_wifi_list_ssidevent_handler(lv_obj_t * obj, lv_event_t event);
extern bool buzzerON;
extern uint8_t stateScreen;

void setup_scr_screen_set_wifi(lv_ui *ui){

	uint8_t WiFin = updateWiFiList();

	//lv_obj_del(lv_scr_act());
	buzzerON = true;

	//Write codes screen_set_wifi
	ui->screen_set_wifi = lv_obj_create(NULL, NULL);

	//Write codes screen_set_wifi_tileview_1
	ui->screen_set_wifi_tileview_1 = lv_tileview_create(ui->screen_set_wifi, NULL);
	static lv_point_t screen_set_wifi_tileview_1_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_set_wifi_tileview_1, screen_set_wifi_tileview_1_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_set_wifi_tileview_1, true);
	lv_tileview_set_anim_time(ui->screen_set_wifi_tileview_1, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_set_wifi_tileview_1
	static lv_style_t style_screen_set_wifi_tileview_1_bg;
	lv_style_init(&style_screen_set_wifi_tileview_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_tileview_1_bg
	lv_style_set_radius(&style_screen_set_wifi_tileview_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xcb, 0xd0, 0xe6));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xe5, 0xe7, 0xeb));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_tileview_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_tileview_1_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_wifi_tileview_1, LV_TILEVIEW_PART_BG, &style_screen_set_wifi_tileview_1_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_set_wifi_tileview_1
	static lv_style_t style_screen_set_wifi_tileview_1_edge_flash;
	lv_style_init(&style_screen_set_wifi_tileview_1_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_tileview_1_edge_flash
	lv_style_set_radius(&style_screen_set_wifi_tileview_1_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_tileview_1_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_tileview_1_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_wifi_tileview_1, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_set_wifi_tileview_1_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_set_wifi_tileview_1
	static lv_style_t style_screen_set_wifi_tileview_1_scrollbar;
	lv_style_init(&style_screen_set_wifi_tileview_1_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_tileview_1_scrollbar
	lv_style_set_radius(&style_screen_set_wifi_tileview_1_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_tileview_1_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_tileview_1_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_wifi_tileview_1, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_set_wifi_tileview_1_scrollbar);
	lv_obj_set_pos(ui->screen_set_wifi_tileview_1, 0, 0);
	lv_obj_set_size(ui->screen_set_wifi_tileview_1, 480, 320);

	//Write codes screen_set_wifi_tileview_1_tileview
	ui->screen_set_wifi_tileview_1_tileview = lv_obj_create(ui->screen_set_wifi_tileview_1, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_set_wifi_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_set_wifi_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_set_wifi_tileview_1_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_set_wifi_tileview_1_tileview, 480, 320);
	lv_tileview_add_element(ui->screen_set_wifi_tileview_1, ui->screen_set_wifi_tileview_1_tileview);

	//Write codes screen_set_wifi_tileview_2
	ui->screen_set_wifi_tileview_2 = lv_tileview_create(ui->screen_set_wifi, NULL);
	static lv_point_t screen_set_wifi_tileview_2_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_set_wifi_tileview_2, screen_set_wifi_tileview_2_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_set_wifi_tileview_2, true);
	lv_tileview_set_anim_time(ui->screen_set_wifi_tileview_2, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_set_wifi_tileview_2
	static lv_style_t style_screen_set_wifi_tileview_2_bg;
	lv_style_init(&style_screen_set_wifi_tileview_2_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_tileview_2_bg
	lv_style_set_radius(&style_screen_set_wifi_tileview_2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0xd0, 0xd2, 0xe6));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0x60, 0x88, 0xc7));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_tileview_2_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_tileview_2_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_wifi_tileview_2, LV_TILEVIEW_PART_BG, &style_screen_set_wifi_tileview_2_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_set_wifi_tileview_2
	static lv_style_t style_screen_set_wifi_tileview_2_edge_flash;
	lv_style_init(&style_screen_set_wifi_tileview_2_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_tileview_2_edge_flash
	lv_style_set_radius(&style_screen_set_wifi_tileview_2_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_tileview_2_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_tileview_2_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_wifi_tileview_2, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_set_wifi_tileview_2_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_set_wifi_tileview_2
	static lv_style_t style_screen_set_wifi_tileview_2_scrollbar;
	lv_style_init(&style_screen_set_wifi_tileview_2_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_tileview_2_scrollbar
	lv_style_set_radius(&style_screen_set_wifi_tileview_2_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_tileview_2_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_tileview_2_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_wifi_tileview_2, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_set_wifi_tileview_2_scrollbar);
	lv_obj_set_pos(ui->screen_set_wifi_tileview_2, 0, 0);
	lv_obj_set_size(ui->screen_set_wifi_tileview_2, 480, 33);

	//Write codes screen_set_wifi_tileview_2_tileview
	ui->screen_set_wifi_tileview_2_tileview = lv_obj_create(ui->screen_set_wifi_tileview_2, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_set_wifi_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_set_wifi_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_set_wifi_tileview_2_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_set_wifi_tileview_2_tileview, 480, 33);
	lv_tileview_add_element(ui->screen_set_wifi_tileview_2, ui->screen_set_wifi_tileview_2_tileview);

	//Write codes screen_set_wifi_bar_1
	ui->screen_set_wifi_bar_1 = lv_bar_create(ui->screen_set_wifi, NULL);

	//Write style LV_BAR_PART_BG for screen_set_wifi_bar_1
	static lv_style_t style_screen_set_wifi_bar_1_bg;
	lv_style_init(&style_screen_set_wifi_bar_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_bar_1_bg
	lv_style_set_radius(&style_screen_set_wifi_bar_1_bg, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_set_wifi_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xee, 0xf3, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0x69, 0x6c, 0x6d));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_bar_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_bar_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen_set_wifi_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_set_wifi_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_set_wifi_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_set_wifi_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_set_wifi_bar_1, LV_BAR_PART_BG, &style_screen_set_wifi_bar_1_bg);

	//Write style LV_BAR_PART_INDIC for screen_set_wifi_bar_1
	static lv_style_t style_screen_set_wifi_bar_1_indic;
	lv_style_init(&style_screen_set_wifi_bar_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_bar_1_indic
	lv_style_set_radius(&style_screen_set_wifi_bar_1_indic, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_set_wifi_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_bar_1_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_bar_1_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_wifi_bar_1, LV_BAR_PART_INDIC, &style_screen_set_wifi_bar_1_indic);
	lv_obj_set_pos(ui->screen_set_wifi_bar_1, 369, 2);
	lv_obj_set_size(ui->screen_set_wifi_bar_1, 107, 29);
	lv_bar_set_anim_time(ui->screen_set_wifi_bar_1,1000);
	lv_bar_set_value(ui->screen_set_wifi_bar_1,50,LV_ANIM_OFF);
	lv_bar_set_range(ui->screen_set_wifi_bar_1,0,100);

	//Write codes screen_set_wifi_bat_status
	ui->screen_set_wifi_bat_status = lv_label_create(ui->screen_set_wifi, NULL);
	lv_label_set_text(ui->screen_set_wifi_bat_status, "%");
	lv_label_set_long_mode(ui->screen_set_wifi_bat_status, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_set_wifi_bat_status, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_set_wifi_bat_status
	static lv_style_t style_screen_set_wifi_bat_status_main;
	lv_style_init(&style_screen_set_wifi_bat_status_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_bat_status_main
	lv_style_set_radius(&style_screen_set_wifi_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_bat_status_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_set_wifi_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_set_wifi_bat_status_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_set_wifi_bat_status_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_set_wifi_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_set_wifi_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_set_wifi_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_set_wifi_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_set_wifi_bat_status, LV_LABEL_PART_MAIN, &style_screen_set_wifi_bat_status_main);
	lv_obj_set_pos(ui->screen_set_wifi_bat_status, 381, 6);
	lv_obj_set_size(ui->screen_set_wifi_bat_status, 100, 0);

	//Write codes screen_set_wifi_charger_status
	ui->screen_set_wifi_charger_status = lv_img_create(ui->screen_set_wifi, NULL);

	//Write style LV_IMG_PART_MAIN for screen_set_wifi_charger_status
	static lv_style_t style_screen_set_wifi_charger_status_main;
	lv_style_init(&style_screen_set_wifi_charger_status_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_charger_status_main
	lv_style_set_image_recolor(&style_screen_set_wifi_charger_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_set_wifi_charger_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_set_wifi_charger_status_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_wifi_charger_status, LV_IMG_PART_MAIN, &style_screen_set_wifi_charger_status_main);
	lv_obj_set_pos(ui->screen_set_wifi_charger_status, 340, 2);
	lv_obj_set_size(ui->screen_set_wifi_charger_status, 25, 30);
	lv_obj_set_click(ui->screen_set_wifi_charger_status, true);
	lv_img_set_src(ui->screen_set_wifi_charger_status, "S:/images/electricity.bin");
	lv_img_set_pivot(ui->screen_set_wifi_charger_status, 0,0);
	lv_img_set_angle(ui->screen_set_wifi_charger_status, 0);

	//Write codes screen_set_wifi_label_tanggal
	ui->screen_set_wifi_label_tanggal = lv_label_create(ui->screen_set_wifi, NULL);
	lv_label_set_text(ui->screen_set_wifi_label_tanggal, "");
	lv_label_set_long_mode(ui->screen_set_wifi_label_tanggal, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_set_wifi_label_tanggal, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_set_wifi_label_tanggal
	static lv_style_t style_screen_set_wifi_label_tanggal_main;
	lv_style_init(&style_screen_set_wifi_label_tanggal_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_label_tanggal_main
	lv_style_set_radius(&style_screen_set_wifi_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xf7, 0xf2, 0xf2));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_label_tanggal_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_set_wifi_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_set_wifi_label_tanggal_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_set_wifi_label_tanggal_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_set_wifi_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_set_wifi_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_set_wifi_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_set_wifi_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_set_wifi_label_tanggal, LV_LABEL_PART_MAIN, &style_screen_set_wifi_label_tanggal_main);
	lv_obj_set_pos(ui->screen_set_wifi_label_tanggal, 3, 5);
	lv_obj_set_size(ui->screen_set_wifi_label_tanggal, 170, 0);

	//Write codes screen_set_wifi_label_jam
	ui->screen_set_wifi_label_jam = lv_label_create(ui->screen_set_wifi, NULL);
	lv_label_set_text(ui->screen_set_wifi_label_jam, "");
	lv_label_set_long_mode(ui->screen_set_wifi_label_jam, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_set_wifi_label_jam, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_set_wifi_label_jam
	static lv_style_t style_screen_set_wifi_label_jam_main;
	lv_style_init(&style_screen_set_wifi_label_jam_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_label_jam_main
	lv_style_set_radius(&style_screen_set_wifi_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_label_jam_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_set_wifi_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_set_wifi_label_jam_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_set_wifi_label_jam_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_set_wifi_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_set_wifi_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_set_wifi_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_set_wifi_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_set_wifi_label_jam, LV_LABEL_PART_MAIN, &style_screen_set_wifi_label_jam_main);
	lv_obj_set_pos(ui->screen_set_wifi_label_jam, 157, 4);
	lv_obj_set_size(ui->screen_set_wifi_label_jam, 130, 0);

	//Write codes screen_set_wifi_btn_scanwifi
	ui->screen_set_wifi_btn_scanwifi = lv_btn_create(ui->screen_set_wifi, NULL);

	//Write style LV_BTN_PART_MAIN for screen_set_wifi_btn_scanwifi
	static lv_style_t style_screen_set_wifi_btn_scanwifi_main;
	lv_style_init(&style_screen_set_wifi_btn_scanwifi_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_btn_scanwifi_main
	lv_style_set_radius(&style_screen_set_wifi_btn_scanwifi_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_set_wifi_btn_scanwifi_main, LV_STATE_DEFAULT, lv_color_make(0xec, 0xb1, 0xb5));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_btn_scanwifi_main, LV_STATE_DEFAULT, lv_color_make(0xd0, 0x62, 0x6d));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_btn_scanwifi_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_btn_scanwifi_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_set_wifi_btn_scanwifi_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_set_wifi_btn_scanwifi_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen_set_wifi_btn_scanwifi_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen_set_wifi_btn_scanwifi_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen_set_wifi_btn_scanwifi_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_wifi_btn_scanwifi, LV_BTN_PART_MAIN, &style_screen_set_wifi_btn_scanwifi_main);
	lv_obj_set_pos(ui->screen_set_wifi_btn_scanwifi, 378, 38);
	lv_obj_set_size(ui->screen_set_wifi_btn_scanwifi, 95, 40);
	ui->screen_set_wifi_btn_scanwifi_label = lv_label_create(ui->screen_set_wifi_btn_scanwifi, NULL);
	lv_label_set_text(ui->screen_set_wifi_btn_scanwifi_label, "Scan WiFi");
	lv_obj_set_style_local_text_color(ui->screen_set_wifi_btn_scanwifi_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen_set_wifi_btn_scanwifi_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_18);

	//Write codes screen_set_wifi_label_ssid
	ui->screen_set_wifi_label_ssid = lv_label_create(ui->screen_set_wifi, NULL);
	lv_label_set_text(ui->screen_set_wifi_label_ssid, "SSID WiFi");
	lv_label_set_long_mode(ui->screen_set_wifi_label_ssid, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_set_wifi_label_ssid, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_set_wifi_label_ssid
	static lv_style_t style_screen_set_wifi_label_ssid_main;
	lv_style_init(&style_screen_set_wifi_label_ssid_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_label_ssid_main
	lv_style_set_radius(&style_screen_set_wifi_label_ssid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_label_ssid_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_label_ssid_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_label_ssid_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_label_ssid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_set_wifi_label_ssid_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_set_wifi_label_ssid_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_set_wifi_label_ssid_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_set_wifi_label_ssid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_set_wifi_label_ssid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_set_wifi_label_ssid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_set_wifi_label_ssid_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_set_wifi_label_ssid, LV_LABEL_PART_MAIN, &style_screen_set_wifi_label_ssid_main);
	lv_obj_set_pos(ui->screen_set_wifi_label_ssid, 183, 43);
	lv_obj_set_size(ui->screen_set_wifi_label_ssid, 107, 0);

	//Write codes screen_set_wifi_list_ssid
	ui->screen_set_wifi_list_ssid = lv_list_create(ui->screen_set_wifi, NULL);
	lv_list_set_edge_flash(ui->screen_set_wifi_list_ssid, true);

	//Write style LV_LIST_PART_BG for screen_set_wifi_list_ssid
	static lv_style_t style_screen_set_wifi_list_ssid_bg;
	lv_style_init(&style_screen_set_wifi_list_ssid_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_list_ssid_bg
	lv_style_set_radius(&style_screen_set_wifi_list_ssid_bg, LV_STATE_DEFAULT, 3);
	lv_style_set_border_color(&style_screen_set_wifi_list_ssid_bg, LV_STATE_DEFAULT, lv_color_make(0x74, 0xc3, 0xbd));
	lv_style_set_border_width(&style_screen_set_wifi_list_ssid_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_set_wifi_list_ssid_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_right(&style_screen_set_wifi_list_ssid_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_top(&style_screen_set_wifi_list_ssid_bg, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->screen_set_wifi_list_ssid, LV_LIST_PART_BG, &style_screen_set_wifi_list_ssid_bg);

	//Write style LV_LIST_PART_SCROLLABLE for screen_set_wifi_list_ssid
	static lv_style_t style_screen_set_wifi_list_ssid_scrollable;
	lv_style_init(&style_screen_set_wifi_list_ssid_scrollable);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_list_ssid_scrollable
	lv_style_set_radius(&style_screen_set_wifi_list_ssid_scrollable, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_screen_set_wifi_list_ssid_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_list_ssid_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_list_ssid_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_list_ssid_scrollable, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_wifi_list_ssid, LV_LIST_PART_SCROLLABLE, &style_screen_set_wifi_list_ssid_scrollable);

	//Write style LV_BTN_PART_MAIN for screen_set_wifi_list_ssid
	static lv_style_t style_screen_set_wifi_list_ssid_main_child;
	lv_style_init(&style_screen_set_wifi_list_ssid_main_child);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_list_ssid_main_child
	lv_style_set_radius(&style_screen_set_wifi_list_ssid_main_child, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_screen_set_wifi_list_ssid_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_list_ssid_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_list_ssid_main_child, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_list_ssid_main_child, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_set_wifi_list_ssid_main_child, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_obj_set_pos(ui->screen_set_wifi_list_ssid, 90, 71);
	lv_obj_set_size(ui->screen_set_wifi_list_ssid, 280, 230);
	lv_obj_t *screen_set_wifi_list_ssid_btn;

	for(int i = 0; i < WiFin; i++){
		char ssid[32];
		strcpy(ssid, getWiFiSSID(i));
		screen_set_wifi_list_ssid_btn = lv_list_add_btn(ui->screen_set_wifi_list_ssid, LV_SYMBOL_WIFI, ssid);
		lv_obj_add_style(screen_set_wifi_list_ssid_btn, LV_BTN_PART_MAIN, &style_screen_set_wifi_list_ssid_main_child);

		lv_obj_set_event_cb(screen_set_wifi_list_ssid_btn, screen_set_wifi_list_ssidevent_handler);
	}

	//Write codes screen_set_wifi_imgbtn_back
	ui->screen_set_wifi_imgbtn_back = lv_imgbtn_create(ui->screen_set_wifi, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen_set_wifi_imgbtn_back
	static lv_style_t style_screen_set_wifi_imgbtn_back_main;
	lv_style_init(&style_screen_set_wifi_imgbtn_back_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_imgbtn_back_main
	lv_style_set_text_color(&style_screen_set_wifi_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen_set_wifi_imgbtn_back_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_set_wifi_imgbtn_back_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_set_wifi_imgbtn_back_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_wifi_imgbtn_back, LV_IMGBTN_PART_MAIN, &style_screen_set_wifi_imgbtn_back_main);
	lv_obj_set_pos(ui->screen_set_wifi_imgbtn_back, 0, 272);
	lv_obj_set_size(ui->screen_set_wifi_imgbtn_back, 57, 48);
	lv_imgbtn_set_src(ui->screen_set_wifi_imgbtn_back,LV_BTN_STATE_RELEASED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_set_wifi_imgbtn_back,LV_BTN_STATE_PRESSED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_set_wifi_imgbtn_back,LV_BTN_STATE_CHECKED_PRESSED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_set_wifi_imgbtn_back,LV_BTN_STATE_CHECKED_RELEASED,"S:/images/back.bin");
	lv_imgbtn_set_checkable(ui->screen_set_wifi_imgbtn_back, true);

	stateScreen = STATE_SCREEN_WIFI;

	events_init_screen_set_wifi(ui);
}