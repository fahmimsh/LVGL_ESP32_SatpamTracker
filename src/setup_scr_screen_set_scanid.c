/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl.h"
#include <stdio.h>
#include "generated/gui_guider.h"
#include "generated/events_init.h"
#include "custom/custom.h"
extern bool buzzerON;

extern uint8_t stateScreen;

static lv_obj_t * kb;
static void kb_event_cb(lv_obj_t * event_kb, lv_event_t event)
{
	/* Just call the regular event handler */
	lv_keyboard_def_event_cb(event_kb, event);
	if(event == LV_EVENT_APPLY || event == LV_EVENT_CANCEL){
		if(NULL != kb){
			lv_obj_del(kb);
		}
	}
}
static void text_area_event_cb(lv_obj_t* ta, lv_event_t event)
{

	if(event == LV_EVENT_CLICKED){
		 if( !lv_debug_check_obj_valid(kb) ){
			/* Create a keyboard and make it fill the width of the above text areas */
			kb = lv_keyboard_create(lv_scr_act(), NULL);
			lv_obj_set_event_cb(kb, kb_event_cb);
			lv_obj_set_size(kb,  LV_HOR_RES, LV_VER_RES / 2);
		}
		lv_keyboard_set_textarea(kb, ta);
		lv_keyboard_set_cursor_manage(kb, true); 
	}
}

void setup_scr_screen_set_scanid(lv_ui *ui){

	//lv_obj_del(lv_scr_act());
	buzzerON = true;
	//Write codes screen_set_scanid
	ui->screen_set_scanid = lv_obj_create(NULL, NULL);

	//Write codes screen_set_scanid_tileview_1
	ui->screen_set_scanid_tileview_1 = lv_tileview_create(ui->screen_set_scanid, NULL);
	static lv_point_t screen_set_scanid_tileview_1_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_set_scanid_tileview_1, screen_set_scanid_tileview_1_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_set_scanid_tileview_1, true);
	lv_tileview_set_anim_time(ui->screen_set_scanid_tileview_1, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_set_scanid_tileview_1
	static lv_style_t style_screen_set_scanid_tileview_1_bg;
	lv_style_init(&style_screen_set_scanid_tileview_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_tileview_1_bg
	lv_style_set_radius(&style_screen_set_scanid_tileview_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_scanid_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xcb, 0xd0, 0xe6));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_tileview_1_bg, LV_STATE_DEFAULT, lv_color_make(0xe5, 0xe7, 0xeb));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_tileview_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_tileview_1_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_scanid_tileview_1, LV_TILEVIEW_PART_BG, &style_screen_set_scanid_tileview_1_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_set_scanid_tileview_1
	static lv_style_t style_screen_set_scanid_tileview_1_edge_flash;
	lv_style_init(&style_screen_set_scanid_tileview_1_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_tileview_1_edge_flash
	lv_style_set_radius(&style_screen_set_scanid_tileview_1_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_scanid_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_tileview_1_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_tileview_1_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_tileview_1_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_scanid_tileview_1, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_set_scanid_tileview_1_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_set_scanid_tileview_1
	static lv_style_t style_screen_set_scanid_tileview_1_scrollbar;
	lv_style_init(&style_screen_set_scanid_tileview_1_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_tileview_1_scrollbar
	lv_style_set_radius(&style_screen_set_scanid_tileview_1_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_scanid_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_tileview_1_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_tileview_1_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_tileview_1_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_scanid_tileview_1, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_set_scanid_tileview_1_scrollbar);
	lv_obj_set_pos(ui->screen_set_scanid_tileview_1, 0, 0);
	lv_obj_set_size(ui->screen_set_scanid_tileview_1, 480, 320);

	//Write codes screen_set_scanid_tileview_1_tileview
	ui->screen_set_scanid_tileview_1_tileview = lv_obj_create(ui->screen_set_scanid_tileview_1, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_set_scanid_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_set_scanid_tileview_1_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_set_scanid_tileview_1_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_set_scanid_tileview_1_tileview, 480, 320);
	lv_tileview_add_element(ui->screen_set_scanid_tileview_1, ui->screen_set_scanid_tileview_1_tileview);

	//Write codes screen_set_scanid_tileview_2
	ui->screen_set_scanid_tileview_2 = lv_tileview_create(ui->screen_set_scanid, NULL);
	static lv_point_t screen_set_scanid_tileview_2_valid_pos[] = {{0, 0},};
	lv_tileview_set_valid_positions(ui->screen_set_scanid_tileview_2, screen_set_scanid_tileview_2_valid_pos, 1);
	lv_tileview_set_edge_flash(ui->screen_set_scanid_tileview_2, true);
	lv_tileview_set_anim_time(ui->screen_set_scanid_tileview_2, 1000);

	//Write style LV_TILEVIEW_PART_BG for screen_set_scanid_tileview_2
	static lv_style_t style_screen_set_scanid_tileview_2_bg;
	lv_style_init(&style_screen_set_scanid_tileview_2_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_tileview_2_bg
	lv_style_set_radius(&style_screen_set_scanid_tileview_2_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_scanid_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0xd0, 0xd2, 0xe6));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_tileview_2_bg, LV_STATE_DEFAULT, lv_color_make(0x60, 0x88, 0xc7));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_tileview_2_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_tileview_2_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_scanid_tileview_2, LV_TILEVIEW_PART_BG, &style_screen_set_scanid_tileview_2_bg);

	//Write style LV_TILEVIEW_PART_EDGE_FLASH for screen_set_scanid_tileview_2
	static lv_style_t style_screen_set_scanid_tileview_2_edge_flash;
	lv_style_init(&style_screen_set_scanid_tileview_2_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_tileview_2_edge_flash
	lv_style_set_radius(&style_screen_set_scanid_tileview_2_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_scanid_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_tileview_2_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_tileview_2_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_tileview_2_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_scanid_tileview_2, LV_TILEVIEW_PART_EDGE_FLASH, &style_screen_set_scanid_tileview_2_edge_flash);

	//Write style LV_TILEVIEW_PART_SCROLLBAR for screen_set_scanid_tileview_2
	static lv_style_t style_screen_set_scanid_tileview_2_scrollbar;
	lv_style_init(&style_screen_set_scanid_tileview_2_scrollbar);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_tileview_2_scrollbar
	lv_style_set_radius(&style_screen_set_scanid_tileview_2_scrollbar, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_scanid_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_tileview_2_scrollbar, LV_STATE_DEFAULT, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_tileview_2_scrollbar, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_tileview_2_scrollbar, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_scanid_tileview_2, LV_TILEVIEW_PART_SCROLLBAR, &style_screen_set_scanid_tileview_2_scrollbar);
	lv_obj_set_pos(ui->screen_set_scanid_tileview_2, 0, 0);
	lv_obj_set_size(ui->screen_set_scanid_tileview_2, 480, 33);

	//Write codes screen_set_scanid_tileview_2_tileview
	ui->screen_set_scanid_tileview_2_tileview = lv_obj_create(ui->screen_set_scanid_tileview_2, NULL);
	lv_obj_set_style_local_bg_opa(ui->screen_set_scanid_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_border_width(ui->screen_set_scanid_tileview_2_tileview, LV_OBJ_PART_MAIN, LV_STATE_FOCUSED, 0);
	lv_obj_set_pos(ui->screen_set_scanid_tileview_2_tileview, 0*480, 0);
	lv_obj_set_size(ui->screen_set_scanid_tileview_2_tileview, 480, 33);
	lv_tileview_add_element(ui->screen_set_scanid_tileview_2, ui->screen_set_scanid_tileview_2_tileview);

	//Write codes screen_set_scanid_bar_1
	ui->screen_set_scanid_bar_1 = lv_bar_create(ui->screen_set_scanid, NULL);

	//Write style LV_BAR_PART_BG for screen_set_scanid_bar_1
	static lv_style_t style_screen_set_scanid_bar_1_bg;
	lv_style_init(&style_screen_set_scanid_bar_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_bar_1_bg
	lv_style_set_radius(&style_screen_set_scanid_bar_1_bg, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_set_scanid_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0xee, 0xf3, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_bar_1_bg, LV_STATE_DEFAULT, lv_color_make(0x69, 0x6c, 0x6d));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_bar_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_bar_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen_set_scanid_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_set_scanid_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_set_scanid_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_set_scanid_bar_1_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_set_scanid_bar_1, LV_BAR_PART_BG, &style_screen_set_scanid_bar_1_bg);

	//Write style LV_BAR_PART_INDIC for screen_set_scanid_bar_1
	static lv_style_t style_screen_set_scanid_bar_1_indic;
	lv_style_init(&style_screen_set_scanid_bar_1_indic);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_bar_1_indic
	lv_style_set_radius(&style_screen_set_scanid_bar_1_indic, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_screen_set_scanid_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_bar_1_indic, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_bar_1_indic, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_bar_1_indic, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_scanid_bar_1, LV_BAR_PART_INDIC, &style_screen_set_scanid_bar_1_indic);
	lv_obj_set_pos(ui->screen_set_scanid_bar_1, 369, 2);
	lv_obj_set_size(ui->screen_set_scanid_bar_1, 107, 29);
	lv_bar_set_anim_time(ui->screen_set_scanid_bar_1,1000);
	lv_bar_set_value(ui->screen_set_scanid_bar_1,50,LV_ANIM_OFF);
	lv_bar_set_range(ui->screen_set_scanid_bar_1,0,100);

	//Write codes screen_set_scanid_bat_status
	ui->screen_set_scanid_bat_status = lv_label_create(ui->screen_set_scanid, NULL);
	lv_label_set_text(ui->screen_set_scanid_bat_status, "%");
	lv_label_set_long_mode(ui->screen_set_scanid_bat_status, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_set_scanid_bat_status, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_set_scanid_bat_status
	static lv_style_t style_screen_set_scanid_bat_status_main;
	lv_style_init(&style_screen_set_scanid_bat_status_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_bat_status_main
	lv_style_set_radius(&style_screen_set_scanid_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_scanid_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_bat_status_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_set_scanid_bat_status_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_set_scanid_bat_status_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_set_scanid_bat_status_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_set_scanid_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_set_scanid_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_set_scanid_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_set_scanid_bat_status_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_set_scanid_bat_status, LV_LABEL_PART_MAIN, &style_screen_set_scanid_bat_status_main);
	lv_obj_set_pos(ui->screen_set_scanid_bat_status, 381, 6);
	lv_obj_set_size(ui->screen_set_scanid_bat_status, 100, 0);

	//Write codes screen_set_scanid_label_tanggal
	ui->screen_set_scanid_label_tanggal = lv_label_create(ui->screen_set_scanid, NULL);
	lv_label_set_text(ui->screen_set_scanid_label_tanggal, "");
	lv_label_set_long_mode(ui->screen_set_scanid_label_tanggal, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_set_scanid_label_tanggal, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_set_scanid_label_tanggal
	static lv_style_t style_screen_set_scanid_label_tanggal_main;
	lv_style_init(&style_screen_set_scanid_label_tanggal_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_label_tanggal_main
	lv_style_set_radius(&style_screen_set_scanid_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_scanid_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0xf7, 0xf2, 0xf2));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_label_tanggal_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_set_scanid_label_tanggal_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_set_scanid_label_tanggal_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_set_scanid_label_tanggal_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_set_scanid_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_set_scanid_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_set_scanid_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_set_scanid_label_tanggal_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_set_scanid_label_tanggal, LV_LABEL_PART_MAIN, &style_screen_set_scanid_label_tanggal_main);
	lv_obj_set_pos(ui->screen_set_scanid_label_tanggal, 3, 5);
	lv_obj_set_size(ui->screen_set_scanid_label_tanggal, 170, 0);

	//Write codes screen_set_scanid_label_jam
	ui->screen_set_scanid_label_jam = lv_label_create(ui->screen_set_scanid, NULL);
	lv_label_set_text(ui->screen_set_scanid_label_jam, "");
	lv_label_set_long_mode(ui->screen_set_scanid_label_jam, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_set_scanid_label_jam, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_set_scanid_label_jam
	static lv_style_t style_screen_set_scanid_label_jam_main;
	lv_style_init(&style_screen_set_scanid_label_jam_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_label_jam_main
	lv_style_set_radius(&style_screen_set_scanid_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_scanid_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_label_jam_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_set_scanid_label_jam_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_set_scanid_label_jam_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_set_scanid_label_jam_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_set_scanid_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_set_scanid_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_set_scanid_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_set_scanid_label_jam_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_set_scanid_label_jam, LV_LABEL_PART_MAIN, &style_screen_set_scanid_label_jam_main);
	lv_obj_set_pos(ui->screen_set_scanid_label_jam, 157, 4);
	lv_obj_set_size(ui->screen_set_scanid_label_jam, 130, 0);

	//Write codes screen_set_scanid_imgbtn_back_set
	ui->screen_set_scanid_imgbtn_back_set = lv_imgbtn_create(ui->screen_set_scanid, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen_set_scanid_imgbtn_back_set
	static lv_style_t style_screen_set_scanid_imgbtn_back_set_main;
	lv_style_init(&style_screen_set_scanid_imgbtn_back_set_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_imgbtn_back_set_main
	lv_style_set_text_color(&style_screen_set_scanid_imgbtn_back_set_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen_set_scanid_imgbtn_back_set_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_set_scanid_imgbtn_back_set_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_set_scanid_imgbtn_back_set_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_scanid_imgbtn_back_set, LV_IMGBTN_PART_MAIN, &style_screen_set_scanid_imgbtn_back_set_main);
	lv_obj_set_pos(ui->screen_set_scanid_imgbtn_back_set, 5, 264);
	lv_obj_set_size(ui->screen_set_scanid_imgbtn_back_set, 57, 48);
	lv_imgbtn_set_src(ui->screen_set_scanid_imgbtn_back_set,LV_BTN_STATE_RELEASED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_set_scanid_imgbtn_back_set,LV_BTN_STATE_PRESSED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_set_scanid_imgbtn_back_set,LV_BTN_STATE_CHECKED_RELEASED,"S:/images/back.bin");
	lv_imgbtn_set_src(ui->screen_set_scanid_imgbtn_back_set,LV_BTN_STATE_CHECKED_PRESSED,"S:/images/back.bin");
	lv_imgbtn_set_checkable(ui->screen_set_scanid_imgbtn_back_set, true);

	//Write codes screen_set_scanid_label_set_scanid
	ui->screen_set_scanid_label_set_scanid = lv_label_create(ui->screen_set_scanid, NULL);
	lv_label_set_text(ui->screen_set_scanid_label_set_scanid, "Scan Id untuk melihat id Card");
	lv_label_set_long_mode(ui->screen_set_scanid_label_set_scanid, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_set_scanid_label_set_scanid, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen_set_scanid_label_set_scanid
	static lv_style_t style_screen_set_scanid_label_set_scanid_main;
	lv_style_init(&style_screen_set_scanid_label_set_scanid_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_label_set_scanid_main
	lv_style_set_radius(&style_screen_set_scanid_label_set_scanid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_scanid_label_set_scanid_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_label_set_scanid_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_label_set_scanid_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_label_set_scanid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_set_scanid_label_set_scanid_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_set_scanid_label_set_scanid_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_set_scanid_label_set_scanid_main, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen_set_scanid_label_set_scanid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_set_scanid_label_set_scanid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_set_scanid_label_set_scanid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_set_scanid_label_set_scanid_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_set_scanid_label_set_scanid, LV_LABEL_PART_MAIN, &style_screen_set_scanid_label_set_scanid_main);
	lv_obj_set_pos(ui->screen_set_scanid_label_set_scanid, 50, 63);
	lv_obj_set_size(ui->screen_set_scanid_label_set_scanid, 401, 0);

	//Write codes screen_set_scanid_ta_scanid
	ui->screen_set_scanid_ta_scanid = lv_textarea_create(ui->screen_set_scanid, NULL);

	//Write style LV_PAGE_PART_BG for screen_set_scanid_ta_scanid
	static lv_style_t style_screen_set_scanid_ta_scanid_bg;
	lv_style_init(&style_screen_set_scanid_ta_scanid_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_ta_scanid_bg
	lv_style_set_radius(&style_screen_set_scanid_ta_scanid_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_screen_set_scanid_ta_scanid_bg, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_set_scanid_ta_scanid_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_text_color(&style_screen_set_scanid_ta_scanid_bg, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_set_scanid_ta_scanid_bg, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_screen_set_scanid_ta_scanid_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_set_scanid_ta_scanid_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_right(&style_screen_set_scanid_ta_scanid_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_top(&style_screen_set_scanid_ta_scanid_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_bottom(&style_screen_set_scanid_ta_scanid_bg, LV_STATE_DEFAULT, 2);
	lv_obj_add_style(ui->screen_set_scanid_ta_scanid, LV_PAGE_PART_BG, &style_screen_set_scanid_ta_scanid_bg);

	//Write style LV_PAGE_PART_SCROLLABLE for screen_set_scanid_ta_scanid
	static lv_style_t style_screen_set_scanid_ta_scanid_scrollable;
	lv_style_init(&style_screen_set_scanid_ta_scanid_scrollable);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_ta_scanid_scrollable
	lv_style_set_radius(&style_screen_set_scanid_ta_scanid_scrollable, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_scanid_ta_scanid_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_ta_scanid_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_ta_scanid_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_ta_scanid_scrollable, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_scanid_ta_scanid, LV_PAGE_PART_SCROLLABLE, &style_screen_set_scanid_ta_scanid_scrollable);

	//Write style LV_PAGE_PART_EDGE_FLASH for screen_set_scanid_ta_scanid
	static lv_style_t style_screen_set_scanid_ta_scanid_edge_flash;
	lv_style_init(&style_screen_set_scanid_ta_scanid_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_scanid_ta_scanid_edge_flash
	lv_style_set_radius(&style_screen_set_scanid_ta_scanid_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_scanid_ta_scanid_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_scanid_ta_scanid_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_scanid_ta_scanid_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_scanid_ta_scanid_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_set_scanid_ta_scanid, LV_PAGE_PART_EDGE_FLASH, &style_screen_set_scanid_ta_scanid_edge_flash);
	lv_obj_set_pos(ui->screen_set_scanid_ta_scanid, 51, 105);
	lv_obj_set_size(ui->screen_set_scanid_ta_scanid, 381, 81);
	lv_textarea_set_text(ui->screen_set_scanid_ta_scanid,"");
	lv_obj_set_event_cb(ui->screen_set_scanid_ta_scanid, text_area_event_cb);
	lv_textarea_set_text_align(ui->screen_set_scanid_ta_scanid, LV_LABEL_ALIGN_LEFT);

	stateScreen = STATE_SCREEN_SCANID;
	//Init events for screen
	events_init_screen_set_scanid(ui);
}