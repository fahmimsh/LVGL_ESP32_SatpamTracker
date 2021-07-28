/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl.h"
#include <stdio.h>
#include "generated/gui_guider.h"
#include "generated/events_init.h"
#include "custom/custom.h"
#include "Buzzer_function.h"

extern uint8_t stateScreen;
extern bool buzzerON;

void setup_scr_screen_Menu(lv_ui *ui){

	//lv_obj_del(lv_scr_act());
	buzzerON = true;
	//Write codes screen_Menu
	ui->screen_Menu = lv_obj_create(NULL, NULL);

	//Write codes screen_Menu_tileview_1
	ui->screen_Menu_tileview_1 = lv_tileview_create(ui->screen_Menu, NULL);
	static lv_point_t screen_Menu_tileview_1_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_Menu_tileview_1, screen_Menu_tileview_1_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_Menu_tileview_1, true);
	lv_tileview_set_anim_time(ui->screen_Menu_tileview_1, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_Menu_tileview_1
	static lv_style_t style_screen_Menu_tileview_1_bg;
	lv_style_init(&style_screen_Menu_tileview_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_tileview_1_bg
	lv_style_set_radius(&style_screen_Menu_tileview_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Menu_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Menu_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Menu_tileview_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_tileview_1_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Menu_tileview_1, LV_TILEVIEW_PART_BG, &style_screen_Menu_tileview_1_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_Menu_tileview_1
	static lv_style_t style_screen_Menu_tileview_1_edge_flash;
	lv_style_init(&style_screen_Menu_tileview_1_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_tileview_1_edge_flash
	lv_style_set_radius(&style_screen_Menu_tileview_1_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Menu_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_Menu_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_Menu_tileview_1_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_tileview_1_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Menu_tileview_1, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_Menu_tileview_1_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_Menu_tileview_1
	static lv_style_t style_screen_Menu_tileview_1_scrollbar;
	lv_style_init(&style_screen_Menu_tileview_1_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_tileview_1_scrollbar
	lv_style_set_radius(&style_screen_Menu_tileview_1_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Menu_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_Menu_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_Menu_tileview_1_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_tileview_1_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Menu_tileview_1, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_Menu_tileview_1_scrollbar);
	lv_obj_set_pos(ui->screen_Menu_tileview_1, 0, 0);
	lv_obj_set_size(ui->screen_Menu_tileview_1, 480, 320);

	//Write codes screen_Menu_tileview_1_tileview
	ui->screen_Menu_tileview_1_tileview = lv_obj_create(ui->screen_Menu_tileview_1, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_Menu_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_Menu_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_Menu_tileview_1_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_Menu_tileview_1_tileview, 480, 320);
	lv_tileview_add_element(ui->screen_Menu_tileview_1, ui->screen_Menu_tileview_1_tileview);

	//Write codes screen_Menu_label_menu_logout
	ui->screen_Menu_label_menu_logout = lv_label_create(ui->screen_Menu_tileview_1_tileview, NULL);
	lv_label_set_text(ui->screen_Menu_label_menu_logout, "Logout");
	lv_label_set_long_mode(ui->screen_Menu_label_menu_logout, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Menu_label_menu_logout, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_Menu_label_menu_logout
	static lv_style_t style_screen_Menu_label_menu_logout_main;
	lv_style_init(&style_screen_Menu_label_menu_logout_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_label_menu_logout_main
	lv_style_set_radius(&style_screen_Menu_label_menu_logout_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Menu_label_menu_logout_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Menu_label_menu_logout_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Menu_label_menu_logout_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_label_menu_logout_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Menu_label_menu_logout_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Menu_label_menu_logout_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_Menu_label_menu_logout_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_Menu_label_menu_logout_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Menu_label_menu_logout_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Menu_label_menu_logout_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Menu_label_menu_logout_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Menu_label_menu_logout, LV_LABEL_PART_MAIN, &style_screen_Menu_label_menu_logout_main);
	lv_obj_set_pos(ui->screen_Menu_label_menu_logout, 281, 294);
	lv_obj_set_size(ui->screen_Menu_label_menu_logout, 100, 0);
	lv_tileview_add_element(ui->screen_Menu_tileview_1, ui->screen_Menu_label_menu_logout);

	//Write codes screen_Menu_img_menu_logout
	ui->screen_Menu_img_menu_logout = lv_imgbtn_create(ui->screen_Menu_tileview_1_tileview, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen_Menu_img_menu_logout
	static lv_style_t style_screen_Menu_img_menu_logout_main;
	lv_style_init(&style_screen_Menu_img_menu_logout_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_img_menu_logout_main
	lv_style_set_text_color(&style_screen_Menu_img_menu_logout_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen_Menu_img_menu_logout_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_Menu_img_menu_logout_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_Menu_img_menu_logout_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Menu_img_menu_logout, LV_IMGBTN_PART_MAIN, &style_screen_Menu_img_menu_logout_main);
	lv_obj_set_pos(ui->screen_Menu_img_menu_logout, 264, 183);
	lv_obj_set_size(ui->screen_Menu_img_menu_logout, 142, 119);
	lv_tileview_add_element(ui->screen_Menu_tileview_1, ui->screen_Menu_img_menu_logout);
	lv_imgbtn_set_src(ui->screen_Menu_img_menu_logout,LV_BTN_STATE_RELEASED,"S:/images/Menu_logout.bin");
	lv_imgbtn_set_src(ui->screen_Menu_img_menu_logout,LV_BTN_STATE_CHECKED_RELEASED,"S:/images/Menu_logout.bin");
	lv_imgbtn_set_checkable(ui->screen_Menu_img_menu_logout, true);

	//Write codes screen_Menu_tileview_2
	ui->screen_Menu_tileview_2 = lv_tileview_create(ui->screen_Menu, NULL);
	static lv_point_t screen_Menu_tileview_2_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_Menu_tileview_2, screen_Menu_tileview_2_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_Menu_tileview_2, true);
	lv_tileview_set_anim_time(ui->screen_Menu_tileview_2, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_Menu_tileview_2
	static lv_style_t style_screen_Menu_tileview_2_bg;
	lv_style_init(&style_screen_Menu_tileview_2_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_tileview_2_bg
	lv_style_set_radius(&style_screen_Menu_tileview_2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Menu_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0xdb, 0xdd, 0xf0));
	lv_style_set_bg_grad_color(&style_screen_Menu_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0x4f, 0x7e, 0xc9));
	lv_style_set_bg_grad_dir(&style_screen_Menu_tileview_2_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_tileview_2_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Menu_tileview_2, LV_TILEVIEW_PART_BG, &style_screen_Menu_tileview_2_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_Menu_tileview_2
	static lv_style_t style_screen_Menu_tileview_2_edge_flash;
	lv_style_init(&style_screen_Menu_tileview_2_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_tileview_2_edge_flash
	lv_style_set_radius(&style_screen_Menu_tileview_2_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Menu_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_Menu_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_Menu_tileview_2_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_tileview_2_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Menu_tileview_2, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_Menu_tileview_2_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_Menu_tileview_2
	static lv_style_t style_screen_Menu_tileview_2_scrollbar;
	lv_style_init(&style_screen_Menu_tileview_2_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_tileview_2_scrollbar
	lv_style_set_radius(&style_screen_Menu_tileview_2_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Menu_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_Menu_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_Menu_tileview_2_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_tileview_2_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Menu_tileview_2, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_Menu_tileview_2_scrollbar);
	lv_obj_set_pos(ui->screen_Menu_tileview_2, 0, 0);
	lv_obj_set_size(ui->screen_Menu_tileview_2, 480, 33);

	//Write codes screen_Menu_tileview_2_tileview
	ui->screen_Menu_tileview_2_tileview = lv_obj_create(ui->screen_Menu_tileview_2, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_Menu_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_Menu_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_Menu_tileview_2_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_Menu_tileview_2_tileview, 480, 33);
	lv_tileview_add_element(ui->screen_Menu_tileview_2, ui->screen_Menu_tileview_2_tileview);

	//Write codes screen_Menu_bar_1
	ui->screen_Menu_bar_1 = lv_bar_create(ui->screen_Menu, NULL);

	//Write style LV_BAR_PART_BG for screen_Menu_bar_1
	static lv_style_t style_screen_Menu_bar_1_bg;
	lv_style_init(&style_screen_Menu_bar_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_bar_1_bg
	lv_style_set_radius(&style_screen_Menu_bar_1_bg, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_Menu_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xee, 0xf3, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_Menu_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0x69, 0x6c, 0x6d));
	lv_style_set_bg_grad_dir(&style_screen_Menu_bar_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_bar_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen_Menu_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Menu_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Menu_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Menu_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Menu_bar_1, LV_BAR_PART_BG, &style_screen_Menu_bar_1_bg);

	//Write style LV_BAR_PART_INDIC for screen_Menu_bar_1
	static lv_style_t style_screen_Menu_bar_1_indic;
	lv_style_init(&style_screen_Menu_bar_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_bar_1_indic
	lv_style_set_radius(&style_screen_Menu_bar_1_indic, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_Menu_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_Menu_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_Menu_bar_1_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_bar_1_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Menu_bar_1, LV_BAR_PART_INDIC, &style_screen_Menu_bar_1_indic);
	lv_obj_set_pos(ui->screen_Menu_bar_1, 369, 2);
	lv_obj_set_size(ui->screen_Menu_bar_1, 107, 29);
	lv_bar_set_anim_time(ui->screen_Menu_bar_1,1000);
	lv_bar_set_value(ui->screen_Menu_bar_1,50,LV_ANIM_OFF);
	lv_bar_set_range(ui->screen_Menu_bar_1,0,100);

	//Write codes screen_Menu_bat_status
	ui->screen_Menu_bat_status = lv_label_create(ui->screen_Menu, NULL);
	lv_label_set_text(ui->screen_Menu_bat_status, "%");
	lv_label_set_long_mode(ui->screen_Menu_bat_status, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Menu_bat_status, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_Menu_bat_status
	static lv_style_t style_screen_Menu_bat_status_main;
	lv_style_init(&style_screen_Menu_bat_status_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_bat_status_main
	lv_style_set_radius(&style_screen_Menu_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Menu_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Menu_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Menu_bat_status_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Menu_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Menu_bat_status_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_Menu_bat_status_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_Menu_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Menu_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Menu_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Menu_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Menu_bat_status, LV_LABEL_PART_MAIN, &style_screen_Menu_bat_status_main);
	lv_obj_set_pos(ui->screen_Menu_bat_status, 381, 6);
	lv_obj_set_size(ui->screen_Menu_bat_status, 100, 0);

	//Write codes screen_Menu_label_tanggal
	ui->screen_Menu_label_tanggal = lv_label_create(ui->screen_Menu, NULL);
	lv_label_set_text(ui->screen_Menu_label_tanggal, "");
	lv_label_set_long_mode(ui->screen_Menu_label_tanggal, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Menu_label_tanggal, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_Menu_label_tanggal
	static lv_style_t style_screen_Menu_label_tanggal_main;
	lv_style_init(&style_screen_Menu_label_tanggal_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_label_tanggal_main
	lv_style_set_radius(&style_screen_Menu_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Menu_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Menu_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xf7, 0xf2, 0xf2));
	lv_style_set_bg_grad_dir(&style_screen_Menu_label_tanggal_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Menu_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Menu_label_tanggal_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_Menu_label_tanggal_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_Menu_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Menu_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Menu_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Menu_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Menu_label_tanggal, LV_LABEL_PART_MAIN, &style_screen_Menu_label_tanggal_main);
	lv_obj_set_pos(ui->screen_Menu_label_tanggal, 3, 5);
	lv_obj_set_size(ui->screen_Menu_label_tanggal, 170, 0);

	//Write codes screen_Menu_label_jam
	ui->screen_Menu_label_jam = lv_label_create(ui->screen_Menu, NULL);
	lv_label_set_text(ui->screen_Menu_label_jam, "");
	lv_label_set_long_mode(ui->screen_Menu_label_jam, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Menu_label_jam, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_Menu_label_jam
	static lv_style_t style_screen_Menu_label_jam_main;
	lv_style_init(&style_screen_Menu_label_jam_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_label_jam_main
	lv_style_set_radius(&style_screen_Menu_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Menu_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Menu_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Menu_label_jam_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Menu_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Menu_label_jam_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_Menu_label_jam_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_Menu_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Menu_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Menu_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Menu_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Menu_label_jam, LV_LABEL_PART_MAIN, &style_screen_Menu_label_jam_main);
	lv_obj_set_pos(ui->screen_Menu_label_jam, 157, 4);
	lv_obj_set_size(ui->screen_Menu_label_jam, 130, 0);

	//Write codes screen_Menu_img_menu_patroli
	ui->screen_Menu_img_menu_patroli = lv_imgbtn_create(ui->screen_Menu, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen_Menu_img_menu_patroli
	static lv_style_t style_screen_Menu_img_menu_patroli_main;
	lv_style_init(&style_screen_Menu_img_menu_patroli_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_img_menu_patroli_main
	lv_style_set_text_color(&style_screen_Menu_img_menu_patroli_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen_Menu_img_menu_patroli_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_Menu_img_menu_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_Menu_img_menu_patroli_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Menu_img_menu_patroli, LV_IMGBTN_PART_MAIN, &style_screen_Menu_img_menu_patroli_main);
	lv_obj_set_pos(ui->screen_Menu_img_menu_patroli, 42, 34);
	lv_obj_set_size(ui->screen_Menu_img_menu_patroli, 157, 128);
	lv_imgbtn_set_src(ui->screen_Menu_img_menu_patroli,LV_BTN_STATE_RELEASED,"S:/images/Menu_Patroli.bin");
	lv_imgbtn_set_src(ui->screen_Menu_img_menu_patroli,LV_BTN_STATE_CHECKED_RELEASED,"S:/images/Menu_Patroli.bin");
	lv_imgbtn_set_checkable(ui->screen_Menu_img_menu_patroli, true);

	//Write codes screen_Menu_img_menu_setting
	ui->screen_Menu_img_menu_setting = lv_imgbtn_create(ui->screen_Menu, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen_Menu_img_menu_setting
	static lv_style_t style_screen_Menu_img_menu_setting_main;
	lv_style_init(&style_screen_Menu_img_menu_setting_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_img_menu_setting_main
	lv_style_set_text_color(&style_screen_Menu_img_menu_setting_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen_Menu_img_menu_setting_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_Menu_img_menu_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_Menu_img_menu_setting_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Menu_img_menu_setting, LV_IMGBTN_PART_MAIN, &style_screen_Menu_img_menu_setting_main);
	lv_obj_set_pos(ui->screen_Menu_img_menu_setting, 46, 187);
	lv_obj_set_size(ui->screen_Menu_img_menu_setting, 154, 113);
	lv_imgbtn_set_src(ui->screen_Menu_img_menu_setting,LV_BTN_STATE_RELEASED,"S:/images/Menu_Set.bin");
	lv_imgbtn_set_src(ui->screen_Menu_img_menu_setting,LV_BTN_STATE_CHECKED_RELEASED,"S:/images/Menu_Set.bin");
	lv_imgbtn_set_checkable(ui->screen_Menu_img_menu_setting, true);

	//Write codes screen_Menu_imgbtn_1
	ui->screen_Menu_imgbtn_1 = lv_imgbtn_create(ui->screen_Menu, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen_Menu_imgbtn_1
	static lv_style_t style_screen_Menu_imgbtn_1_main;
	lv_style_init(&style_screen_Menu_imgbtn_1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_imgbtn_1_main
	lv_style_set_text_color(&style_screen_Menu_imgbtn_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen_Menu_imgbtn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_Menu_imgbtn_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_Menu_imgbtn_1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_Menu_imgbtn_1, LV_IMGBTN_PART_MAIN, &style_screen_Menu_imgbtn_1_main);
	lv_obj_set_pos(ui->screen_Menu_imgbtn_1, 263, 42);
	lv_obj_set_size(ui->screen_Menu_imgbtn_1, 142, 119);
	lv_imgbtn_set_src(ui->screen_Menu_imgbtn_1,LV_BTN_STATE_RELEASED,"S:/images/Menu_Pinjam.bin");
	lv_imgbtn_set_src(ui->screen_Menu_imgbtn_1,LV_BTN_STATE_CHECKED_RELEASED,"S:/images/Menu_Pinjam.bin");
	lv_imgbtn_set_checkable(ui->screen_Menu_imgbtn_1, true);

	//Write codes screen_Menu_label_menu_patroli
	ui->screen_Menu_label_menu_patroli = lv_label_create(ui->screen_Menu, NULL);
	lv_label_set_text(ui->screen_Menu_label_menu_patroli, "Patroli");
	lv_label_set_long_mode(ui->screen_Menu_label_menu_patroli, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Menu_label_menu_patroli, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_Menu_label_menu_patroli
	static lv_style_t style_screen_Menu_label_menu_patroli_main;
	lv_style_init(&style_screen_Menu_label_menu_patroli_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_label_menu_patroli_main
	lv_style_set_radius(&style_screen_Menu_label_menu_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Menu_label_menu_patroli_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Menu_label_menu_patroli_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Menu_label_menu_patroli_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_label_menu_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Menu_label_menu_patroli_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Menu_label_menu_patroli_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_Menu_label_menu_patroli_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_Menu_label_menu_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Menu_label_menu_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Menu_label_menu_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Menu_label_menu_patroli_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Menu_label_menu_patroli, LV_LABEL_PART_MAIN, &style_screen_Menu_label_menu_patroli_main);
	lv_obj_set_pos(ui->screen_Menu_label_menu_patroli, 62, 157);
	lv_obj_set_size(ui->screen_Menu_label_menu_patroli, 102, 0);

	//Write codes screen_Menu_label_menu_setting
	ui->screen_Menu_label_menu_setting = lv_label_create(ui->screen_Menu, NULL);
	lv_label_set_text(ui->screen_Menu_label_menu_setting, "Setting");
	lv_label_set_long_mode(ui->screen_Menu_label_menu_setting, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Menu_label_menu_setting, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_Menu_label_menu_setting
	static lv_style_t style_screen_Menu_label_menu_setting_main;
	lv_style_init(&style_screen_Menu_label_menu_setting_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_label_menu_setting_main
	lv_style_set_radius(&style_screen_Menu_label_menu_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Menu_label_menu_setting_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Menu_label_menu_setting_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Menu_label_menu_setting_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_label_menu_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Menu_label_menu_setting_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Menu_label_menu_setting_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_Menu_label_menu_setting_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_Menu_label_menu_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Menu_label_menu_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Menu_label_menu_setting_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Menu_label_menu_setting_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Menu_label_menu_setting, LV_LABEL_PART_MAIN, &style_screen_Menu_label_menu_setting_main);
	lv_obj_set_pos(ui->screen_Menu_label_menu_setting, 69, 294);
	lv_obj_set_size(ui->screen_Menu_label_menu_setting, 101, 0);

	//Write codes screen_Menu_label_menu_listRoom
	ui->screen_Menu_label_menu_listRoom = lv_label_create(ui->screen_Menu, NULL);
	lv_label_set_text(ui->screen_Menu_label_menu_listRoom, "List Location");
	lv_label_set_long_mode(ui->screen_Menu_label_menu_listRoom, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_Menu_label_menu_listRoom, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_Menu_label_menu_listRoom
	static lv_style_t style_screen_Menu_label_menu_listRoom_main;
	lv_style_init(&style_screen_Menu_label_menu_listRoom_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_label_menu_listRoom_main
	lv_style_set_radius(&style_screen_Menu_label_menu_listRoom_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_Menu_label_menu_listRoom_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_Menu_label_menu_listRoom_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Menu_label_menu_listRoom_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_label_menu_listRoom_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Menu_label_menu_listRoom_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_Menu_label_menu_listRoom_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_Menu_label_menu_listRoom_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_Menu_label_menu_listRoom_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_Menu_label_menu_listRoom_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_Menu_label_menu_listRoom_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_Menu_label_menu_listRoom_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_Menu_label_menu_listRoom, LV_LABEL_PART_MAIN, &style_screen_Menu_label_menu_listRoom_main);
	lv_obj_set_pos(ui->screen_Menu_label_menu_listRoom, 263, 159);
	lv_obj_set_size(ui->screen_Menu_label_menu_listRoom, 146, 0);

	stateScreen = STATE_SCREEN_MENU;

	//Init events for screen
	events_init_screen_Menu(ui);
}