#ifndef __WIFI_FUNCTION_H__
#define __WIFI_FUNCTION_H__

#ifdef __cplusplus
extern "C"{
#endif
#include <stdint.h>

typedef struct {
    char SSID[32];
    uint8_t RSSI;
    char* password;
    uint8_t status;
} WiFi_t;

void initWiFi();
uint8_t updateWiFiList();
void getWiFiIndex(WiFi_t *wifi, unsigned int i);
void connectWiFi(WiFi_t wifi, const char* password);
const char* getWiFiSSID(unsigned int i);
bool isWiFiConnected(WiFi_t wifi);

#ifdef __cplusplus
}
#endif

#endif