/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "lvgl.h"
#include "guider_fonts/guider_fonts.h"

enum STATE_SCREEN{
    STATE_SCREEN_LOGIN = 0,
    STATE_SCREEN_MENU = 1,
    STATE_SCREEN_PATROLI = 2,
    STATE_SCREEN_RUANGAN = 3,
    STATE_SCREEN_SETTING = 4,
    STATE_SCREEN_SCANID = 5,
    STATE_SCREEN_WIFI = 6,
    STATE_SCREEN_HISTORY = 7
};

typedef struct
{
	lv_obj_t *screen_Login;
	lv_obj_t *screen_Login_tileview_1;
	lv_obj_t *screen_Login_tileview_1_tileview;
	lv_obj_t *screen_Login_tileview_2;
	lv_obj_t *screen_Login_tileview_2_tileview;
	lv_obj_t *screen_Login_tileview_3;
	lv_obj_t *screen_Login_tileview_3_tileview;
	lv_obj_t *screen_Login_bar_1;
	lv_obj_t *screen_Login_bat_status;
	lv_obj_t *screen_Login_charger_status;
	lv_obj_t *screen_Login_label_tanggal;
	lv_obj_t *screen_Login_label_jam;
	lv_obj_t *screen_Login_img_1;
	lv_obj_t *screen_Login_label_nama;
	lv_obj_t *screen_Login_label_nama_satpam;
	lv_obj_t *screen_Login_label_nip;
	lv_obj_t *screen_Login_label_1;
	lv_obj_t *screen_Menu;
	lv_obj_t *screen_Menu_tileview_1;
	lv_obj_t *screen_Menu_tileview_1_tileview;
	lv_obj_t *screen_Menu_label_menu_logout;
	lv_obj_t *screen_Menu_img_menu_logout;
	lv_obj_t *screen_Menu_img_menu_logout_label;
	lv_obj_t *screen_Menu_tileview_2;
	lv_obj_t *screen_Menu_tileview_2_tileview;
	lv_obj_t *screen_Menu_bar_1;
	lv_obj_t *screen_Menu_bat_status;
	lv_obj_t *screen_Menu_charger_status;
	lv_obj_t *screen_Menu_label_tanggal;
	lv_obj_t *screen_Menu_label_jam;
	lv_obj_t *screen_Menu_img_menu_patroli;
	lv_obj_t *screen_Menu_img_menu_patroli_label;
	lv_obj_t *screen_Menu_img_menu_setting;
	lv_obj_t *screen_Menu_img_menu_setting_label;
	lv_obj_t *screen_Menu_imgbtn_1;
	lv_obj_t *screen_Menu_imgbtn_1_label;
	lv_obj_t *screen_Menu_label_menu_patroli;
	lv_obj_t *screen_Menu_label_menu_setting;
	lv_obj_t *screen_Menu_label_menu_listRoom;
	lv_obj_t *screen_Menu_msgbox_Logout;
	lv_obj_t *screen_menu_ruangan;
	lv_obj_t *screen_menu_ruangan_tileview_1;
	lv_obj_t *screen_menu_ruangan_tileview_1_tileview;
	lv_obj_t *screen_menu_ruangan_tileview_2;
	lv_obj_t *screen_menu_ruangan_tileview_2_tileview;
	lv_obj_t *screen_menu_ruangan_bar_1;
	lv_obj_t *screen_menu_ruangan_bat_status;
	lv_obj_t *screen_menu_ruangan_charger_status;
	lv_obj_t *screen_menu_ruangan_label_tanggal;
	lv_obj_t *screen_menu_ruangan_label_jam;
	lv_obj_t *screen_menu_ruangan_table_history;
	lv_obj_t *screen_menu_ruangan_imgbtn_back_patroli;
	lv_obj_t *screen_menu_ruangan_imgbtn_back_patroli_label;
	lv_obj_t *screen_history;
	lv_obj_t *screen_history_tileview_1;
	lv_obj_t *screen_history_tileview_1_tileview;
	lv_obj_t *screen_history_tileview_2;
	lv_obj_t *screen_history_tileview_2_tileview;
	lv_obj_t *screen_history_bar_1;
	lv_obj_t *screen_history_bat_status;
	lv_obj_t *screen_history_charger_status;
	lv_obj_t *screen_history_label_tanggal;
	lv_obj_t *screen_history_label_jam;
	lv_obj_t *screen_history_table_history;
	lv_obj_t *screen_history_imgbtn_back_patroli;
	lv_obj_t *screen_history_imgbtn_back_patroli_label;
	lv_obj_t *screen_menu_patroli;
	lv_obj_t *screen_menu_patroli_tileview_1;
	lv_obj_t *screen_menu_patroli_tileview_1_tileview;
	lv_obj_t *screen_menu_patroli_imgbtn_1;
	lv_obj_t *screen_menu_patroli_imgbtn_1_label;
	lv_obj_t *screen_menu_patroli_tileview_2;
	lv_obj_t *screen_menu_patroli_tileview_2_tileview;
	lv_obj_t *screen_menu_patroli_tileview_3;
	lv_obj_t *screen_menu_patroli_tileview_3_tileview;
	lv_obj_t *screen_menu_patroli_bar_1;
	lv_obj_t *screen_menu_patroli_bat_status;
	lv_obj_t *screen_menu_patroli_charger_status;
	lv_obj_t *screen_menu_patroli_label_tanggal;
	lv_obj_t *screen_menu_patroli_label_jam;
	lv_obj_t *screen_menu_patroli_label_nama;
	lv_obj_t *screen_menu_patroli_label_nama_satpam;
	lv_obj_t *screen_menu_patroli_label_nip;
	lv_obj_t *screen_menu_patroli_label_nip_satpam;
	lv_obj_t *screen_menu_patroli_label_lokasi;
	lv_obj_t *screen_menu_patroli_label_lokasi_patroli;
	lv_obj_t *screen_menu_patroli_label_ket_Scan_id_card;
	lv_obj_t *screen_menu_patroli_led_Tap_ID_card;
	lv_obj_t *screen_menu_patroli_label_status_patroli;
	lv_obj_t *screen_menu_patroli_ddlist_status;
	lv_obj_t *screen_menu_patroli_imgbtn_back_menu;
	lv_obj_t *screen_menu_patroli_imgbtn_back_menu_label;
	lv_obj_t *screen_menu_patroli_arc_1;
	lv_obj_t *screen_menu_patroli_img_indikasi_Patroli_Selesai;
	lv_obj_t *screen_menu_setting;
	lv_obj_t *screen_menu_setting_tileview_1;
	lv_obj_t *screen_menu_setting_tileview_1_tileview;
	lv_obj_t *screen_menu_setting_btn_cek_idcard;
	lv_obj_t *screen_menu_setting_btn_cek_idcard_label;
	lv_obj_t *screen_menu_setting_tileview_2;
	lv_obj_t *screen_menu_setting_tileview_2_tileview;
	lv_obj_t *screen_menu_setting_bar_1;
	lv_obj_t *screen_menu_setting_bat_status;
	lv_obj_t *screen_menu_setting_charger_status;
	lv_obj_t *screen_menu_setting_label_tanggal;
	lv_obj_t *screen_menu_setting_label_jam;
	lv_obj_t *screen_menu_setting_imgbtn_back_menu;
	lv_obj_t *screen_menu_setting_imgbtn_back_menu_label;
	lv_obj_t *screen_menu_setting_label_kecerahan;
	lv_obj_t *screen_menu_setting_slider_kecerahan;
	lv_obj_t *screen_menu_setting_label_volume_buz;
	lv_obj_t *screen_menu_setting_slider_vol_buz;
	lv_obj_t *screen_menu_setting_btn_set_wifi;
	lv_obj_t *screen_menu_setting_btn_set_wifi_label;
	lv_obj_t *screen_set_scanid;
	lv_obj_t *screen_set_scanid_tileview_1;
	lv_obj_t *screen_set_scanid_tileview_1_tileview;
	lv_obj_t *screen_set_scanid_tileview_2;
	lv_obj_t *screen_set_scanid_tileview_2_tileview;
	lv_obj_t *screen_set_scanid_bar_1;
	lv_obj_t *screen_set_scanid_bat_status;
	lv_obj_t *screen_set_scanid_charger_status;
	lv_obj_t *screen_set_scanid_label_tanggal;
	lv_obj_t *screen_set_scanid_label_jam;
	lv_obj_t *screen_set_scanid_imgbtn_back_set;
	lv_obj_t *screen_set_scanid_imgbtn_back_set_label;
	lv_obj_t *screen_set_scanid_label_set_scanid;
	lv_obj_t *screen_set_scanid_ta_scanid;
	lv_obj_t *screen_set_wifi;
	lv_obj_t *screen_set_wifi_tileview_1;
	lv_obj_t *screen_set_wifi_tileview_1_tileview;
	lv_obj_t *screen_set_wifi_tileview_2;
	lv_obj_t *screen_set_wifi_tileview_2_tileview;
	lv_obj_t *screen_set_wifi_bar_1;
	lv_obj_t *screen_set_wifi_bat_status;
	lv_obj_t *screen_set_wifi_charger_status;
	lv_obj_t *screen_set_wifi_label_tanggal;
	lv_obj_t *screen_set_wifi_label_jam;
	lv_obj_t *screen_set_wifi_btn_connect_wifi;
	lv_obj_t *screen_set_wifi_btn_connect_wifi_label;
	lv_obj_t *screen_set_wifi_btn_scanwifi;
	lv_obj_t *screen_set_wifi_btn_scanwifi_label;
	lv_obj_t *screen_set_wifi_label_ssid;
	lv_obj_t *screen_set_wifi_list_ssid;
	lv_obj_t *screen_set_wifi_ta_password;
	lv_obj_t *screen_set_wifi_label_password;
	lv_obj_t *screen_set_wifi_imgbtn_back;
	lv_obj_t *screen_set_wifi_imgbtn_back_label;
	lv_obj_t *screen_set_wifi_cont_connect_wifi;
	lv_obj_t *screen_set_wifi_btn_connect;
	lv_obj_t *screen_set_wifi_btn_connect_label;
	lv_obj_t *screen_set_wifi_btn_cancel;
	lv_obj_t *screen_set_wifi_btn_cancel_label;
	lv_obj_t *screen_set_wifi_ta_password_wifi;
	lv_obj_t *screen_set_wifi_label_nama_wifi;
}lv_ui;

typedef struct {
  const char* nama_satpam;
  uint32_t nip_satpam;
  bool status_absen;
} Satpam_t;

extern lv_ui guider_ui;
extern Satpam_t satpam;

void setup_ui(lv_ui *ui);
void setup_scr_screen_Login(lv_ui *ui);
void setup_scr_screen_Menu(lv_ui *ui);
void setup_scr_screen_menu_ruangan(lv_ui *ui);
void setup_scr_screen_history(lv_ui *ui);
void setup_scr_screen_menu_patroli(lv_ui *ui);
void setup_scr_screen_menu_setting(lv_ui *ui);
void setup_scr_screen_set_scanid(lv_ui *ui);
void setup_scr_screen_set_wifi(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif