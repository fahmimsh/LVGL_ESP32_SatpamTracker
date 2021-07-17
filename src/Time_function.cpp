#include <Time_function.h>
#include <WiFi.h>

static tm timeinfo;
static const char* ntpServer = "pool.ntp.org";
static const long  gmtOffset_sec = 25200;
static const int   daylightOffset_sec = 0;

bool initTime(){
    if(WiFi.status() == WL_CONNECTED){
        configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
        getTime();
        return true;
    }
    return false;
}
const char* getTime(){
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return 0;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");

  return 0;
}

void getTime_tm(struct tm* var){
    if(!getLocalTime(var)){
        Serial.println("Failed to obtain time");
        return;
    }
    return;
}