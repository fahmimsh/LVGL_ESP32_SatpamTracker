#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <generated/gui_guider.h>
#include "HTTP_function.h"

extern DynamicJsonDocument doc;

const char* httpGETRequest(const char* serverName) {
  HTTPClient http;
     
  // Your IP address with path or Domain name with URL path 
  http.begin(serverName);
   
  // Send HTTP POST request
  int httpResponseCode = http.GET();
   
  String *payload = new String(""); 
   
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    *(payload) = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
    *(payload) = String(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload->c_str();
}

const char* httpGETLokasi(){
  char url[100];
  const char* payload;

  sprintf(url, HTTP_TUGAS, satpam.nip_satpam);
  payload = httpGETRequest(url);

  Serial.println(payload);

  return payload;
}

void getLokasi(Lokasi_t *lokasi){
  const char* payload = httpGETLokasi();

  deserializeJson(doc, payload);
  //JsonArray arrayLokasi = doc.to<JsonArray>();

  JsonArray arrayLokasi = doc["lokasi"];

  int i = 0;

  for(JsonVariant v : arrayLokasi){
    lokasi[i].nama_lokasi =  v.as<const char*>();
    i++;
  }
}