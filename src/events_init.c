/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "generated/events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "lcdBrightness.h"
#include "WiFi_function.h"

extern uint8_t stateScreen;
extern void brightness(uint16_t val);
static void screen_Menu_msgbox_Logoutevent_handler(lv_obj_t * obj, lv_event_t event);

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


void events_init(lv_ui *ui)
{
}

static void screen_Menu_img_menu_logoutevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		//Write codes screen_Menu_msgbox_Logout
	guider_ui.screen_Menu_msgbox_Logout = lv_msgbox_create(guider_ui.screen_Menu, NULL);

	//Write style LV_MSGBOX_PART_BG for screen_Menu_msgbox_Logout
	static lv_style_t style_screen_Menu_msgbox_Logout_bg;
	lv_style_init(&style_screen_Menu_msgbox_Logout_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_msgbox_Logout_bg
	lv_style_set_radius(&style_screen_Menu_msgbox_Logout_bg, LV_STATE_DEFAULT, 4);
	lv_style_set_bg_color(&style_screen_Menu_msgbox_Logout_bg, LV_STATE_DEFAULT, lv_color_make(0xeb, 0xeb, 0xeb));
	lv_style_set_bg_grad_color(&style_screen_Menu_msgbox_Logout_bg, LV_STATE_DEFAULT, lv_color_make(0xeb, 0xeb, 0xeb));
	lv_style_set_bg_grad_dir(&style_screen_Menu_msgbox_Logout_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_msgbox_Logout_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_Menu_msgbox_Logout_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_screen_Menu_msgbox_Logout_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_screen_Menu_msgbox_Logout_bg, LV_STATE_DEFAULT, lv_color_make(0x0d, 0x0d, 0x0d));
	lv_style_set_text_font(&style_screen_Menu_msgbox_Logout_bg, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_Menu_msgbox_Logout_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_text_line_space(&style_screen_Menu_msgbox_Logout_bg, LV_STATE_DEFAULT, 10);
	lv_obj_add_style(guider_ui.screen_Menu_msgbox_Logout, LV_MSGBOX_PART_BG, &style_screen_Menu_msgbox_Logout_bg);

		//Write style LV_MSGBOX_PART_BTN_BG for screen_Menu_msgbox_Logout
	static lv_style_t style_screen_Menu_msgbox_Logout_btn_bg;
	lv_style_init(&style_screen_Menu_msgbox_Logout_btn_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_msgbox_Logout_btn_bg
	lv_style_set_radius(&style_screen_Menu_msgbox_Logout_btn_bg, LV_STATE_DEFAULT, 4);
	lv_style_set_bg_color(&style_screen_Menu_msgbox_Logout_btn_bg, LV_STATE_DEFAULT, lv_color_make(0xf4, 0xf0, 0xf0));
	lv_style_set_bg_grad_color(&style_screen_Menu_msgbox_Logout_btn_bg, LV_STATE_DEFAULT, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_bg_grad_dir(&style_screen_Menu_msgbox_Logout_btn_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_msgbox_Logout_btn_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_Menu_msgbox_Logout_btn_bg, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_Menu_msgbox_Logout_btn_bg, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(guider_ui.screen_Menu_msgbox_Logout, LV_MSGBOX_PART_BTN_BG, &style_screen_Menu_msgbox_Logout_btn_bg);

	//Write style LV_MSGBOX_PART_BTN for screen_Menu_msgbox_Logout
	static lv_style_t style_screen_Menu_msgbox_Logout_btn;
	lv_style_init(&style_screen_Menu_msgbox_Logout_btn);

	//Write style state: LV_STATE_DEFAULT for style_screen_Menu_msgbox_Logout_btn
	lv_style_set_radius(&style_screen_Menu_msgbox_Logout_btn, LV_STATE_DEFAULT, 20);
	lv_style_set_bg_color(&style_screen_Menu_msgbox_Logout_btn, LV_STATE_DEFAULT, lv_color_make(0xcd, 0xe0, 0xf9));
	lv_style_set_bg_grad_color(&style_screen_Menu_msgbox_Logout_btn, LV_STATE_DEFAULT, lv_color_make(0xcf, 0xc2, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_Menu_msgbox_Logout_btn, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_Menu_msgbox_Logout_btn, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_Menu_msgbox_Logout_btn, LV_STATE_DEFAULT, lv_color_make(0x14, 0xa2, 0xbe));
	lv_style_set_border_width(&style_screen_Menu_msgbox_Logout_btn, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_screen_Menu_msgbox_Logout_btn, LV_STATE_DEFAULT, lv_color_make(0x4e, 0x4e, 0x4e));
	lv_style_set_text_font(&style_screen_Menu_msgbox_Logout_btn, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_obj_add_style(guider_ui.screen_Menu_msgbox_Logout, LV_MSGBOX_PART_BTN, &style_screen_Menu_msgbox_Logout_btn);
	lv_obj_set_pos(guider_ui.screen_Menu_msgbox_Logout, 52, 90);
	lv_obj_set_size(guider_ui.screen_Menu_msgbox_Logout, 370, 0);
	lv_msgbox_set_text(guider_ui.screen_Menu_msgbox_Logout,"Apakah anda yakin ingin \nLogout?");
	static const char * screen_Menu_msgbox_Logout_btns[] = {"Tidak","Logout",""};
	lv_msgbox_add_btns(guider_ui.screen_Menu_msgbox_Logout, screen_Menu_msgbox_Logout_btns);
	lv_obj_set_width(guider_ui.screen_Menu_msgbox_Logout,370);
	lv_obj_add_style(guider_ui.screen_Menu_msgbox_Logout, LV_MSGBOX_PART_BTN_BG, &style_screen_Menu_msgbox_Logout_btn_bg);
	lv_obj_add_style(guider_ui.screen_Menu_msgbox_Logout, LV_MSGBOX_PART_BTN, &style_screen_Menu_msgbox_Logout_btn);
	lv_obj_set_event_cb(guider_ui.screen_Menu_msgbox_Logout, screen_Menu_msgbox_Logoutevent_handler);

	}
	break;
	default:
		break;
	}
}

static void screen_Menu_img_menu_patrolievent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_del(lv_scr_act());
		setup_scr_screen_menu_patroli(&guider_ui);
		lv_scr_load(guider_ui.screen_menu_patroli);
	}
		break;
	default:
		break;
	}
}

static void screen_Menu_img_menu_settingevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_del(lv_scr_act());
		setup_scr_screen_menu_setting(&guider_ui);
		lv_scr_load(guider_ui.screen_menu_setting);
	}
		break;
	default:
		break;
	}
}


static void screen_Menu_imgbtn_1event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_clean(lv_scr_act());
		setup_scr_screen_menu_ruangan(&guider_ui);
		lv_scr_load(guider_ui.screen_menu_ruangan);
	}
		break;
	default:
		break;
	}
}

static void screen_Menu_msgbox_Logoutevent_handler(lv_obj_t * obj, lv_event_t event)
{
	if (event == LV_EVENT_VALUE_CHANGED) {
		if (strcmp(lv_msgbox_get_active_btn_text(obj), "Logout") == 0) {
			stateScreen = 0;
			lv_obj_del(obj);
			setup_scr_screen_Login(&guider_ui);
			lv_scr_load(guider_ui.screen_Login);
		}
		else {
			lv_obj_del(obj);
			setup_scr_screen_Menu(&guider_ui);
			lv_scr_load(guider_ui.screen_Menu);
		}
	}
	/*switch (event)
	{
	case LV_EVENT_VALUE_CHANGED:
	{

	}
		break;
	default:
		break;
	}*/
}

void events_init_screen_Menu(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen_Menu_img_menu_logout, screen_Menu_img_menu_logoutevent_handler);
	lv_obj_set_event_cb(ui->screen_Menu_img_menu_patroli, screen_Menu_img_menu_patrolievent_handler);
	lv_obj_set_event_cb(ui->screen_Menu_img_menu_setting, screen_Menu_img_menu_settingevent_handler);
	lv_obj_set_event_cb(ui->screen_Menu_imgbtn_1, screen_Menu_imgbtn_1event_handler);
}

static void screen_menu_setting_btn_cek_idcardevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_del(lv_scr_act());
		setup_scr_screen_set_scanid(&guider_ui);
		lv_scr_load(guider_ui.screen_set_scanid);
	}
		break;
	default:
		break;
	}
}


static void screen_menu_setting_btn_set_wifievent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_del(lv_scr_act());
		setup_scr_screen_set_wifi(&guider_ui);
		lv_scr_load(guider_ui.screen_set_wifi);
	}
		break;
	default:
		break;
	}
}

static void screen_menu_setting_imgbtn_back_menuevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_del(lv_scr_act());
		setup_scr_screen_Menu(&guider_ui);
		lv_scr_load(guider_ui.screen_Menu);
	}
		break;
	default:
		break;
	}
}

static void screen_menu_setting_slider_kecerahanevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		//Tuliskan Kode Mengatur Kecerahan
		lcd_setBrightness(lv_slider_get_value(obj));
	}
		break;
	default:
		break;
	}
}

static void screen_menu_setting_slider_vol_buzevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		//Tulis Kode Mengatur Out Buzzer PWM
	}
		break;
	default:
		break;
	}
}

void events_init_screen_menu_setting(lv_ui *ui)
{

	lv_obj_set_event_cb(ui->screen_menu_setting_btn_cek_idcard, screen_menu_setting_btn_cek_idcardevent_handler);
	lv_obj_set_event_cb(ui->screen_menu_setting_imgbtn_back_menu, screen_menu_setting_imgbtn_back_menuevent_handler);
	lv_obj_set_event_cb(ui->screen_menu_setting_slider_kecerahan, screen_menu_setting_slider_kecerahanevent_handler);
	lv_obj_set_event_cb(ui->screen_menu_setting_slider_vol_buz, screen_menu_setting_slider_vol_buzevent_handler);
	lv_obj_set_event_cb(ui->screen_menu_setting_btn_set_wifi, screen_menu_setting_btn_set_wifievent_handler);
}

static void screen_set_wifi_btn_scanwifievent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		//Tuliskan code connect wifi
	}
		break;
	default:
		break;
	}
}

static void screen_set_wifi_btn_connectevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		//Tuliskan setting connect ke WiFI
		WiFi_t wifi;

		strcpy(wifi.SSID, lv_label_get_text(guider_ui.screen_set_wifi_label_nama_wifi));
		char password[20];
		strcpy(password, lv_textarea_get_text(guider_ui.screen_set_wifi_ta_password_wifi));
		connectWiFi(wifi, password);
		uint32_t prevMillis = millis();
		while(!isWiFiConnected(wifi) && (millis() - prevMillis) >= 10000){
			prevMillis = millis();
		}
	}
		break;
	default:
		break;
	}
}

static void screen_set_wifi_btn_cancelevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		setup_scr_screen_set_wifi(&guider_ui);
		lv_scr_load_anim(guider_ui.screen_set_wifi, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
	}
		break;
	default:
		break;
	}
}


static void screen_set_wifi_imgbtn_backevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_del(lv_scr_act());
		setup_scr_screen_menu_setting(&guider_ui);
		lv_scr_load(guider_ui.screen_menu_setting);
	}
		break;
	default:
		break;
	}
}

void screen_set_wifi_list_ssidevent_handler(lv_obj_t * obj, lv_event_t event){	
	//Write codes screen_set_wifi_cont_connect_wifi
	guider_ui.screen_set_wifi_cont_connect_wifi = lv_cont_create(guider_ui.screen_set_wifi, NULL);

	//Write style LV_CONT_PART_MAIN for screen_set_wifi_cont_connect_wifi
	static lv_style_t style_screen_set_wifi_cont_connect_wifi_main;
	lv_style_init(&style_screen_set_wifi_cont_connect_wifi_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_cont_connect_wifi_main
	lv_style_set_radius(&style_screen_set_wifi_cont_connect_wifi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_cont_connect_wifi_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_cont_connect_wifi_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_cont_connect_wifi_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_cont_connect_wifi_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_set_wifi_cont_connect_wifi_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_screen_set_wifi_cont_connect_wifi_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_screen_set_wifi_cont_connect_wifi_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen_set_wifi_cont_connect_wifi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_set_wifi_cont_connect_wifi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_set_wifi_cont_connect_wifi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_set_wifi_cont_connect_wifi_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(guider_ui.screen_set_wifi_cont_connect_wifi, LV_CONT_PART_MAIN, &style_screen_set_wifi_cont_connect_wifi_main);
	lv_obj_set_pos(guider_ui.screen_set_wifi_cont_connect_wifi, 72, 89);
	lv_obj_set_size(guider_ui.screen_set_wifi_cont_connect_wifi, 285, 150);
	lv_obj_set_click(guider_ui.screen_set_wifi_cont_connect_wifi, false);
	lv_cont_set_layout(guider_ui.screen_set_wifi_cont_connect_wifi, LV_LAYOUT_OFF);
	lv_cont_set_fit(guider_ui.screen_set_wifi_cont_connect_wifi, LV_FIT_NONE);

	//Write codes screen_set_wifi_btn_connect
	guider_ui.screen_set_wifi_btn_connect = lv_btn_create(guider_ui.screen_set_wifi, NULL);

	//Write style LV_BTN_PART_MAIN for screen_set_wifi_btn_connect
	static lv_style_t style_screen_set_wifi_btn_connect_main;
	lv_style_init(&style_screen_set_wifi_btn_connect_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_btn_connect_main
	lv_style_set_radius(&style_screen_set_wifi_btn_connect_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_set_wifi_btn_connect_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_btn_connect_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_btn_connect_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_btn_connect_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_set_wifi_btn_connect_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_set_wifi_btn_connect_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen_set_wifi_btn_connect_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen_set_wifi_btn_connect_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen_set_wifi_btn_connect_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(guider_ui.screen_set_wifi_btn_connect, LV_BTN_PART_MAIN, &style_screen_set_wifi_btn_connect_main);
	lv_obj_set_pos(guider_ui.screen_set_wifi_btn_connect, 100, 162);
	lv_obj_set_size(guider_ui.screen_set_wifi_btn_connect, 100, 50);
	guider_ui.screen_set_wifi_btn_connect_label = lv_label_create(guider_ui.screen_set_wifi_btn_connect, NULL);
	lv_label_set_text(guider_ui.screen_set_wifi_btn_connect_label, "Connect");
	lv_obj_set_style_local_text_color(guider_ui.screen_set_wifi_btn_connect_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(guider_ui.screen_set_wifi_btn_connect_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_14);

	//Write codes screen_set_wifi_btn_cancel
	guider_ui.screen_set_wifi_btn_cancel = lv_btn_create(guider_ui.screen_set_wifi, NULL);

	//Write style LV_BTN_PART_MAIN for screen_set_wifi_btn_cancel
	static lv_style_t style_screen_set_wifi_btn_cancel_main;
	lv_style_init(&style_screen_set_wifi_btn_cancel_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_btn_cancel_main
	lv_style_set_radius(&style_screen_set_wifi_btn_cancel_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_set_wifi_btn_cancel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_btn_cancel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_btn_cancel_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_btn_cancel_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_set_wifi_btn_cancel_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_set_wifi_btn_cancel_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen_set_wifi_btn_cancel_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen_set_wifi_btn_cancel_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen_set_wifi_btn_cancel_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(guider_ui.screen_set_wifi_btn_cancel, LV_BTN_PART_MAIN, &style_screen_set_wifi_btn_cancel_main);
	lv_obj_set_pos(guider_ui.screen_set_wifi_btn_cancel, 241, 162);
	lv_obj_set_size(guider_ui.screen_set_wifi_btn_cancel, 100, 50);
	guider_ui.screen_set_wifi_btn_cancel_label = lv_label_create(guider_ui.screen_set_wifi_btn_cancel, NULL);
	lv_label_set_text(guider_ui.screen_set_wifi_btn_cancel_label, "Cancel");
	lv_obj_set_style_local_text_color(guider_ui.screen_set_wifi_btn_cancel_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(guider_ui.screen_set_wifi_btn_cancel_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_14);

	//Write codes screen_set_wifi_ta_password_wifi
	guider_ui.screen_set_wifi_ta_password_wifi = lv_textarea_create(guider_ui.screen_set_wifi, NULL);

	//Write style LV_PAGE_PART_BG for screen_set_wifi_ta_password_wifi
	static lv_style_t style_screen_set_wifi_ta_password_wifi_bg;
	lv_style_init(&style_screen_set_wifi_ta_password_wifi_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_ta_password_wifi_bg
	lv_style_set_radius(&style_screen_set_wifi_ta_password_wifi_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_screen_set_wifi_ta_password_wifi_bg, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_set_wifi_ta_password_wifi_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_text_color(&style_screen_set_wifi_ta_password_wifi_bg, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_set_wifi_ta_password_wifi_bg, LV_STATE_DEFAULT, &lv_font_montserrat_14);
	lv_style_set_text_letter_space(&style_screen_set_wifi_ta_password_wifi_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_set_wifi_ta_password_wifi_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_right(&style_screen_set_wifi_ta_password_wifi_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_top(&style_screen_set_wifi_ta_password_wifi_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_bottom(&style_screen_set_wifi_ta_password_wifi_bg, LV_STATE_DEFAULT, 2);
	lv_obj_add_style(guider_ui.screen_set_wifi_ta_password_wifi, LV_PAGE_PART_BG, &style_screen_set_wifi_ta_password_wifi_bg);

	//Write style LV_PAGE_PART_SCROLLABLE for screen_set_wifi_ta_password_wifi
	static lv_style_t style_screen_set_wifi_ta_password_wifi_scrollable;
	lv_style_init(&style_screen_set_wifi_ta_password_wifi_scrollable);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_ta_password_wifi_scrollable
	lv_style_set_radius(&style_screen_set_wifi_ta_password_wifi_scrollable, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_ta_password_wifi_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_ta_password_wifi_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_ta_password_wifi_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_ta_password_wifi_scrollable, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(guider_ui.screen_set_wifi_ta_password_wifi, LV_PAGE_PART_SCROLLABLE, &style_screen_set_wifi_ta_password_wifi_scrollable);

	//Write style LV_PAGE_PART_EDGE_FLASH for screen_set_wifi_ta_password_wifi
	static lv_style_t style_screen_set_wifi_ta_password_wifi_edge_flash;
	lv_style_init(&style_screen_set_wifi_ta_password_wifi_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_ta_password_wifi_edge_flash
	lv_style_set_radius(&style_screen_set_wifi_ta_password_wifi_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_ta_password_wifi_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_ta_password_wifi_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_ta_password_wifi_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_ta_password_wifi_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(guider_ui.screen_set_wifi_ta_password_wifi, LV_PAGE_PART_EDGE_FLASH, &style_screen_set_wifi_ta_password_wifi_edge_flash);
	lv_obj_set_pos(guider_ui.screen_set_wifi_ta_password_wifi, 122, 127);
	lv_obj_set_size(guider_ui.screen_set_wifi_ta_password_wifi, 200, 26);
	lv_textarea_set_text(guider_ui.screen_set_wifi_ta_password_wifi,"PASSWORD");
	lv_obj_set_event_cb(guider_ui.screen_set_wifi_ta_password_wifi, text_area_event_cb);
	lv_textarea_set_text_align(guider_ui.screen_set_wifi_ta_password_wifi, LV_LABEL_ALIGN_LEFT);

	//Write codes screen_set_wifi_label_nama_wifi
	guider_ui.screen_set_wifi_label_nama_wifi = lv_label_create(guider_ui.screen_set_wifi, NULL);
	lv_label_set_text(guider_ui.screen_set_wifi_label_nama_wifi, lv_list_get_btn_text(obj));
	lv_label_set_long_mode(guider_ui.screen_set_wifi_label_nama_wifi, LV_LABEL_LONG_BREAK);
	lv_label_set_align(guider_ui.screen_set_wifi_label_nama_wifi, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_set_wifi_label_nama_wifi
	static lv_style_t style_screen_set_wifi_label_nama_wifi_main;
	lv_style_init(&style_screen_set_wifi_label_nama_wifi_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_set_wifi_label_nama_wifi_main
	lv_style_set_radius(&style_screen_set_wifi_label_nama_wifi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_set_wifi_label_nama_wifi_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_set_wifi_label_nama_wifi_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_set_wifi_label_nama_wifi_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_set_wifi_label_nama_wifi_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_set_wifi_label_nama_wifi_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_set_wifi_label_nama_wifi_main, LV_STATE_DEFAULT, &lv_font_montserrat_18);
	lv_style_set_text_letter_space(&style_screen_set_wifi_label_nama_wifi_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_set_wifi_label_nama_wifi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_set_wifi_label_nama_wifi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_set_wifi_label_nama_wifi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_set_wifi_label_nama_wifi_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(guider_ui.screen_set_wifi_label_nama_wifi, LV_LABEL_PART_MAIN, &style_screen_set_wifi_label_nama_wifi_main);
	lv_obj_set_pos(guider_ui.screen_set_wifi_label_nama_wifi, 168, 98);
	lv_obj_set_size(guider_ui.screen_set_wifi_label_nama_wifi, 100, 0);

	lv_obj_set_event_cb(guider_ui.screen_set_wifi_btn_connect, screen_set_wifi_btn_connectevent_handler);
	lv_obj_set_event_cb(guider_ui.screen_set_wifi_btn_cancel, screen_set_wifi_btn_cancelevent_handler);
}

void events_init_screen_set_wifi(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen_set_wifi_imgbtn_back, screen_set_wifi_imgbtn_backevent_handler);
	lv_obj_set_event_cb(ui->screen_set_wifi_btn_scanwifi, screen_set_wifi_btn_scanwifievent_handler);
	//lv_obj_set_event_cb(ui->screen_set_wifi_list_ssid, screen_set_wifi_list_ssidevent_handler);
}

static void screen_menu_patroli_imgbtn_back_menuevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_del(lv_scr_act());
		setup_scr_screen_Menu(&guider_ui);
		lv_scr_load(guider_ui.screen_Menu);
	}
		break;
	default:
		break;
	}
}

static void screen_menu_patroli_imgbtn_1event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_del(lv_scr_act());
		setup_scr_screen_history(&guider_ui);
		lv_scr_load(guider_ui.screen_history);
	}
		break;
	default:
		break;
	}
}

void events_init_screen_menu_patroli(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen_menu_patroli_imgbtn_1, screen_menu_patroli_imgbtn_1event_handler);
	lv_obj_set_event_cb(ui->screen_menu_patroli_imgbtn_back_menu, screen_menu_patroli_imgbtn_back_menuevent_handler);
}

static void screen_history_imgbtn_back_patrolievent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_del(lv_scr_act());
		setup_scr_screen_menu_patroli(&guider_ui);
		lv_scr_load(guider_ui.screen_menu_patroli);
	}
		break;
	default:
		break;
	}
}

void events_init_screen_history(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen_history_imgbtn_back_patroli, screen_history_imgbtn_back_patrolievent_handler);
}

static void screen_menu_ruangan_imgbtn_back_patrolievent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_del(lv_scr_act());
		setup_scr_screen_Menu(&guider_ui);
		lv_scr_load(guider_ui.screen_Menu);
	}
		break;
	default:
		break;
	}
}

void events_init_screen_menu_ruangan(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen_menu_ruangan_imgbtn_back_patroli, screen_menu_ruangan_imgbtn_back_patrolievent_handler);
}

static void screen_set_scanid_imgbtn_back_setevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_del(lv_scr_act());
		setup_scr_screen_menu_setting(&guider_ui);
		lv_scr_load(guider_ui.screen_menu_setting);
	}
		break;
	default:
		break;
	}
}

void events_init_screen_set_scanid(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->screen_set_scanid_imgbtn_back_set, screen_set_scanid_imgbtn_back_setevent_handler);
}