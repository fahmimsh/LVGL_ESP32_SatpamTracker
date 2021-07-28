/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl.h"
#include <stdio.h>
#include "generated/gui_guider.h"
#include "generated/events_init.h"
#include "custom/custom.h"
#include <HTTP_function.h>

extern uint8_t stateScreen;
extern bool buzzerON;

void setup_scr_screen_menu_patroli(lv_ui *ui){

	//lv_obj_del(lv_scr_act());
	buzzerON = true;
	//Write codes screen_menu_patroli
	ui->screen_menu_patroli = lv_obj_create(NULL, NULL);

	//Write codes screen_menu_patroli_tileview_1
	ui->screen_menu_patroli_tileview_1 = lv_tileview_create(ui->screen_menu_patroli, NULL);
	static lv_point_t screen_menu_patroli_tileview_1_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_menu_patroli_tileview_1, screen_menu_patroli_tileview_1_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_menu_patroli_tileview_1, true);
	lv_tileview_set_anim_time(ui->screen_menu_patroli_tileview_1, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_menu_patroli_tileview_1
	static lv_style_t style_screen_menu_patroli_tileview_1_bg;
	lv_style_init(&style_screen_menu_patroli_tileview_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_tileview_1_bg
	lv_style_set_radius(&style_screen_menu_patroli_tileview_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_tileview_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_tileview_1_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_patroli_tileview_1, LV_TILEVIEW_PART_BG, &style_screen_menu_patroli_tileview_1_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_menu_patroli_tileview_1
	static lv_style_t style_screen_menu_patroli_tileview_1_edge_flash;
	lv_style_init(&style_screen_menu_patroli_tileview_1_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_tileview_1_edge_flash
	lv_style_set_radius(&style_screen_menu_patroli_tileview_1_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_tileview_1_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_tileview_1_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_patroli_tileview_1, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_menu_patroli_tileview_1_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_menu_patroli_tileview_1
	static lv_style_t style_screen_menu_patroli_tileview_1_scrollbar;
	lv_style_init(&style_screen_menu_patroli_tileview_1_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_tileview_1_scrollbar
	lv_style_set_radius(&style_screen_menu_patroli_tileview_1_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_tileview_1_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_tileview_1_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_patroli_tileview_1, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_menu_patroli_tileview_1_scrollbar);
	lv_obj_set_pos(ui->screen_menu_patroli_tileview_1, 0, 0);
	lv_obj_set_size(ui->screen_menu_patroli_tileview_1, 480, 320);

	//Write codes screen_menu_patroli_tileview_1_tileview
	ui->screen_menu_patroli_tileview_1_tileview = lv_obj_create(ui->screen_menu_patroli_tileview_1, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_menu_patroli_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_menu_patroli_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_menu_patroli_tileview_1_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_menu_patroli_tileview_1_tileview, 480, 320);
	lv_tileview_add_element(ui->screen_menu_patroli_tileview_1, ui->screen_menu_patroli_tileview_1_tileview);

	//Write codes screen_menu_patroli_imgbtn_1
	ui->screen_menu_patroli_imgbtn_1 = lv_imgbtn_create(ui->screen_menu_patroli_tileview_1_tileview, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen_menu_patroli_imgbtn_1
	static lv_style_t style_screen_menu_patroli_imgbtn_1_main;
	lv_style_init(&style_screen_menu_patroli_imgbtn_1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_imgbtn_1_main
	lv_style_set_text_color(&style_screen_menu_patroli_imgbtn_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen_menu_patroli_imgbtn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_menu_patroli_imgbtn_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_menu_patroli_imgbtn_1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_patroli_imgbtn_1, LV_IMGBTN_PART_MAIN, &style_screen_menu_patroli_imgbtn_1_main);
	lv_obj_set_pos(ui->screen_menu_patroli_imgbtn_1, 322, 212);
	lv_obj_set_size(ui->screen_menu_patroli_imgbtn_1, 105, 91);
	lv_tileview_add_element(ui->screen_menu_patroli_tileview_1, ui->screen_menu_patroli_imgbtn_1);
	lv_imgbtn_set_src(ui->screen_menu_patroli_imgbtn_1,LV_BTN_STATE_RELEASED,"S:/images/History.bin");
	lv_imgbtn_set_src(ui->screen_menu_patroli_imgbtn_1,LV_BTN_STATE_PRESSED,"S:/images/History_1.bin");
	lv_imgbtn_set_src(ui->screen_menu_patroli_imgbtn_1,LV_BTN_STATE_CHECKED_RELEASED,"S:/images/History.bin");
	lv_imgbtn_set_src(ui->screen_menu_patroli_imgbtn_1,LV_BTN_STATE_CHECKED_PRESSED,"S:/images/History_1.bin");
	lv_imgbtn_set_checkable(ui->screen_menu_patroli_imgbtn_1, true);

	//Write codes screen_menu_patroli_tileview_2
	ui->screen_menu_patroli_tileview_2 = lv_tileview_create(ui->screen_menu_patroli, NULL);
	static lv_point_t screen_menu_patroli_tileview_2_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_menu_patroli_tileview_2, screen_menu_patroli_tileview_2_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_menu_patroli_tileview_2, true);
	lv_tileview_set_anim_time(ui->screen_menu_patroli_tileview_2, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_menu_patroli_tileview_2
	static lv_style_t style_screen_menu_patroli_tileview_2_bg;
	lv_style_init(&style_screen_menu_patroli_tileview_2_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_tileview_2_bg
	lv_style_set_radius(&style_screen_menu_patroli_tileview_2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0xd0, 0xd2, 0xe6));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0x60, 0x88, 0xc7));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_tileview_2_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_tileview_2_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_patroli_tileview_2, LV_TILEVIEW_PART_BG, &style_screen_menu_patroli_tileview_2_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_menu_patroli_tileview_2
	static lv_style_t style_screen_menu_patroli_tileview_2_edge_flash;
	lv_style_init(&style_screen_menu_patroli_tileview_2_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_tileview_2_edge_flash
	lv_style_set_radius(&style_screen_menu_patroli_tileview_2_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_tileview_2_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_tileview_2_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_patroli_tileview_2, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_menu_patroli_tileview_2_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_menu_patroli_tileview_2
	static lv_style_t style_screen_menu_patroli_tileview_2_scrollbar;
	lv_style_init(&style_screen_menu_patroli_tileview_2_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_tileview_2_scrollbar
	lv_style_set_radius(&style_screen_menu_patroli_tileview_2_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_tileview_2_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_tileview_2_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_patroli_tileview_2, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_menu_patroli_tileview_2_scrollbar);
	lv_obj_set_pos(ui->screen_menu_patroli_tileview_2, 0, 0);
	lv_obj_set_size(ui->screen_menu_patroli_tileview_2, 480, 33);

	//Write codes screen_menu_patroli_tileview_2_tileview
	ui->screen_menu_patroli_tileview_2_tileview = lv_obj_create(ui->screen_menu_patroli_tileview_2, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_menu_patroli_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_menu_patroli_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_menu_patroli_tileview_2_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_menu_patroli_tileview_2_tileview, 480, 33);
	lv_tileview_add_element(ui->screen_menu_patroli_tileview_2, ui->screen_menu_patroli_tileview_2_tileview);

	//Write codes screen_menu_patroli_tileview_3
	ui->screen_menu_patroli_tileview_3 = lv_tileview_create(ui->screen_menu_patroli, NULL);
	static lv_point_t screen_menu_patroli_tileview_3_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_menu_patroli_tileview_3, screen_menu_patroli_tileview_3_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_menu_patroli_tileview_3, true);
	lv_tileview_set_anim_time(ui->screen_menu_patroli_tileview_3, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_menu_patroli_tileview_3
	static lv_style_t style_screen_menu_patroli_tileview_3_bg;
	lv_style_init(&style_screen_menu_patroli_tileview_3_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_tileview_3_bg
	lv_style_set_radius(&style_screen_menu_patroli_tileview_3_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_tileview_3_bg, LV_STATE_DEFAULT, lv_color_make(0x6a, 0x6a, 0x7c));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_tileview_3_bg, LV_STATE_DEFAULT, lv_color_make(0x85, 0x80, 0x9d));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_tileview_3_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_tileview_3_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_patroli_tileview_3, LV_TILEVIEW_PART_BG, &style_screen_menu_patroli_tileview_3_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_menu_patroli_tileview_3
	static lv_style_t style_screen_menu_patroli_tileview_3_edge_flash;
	lv_style_init(&style_screen_menu_patroli_tileview_3_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_tileview_3_edge_flash
	lv_style_set_radius(&style_screen_menu_patroli_tileview_3_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_tileview_3_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_tileview_3_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_tileview_3_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_tileview_3_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_patroli_tileview_3, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_menu_patroli_tileview_3_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_menu_patroli_tileview_3
	static lv_style_t style_screen_menu_patroli_tileview_3_scrollbar;
	lv_style_init(&style_screen_menu_patroli_tileview_3_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_tileview_3_scrollbar
	lv_style_set_radius(&style_screen_menu_patroli_tileview_3_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_tileview_3_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_tileview_3_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_tileview_3_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_tileview_3_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_patroli_tileview_3, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_menu_patroli_tileview_3_scrollbar);
	lv_obj_set_pos(ui->screen_menu_patroli_tileview_3, 6, 103);
	lv_obj_set_size(ui->screen_menu_patroli_tileview_3, 296, 139);

	//Write codes screen_menu_patroli_tileview_3_tileview
	ui->screen_menu_patroli_tileview_3_tileview = lv_obj_create(ui->screen_menu_patroli_tileview_3, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_menu_patroli_tileview_3_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_menu_patroli_tileview_3_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_menu_patroli_tileview_3_tileview, 0*296, 0);
	lv_obj_set_size(ui->screen_menu_patroli_tileview_3_tileview, 296, 139);
	lv_tileview_add_element(ui->screen_menu_patroli_tileview_3, ui->screen_menu_patroli_tileview_3_tileview);

	//Write codes screen_menu_patroli_bar_1
	ui->screen_menu_patroli_bar_1 = lv_bar_create(ui->screen_menu_patroli, NULL);

	//Write style LV_BAR_PART_BG for screen_menu_patroli_bar_1
	static lv_style_t style_screen_menu_patroli_bar_1_bg;
	lv_style_init(&style_screen_menu_patroli_bar_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_bar_1_bg
	lv_style_set_radius(&style_screen_menu_patroli_bar_1_bg, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_menu_patroli_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xee, 0xf3, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0x69, 0x6c, 0x6d));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_bar_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_bar_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen_menu_patroli_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_patroli_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_patroli_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_patroli_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_patroli_bar_1, LV_BAR_PART_BG, &style_screen_menu_patroli_bar_1_bg);

	//Write style LV_BAR_PART_INDIC for screen_menu_patroli_bar_1
	static lv_style_t style_screen_menu_patroli_bar_1_indic;
	lv_style_init(&style_screen_menu_patroli_bar_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_bar_1_indic
	lv_style_set_radius(&style_screen_menu_patroli_bar_1_indic, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_menu_patroli_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_bar_1_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_bar_1_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_patroli_bar_1, LV_BAR_PART_INDIC, &style_screen_menu_patroli_bar_1_indic);
	lv_obj_set_pos(ui->screen_menu_patroli_bar_1, 369, 2);
	lv_obj_set_size(ui->screen_menu_patroli_bar_1, 107, 29);
	lv_bar_set_anim_time(ui->screen_menu_patroli_bar_1,1000);
	lv_bar_set_value(ui->screen_menu_patroli_bar_1,50,LV_ANIM_OFF);
	lv_bar_set_range(ui->screen_menu_patroli_bar_1,0,100);

	//Write codes screen_menu_patroli_bat_status
	ui->screen_menu_patroli_bat_status = lv_label_create(ui->screen_menu_patroli, NULL);
	lv_label_set_text(ui->screen_menu_patroli_bat_status, "0%");
	lv_label_set_long_mode(ui->screen_menu_patroli_bat_status, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_patroli_bat_status, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_menu_patroli_bat_status
	static lv_style_t style_screen_menu_patroli_bat_status_main;
	lv_style_init(&style_screen_menu_patroli_bat_status_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_bat_status_main
	lv_style_set_radius(&style_screen_menu_patroli_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_bat_status_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_patroli_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_menu_patroli_bat_status_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_menu_patroli_bat_status_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_menu_patroli_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_patroli_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_patroli_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_patroli_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_patroli_bat_status, LV_LABEL_PART_MAIN, &style_screen_menu_patroli_bat_status_main);
	lv_obj_set_pos(ui->screen_menu_patroli_bat_status, 381, 6);
	lv_obj_set_size(ui->screen_menu_patroli_bat_status, 100, 0);

	//Write codes screen_menu_patroli_label_tanggal
	ui->screen_menu_patroli_label_tanggal = lv_label_create(ui->screen_menu_patroli, NULL);
	lv_label_set_text(ui->screen_menu_patroli_label_tanggal, "");
	lv_label_set_long_mode(ui->screen_menu_patroli_label_tanggal, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_patroli_label_tanggal, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_menu_patroli_label_tanggal
	static lv_style_t style_screen_menu_patroli_label_tanggal_main;
	lv_style_init(&style_screen_menu_patroli_label_tanggal_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_label_tanggal_main
	lv_style_set_radius(&style_screen_menu_patroli_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xf7, 0xf2, 0xf2));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_label_tanggal_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_patroli_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_menu_patroli_label_tanggal_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_menu_patroli_label_tanggal_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_menu_patroli_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_patroli_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_patroli_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_patroli_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_patroli_label_tanggal, LV_LABEL_PART_MAIN, &style_screen_menu_patroli_label_tanggal_main);
	lv_obj_set_pos(ui->screen_menu_patroli_label_tanggal, 3, 5);
	lv_obj_set_size(ui->screen_menu_patroli_label_tanggal, 170, 0);

	//Write codes screen_menu_patroli_label_jam
	ui->screen_menu_patroli_label_jam = lv_label_create(ui->screen_menu_patroli, NULL);
	lv_label_set_text(ui->screen_menu_patroli_label_jam, "");
	lv_label_set_long_mode(ui->screen_menu_patroli_label_jam, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_patroli_label_jam, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_menu_patroli_label_jam
	static lv_style_t style_screen_menu_patroli_label_jam_main;
	lv_style_init(&style_screen_menu_patroli_label_jam_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_label_jam_main
	lv_style_set_radius(&style_screen_menu_patroli_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_label_jam_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_patroli_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_menu_patroli_label_jam_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_menu_patroli_label_jam_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_menu_patroli_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_patroli_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_patroli_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_patroli_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_patroli_label_jam, LV_LABEL_PART_MAIN, &style_screen_menu_patroli_label_jam_main);
	lv_obj_set_pos(ui->screen_menu_patroli_label_jam, 157, 4);
	lv_obj_set_size(ui->screen_menu_patroli_label_jam, 130, 0);

	//Write codes screen_menu_patroli_label_nama
	ui->screen_menu_patroli_label_nama = lv_label_create(ui->screen_menu_patroli, NULL);
	lv_label_set_text(ui->screen_menu_patroli_label_nama, "Nama Satpam:");
	lv_label_set_long_mode(ui->screen_menu_patroli_label_nama, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_patroli_label_nama, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_menu_patroli_label_nama
	static lv_style_t style_screen_menu_patroli_label_nama_main;
	lv_style_init(&style_screen_menu_patroli_label_nama_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_label_nama_main
	lv_style_set_radius(&style_screen_menu_patroli_label_nama_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_label_nama_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_label_nama_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_label_nama_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_label_nama_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_patroli_label_nama_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_menu_patroli_label_nama_main, LV_STATE_DEFAULT, &lv_font_montserrat_14);
	lv_style_set_text_letter_space(&style_screen_menu_patroli_label_nama_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_menu_patroli_label_nama_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_patroli_label_nama_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_patroli_label_nama_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_patroli_label_nama_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_patroli_label_nama, LV_LABEL_PART_MAIN, &style_screen_menu_patroli_label_nama_main);
	lv_obj_set_pos(ui->screen_menu_patroli_label_nama, 9, 42);
	lv_obj_set_size(ui->screen_menu_patroli_label_nama, 129, 0);

	//Write codes screen_menu_patroli_label_nama_satpam
	ui->screen_menu_patroli_label_nama_satpam = lv_label_create(ui->screen_menu_patroli, NULL);
	lv_label_set_text(ui->screen_menu_patroli_label_nama_satpam, satpam.nama_satpam);
	lv_label_set_long_mode(ui->screen_menu_patroli_label_nama_satpam, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_patroli_label_nama_satpam, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_menu_patroli_label_nama_satpam
	static lv_style_t style_screen_menu_patroli_label_nama_satpam_main;
	lv_style_init(&style_screen_menu_patroli_label_nama_satpam_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_label_nama_satpam_main
	lv_style_set_radius(&style_screen_menu_patroli_label_nama_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_label_nama_satpam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_label_nama_satpam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_label_nama_satpam_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_label_nama_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_patroli_label_nama_satpam_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_menu_patroli_label_nama_satpam_main, LV_STATE_DEFAULT, &lv_font_montserrat_14);
	lv_style_set_text_letter_space(&style_screen_menu_patroli_label_nama_satpam_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_menu_patroli_label_nama_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_patroli_label_nama_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_patroli_label_nama_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_patroli_label_nama_satpam_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_patroli_label_nama_satpam, LV_LABEL_PART_MAIN, &style_screen_menu_patroli_label_nama_satpam_main);
	lv_obj_set_pos(ui->screen_menu_patroli_label_nama_satpam, 139, 43);
	lv_obj_set_size(ui->screen_menu_patroli_label_nama_satpam, 190, 0);

	//Write codes screen_menu_patroli_label_nip
	ui->screen_menu_patroli_label_nip = lv_label_create(ui->screen_menu_patroli, NULL);
	lv_label_set_text(ui->screen_menu_patroli_label_nip, "NIP Satpam:");
	lv_label_set_long_mode(ui->screen_menu_patroli_label_nip, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_patroli_label_nip, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_menu_patroli_label_nip
	static lv_style_t style_screen_menu_patroli_label_nip_main;
	lv_style_init(&style_screen_menu_patroli_label_nip_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_label_nip_main
	lv_style_set_radius(&style_screen_menu_patroli_label_nip_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_label_nip_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_label_nip_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_label_nip_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_label_nip_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_patroli_label_nip_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_menu_patroli_label_nip_main, LV_STATE_DEFAULT, &lv_font_montserrat_14);
	lv_style_set_text_letter_space(&style_screen_menu_patroli_label_nip_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_menu_patroli_label_nip_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_patroli_label_nip_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_patroli_label_nip_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_patroli_label_nip_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_patroli_label_nip, LV_LABEL_PART_MAIN, &style_screen_menu_patroli_label_nip_main);
	lv_obj_set_pos(ui->screen_menu_patroli_label_nip, 20, 72);
	lv_obj_set_size(ui->screen_menu_patroli_label_nip, 112, 0);

	char tmp[100];
	sprintf(tmp, "%zu", satpam.nip_satpam);

	//Write codes screen_menu_patroli_label_nip_satpam
	ui->screen_menu_patroli_label_nip_satpam = lv_label_create(ui->screen_menu_patroli, NULL);
	lv_label_set_text(ui->screen_menu_patroli_label_nip_satpam, tmp);
	lv_label_set_long_mode(ui->screen_menu_patroli_label_nip_satpam, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_patroli_label_nip_satpam, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_menu_patroli_label_nip_satpam
	static lv_style_t style_screen_menu_patroli_label_nip_satpam_main;
	lv_style_init(&style_screen_menu_patroli_label_nip_satpam_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_label_nip_satpam_main
	lv_style_set_radius(&style_screen_menu_patroli_label_nip_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_label_nip_satpam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_label_nip_satpam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_label_nip_satpam_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_label_nip_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_patroli_label_nip_satpam_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_menu_patroli_label_nip_satpam_main, LV_STATE_DEFAULT, &lv_font_montserrat_14);
	lv_style_set_text_letter_space(&style_screen_menu_patroli_label_nip_satpam_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_menu_patroli_label_nip_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_patroli_label_nip_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_patroli_label_nip_satpam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_patroli_label_nip_satpam_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_patroli_label_nip_satpam, LV_LABEL_PART_MAIN, &style_screen_menu_patroli_label_nip_satpam_main);
	lv_obj_set_pos(ui->screen_menu_patroli_label_nip_satpam, 139, 72);
	lv_obj_set_size(ui->screen_menu_patroli_label_nip_satpam, 196, 0);

	//Write codes screen_menu_patroli_label_lokasi
	ui->screen_menu_patroli_label_lokasi = lv_label_create(ui->screen_menu_patroli, NULL);
	lv_label_set_text(ui->screen_menu_patroli_label_lokasi, "Lokasi = ");
	lv_label_set_long_mode(ui->screen_menu_patroli_label_lokasi, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_patroli_label_lokasi, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_menu_patroli_label_lokasi
	static lv_style_t style_screen_menu_patroli_label_lokasi_main;
	lv_style_init(&style_screen_menu_patroli_label_lokasi_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_label_lokasi_main
	lv_style_set_radius(&style_screen_menu_patroli_label_lokasi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_label_lokasi_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_label_lokasi_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_label_lokasi_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_label_lokasi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_patroli_label_lokasi_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_menu_patroli_label_lokasi_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_menu_patroli_label_lokasi_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_menu_patroli_label_lokasi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_patroli_label_lokasi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_patroli_label_lokasi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_patroli_label_lokasi_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_patroli_label_lokasi, LV_LABEL_PART_MAIN, &style_screen_menu_patroli_label_lokasi_main);
	lv_obj_set_pos(ui->screen_menu_patroli_label_lokasi, 4, 112);
	lv_obj_set_size(ui->screen_menu_patroli_label_lokasi, 121, 0);

	//Write codes screen_menu_patroli_label_lokasi_patroli
	const char* lokasi = httpGETLokasi();
	
	ui->screen_menu_patroli_label_lokasi_patroli = lv_label_create(ui->screen_menu_patroli, NULL);
	lv_label_set_text(ui->screen_menu_patroli_label_lokasi_patroli, lokasi);
	lv_label_set_long_mode(ui->screen_menu_patroli_label_lokasi_patroli, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_patroli_label_lokasi_patroli, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_menu_patroli_label_lokasi_patroli
	static lv_style_t style_screen_menu_patroli_label_lokasi_patroli_main;
	lv_style_init(&style_screen_menu_patroli_label_lokasi_patroli_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_label_lokasi_patroli_main
	lv_style_set_radius(&style_screen_menu_patroli_label_lokasi_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_label_lokasi_patroli_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_label_lokasi_patroli_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_label_lokasi_patroli_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_label_lokasi_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_patroli_label_lokasi_patroli_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_menu_patroli_label_lokasi_patroli_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_menu_patroli_label_lokasi_patroli_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_menu_patroli_label_lokasi_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_patroli_label_lokasi_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_patroli_label_lokasi_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_patroli_label_lokasi_patroli_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_patroli_label_lokasi_patroli, LV_LABEL_PART_MAIN, &style_screen_menu_patroli_label_lokasi_patroli_main);
	lv_obj_set_pos(ui->screen_menu_patroli_label_lokasi_patroli, 125, 112);
	lv_obj_set_size(ui->screen_menu_patroli_label_lokasi_patroli, 100, 0);

	//Write codes screen_menu_patroli_label_ket_Scan_id_card
	ui->screen_menu_patroli_label_ket_Scan_id_card = lv_label_create(ui->screen_menu_patroli, NULL);
	lv_label_set_text(ui->screen_menu_patroli_label_ket_Scan_id_card, "Scan ID untuk Melanjutkan Patroli");
	lv_label_set_long_mode(ui->screen_menu_patroli_label_ket_Scan_id_card, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_patroli_label_ket_Scan_id_card, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_menu_patroli_label_ket_Scan_id_card
	static lv_style_t style_screen_menu_patroli_label_ket_Scan_id_card_main;
	lv_style_init(&style_screen_menu_patroli_label_ket_Scan_id_card_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_label_ket_Scan_id_card_main
	lv_style_set_radius(&style_screen_menu_patroli_label_ket_Scan_id_card_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_label_ket_Scan_id_card_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_label_ket_Scan_id_card_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_label_ket_Scan_id_card_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_label_ket_Scan_id_card_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_patroli_label_ket_Scan_id_card_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_menu_patroli_label_ket_Scan_id_card_main, LV_STATE_DEFAULT, &lv_font_montserrat_14);
	lv_style_set_text_letter_space(&style_screen_menu_patroli_label_ket_Scan_id_card_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_menu_patroli_label_ket_Scan_id_card_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_patroli_label_ket_Scan_id_card_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_patroli_label_ket_Scan_id_card_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_patroli_label_ket_Scan_id_card_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_patroli_label_ket_Scan_id_card, LV_LABEL_PART_MAIN, &style_screen_menu_patroli_label_ket_Scan_id_card_main);
	lv_obj_set_pos(ui->screen_menu_patroli_label_ket_Scan_id_card, 293, 43);
	lv_obj_set_size(ui->screen_menu_patroli_label_ket_Scan_id_card, 164, 0);

	//Write codes screen_menu_patroli_led_Tap_ID_card
	ui->screen_menu_patroli_led_Tap_ID_card = lv_led_create(ui->screen_menu_patroli, NULL);

	//Write style LV_LED_PART_MAIN for screen_menu_patroli_led_Tap_ID_card
	static lv_style_t style_screen_menu_patroli_led_Tap_ID_card_main;
	lv_style_init(&style_screen_menu_patroli_led_Tap_ID_card_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_led_Tap_ID_card_main
	lv_style_set_radius(&style_screen_menu_patroli_led_Tap_ID_card_main, LV_STATE_DEFAULT, 20);
	lv_style_set_bg_color(&style_screen_menu_patroli_led_Tap_ID_card_main, LV_STATE_DEFAULT, lv_color_make(0xb3, 0x00, 0x1b));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_led_Tap_ID_card_main, LV_STATE_DEFAULT, lv_color_make(0x06, 0xea, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_led_Tap_ID_card_main, LV_STATE_DEFAULT, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_menu_patroli_led_Tap_ID_card_main, LV_STATE_DEFAULT, 255);
	lv_style_set_shadow_color(&style_screen_menu_patroli_led_Tap_ID_card_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_shadow_width(&style_screen_menu_patroli_led_Tap_ID_card_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_screen_menu_patroli_led_Tap_ID_card_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_screen_menu_patroli_led_Tap_ID_card_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_screen_menu_patroli_led_Tap_ID_card_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_patroli_led_Tap_ID_card, LV_LED_PART_MAIN, &style_screen_menu_patroli_led_Tap_ID_card_main);
	lv_obj_set_pos(ui->screen_menu_patroli_led_Tap_ID_card, 324, 106);
	lv_obj_set_size(ui->screen_menu_patroli_led_Tap_ID_card, 104, 84);
	lv_led_set_bright(ui->screen_menu_patroli_led_Tap_ID_card, 200);

	//Write codes screen_menu_patroli_label_status_patroli
	ui->screen_menu_patroli_label_status_patroli = lv_label_create(ui->screen_menu_patroli, NULL);
	lv_label_set_text(ui->screen_menu_patroli_label_status_patroli, "Status = ");
	lv_label_set_long_mode(ui->screen_menu_patroli_label_status_patroli, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_menu_patroli_label_status_patroli, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_menu_patroli_label_status_patroli
	static lv_style_t style_screen_menu_patroli_label_status_patroli_main;
	lv_style_init(&style_screen_menu_patroli_label_status_patroli_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_label_status_patroli_main
	lv_style_set_radius(&style_screen_menu_patroli_label_status_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_menu_patroli_label_status_patroli_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_label_status_patroli_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_label_status_patroli_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_label_status_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_menu_patroli_label_status_patroli_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_menu_patroli_label_status_patroli_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_menu_patroli_label_status_patroli_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_menu_patroli_label_status_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_menu_patroli_label_status_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_menu_patroli_label_status_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_menu_patroli_label_status_patroli_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_menu_patroli_label_status_patroli, LV_LABEL_PART_MAIN, &style_screen_menu_patroli_label_status_patroli_main);
	lv_obj_set_pos(ui->screen_menu_patroli_label_status_patroli, 14, 149);
	lv_obj_set_size(ui->screen_menu_patroli_label_status_patroli, 100, 0);

	//Write codes screen_menu_patroli_ddlist_status
	ui->screen_menu_patroli_ddlist_status = lv_dropdown_create(ui->screen_menu_patroli, NULL);
	lv_dropdown_set_options(ui->screen_menu_patroli_ddlist_status, "Tidak Terdaftar\nTidak ada Masalah\nAda Masalah");
	lv_dropdown_set_max_height(ui->screen_menu_patroli_ddlist_status, 96);

	//Write style LV_DROPDOWN_PART_MAIN for screen_menu_patroli_ddlist_status
	static lv_style_t style_screen_menu_patroli_ddlist_status_main;
	lv_style_init(&style_screen_menu_patroli_ddlist_status_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_ddlist_status_main
	lv_style_set_radius(&style_screen_menu_patroli_ddlist_status_main, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_screen_menu_patroli_ddlist_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_ddlist_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_ddlist_status_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_ddlist_status_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_menu_patroli_ddlist_status_main, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_screen_menu_patroli_ddlist_status_main, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_screen_menu_patroli_ddlist_status_main, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_menu_patroli_ddlist_status_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_line_space(&style_screen_menu_patroli_ddlist_status_main, LV_STATE_DEFAULT, 20);
	lv_obj_add_style(ui->screen_menu_patroli_ddlist_status, LV_DROPDOWN_PART_MAIN, &style_screen_menu_patroli_ddlist_status_main);

	//Write style LV_DROPDOWN_PART_SELECTED for screen_menu_patroli_ddlist_status
	static lv_style_t style_screen_menu_patroli_ddlist_status_selected;
	lv_style_init(&style_screen_menu_patroli_ddlist_status_selected);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_ddlist_status_selected
	lv_style_set_radius(&style_screen_menu_patroli_ddlist_status_selected, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_screen_menu_patroli_ddlist_status_selected, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_ddlist_status_selected, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_ddlist_status_selected, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_ddlist_status_selected, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_menu_patroli_ddlist_status_selected, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_screen_menu_patroli_ddlist_status_selected, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_screen_menu_patroli_ddlist_status_selected, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_menu_patroli_ddlist_status_selected, LV_STATE_DEFAULT, &lv_font_montserrat_14);
	lv_obj_add_style(ui->screen_menu_patroli_ddlist_status, LV_DROPDOWN_PART_SELECTED, &style_screen_menu_patroli_ddlist_status_selected);

	//Write style LV_DROPDOWN_PART_LIST for screen_menu_patroli_ddlist_status
	static lv_style_t style_screen_menu_patroli_ddlist_status_list;
	lv_style_init(&style_screen_menu_patroli_ddlist_status_list);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_ddlist_status_list
	lv_style_set_radius(&style_screen_menu_patroli_ddlist_status_list, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_screen_menu_patroli_ddlist_status_list, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_ddlist_status_list, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_ddlist_status_list, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_ddlist_status_list, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_menu_patroli_ddlist_status_list, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_screen_menu_patroli_ddlist_status_list, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_screen_menu_patroli_ddlist_status_list, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_screen_menu_patroli_ddlist_status_list, LV_STATE_DEFAULT, &lv_font_montserrat_14);
	lv_obj_add_style(ui->screen_menu_patroli_ddlist_status, LV_DROPDOWN_PART_LIST, &style_screen_menu_patroli_ddlist_status_list);
	lv_obj_set_pos(ui->screen_menu_patroli_ddlist_status, 120, 152);
	lv_obj_set_width(ui->screen_menu_patroli_ddlist_status, 168);

	//Write codes screen_menu_patroli_imgbtn_back_menu
	ui->screen_menu_patroli_imgbtn_back_menu = lv_imgbtn_create(ui->screen_menu_patroli, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen_menu_patroli_imgbtn_back_menu
	static lv_style_t style_screen_menu_patroli_imgbtn_back_menu_main;
	lv_style_init(&style_screen_menu_patroli_imgbtn_back_menu_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_imgbtn_back_menu_main
	lv_style_set_text_color(&style_screen_menu_patroli_imgbtn_back_menu_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen_menu_patroli_imgbtn_back_menu_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_menu_patroli_imgbtn_back_menu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_menu_patroli_imgbtn_back_menu_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_menu_patroli_imgbtn_back_menu, LV_IMGBTN_PART_MAIN, &style_screen_menu_patroli_imgbtn_back_menu_main);
	lv_obj_set_pos(ui->screen_menu_patroli_imgbtn_back_menu, 17, 256);
	lv_obj_set_size(ui->screen_menu_patroli_imgbtn_back_menu, 84, 59);
	lv_imgbtn_set_src(ui->screen_menu_patroli_imgbtn_back_menu,LV_BTN_STATE_RELEASED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_menu_patroli_imgbtn_back_menu,LV_BTN_STATE_PRESSED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_menu_patroli_imgbtn_back_menu,LV_BTN_STATE_CHECKED_RELEASED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_menu_patroli_imgbtn_back_menu,LV_BTN_STATE_CHECKED_PRESSED,"S:/images/back.bin");
	lv_imgbtn_set_checkable(ui->screen_menu_patroli_imgbtn_back_menu, true);

	//Write codes screen_menu_patroli_arc_1
	ui->screen_menu_patroli_arc_1 = lv_arc_create(ui->screen_menu_patroli, NULL);

	//Write style LV_ARC_PART_BG for screen_menu_patroli_arc_1
	static lv_style_t style_screen_menu_patroli_arc_1_bg;
	lv_style_init(&style_screen_menu_patroli_arc_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_arc_1_bg
	lv_style_set_bg_color(&style_screen_menu_patroli_arc_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_menu_patroli_arc_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_menu_patroli_arc_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_menu_patroli_arc_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_width(&style_screen_menu_patroli_arc_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_line_color(&style_screen_menu_patroli_arc_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_line_width(&style_screen_menu_patroli_arc_1_bg, LV_STATE_DEFAULT, 16);
	lv_obj_add_style(ui->screen_menu_patroli_arc_1, LV_ARC_PART_BG, &style_screen_menu_patroli_arc_1_bg);

	//Write style LV_ARC_PART_INDIC for screen_menu_patroli_arc_1
	static lv_style_t style_screen_menu_patroli_arc_1_indic;
	lv_style_init(&style_screen_menu_patroli_arc_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_arc_1_indic
	lv_style_set_line_color(&style_screen_menu_patroli_arc_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_line_width(&style_screen_menu_patroli_arc_1_indic, LV_STATE_DEFAULT, 16);
	lv_obj_add_style(ui->screen_menu_patroli_arc_1, LV_ARC_PART_INDIC, &style_screen_menu_patroli_arc_1_indic);
	lv_obj_set_pos(ui->screen_menu_patroli_arc_1, 324, 100);
	lv_obj_set_size(ui->screen_menu_patroli_arc_1, 100, 100);
	lv_arc_set_angles(ui->screen_menu_patroli_arc_1, 90, 180);
	lv_arc_set_bg_angles(ui->screen_menu_patroli_arc_1, 0, 360);
	lv_arc_set_rotation(ui->screen_menu_patroli_arc_1, 0);
	lv_obj_set_style_local_pad_top(ui->screen_menu_patroli_arc_1, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_bottom(ui->screen_menu_patroli_arc_1, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_left(ui->screen_menu_patroli_arc_1, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_pad_right(ui->screen_menu_patroli_arc_1, LV_ARC_PART_BG, LV_STATE_DEFAULT, 20);
	lv_obj_set_style_local_line_rounded(ui->screen_menu_patroli_arc_1, LV_ARC_PART_INDIC, LV_STATE_DEFAULT, 0);

	//Write codes screen_menu_patroli_img_indikasi_Patroli_Selesai
	// ui->screen_menu_patroli_img_indikasi_Patroli_Selesai = lv_img_create(ui->screen_menu_patroli, NULL);

	// //Write style LV_IMG_PART_MAIN for screen_menu_patroli_img_indikasi_Patroli_Selesai
	// static lv_style_t style_screen_menu_patroli_img_indikasi_Patroli_Selesai_main;
	// lv_style_init(&style_screen_menu_patroli_img_indikasi_Patroli_Selesai_main);

	// //Write style state: LV_STATE_DEFAULT for style_screen_menu_patroli_img_indikasi_Patroli_Selesai_main
	// lv_style_set_image_recolor(&style_screen_menu_patroli_img_indikasi_Patroli_Selesai_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	// lv_style_set_image_recolor_opa(&style_screen_menu_patroli_img_indikasi_Patroli_Selesai_main, LV_STATE_DEFAULT, 0);
	// lv_style_set_image_opa(&style_screen_menu_patroli_img_indikasi_Patroli_Selesai_main, LV_STATE_DEFAULT, 255);
	// lv_obj_add_style(ui->screen_menu_patroli_img_indikasi_Patroli_Selesai, LV_IMG_PART_MAIN, &style_screen_menu_patroli_img_indikasi_Patroli_Selesai_main);
	// lv_obj_set_pos(ui->screen_menu_patroli_img_indikasi_Patroli_Selesai, 101, 52);
	// lv_obj_set_size(ui->screen_menu_patroli_img_indikasi_Patroli_Selesai, 250, 210);
	// lv_obj_set_click(ui->screen_menu_patroli_img_indikasi_Patroli_Selesai, true);
	// lv_img_set_src(ui->screen_menu_patroli_img_indikasi_Patroli_Selesai,"S:/images/SelesaiPatroli.bin");
	// lv_img_set_pivot(ui->screen_menu_patroli_img_indikasi_Patroli_Selesai, 0,0);
	// lv_img_set_angle(ui->screen_menu_patroli_img_indikasi_Patroli_Selesai, 0);

	stateScreen = STATE_SCREEN_PATROLI;

	//Init events for screen
	events_init_screen_menu_patroli(ui);
}