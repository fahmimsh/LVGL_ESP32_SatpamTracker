#ifndef __NFC_FUNCTION__
#define __NFC_FUNCTION__

#include <Adafruit_PN532.h>

#define PN532_PIN_IRQ 16
#define PN532_PIN_RESET 17

extern Adafruit_PN532 nfc;

void handleCardDetected();
void startListeningToNFC();
void init_nfc();
void loop_nfc();

#endif