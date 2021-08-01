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

  //Serial.println(payload);
  
  deserializeJson(doc, payload);
  const char* strLokasi = doc["lokasi"];
  Serial.println(strLokasi);

  return strLokasi;
}

uint16_t httpGETHistory(Lokasi_t *lokasi){
  char url[255];
  sprintf(url, HTTP_SUMMARY, satpam.nip_satpam);
  const char* payload = httpGETRequest(url);
  Serial.println(payload);
  deserializeJson(doc, payload);

  uint16_t sz = doc.size();
  
  for(int i = 0; i < doc.size(); i++){
    lokasi[i].nama_lokasi = doc[i]["Lokasi"];
    Serial.println(String("Lokasi: ") + String(lokasi[i].nama_lokasi));
    lokasi[i].status = doc[i]["Status"];
    Serial.println(String("Status: ") + String(lokasi[i].status));
  }

  return sz;


  //JsonArray arrayLokasi = doc.to<JsonArray>();

  /*JsonArray arrayLokasi = doc[];

  int i = 0;

  for(JsonVariant v : arrayLokasi){
    lokasi[i].nama_lokasi =  v.as<const char*>();
    i++;
  }*/
}