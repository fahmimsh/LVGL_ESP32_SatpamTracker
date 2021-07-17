#include <ArduinoJson.h>
#include "NFC_function.h"
#include "HTTP_function.h"
#include "Time_function.h"
#include "generated/gui_guider.h"
#include "generated/events_init.h"

extern lv_ui guider_ui;
extern uint8_t stateScreen;
//NFC Variable
static const int DELAY_BETWEEN_CARDS = 1500;
static long timeLastCardRead = 0;
static boolean readerDisabled = false;
static int irqCurr;
static int irqPrev;
static uint32_t cardid;
static uint8_t strBuffer[32];

extern DynamicJsonDocument doc;

void handleCardDetected() {
    uint8_t success = false;
    uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
    uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)

    // read the NFC tag's info
    success = nfc.readDetectedPassiveTargetID(uid, &uidLength);
    Serial.println(success ? "Read successful" : "Read failed (not a card?)");

    if (success) {
      // Display some basic information about the card
      Serial.println("Found an ISO14443A card");
      Serial.print("  UID Length: ");Serial.print(uidLength, DEC);Serial.println(" bytes");
      Serial.print("  UID Value: ");
      nfc.PrintHex(uid, uidLength);
      
      if (uidLength == 4)
      {
        // We probably have a Mifare Classic card ... 
        cardid = uid[0];
        cardid <<= 8;
        cardid |= uid[1];
        cardid <<= 8;
        cardid |= uid[2];  
        cardid <<= 8;
        cardid |= uid[3]; 
        Serial.print("Seems to be a Mifare Classic card #");
        Serial.println(cardid);
      }
      Serial.println("");

      timeLastCardRead = millis();
    }

    // The reader will be enabled again after DELAY_BETWEEN_CARDS ms will pass.
    readerDisabled = true;
}

void startListeningToNFC() {
  // Reset our IRQ indicators
  irqPrev = irqCurr = HIGH;
  
  Serial.println("Waiting for an ISO14443A Card ...");
  nfc.startPassiveTargetIDDetection(PN532_MIFARE_ISO14443A);
}

void init_nfc(){
	nfc.begin();

	uint32_t versiondata = nfc.getFirmwareVersion();
	if(!versiondata){
		Serial.print("Didn't find PN532x board");
	}

	Serial.print("Found chip PN5"); Serial.println((versiondata>>24) & 0xFF, HEX); 
  	Serial.print("Firmware ver. "); Serial.print((versiondata>>16) & 0xFF, DEC); 
  	Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);

	nfc.SAMConfig();

	startListeningToNFC();
}

void loop_nfc(){
    if (readerDisabled) {
        if (millis() - timeLastCardRead > DELAY_BETWEEN_CARDS) {
        readerDisabled = false;
        startListeningToNFC();
        }
    } else {
    irqCurr = digitalRead(PN532_PIN_IRQ);

    // When the IRQ is pulled low - the reader has got something for us.
    if (irqCurr == LOW && irqPrev == HIGH) {
      Serial.println("Got NFC IRQ");  
      handleCardDetected();
      getTime();
	   if(stateScreen == STATE_SCREEN_LOGIN) {
          char tmp[100];
          sprintf((char*)tmp, HTTP_ABSEN, cardid);
          String received = String(httpGETRequest(tmp));
          Serial.println(received);
          Serial.println("Load Menu...");
          setup_scr_screen_Menu(&guider_ui);
          Serial.println("....");
          lv_scr_load(guider_ui.screen_Menu);
          Serial.println("Load Menu Berhasil");

          deserializeJson(doc, received);

          satpam.nama_satpam = doc["nama"];
          satpam.nip_satpam = doc["nip"];
          //uint32_t nip_satpam = doc["nip"];
          sprintf((char*)tmp, "%zu", satpam.nip_satpam);

          lv_label_set_text(guider_ui.screen_Login_label_nama_satpam, satpam.nama_satpam);
          lv_label_set_text(guider_ui.screen_Login_label_1, tmp);
          
          delay(2000);          
	   }

      else if(stateScreen == STATE_SCREEN_SCANID){
        sprintf((char*)strBuffer, "%ul", cardid);
        lv_textarea_set_text(guider_ui.screen_set_scanid_ta_scanid, (char*)strBuffer);
     }
    }

      else if(stateScreen == STATE_SCREEN_PATROLI){
        char tmp[100];
        sprintf((char*)tmp, HTTP_RUANG, cardid, lv_list_get_btn_text(lv_list_get_btn_selected(guider_ui.screen_menu_patroli_ddlist_status)));
        Serial.println(tmp);
      }
    irqPrev = irqCurr;
  }
}