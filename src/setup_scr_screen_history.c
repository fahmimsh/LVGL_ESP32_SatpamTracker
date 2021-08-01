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

void setup_scr_screen_history(lv_ui *ui){

	//lv_obj_del(lv_scr_act());
    buzzerON = true;

	//Write codes screen_history
	ui->screen_history = lv_obj_create(NULL, NULL);

	//Write codes screen_history_tileview_1
	ui->screen_history_tileview_1 = lv_tileview_create(ui->screen_history, NULL);
	static lv_point_t screen_history_tileview_1_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_history_tileview_1, screen_history_tileview_1_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_history_tileview_1, true);
	lv_tileview_set_anim_time(ui->screen_history_tileview_1, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_history_tileview_1
	static lv_style_t style_screen_history_tileview_1_bg;
	lv_style_init(&style_screen_history_tileview_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_tileview_1_bg
	lv_style_set_radius(&style_screen_history_tileview_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_history_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xe7, 0xda, 0xda));
	lv_style_set_bg_grad_color(&style_screen_history_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xd3, 0x9c, 0x9c));
	lv_style_set_bg_grad_dir(&style_screen_history_tileview_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_history_tileview_1_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_history_tileview_1, LV_TILEVIEW_PART_BG, &style_screen_history_tileview_1_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_history_tileview_1
	static lv_style_t style_screen_history_tileview_1_edge_flash;
	lv_style_init(&style_screen_history_tileview_1_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_tileview_1_edge_flash
	lv_style_set_radius(&style_screen_history_tileview_1_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_history_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_history_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_history_tileview_1_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_history_tileview_1_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_history_tileview_1, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_history_tileview_1_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_history_tileview_1
	static lv_style_t style_screen_history_tileview_1_scrollbar;
	lv_style_init(&style_screen_history_tileview_1_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_tileview_1_scrollbar
	lv_style_set_radius(&style_screen_history_tileview_1_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_history_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_history_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_history_tileview_1_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_history_tileview_1_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_history_tileview_1, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_history_tileview_1_scrollbar);
	lv_obj_set_pos(ui->screen_history_tileview_1, 0, 0);
	lv_obj_set_size(ui->screen_history_tileview_1, 480, 320);

	//Write codes screen_history_tileview_1_tileview
	ui->screen_history_tileview_1_tileview = lv_obj_create(ui->screen_history_tileview_1, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_history_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_history_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_history_tileview_1_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_history_tileview_1_tileview, 480, 320);
	lv_tileview_add_element(ui->screen_history_tileview_1, ui->screen_history_tileview_1_tileview);

	//Write codes screen_history_tileview_2
	ui->screen_history_tileview_2 = lv_tileview_create(ui->screen_history, NULL);
	static lv_point_t screen_history_tileview_2_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_history_tileview_2, screen_history_tileview_2_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_history_tileview_2, true);
	lv_tileview_set_anim_time(ui->screen_history_tileview_2, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_history_tileview_2
	static lv_style_t style_screen_history_tileview_2_bg;
	lv_style_init(&style_screen_history_tileview_2_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_tileview_2_bg
	lv_style_set_radius(&style_screen_history_tileview_2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_history_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0xd0, 0xd2, 0xe6));
	lv_style_set_bg_grad_color(&style_screen_history_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0x60, 0x88, 0xc7));
	lv_style_set_bg_grad_dir(&style_screen_history_tileview_2_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_history_tileview_2_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_history_tileview_2, LV_TILEVIEW_PART_BG, &style_screen_history_tileview_2_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_history_tileview_2
	static lv_style_t style_screen_history_tileview_2_edge_flash;
	lv_style_init(&style_screen_history_tileview_2_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_tileview_2_edge_flash
	lv_style_set_radius(&style_screen_history_tileview_2_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_history_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_history_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_history_tileview_2_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_history_tileview_2_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_history_tileview_2, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_history_tileview_2_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_history_tileview_2
	static lv_style_t style_screen_history_tileview_2_scrollbar;
	lv_style_init(&style_screen_history_tileview_2_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_tileview_2_scrollbar
	lv_style_set_radius(&style_screen_history_tileview_2_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_history_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_history_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_history_tileview_2_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_history_tileview_2_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_history_tileview_2, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_history_tileview_2_scrollbar);
	lv_obj_set_pos(ui->screen_history_tileview_2, 0, 0);
	lv_obj_set_size(ui->screen_history_tileview_2, 480, 33);

	//Write codes screen_history_tileview_2_tileview
	ui->screen_history_tileview_2_tileview = lv_obj_create(ui->screen_history_tileview_2, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_history_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_history_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_history_tileview_2_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_history_tileview_2_tileview, 480, 33);
	lv_tileview_add_element(ui->screen_history_tileview_2, ui->screen_history_tileview_2_tileview);

	//Write codes screen_history_bar_1
	ui->screen_history_bar_1 = lv_bar_create(ui->screen_history, NULL);

	//Write style LV_BAR_PART_BG for screen_history_bar_1
	static lv_style_t style_screen_history_bar_1_bg;
	lv_style_init(&style_screen_history_bar_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_bar_1_bg
	lv_style_set_radius(&style_screen_history_bar_1_bg, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_history_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xee, 0xf3, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_history_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0x69, 0x6c, 0x6d));
	lv_style_set_bg_grad_dir(&style_screen_history_bar_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_history_bar_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen_history_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_history_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_history_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_history_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_history_bar_1, LV_BAR_PART_BG, &style_screen_history_bar_1_bg);

	//Write style LV_BAR_PART_INDIC for screen_history_bar_1
	static lv_style_t style_screen_history_bar_1_indic;
	lv_style_init(&style_screen_history_bar_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_bar_1_indic
	lv_style_set_radius(&style_screen_history_bar_1_indic, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_history_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_history_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_history_bar_1_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_history_bar_1_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_history_bar_1, LV_BAR_PART_INDIC, &style_screen_history_bar_1_indic);
	lv_obj_set_pos(ui->screen_history_bar_1, 369, 2);
	lv_obj_set_size(ui->screen_history_bar_1, 107, 29);
	lv_bar_set_anim_time(ui->screen_history_bar_1,1000);
	lv_bar_set_value(ui->screen_history_bar_1,50,LV_ANIM_OFF);
	lv_bar_set_range(ui->screen_history_bar_1,0,100);

	//Write codes screen_history_bat_status
	ui->screen_history_bat_status = lv_label_create(ui->screen_history, NULL);
	lv_label_set_text(ui->screen_history_bat_status, "0%");
	lv_label_set_long_mode(ui->screen_history_bat_status, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_history_bat_status, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_history_bat_status
	static lv_style_t style_screen_history_bat_status_main;
	lv_style_init(&style_screen_history_bat_status_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_bat_status_main
	lv_style_set_radius(&style_screen_history_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_history_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_history_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_history_bat_status_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_history_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_history_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_history_bat_status_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_history_bat_status_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_history_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_history_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_history_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_history_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_history_bat_status, LV_LABEL_PART_MAIN, &style_screen_history_bat_status_main);
	lv_obj_set_pos(ui->screen_history_bat_status, 381, 6);
	lv_obj_set_size(ui->screen_history_bat_status, 51, 0);

	//Write codes screen_history_label_tanggal
	ui->screen_history_label_tanggal = lv_label_create(ui->screen_history, NULL);
	lv_label_set_text(ui->screen_history_label_tanggal, "12 Juni 2021");
	lv_label_set_long_mode(ui->screen_history_label_tanggal, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_history_label_tanggal, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_history_label_tanggal
	static lv_style_t style_screen_history_label_tanggal_main;
	lv_style_init(&style_screen_history_label_tanggal_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_label_tanggal_main
	lv_style_set_radius(&style_screen_history_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_history_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_history_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xf7, 0xf2, 0xf2));
	lv_style_set_bg_grad_dir(&style_screen_history_label_tanggal_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_history_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_history_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_history_label_tanggal_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_history_label_tanggal_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_history_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_history_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_history_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_history_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_history_label_tanggal, LV_LABEL_PART_MAIN, &style_screen_history_label_tanggal_main);
	lv_obj_set_pos(ui->screen_history_label_tanggal, 3, 5);
	lv_obj_set_size(ui->screen_history_label_tanggal, 170, 0);

	//Write codes screen_history_label_jam
	ui->screen_history_label_jam = lv_label_create(ui->screen_history, NULL);
	lv_label_set_text(ui->screen_history_label_jam, "18:06");
	lv_label_set_long_mode(ui->screen_history_label_jam, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_history_label_jam, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_history_label_jam
	static lv_style_t style_screen_history_label_jam_main;
	lv_style_init(&style_screen_history_label_jam_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_label_jam_main
	lv_style_set_radius(&style_screen_history_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_history_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_history_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_history_label_jam_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_history_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_history_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_history_label_jam_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_history_label_jam_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_history_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_history_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_history_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_history_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_history_label_jam, LV_LABEL_PART_MAIN, &style_screen_history_label_jam_main);
	lv_obj_set_pos(ui->screen_history_label_jam, 157, 4);
	lv_obj_set_size(ui->screen_history_label_jam, 130, 0);

	Lokasi_t listLokasi[10];
	uint16_t sizeLokasi = httpGETHistory(listLokasi);

	//Write codes screen_history_table_history
	ui->screen_history_table_history = lv_table_create(ui->screen_history, NULL);

	//Write style LV_TABLE_PART_BG for screen_history_table_history
	static lv_style_t style_screen_history_table_history_bg;
	lv_style_init(&style_screen_history_table_history_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_table_history_bg
	lv_style_set_bg_color(&style_screen_history_table_history_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_history_table_history_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_history_table_history_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_history_table_history_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_history_table_history_bg, LV_STATE_DEFAULT, lv_color_make(0x62, 0x5b, 0x5b));
	lv_style_set_border_width(&style_screen_history_table_history_bg, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_screen_history_table_history_bg, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_decor(&style_screen_history_table_history_bg, LV_STATE_DEFAULT, LV_TEXT_DECOR_NONE);
	lv_style_set_pad_left(&style_screen_history_table_history_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_right(&style_screen_history_table_history_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_top(&style_screen_history_table_history_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_bottom(&style_screen_history_table_history_bg, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->screen_history_table_history, LV_TABLE_PART_BG, &style_screen_history_table_history_bg);

	//Write style LV_TABLE_PART_CELL1 for screen_history_table_history
	static lv_style_t style_screen_history_table_history_cell1;
	lv_style_init(&style_screen_history_table_history_cell1);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_table_history_cell1
	lv_style_set_border_color(&style_screen_history_table_history_cell1, LV_STATE_DEFAULT, lv_color_make(0x1f, 0x26, 0x47));
	lv_style_set_border_width(&style_screen_history_table_history_cell1, LV_STATE_DEFAULT, 1);
	lv_obj_add_style(ui->screen_history_table_history, LV_TABLE_PART_CELL1, &style_screen_history_table_history_cell1);
	lv_obj_set_pos(ui->screen_history_table_history, 60, 42);
	lv_table_set_col_cnt(ui->screen_history_table_history, 3);
	lv_table_set_row_cnt(ui->screen_history_table_history, 6);

	lv_table_set_cell_value(ui->screen_history_table_history,0,0,"Lokasi");
	for(int i = 1; i <= sizeLokasi; i++){
		lv_table_set_cell_value(ui->screen_history_table_history, i, 0, listLokasi[i - 1].nama_lokasi);
	}

	lv_table_set_cell_value(ui->screen_history_table_history,0,1,"Status Lokasi");
	for(int i = 1; i <= sizeLokasi; i++){
		lv_table_set_cell_value(ui->screen_history_table_history, i, 1, listLokasi[i - 1].status);
	}

	/*lv_table_set_cell_value(ui->screen_history_table_history,1,0,"HH105");
	lv_table_set_cell_value(ui->screen_history_table_history,2,0,"JJ105");
	lv_table_set_cell_value(ui->screen_history_table_history,3,0,"Citron");
	lv_table_set_cell_value(ui->screen_history_table_history,4,0,"a");
	lv_table_set_cell_value(ui->screen_history_table_history,5,0,"b");
	lv_table_set_cell_value(ui->screen_history_table_history,1,1,"Tidak Masalah");
	lv_table_set_cell_value(ui->screen_history_table_history,2,1,"Tidak Masalah");
	lv_table_set_cell_value(ui->screen_history_table_history,3,1,"$3");
	lv_table_set_cell_value(ui->screen_history_table_history,4,1,"");
	lv_table_set_cell_value(ui->screen_history_table_history,5,1,"");
	lv_table_set_cell_value(ui->screen_history_table_history,0,2,"Waktu");
	lv_table_set_cell_value(ui->screen_history_table_history,1,2,"08:05");
	lv_table_set_cell_value(ui->screen_history_table_history,2,2,"08:15");
	lv_table_set_cell_value(ui->screen_history_table_history,3,2," ");
	lv_table_set_cell_value(ui->screen_history_table_history,4,2,"");
	lv_table_set_cell_value(ui->screen_history_table_history,5,2,"");*/
	lv_obj_set_style_local_pad_left(ui->screen_history_table_history, LV_TABLE_PART_CELL1, LV_STATE_DEFAULT, 10);
	lv_obj_set_style_local_pad_right(ui->screen_history_table_history, LV_TABLE_PART_CELL1, LV_STATE_DEFAULT, 10);
	lv_obj_set_style_local_pad_top(ui->screen_history_table_history, LV_TABLE_PART_CELL1, LV_STATE_DEFAULT, 10);
	lv_obj_set_style_local_pad_bottom(ui->screen_history_table_history, LV_TABLE_PART_CELL1, LV_STATE_DEFAULT, 10);

	//Write codes screen_history_imgbtn_back_patroli
	ui->screen_history_imgbtn_back_patroli = lv_imgbtn_create(ui->screen_history, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen_history_imgbtn_back_patroli
	static lv_style_t style_screen_history_imgbtn_back_patroli_main;
	lv_style_init(&style_screen_history_imgbtn_back_patroli_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_history_imgbtn_back_patroli_main
	lv_style_set_text_color(&style_screen_history_imgbtn_back_patroli_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen_history_imgbtn_back_patroli_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_history_imgbtn_back_patroli_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_history_imgbtn_back_patroli_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_history_imgbtn_back_patroli, LV_IMGBTN_PART_MAIN, &style_screen_history_imgbtn_back_patroli_main);
	lv_obj_set_pos(ui->screen_history_imgbtn_back_patroli, 5, 264);
	lv_obj_set_size(ui->screen_history_imgbtn_back_patroli, 57, 48);
	lv_imgbtn_set_src(ui->screen_history_imgbtn_back_patroli,LV_BTN_STATE_RELEASED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_history_imgbtn_back_patroli,LV_BTN_STATE_PRESSED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_history_imgbtn_back_patroli,LV_BTN_STATE_CHECKED_RELEASED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_history_imgbtn_back_patroli,LV_BTN_STATE_CHECKED_PRESSED,"S:/images/back.bin");
	lv_imgbtn_set_checkable(ui->screen_history_imgbtn_back_patroli, true);

	stateScreen = STATE_SCREEN_HISTORY;

	events_init_screen_history(ui);
}