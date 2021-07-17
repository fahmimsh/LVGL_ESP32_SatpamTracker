/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl.h"
#include <stdio.h>
#include "generated/gui_guider.h"
#include "generated/events_init.h"
#include "custom/custom.h"
#include "lcdBrightness.h"

extern uint8_t stateScreen;
extern bool buzzerON;

void setup_scr_screen_menu_setting(lv_ui *ui){

	//lv_obj_del(lv_scr_act());
	buzzerON = true;
	//Write codes screen_menu_setting
	ui->screen_menu_setting = lv_obj_create(NULL, NULL);

	//Write codes screen_menu_setting_tileview_1
	ui->screen_menu_setting_tileview_1 = lv_tileview_create(ui->screen_menu_setting, NULL);
	static lv_point_t screen_menu_setting_tileview_1_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_menu_setting_tileview_1, screen_menu_setting_tileview_1_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_menu_setting_tileview_1, true);
	lv_tileview_set_anim_time(ui->screen_menu_setting_tileview_1, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_menu_setting_tileview_1
	static lv_style_t style_screen_menu_setting_tileview_1_bg;
	lv_style_init(&style_screen_menu_setting_tileview_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_tileview_1_bg
	lv_style_set_radius(&style_screen_menu_setting_tileview_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_setting_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xcb, 0xd0, 0xe6));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xe5, 0xe7, 0xeb));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_tileview_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_tileview_1_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_setting_tileview_1, LV_TILEVIEW_PART_BG, &style_screen_menu_setting_tileview_1_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_menu_setting_tileview_1
	static lv_style_t style_screen_menu_setting_tileview_1_edge_flash;
	lv_style_init(&style_screen_menu_setting_tileview_1_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_tileview_1_edge_flash
	lv_style_set_radius(&style_screen_menu_setting_tileview_1_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_setting_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_tileview_1_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_tileview_1_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_setting_tileview_1, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_menu_setting_tileview_1_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_menu_setting_tileview_1
	static lv_style_t style_screen_menu_setting_tileview_1_scrollbar;
	lv_style_init(&style_screen_menu_setting_tileview_1_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_tileview_1_scrollbar
	lv_style_set_radius(&style_screen_menu_setting_tileview_1_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_setting_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_tileview_1_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_tileview_1_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_setting_tileview_1, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_menu_setting_tileview_1_scrollbar);
	lv_obj_set_pos(ui->screen_menu_setting_tileview_1, 0, 0);
	lv_obj_set_size(ui->screen_menu_setting_tileview_1, 480, 320);

	//Write codes screen_menu_setting_tileview_1_tileview
	ui->screen_menu_setting_tileview_1_tileview = lv_obj_create(ui->screen_menu_setting_tileview_1, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_menu_setting_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_menu_setting_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_menu_setting_tileview_1_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_menu_setting_tileview_1_tileview, 480, 320);
	lv_tileview_add_element(ui->screen_menu_setting_tileview_1, ui->screen_menu_setting_tileview_1_tileview);

	//Write codes screen_menu_setting_btn_cek_idcard
	ui->screen_menu_setting_btn_cek_idcard = lv_btn_create(ui->screen_menu_setting_tileview_1_tileview, NULL);

	//Write style LV_BTN_PART_MAIN for screen_menu_setting_btn_cek_idcard
	static lv_style_t style_screen_menu_setting_btn_cek_idcard_main;
	lv_style_init(&style_screen_menu_setting_btn_cek_idcard_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_btn_cek_idcard_main
	lv_style_set_radius(&style_screen_menu_setting_btn_cek_idcard_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_menu_setting_btn_cek_idcard_main, LV_STATE_DEFAULT, lv_color_make(0x74, 0xc1, 0xe2));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_btn_cek_idcard_main, LV_STATE_DEFAULT, lv_color_make(0x54, 0x91, 0xc0));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_btn_cek_idcard_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_btn_cek_idcard_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_menu_setting_btn_cek_idcard_main, LV_STATE_DEFAULT, lv_color_make(0x5b, 0x95, 0xc8));
	lv_style_set_border_width(&style_screen_menu_setting_btn_cek_idcard_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen_menu_setting_btn_cek_idcard_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen_menu_setting_btn_cek_idcard_main, LV_STATE_DEFAULT, lv_color_make(0x5f, 0x83, 0x9b));
	lv_style_set_outline_opa(&style_screen_menu_setting_btn_cek_idcard_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_setting_btn_cek_idcard, LV_BTN_PART_MAIN, &style_screen_menu_setting_btn_cek_idcard_main);
	lv_obj_set_pos(ui->screen_menu_setting_btn_cek_idcard, 99, 216);
	lv_obj_set_size(ui->screen_menu_setting_btn_cek_idcard, 145, 85);
	lv_tileview_add_element(ui->screen_menu_setting_tileview_1, ui->screen_menu_setting_btn_cek_idcard);
	ui->screen_menu_setting_btn_cek_idcard_label = lv_label_create(ui->screen_menu_setting_btn_cek_idcard, NULL);
	lv_label_set_text(ui->screen_menu_setting_btn_cek_idcard_label, "CHECK ID");
	lv_obj_set_style_local_text_color(ui->screen_menu_setting_btn_cek_idcard_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen_menu_setting_btn_cek_idcard_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_24);

	//Write codes screen_menu_setting_tileview_2
	ui->screen_menu_setting_tileview_2 = lv_tileview_create(ui->screen_menu_setting, NULL);
	static lv_point_t screen_menu_setting_tileview_2_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_menu_setting_tileview_2, screen_menu_setting_tileview_2_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_menu_setting_tileview_2, true);
	lv_tileview_set_anim_time(ui->screen_menu_setting_tileview_2, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_menu_setting_tileview_2
	static lv_style_t style_screen_menu_setting_tileview_2_bg;
	lv_style_init(&style_screen_menu_setting_tileview_2_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_tileview_2_bg
	lv_style_set_radius(&style_screen_menu_setting_tileview_2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_setting_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0xd0, 0xd2, 0xe6));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0x60, 0x88, 0xc7));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_tileview_2_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_tileview_2_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_setting_tileview_2, LV_TILEVIEW_PART_BG, &style_screen_menu_setting_tileview_2_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_menu_setting_tileview_2
	static lv_style_t style_screen_menu_setting_tileview_2_edge_flash;
	lv_style_init(&style_screen_menu_setting_tileview_2_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_tileview_2_edge_flash
	lv_style_set_radius(&style_screen_menu_setting_tileview_2_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_setting_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_tileview_2_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_tileview_2_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_setting_tileview_2, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_menu_setting_tileview_2_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_menu_setting_tileview_2
	static lv_style_t style_screen_menu_setting_tileview_2_scrollbar;
	lv_style_init(&style_screen_menu_setting_tileview_2_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_tileview_2_scrollbar
	lv_style_set_radius(&style_screen_menu_setting_tileview_2_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_setting_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_tileview_2_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_tileview_2_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_setting_tileview_2, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_menu_setting_tileview_2_scrollbar);
	lv_obj_set_pos(ui->screen_menu_setting_tileview_2, 0, 0);
	lv_obj_set_size(ui->screen_menu_setting_tileview_2, 480, 33);

	//Write codes screen_menu_setting_tileview_2_tileview
	ui->screen_menu_setting_tileview_2_tileview = lv_obj_create(ui->screen_menu_setting_tileview_2, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_menu_setting_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_menu_setting_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_menu_setting_tileview_2_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_menu_setting_tileview_2_tileview, 480, 33);
	lv_tileview_add_element(ui->screen_menu_setting_tileview_2, ui->screen_menu_setting_tileview_2_tileview);

	//Write codes screen_menu_setting_bar_1
	ui->screen_menu_setting_bar_1 = lv_bar_create(ui->screen_menu_setting, NULL);

	//Write style LV_BAR_PART_BG for screen_menu_setting_bar_1
	static lv_style_t style_screen_menu_setting_bar_1_bg;
	lv_style_init(&style_screen_menu_setting_bar_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_bar_1_bg
	lv_style_set_radius(&style_screen_menu_setting_bar_1_bg, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_menu_setting_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xee, 0xf3, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0x69, 0x6c, 0x6d));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_bar_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_bar_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen_menu_setting_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_setting_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_setting_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_setting_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_setting_bar_1, LV_BAR_PART_BG, &style_screen_menu_setting_bar_1_bg);

	//Write style LV_BAR_PART_INDIC for screen_menu_setting_bar_1
	static lv_style_t style_screen_menu_setting_bar_1_indic;
	lv_style_init(&style_screen_menu_setting_bar_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_bar_1_indic
	lv_style_set_radius(&style_screen_menu_setting_bar_1_indic, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_menu_setting_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_bar_1_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_bar_1_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_setting_bar_1, LV_BAR_PART_INDIC, &style_screen_menu_setting_bar_1_indic);
	lv_obj_set_pos(ui->screen_menu_setting_bar_1, 369, 2);
	lv_obj_set_size(ui->screen_menu_setting_bar_1, 107, 29);
	lv_bar_set_anim_time(ui->screen_menu_setting_bar_1,1000);
	lv_bar_set_value(ui->screen_menu_setting_bar_1,50,LV_ANIM_OFF);
	lv_bar_set_range(ui->screen_menu_setting_bar_1,0,100);

	//Write codes screen_menu_setting_bat_status
	ui->screen_menu_setting_bat_status = lv_label_create(ui->screen_menu_setting, NULL);
	lv_label_set_text(ui->screen_menu_setting_bat_status, "0%");
	lv_label_set_long_mode(ui->screen_menu_setting_bat_status, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_setting_bat_status, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_menu_setting_bat_status
	static lv_style_t style_screen_menu_setting_bat_status_main;
	lv_style_init(&style_screen_menu_setting_bat_status_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_bat_status_main
	lv_style_set_radius(&style_screen_menu_setting_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_setting_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_bat_status_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_setting_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_menu_setting_bat_status_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_menu_setting_bat_status_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_menu_setting_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_setting_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_setting_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_setting_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_setting_bat_status, LV_LABEL_PART_MAIN, &style_screen_menu_setting_bat_status_main);
	lv_obj_set_pos(ui->screen_menu_setting_bat_status, 381, 6);
	lv_obj_set_size(ui->screen_menu_setting_bat_status, 51, 0);

	//Write codes screen_menu_setting_label_tanggal
	ui->screen_menu_setting_label_tanggal = lv_label_create(ui->screen_menu_setting, NULL);
	lv_label_set_text(ui->screen_menu_setting_label_tanggal, "12 Juni 2021");
	lv_label_set_long_mode(ui->screen_menu_setting_label_tanggal, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_setting_label_tanggal, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_menu_setting_label_tanggal
	static lv_style_t style_screen_menu_setting_label_tanggal_main;
	lv_style_init(&style_screen_menu_setting_label_tanggal_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_label_tanggal_main
	lv_style_set_radius(&style_screen_menu_setting_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_setting_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xf7, 0xf2, 0xf2));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_label_tanggal_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_setting_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_menu_setting_label_tanggal_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_menu_setting_label_tanggal_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_menu_setting_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_setting_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_setting_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_setting_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_setting_label_tanggal, LV_LABEL_PART_MAIN, &style_screen_menu_setting_label_tanggal_main);
	lv_obj_set_pos(ui->screen_menu_setting_label_tanggal, 3, 5);
	lv_obj_set_size(ui->screen_menu_setting_label_tanggal, 170, 0);

	//Write codes screen_menu_setting_label_jam
	ui->screen_menu_setting_label_jam = lv_label_create(ui->screen_menu_setting, NULL);
	lv_label_set_text(ui->screen_menu_setting_label_jam, "18:06");
	lv_label_set_long_mode(ui->screen_menu_setting_label_jam, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_setting_label_jam, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_menu_setting_label_jam
	static lv_style_t style_screen_menu_setting_label_jam_main;
	lv_style_init(&style_screen_menu_setting_label_jam_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_label_jam_main
	lv_style_set_radius(&style_screen_menu_setting_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_setting_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_label_jam_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_setting_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_menu_setting_label_jam_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_menu_setting_label_jam_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_menu_setting_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_setting_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_setting_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_setting_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_setting_label_jam, LV_LABEL_PART_MAIN, &style_screen_menu_setting_label_jam_main);
	lv_obj_set_pos(ui->screen_menu_setting_label_jam, 157, 4);
	lv_obj_set_size(ui->screen_menu_setting_label_jam, 130, 0);

	//Write codes screen_menu_setting_imgbtn_back_menu
	ui->screen_menu_setting_imgbtn_back_menu = lv_imgbtn_create(ui->screen_menu_setting, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen_menu_setting_imgbtn_back_menu
	static lv_style_t style_screen_menu_setting_imgbtn_back_menu_main;
	lv_style_init(&style_screen_menu_setting_imgbtn_back_menu_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_imgbtn_back_menu_main
	lv_style_set_text_color(&style_screen_menu_setting_imgbtn_back_menu_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen_menu_setting_imgbtn_back_menu_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_menu_setting_imgbtn_back_menu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_menu_setting_imgbtn_back_menu_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_setting_imgbtn_back_menu, LV_IMGBTN_PART_MAIN, &style_screen_menu_setting_imgbtn_back_menu_main);
	lv_obj_set_pos(ui->screen_menu_setting_imgbtn_back_menu, 5, 264);
	lv_obj_set_size(ui->screen_menu_setting_imgbtn_back_menu, 57, 48);
	lv_imgbtn_set_src(ui->screen_menu_setting_imgbtn_back_menu,LV_BTN_STATE_RELEASED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_menu_setting_imgbtn_back_menu,LV_BTN_STATE_PRESSED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_menu_setting_imgbtn_back_menu,LV_BTN_STATE_CHECKED_RELEASED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_menu_setting_imgbtn_back_menu,LV_BTN_STATE_CHECKED_PRESSED,"S:/images/back.bin");
	lv_imgbtn_set_checkable(ui->screen_menu_setting_imgbtn_back_menu, true);

	//Write codes screen_menu_setting_label_kecerahan
	ui->screen_menu_setting_label_kecerahan = lv_label_create(ui->screen_menu_setting, NULL);
	lv_label_set_text(ui->screen_menu_setting_label_kecerahan, "Kecerahan");
	lv_label_set_long_mode(ui->screen_menu_setting_label_kecerahan, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_setting_label_kecerahan, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_menu_setting_label_kecerahan
	static lv_style_t style_screen_menu_setting_label_kecerahan_main;
	lv_style_init(&style_screen_menu_setting_label_kecerahan_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_label_kecerahan_main
	lv_style_set_radius(&style_screen_menu_setting_label_kecerahan_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_setting_label_kecerahan_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_label_kecerahan_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_label_kecerahan_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_label_kecerahan_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_setting_label_kecerahan_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_menu_setting_label_kecerahan_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_menu_setting_label_kecerahan_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_menu_setting_label_kecerahan_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_setting_label_kecerahan_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_setting_label_kecerahan_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_setting_label_kecerahan_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_setting_label_kecerahan, LV_LABEL_PART_MAIN, &style_screen_menu_setting_label_kecerahan_main);
	lv_obj_set_pos(ui->screen_menu_setting_label_kecerahan, 9, 67);
	lv_obj_set_size(ui->screen_menu_setting_label_kecerahan, 132, 0);

	//Write codes screen_menu_setting_slider_kecerahan
	ui->screen_menu_setting_slider_kecerahan = lv_slider_create(ui->screen_menu_setting, NULL);

	//Write style LV_SLIDER_PART_INDIC for screen_menu_setting_slider_kecerahan
	static lv_style_t style_screen_menu_setting_slider_kecerahan_indic;
	lv_style_init(&style_screen_menu_setting_slider_kecerahan_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_slider_kecerahan_indic
	lv_style_set_radius(&style_screen_menu_setting_slider_kecerahan_indic, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_menu_setting_slider_kecerahan_indic, LV_STATE_DEFAULT, lv_color_make(0xa0, 0xdf, 0x6d));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_slider_kecerahan_indic, LV_STATE_DEFAULT, lv_color_make(0x03, 0x91, 0x6d));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_slider_kecerahan_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_slider_kecerahan_indic, LV_STATE_DEFAULT, 225);
	lv_obj_add_style(ui->screen_menu_setting_slider_kecerahan, LV_SLIDER_PART_INDIC, &style_screen_menu_setting_slider_kecerahan_indic);

	//Write style LV_SLIDER_PART_BG for screen_menu_setting_slider_kecerahan
	static lv_style_t style_screen_menu_setting_slider_kecerahan_bg;
	lv_style_init(&style_screen_menu_setting_slider_kecerahan_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_slider_kecerahan_bg
	lv_style_set_radius(&style_screen_menu_setting_slider_kecerahan_bg, LV_STATE_DEFAULT, 100);
	lv_style_set_bg_color(&style_screen_menu_setting_slider_kecerahan_bg, LV_STATE_DEFAULT, lv_color_make(0x4a, 0x53, 0x59));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_slider_kecerahan_bg, LV_STATE_DEFAULT, lv_color_make(0x89, 0x8a, 0xae));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_slider_kecerahan_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_slider_kecerahan_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen_menu_setting_slider_kecerahan_bg, LV_STATE_DEFAULT, lv_color_make(0xd8, 0xd4, 0xd9));
	lv_style_set_outline_opa(&style_screen_menu_setting_slider_kecerahan_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_left(&style_screen_menu_setting_slider_kecerahan_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_setting_slider_kecerahan_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_setting_slider_kecerahan_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_setting_slider_kecerahan_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_setting_slider_kecerahan, LV_SLIDER_PART_BG, &style_screen_menu_setting_slider_kecerahan_bg);

	//Write style LV_SLIDER_PART_KNOB for screen_menu_setting_slider_kecerahan
	static lv_style_t style_screen_menu_setting_slider_kecerahan_knob;
	lv_style_init(&style_screen_menu_setting_slider_kecerahan_knob);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_slider_kecerahan_knob
	lv_style_set_radius(&style_screen_menu_setting_slider_kecerahan_knob, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_menu_setting_slider_kecerahan_knob, LV_STATE_DEFAULT, lv_color_make(0xb1, 0x02, 0x13));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_slider_kecerahan_knob, LV_STATE_DEFAULT, lv_color_make(0xb1, 0x02, 0x71));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_slider_kecerahan_knob, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_slider_kecerahan_knob, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_setting_slider_kecerahan, LV_SLIDER_PART_KNOB, &style_screen_menu_setting_slider_kecerahan_knob);
	lv_obj_set_pos(ui->screen_menu_setting_slider_kecerahan, 150, 67);
	lv_obj_set_size(ui->screen_menu_setting_slider_kecerahan, 314, 28);
	lv_slider_set_range(ui->screen_menu_setting_slider_kecerahan,0, 100);
	lv_slider_set_value(ui->screen_menu_setting_slider_kecerahan, lcd_getBrightness(), false);

	//Write codes screen_menu_setting_label_volume_buz
	ui->screen_menu_setting_label_volume_buz = lv_label_create(ui->screen_menu_setting, NULL);
	lv_label_set_text(ui->screen_menu_setting_label_volume_buz, "Volume Buz");
	lv_label_set_long_mode(ui->screen_menu_setting_label_volume_buz, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_setting_label_volume_buz, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_menu_setting_label_volume_buz
	static lv_style_t style_screen_menu_setting_label_volume_buz_main;
	lv_style_init(&style_screen_menu_setting_label_volume_buz_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_label_volume_buz_main
	lv_style_set_radius(&style_screen_menu_setting_label_volume_buz_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_setting_label_volume_buz_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_label_volume_buz_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_label_volume_buz_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_label_volume_buz_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_setting_label_volume_buz_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_menu_setting_label_volume_buz_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_menu_setting_label_volume_buz_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_menu_setting_label_volume_buz_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_setting_label_volume_buz_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_setting_label_volume_buz_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_setting_label_volume_buz_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_setting_label_volume_buz, LV_LABEL_PART_MAIN, &style_screen_menu_setting_label_volume_buz_main);
	lv_obj_set_pos(ui->screen_menu_setting_label_volume_buz, 1, 157);
	lv_obj_set_size(ui->screen_menu_setting_label_volume_buz, 147, 0);

	//Write codes screen_menu_setting_slider_vol_buz
	ui->screen_menu_setting_slider_vol_buz = lv_slider_create(ui->screen_menu_setting, NULL);

	//Write style LV_SLIDER_PART_INDIC for screen_menu_setting_slider_vol_buz
	static lv_style_t style_screen_menu_setting_slider_vol_buz_indic;
	lv_style_init(&style_screen_menu_setting_slider_vol_buz_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_slider_vol_buz_indic
	lv_style_set_radius(&style_screen_menu_setting_slider_vol_buz_indic, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_menu_setting_slider_vol_buz_indic, LV_STATE_DEFAULT, lv_color_make(0x92, 0xe7, 0xcb));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_slider_vol_buz_indic, LV_STATE_DEFAULT, lv_color_make(0x02, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_slider_vol_buz_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_slider_vol_buz_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_setting_slider_vol_buz, LV_SLIDER_PART_INDIC, &style_screen_menu_setting_slider_vol_buz_indic);

	//Write style LV_SLIDER_PART_BG for screen_menu_setting_slider_vol_buz
	static lv_style_t style_screen_menu_setting_slider_vol_buz_bg;
	lv_style_init(&style_screen_menu_setting_slider_vol_buz_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_slider_vol_buz_bg
	lv_style_set_radius(&style_screen_menu_setting_slider_vol_buz_bg, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_menu_setting_slider_vol_buz_bg, LV_STATE_DEFAULT, lv_color_make(0x63, 0x73, 0x7e));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_slider_vol_buz_bg, LV_STATE_DEFAULT, lv_color_make(0x95, 0xa6, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_slider_vol_buz_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_slider_vol_buz_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen_menu_setting_slider_vol_buz_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen_menu_setting_slider_vol_buz_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_left(&style_screen_menu_setting_slider_vol_buz_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_setting_slider_vol_buz_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_setting_slider_vol_buz_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_setting_slider_vol_buz_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_setting_slider_vol_buz, LV_SLIDER_PART_BG, &style_screen_menu_setting_slider_vol_buz_bg);

	//Write style LV_SLIDER_PART_KNOB for screen_menu_setting_slider_vol_buz
	static lv_style_t style_screen_menu_setting_slider_vol_buz_knob;
	lv_style_init(&style_screen_menu_setting_slider_vol_buz_knob);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_slider_vol_buz_knob
	lv_style_set_radius(&style_screen_menu_setting_slider_vol_buz_knob, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_menu_setting_slider_vol_buz_knob, LV_STATE_DEFAULT, lv_color_make(0xb1, 0x02, 0x68));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_slider_vol_buz_knob, LV_STATE_DEFAULT, lv_color_make(0xb1, 0x02, 0x71));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_slider_vol_buz_knob, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_slider_vol_buz_knob, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_setting_slider_vol_buz, LV_SLIDER_PART_KNOB, &style_screen_menu_setting_slider_vol_buz_knob);
	lv_obj_set_pos(ui->screen_menu_setting_slider_vol_buz, 149, 157);
	lv_obj_set_size(ui->screen_menu_setting_slider_vol_buz, 314, 28);
	lv_slider_set_range(ui->screen_menu_setting_slider_vol_buz,0, 100);
	lv_slider_set_value(ui->screen_menu_setting_slider_vol_buz,50,false);

	//Write codes screen_menu_setting_btn_set_wifi
	ui->screen_menu_setting_btn_set_wifi = lv_btn_create(ui->screen_menu_setting, NULL);

	//Write style LV_BTN_PART_MAIN for screen_menu_setting_btn_set_wifi
	static lv_style_t style_screen_menu_setting_btn_set_wifi_main;
	lv_style_init(&style_screen_menu_setting_btn_set_wifi_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_setting_btn_set_wifi_main
	lv_style_set_radius(&style_screen_menu_setting_btn_set_wifi_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_menu_setting_btn_set_wifi_main, LV_STATE_DEFAULT, lv_color_make(0xbe, 0xd3, 0x55));
	lv_style_set_bg_grad_color(&style_screen_menu_setting_btn_set_wifi_main, LV_STATE_DEFAULT, lv_color_make(0xb6, 0xb3, 0x49));
	lv_style_set_bg_grad_dir(&style_screen_menu_setting_btn_set_wifi_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_setting_btn_set_wifi_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_menu_setting_btn_set_wifi_main, LV_STATE_DEFAULT, lv_color_make(0x7d, 0xb2, 0x01));
	lv_style_set_border_width(&style_screen_menu_setting_btn_set_wifi_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen_menu_setting_btn_set_wifi_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen_menu_setting_btn_set_wifi_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen_menu_setting_btn_set_wifi_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_setting_btn_set_wifi, LV_BTN_PART_MAIN, &style_screen_menu_setting_btn_set_wifi_main);
	lv_obj_set_pos(ui->screen_menu_setting_btn_set_wifi, 289, 216);
	lv_obj_set_size(ui->screen_menu_setting_btn_set_wifi, 145, 85);
	ui->screen_menu_setting_btn_set_wifi_label = lv_label_create(ui->screen_menu_setting_btn_set_wifi, NULL);
	lv_label_set_text(ui->screen_menu_setting_btn_set_wifi_label, "SET WIFI");
	lv_obj_set_style_local_text_color(ui->screen_menu_setting_btn_set_wifi_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen_menu_setting_btn_set_wifi_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_24);

	//Init events for screen
	events_init_screen_menu_setting(ui);

	stateScreen = STATE_SCREEN_SETTING;
}