#include "stdint.h"

extern uint16_t timer1ms;
#ifndef TIMERR_H
  #define TIMERR_H

  #ifndef uint8_t
    #define uint8_t unsigned char
  #endif
  
  #define NOT_USE 0
  #define WAITING 1
  #define TIME_OVER 2
  #define SETTING_ZERO 3

  typedef struct {
    uint16_t stopVar;
    uint16_t startVar;
    uint8_t overFlowFlag:1;
    uint8_t checkFlag:1;
    uint8_t outputCode:6;
  }timerr_t;
  void initTimer(timerr_t* tr, uint16_t settingVar);
  uint8_t checkTimer(timerr_t* tr);
  uint8_t checkOverSum(timerr_t* tr);
#endif