#include "commP.h"

CommProcess_t dummyCp;
extern uint8_t* txDataPtr;
extern uint8_t* txEndPtr;

void initCom(CommProcess_t* cp){
  cp->ready = READY;
  cp->para.txCount = 0; // no use
  cp->para.rxCount = 0;
  cp->para.reTransCount = 0;
}
void initTimer(CommProcess_t cp){
  
}

void transmit(void){
  printf("hello");
}
void sendData(uint8_t* data, uint16_t n){
  txDataPtr = data;
  txEndPtr = &data[n];
}