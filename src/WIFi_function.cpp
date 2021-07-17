#include <WiFi_function.h>
#include <Arduino.h>
#include <WiFi.h>

static WiFi_t WiFiList[10];

void initWiFi(){
    //WiFi.mode(WIFI_STA);
}

uint8_t updateWiFiList(){
    WiFi.mode(WIFI_STA);
    delay(100);
    int n = WiFi.scanNetworks();
    if(n == 0){
        Serial.println("no networks");
        *(WiFiList[0].SSID) = 0;
        return 0;
    } 
    else Serial.printf("%d jumlah wifi\r\n", n);

    for(int i = 0; i < n; i++){
        Serial.printf("%d: SSID: ", i + 1);
        Serial.println(WiFi.SSID(i).c_str());
        strcpy(WiFiList[0].SSID, WiFi.SSID(i).c_str());
    }

    Serial.println();
    return n;
}

void getWiFiIndex(WiFi_t *wifi, unsigned int i){
    wifi = &WiFiList[i];
}

const char* getWiFiSSID(unsigned int i){
    return WiFiList[i].SSID;
}

void connectWiFi(WiFi_t wifi, const char* password){
    strcpy(wifi.password, password);
    WiFi.begin(wifi.SSID, password);
}

bool isWiFiConnected(WiFi_t wifi){
    wifi.status = WiFi.status();
    if(wifi.status == WL_CONNECTED) return true;
    else return false;
}