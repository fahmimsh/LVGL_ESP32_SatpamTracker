#include <Arduino.h>
#include "Buzzer_function.h"

#define BUZZER_PIN 33
#define BUZZER_CHANNEL_PWM 5

extern bool buzzerON;
extern uint32_t BuzzerCurrentMillis;
extern uint32_t BuzzerPreviousMillis;
extern bool BuzzerPrevMillisSet;

void initBuzzer(){
  pinMode(BUZZER_PIN, OUTPUT);
  ledcSetup(BUZZER_CHANNEL_PWM, 5000, 12);
  ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL_PWM);
}

void loop_buzzer(){
  if(buzzerON){
    BuzzerCurrentMillis = millis();
    BuzzerPreviousMillis = BuzzerPrevMillisSet ? BuzzerCurrentMillis : BuzzerPreviousMillis;
    BuzzerPrevMillisSet = false;
    ledcWriteNote(BUZZER_CHANNEL_PWM, NOTE_G, 5);

    if(BuzzerCurrentMillis - BuzzerPreviousMillis >= 50){
        ledcWrite(BUZZER_CHANNEL_PWM, 0);
        buzzerON = false;
        BuzzerPrevMillisSet = true;
    }
  }
}