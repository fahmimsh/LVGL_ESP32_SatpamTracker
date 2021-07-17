/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl.h"
#include <stdio.h>
#include "generated/gui_guider.h"
#include "generated/events_init.h"
#include "custom/custom.h"

extern uint8_t stateScreen;
extern bool buzzerON;

void setup_scr_screen_Login(lv_ui *ui){

	//lv_obj_del(lv_scr_act());
	buzzerON = true;
	//Write codes screen_Login
	ui->screen_Login = lv_obj_create(NULL, NULL);

	//Write codes screen_Login_tileview_1
	ui->screen_Login_tileview_1 = lv_tileview_create(ui->screen_Login, NULL);
	static lv_point_t screen_Login_tileview_1_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_Login_tileview_1, screen_Login_tileview_1_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_Login_tileview_1, true);
	lv_tileview_set_anim_time(ui->screen_Login_tileview_1, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_Login_tileview_1
	static lv_style_t style_screen_Login_tileview_1_bg;
	lv_style_init(&style_screen_Login_tileview_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_tileview_1_bg
	lv_style_set_radius(&style_screen_Login_tileview_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Login_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Login_tileview_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_tileview_1_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Login_tileview_1, LV_TILEVIEW_PART_BG, &style_screen_Login_tileview_1_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_Login_tileview_1
	static lv_style_t style_screen_Login_tileview_1_edge_flash;
	lv_style_init(&style_screen_Login_tileview_1_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_tileview_1_edge_flash
	lv_style_set_radius(&style_screen_Login_tileview_1_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_Login_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_Login_tileview_1_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_tileview_1_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Login_tileview_1, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_Login_tileview_1_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_Login_tileview_1
	static lv_style_t style_screen_Login_tileview_1_scrollbar;
	lv_style_init(&style_screen_Login_tileview_1_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_tileview_1_scrollbar
	lv_style_set_radius(&style_screen_Login_tileview_1_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_Login_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_Login_tileview_1_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_tileview_1_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Login_tileview_1, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_Login_tileview_1_scrollbar);
	lv_obj_set_pos(ui->screen_Login_tileview_1, 0, 0);
	lv_obj_set_size(ui->screen_Login_tileview_1, 480, 320);

	//Write codes screen_Login_tileview_1_tileview
	ui->screen_Login_tileview_1_tileview = lv_obj_create(ui->screen_Login_tileview_1, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_Login_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_Login_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_Login_tileview_1_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_Login_tileview_1_tileview, 480, 320);
	lv_tileview_add_element(ui->screen_Login_tileview_1, ui->screen_Login_tileview_1_tileview);

	//Write codes screen_Login_tileview_2
	ui->screen_Login_tileview_2 = lv_tileview_create(ui->screen_Login, NULL);
	static lv_point_t screen_Login_tileview_2_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_Login_tileview_2, screen_Login_tileview_2_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_Login_tileview_2, true);
	lv_tileview_set_anim_time(ui->screen_Login_tileview_2, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_Login_tileview_2
	static lv_style_t style_screen_Login_tileview_2_bg;
	lv_style_init(&style_screen_Login_tileview_2_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_tileview_2_bg
	lv_style_set_radius(&style_screen_Login_tileview_2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0xd0, 0xd2, 0xe6));
	lv_style_set_bg_grad_color(&style_screen_Login_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0x60, 0x88, 0xc7));
	lv_style_set_bg_grad_dir(&style_screen_Login_tileview_2_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_tileview_2_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Login_tileview_2, LV_TILEVIEW_PART_BG, &style_screen_Login_tileview_2_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_Login_tileview_2
	static lv_style_t style_screen_Login_tileview_2_edge_flash;
	lv_style_init(&style_screen_Login_tileview_2_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_tileview_2_edge_flash
	lv_style_set_radius(&style_screen_Login_tileview_2_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_Login_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_Login_tileview_2_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_tileview_2_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Login_tileview_2, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_Login_tileview_2_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_Login_tileview_2
	static lv_style_t style_screen_Login_tileview_2_scrollbar;
	lv_style_init(&style_screen_Login_tileview_2_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_tileview_2_scrollbar
	lv_style_set_radius(&style_screen_Login_tileview_2_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_Login_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_Login_tileview_2_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_tileview_2_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Login_tileview_2, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_Login_tileview_2_scrollbar);
	lv_obj_set_pos(ui->screen_Login_tileview_2, 0, 0);
	lv_obj_set_size(ui->screen_Login_tileview_2, 480, 33);

	//Write codes screen_Login_tileview_2_tileview
	ui->screen_Login_tileview_2_tileview = lv_obj_create(ui->screen_Login_tileview_2, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_Login_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_Login_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_Login_tileview_2_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_Login_tileview_2_tileview, 480, 33);
	lv_tileview_add_element(ui->screen_Login_tileview_2, ui->screen_Login_tileview_2_tileview);

	//Write codes screen_Login_charger_status
	ui->screen_Login_charger_status = lv_label_create(ui->screen_Login_tileview_2_tileview, NULL);
	lv_label_set_text(ui->screen_Login_charger_status, LV_SYMBOL_CHARGE);
	lv_label_set_long_mode(ui->screen_Login_charger_status, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Login_charger_status, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_Login_charger_status
	static lv_style_t style_screen_Login_charger_status_main;
	lv_style_init(&style_screen_Login_charger_status_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_charger_status_main
	lv_style_set_radius(&style_screen_Login_charger_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_charger_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Login_charger_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Login_charger_status_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_charger_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Login_charger_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0x1c));
	lv_style_set_text_font(&style_screen_Login_charger_status_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_Login_charger_status_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_Login_charger_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Login_charger_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Login_charger_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Login_charger_status_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Login_charger_status, LV_LABEL_PART_MAIN, &style_screen_Login_charger_status_main);
	lv_obj_set_pos(ui->screen_Login_charger_status, 340, 7);
	lv_obj_set_size(ui->screen_Login_charger_status, 20, 0);
	lv_tileview_add_element(ui->screen_Login_tileview_2, ui->screen_Login_charger_status);

	//Write codes screen_Login_tileview_3
	ui->screen_Login_tileview_3 = lv_tileview_create(ui->screen_Login, NULL);
	static lv_point_t screen_Login_tileview_3_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_Login_tileview_3, screen_Login_tileview_3_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_Login_tileview_3, true);
	lv_tileview_set_anim_time(ui->screen_Login_tileview_3, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_Login_tileview_3
	static lv_style_t style_screen_Login_tileview_3_bg;
	lv_style_init(&style_screen_Login_tileview_3_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_tileview_3_bg
	lv_style_set_radius(&style_screen_Login_tileview_3_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_tileview_3_bg, LV_STATE_DEFAULT, lv_color_make(0xc4, 0xcd, 0xe9));
	lv_style_set_bg_grad_color(&style_screen_Login_tileview_3_bg, LV_STATE_DEFAULT, lv_color_make(0xd1, 0xd6, 0xf0));
	lv_style_set_bg_grad_dir(&style_screen_Login_tileview_3_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_tileview_3_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Login_tileview_3, LV_TILEVIEW_PART_BG, &style_screen_Login_tileview_3_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_Login_tileview_3
	static lv_style_t style_screen_Login_tileview_3_edge_flash;
	lv_style_init(&style_screen_Login_tileview_3_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_tileview_3_edge_flash
	lv_style_set_radius(&style_screen_Login_tileview_3_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_tileview_3_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_Login_tileview_3_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_Login_tileview_3_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_tileview_3_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Login_tileview_3, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_Login_tileview_3_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_Login_tileview_3
	static lv_style_t style_screen_Login_tileview_3_scrollbar;
	lv_style_init(&style_screen_Login_tileview_3_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_tileview_3_scrollbar
	lv_style_set_radius(&style_screen_Login_tileview_3_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_tileview_3_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_Login_tileview_3_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_Login_tileview_3_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_tileview_3_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Login_tileview_3, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_Login_tileview_3_scrollbar);
	lv_obj_set_pos(ui->screen_Login_tileview_3, 224, 69);
	lv_obj_set_size(ui->screen_Login_tileview_3, 226, 200);

	//Write codes screen_Login_tileview_3_tileview
	ui->screen_Login_tileview_3_tileview = lv_obj_create(ui->screen_Login_tileview_3, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_Login_tileview_3_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_Login_tileview_3_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_Login_tileview_3_tileview, 0*226, 0);
	lv_obj_set_size(ui->screen_Login_tileview_3_tileview, 226, 200);
	lv_tileview_add_element(ui->screen_Login_tileview_3, ui->screen_Login_tileview_3_tileview);

	//Write codes screen_Login_bar_1
	ui->screen_Login_bar_1 = lv_bar_create(ui->screen_Login, NULL);

	//Write style LV_BAR_PART_BG for screen_Login_bar_1
	static lv_style_t style_screen_Login_bar_1_bg;
	lv_style_init(&style_screen_Login_bar_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_bar_1_bg
	lv_style_set_radius(&style_screen_Login_bar_1_bg, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_Login_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xee, 0xf3, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_Login_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0x69, 0x6c, 0x6d));
	lv_style_set_bg_grad_dir(&style_screen_Login_bar_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_bar_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen_Login_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Login_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Login_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Login_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Login_bar_1, LV_BAR_PART_BG, &style_screen_Login_bar_1_bg);

	//Write style LV_BAR_PART_INDIC for screen_Login_bar_1
	static lv_style_t style_screen_Login_bar_1_indic;
	lv_style_init(&style_screen_Login_bar_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_bar_1_indic
	lv_style_set_radius(&style_screen_Login_bar_1_indic, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_Login_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_Login_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_Login_bar_1_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_bar_1_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Login_bar_1, LV_BAR_PART_INDIC, &style_screen_Login_bar_1_indic);
	lv_obj_set_pos(ui->screen_Login_bar_1, 369, 2);
	lv_obj_set_size(ui->screen_Login_bar_1, 107, 29);
	lv_bar_set_anim_time(ui->screen_Login_bar_1,1000);
	lv_bar_set_value(ui->screen_Login_bar_1,50,LV_ANIM_OFF);
	lv_bar_set_range(ui->screen_Login_bar_1,0,100);

	//Write codes screen_Login_bat_status
	ui->screen_Login_bat_status = lv_label_create(ui->screen_Login, NULL);
	lv_label_set_text(ui->screen_Login_bat_status, "0%");
	lv_label_set_long_mode(ui->screen_Login_bat_status, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Login_bat_status, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_Login_bat_status
	static lv_style_t style_screen_Login_bat_status_main;
	lv_style_init(&style_screen_Login_bat_status_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_bat_status_main
	lv_style_set_radius(&style_screen_Login_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Login_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Login_bat_status_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Login_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Login_bat_status_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_Login_bat_status_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_Login_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Login_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Login_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Login_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Login_bat_status, LV_LABEL_PART_MAIN, &style_screen_Login_bat_status_main);
	lv_obj_set_pos(ui->screen_Login_bat_status, 381, 6);
	lv_obj_set_size(ui->screen_Login_bat_status, 51, 0);

	//Write codes screen_Login_label_tanggal
	ui->screen_Login_label_tanggal = lv_label_create(ui->screen_Login, NULL);
	lv_label_set_text(ui->screen_Login_label_tanggal, "12 Juni 2021");
	lv_label_set_long_mode(ui->screen_Login_label_tanggal, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Login_label_tanggal, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_Login_label_tanggal
	static lv_style_t style_screen_Login_label_tanggal_main;
	lv_style_init(&style_screen_Login_label_tanggal_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_label_tanggal_main
	lv_style_set_radius(&style_screen_Login_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Login_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xf7, 0xf2, 0xf2));
	lv_style_set_bg_grad_dir(&style_screen_Login_label_tanggal_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Login_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Login_label_tanggal_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_Login_label_tanggal_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_Login_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Login_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Login_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Login_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Login_label_tanggal, LV_LABEL_PART_MAIN, &style_screen_Login_label_tanggal_main);
	lv_obj_set_pos(ui->screen_Login_label_tanggal, 3, 5);
	lv_obj_set_size(ui->screen_Login_label_tanggal, 170, 0);

	//Write codes screen_Login_label_jam
	ui->screen_Login_label_jam = lv_label_create(ui->screen_Login, NULL);
	lv_label_set_text(ui->screen_Login_label_jam, "18:06");
	lv_label_set_long_mode(ui->screen_Login_label_jam, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Login_label_jam, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_Login_label_jam
	static lv_style_t style_screen_Login_label_jam_main;
	lv_style_init(&style_screen_Login_label_jam_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_label_jam_main
	lv_style_set_radius(&style_screen_Login_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Login_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Login_label_jam_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Login_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Login_label_jam_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_Login_label_jam_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_Login_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Login_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Login_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Login_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Login_label_jam, LV_LABEL_PART_MAIN, &style_screen_Login_label_jam_main);
	lv_obj_set_pos(ui->screen_Login_label_jam, 156, 4);
	lv_obj_set_size(ui->screen_Login_label_jam, 130, 0);

	//Write codes screen_Login_img_1
	ui->screen_Login_img_1 = lv_img_create(ui->screen_Login, NULL);

	//Write style LV_IMG_PART_MAIN for screen_Login_img_1
	static lv_style_t style_screen_Login_img_1_main;
	lv_style_init(&style_screen_Login_img_1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_img_1_main
	lv_style_set_image_recolor(&style_screen_Login_img_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_Login_img_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_Login_img_1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Login_img_1, LV_IMG_PART_MAIN, &style_screen_Login_img_1_main);
	lv_obj_set_pos(ui->screen_Login_img_1, 9, 59);
	lv_obj_set_size(ui->screen_Login_img_1, 206, 216);
	lv_obj_set_click(ui->screen_Login_img_1, true);
	lv_img_set_src(ui->screen_Login_img_1,"S:/images/PictureLogin.bin");
	lv_img_set_pivot(ui->screen_Login_img_1, 0,0);
	lv_img_set_angle(ui->screen_Login_img_1, 0);

	//Write codes screen_Login_label_nama
	ui->screen_Login_label_nama = lv_label_create(ui->screen_Login, NULL);
	lv_label_set_text(ui->screen_Login_label_nama, "Nama Satpam:");
	lv_label_set_long_mode(ui->screen_Login_label_nama, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Login_label_nama, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_Login_label_nama
	static lv_style_t style_screen_Login_label_nama_main;
	lv_style_init(&style_screen_Login_label_nama_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_label_nama_main
	lv_style_set_radius(&style_screen_Login_label_nama_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_label_nama_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Login_label_nama_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Login_label_nama_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_label_nama_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Login_label_nama_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Login_label_nama_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_Login_label_nama_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_Login_label_nama_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Login_label_nama_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Login_label_nama_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Login_label_nama_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Login_label_nama, LV_LABEL_PART_MAIN, &style_screen_Login_label_nama_main);
	lv_obj_set_pos(ui->screen_Login_label_nama, 237, 85);
	lv_obj_set_size(ui->screen_Login_label_nama, 129, 0);

	//Write codes screen_Login_label_nama_satpam
	ui->screen_Login_label_nama_satpam = lv_label_create(ui->screen_Login, NULL);
	lv_label_set_text(ui->screen_Login_label_nama_satpam, "");
	lv_label_set_long_mode(ui->screen_Login_label_nama_satpam, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Login_label_nama_satpam, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_Login_label_nama_satpam
	static lv_style_t style_screen_Login_label_nama_satpam_main;
	lv_style_init(&style_screen_Login_label_nama_satpam_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_label_nama_satpam_main
	lv_style_set_radius(&style_screen_Login_label_nama_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_label_nama_satpam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Login_label_nama_satpam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Login_label_nama_satpam_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_label_nama_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Login_label_nama_satpam_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Login_label_nama_satpam_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_Login_label_nama_satpam_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_Login_label_nama_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Login_label_nama_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Login_label_nama_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Login_label_nama_satpam_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Login_label_nama_satpam, LV_LABEL_PART_MAIN, &style_screen_Login_label_nama_satpam_main);
	lv_obj_set_pos(ui->screen_Login_label_nama_satpam, 236, 113);
	lv_obj_set_size(ui->screen_Login_label_nama_satpam, 190, 0);

	//Write codes screen_Login_label_nip
	ui->screen_Login_label_nip = lv_label_create(ui->screen_Login, NULL);
	lv_label_set_text(ui->screen_Login_label_nip, "NIP Satpam:");
	lv_label_set_long_mode(ui->screen_Login_label_nip, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Login_label_nip, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_Login_label_nip
	static lv_style_t style_screen_Login_label_nip_main;
	lv_style_init(&style_screen_Login_label_nip_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_label_nip_main
	lv_style_set_radius(&style_screen_Login_label_nip_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_label_nip_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Login_label_nip_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Login_label_nip_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_label_nip_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Login_label_nip_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Login_label_nip_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_Login_label_nip_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_Login_label_nip_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Login_label_nip_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Login_label_nip_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Login_label_nip_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Login_label_nip, LV_LABEL_PART_MAIN, &style_screen_Login_label_nip_main);
	lv_obj_set_pos(ui->screen_Login_label_nip, 238, 173);
	lv_obj_set_size(ui->screen_Login_label_nip, 112, 0);

	//Write codes screen_Login_label_1
	ui->screen_Login_label_1 = lv_label_create(ui->screen_Login, NULL);
	lv_label_set_text(ui->screen_Login_label_1, "");
	lv_label_set_long_mode(ui->screen_Login_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Login_label_1, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_Login_label_1
	static lv_style_t style_screen_Login_label_1_main;
	lv_style_init(&style_screen_Login_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Login_label_1_main
	lv_style_set_radius(&style_screen_Login_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Login_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Login_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Login_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Login_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Login_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Login_label_1_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_Login_label_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_Login_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Login_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Login_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Login_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Login_label_1, LV_LABEL_PART_MAIN, &style_screen_Login_label_1_main);
	lv_obj_set_pos(ui->screen_Login_label_1, 236, 204);
	lv_obj_set_size(ui->screen_Login_label_1, 196, 0);

	stateScreen = STATE_SCREEN_LOGIN;
}