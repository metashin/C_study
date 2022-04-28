#include "timerr.h"

void initTimer(timerr_t* tr, uint16_t settingVar){
  tr->startVar = timer1ms;//this code must be here.
  uint16_t sum = tr->startVar + settingVar;

  if(settingVar == 0){
    tr->overFlowFlag = 0;
    tr->checkFlag = 0;
    tr->startVar = 0;
    tr->stopVar = 0;
    tr->outputCode = SETTING_ZERO;
  }else if(sum < timer1ms){
    tr->overFlowFlag = 1;
    tr->checkFlag = 1;
  }else{
    tr->overFlowFlag = 0;
    tr->checkFlag = 0;
  }

  tr->stopVar = sum;
  tr->outputCode = WAITING;
}
uint8_t checkTimer(timerr_t* tr){
  if(tr->outputCode != WAITING){return 1;}
  if(tr->overFlowFlag != 0){
    if(timer1ms != tr->startVar){
      tr->checkFlag = 0;
    }
    if(timer1ms < tr->startVar){
      tr->overFlowFlag = 0;
      return checkOverSum(tr);
    }
    return WAITING;
  }
  return checkOverSum(tr);
}

uint8_t checkOverSum(timerr_t* tr){
  if(tr->stopVar <= timer1ms){
    return TIME_OVER;
  }
  return WAITING;
}