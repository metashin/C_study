#include "stdio.h"
#include "stdint.h"

#include "main.h"
#include "commP.h"

/*
 notice : 
  1개의 하드웨어 UART를 이용하여 SPI와 UART를 섞어서 통신하는 상태.
  이 장치에는
  Uart로 n개의 장치가 연결되어 있고,
  SPI로 m개의 장치가 연결되어 있다. 
*/
#define TX_BUF_SIZE 256
#define RX_BUF_SIZE 1024

CommProcess_t commUart;
CommProcess_t commSpi;

uint8_t txBufCommP[TX_BUF_SIZE]={0,};
uint8_t rxBufCommP[RX_BUF_SIZE]={0,};

uint8_t txDataPtrDummy=0;
uint8_t counterDummy=0;
uint8_t* txDataPtr = (uint8_t*) &txDataPtrDummy;
uint8_t* txEndPtr = (uint8_t*) &counterDummy;

void msgSend(void){
  //ISR 대용
  //UART Tx Complete ISR 의사함수
  if(txDataPtr == &txDataPtrDummy){return;}
  printf("%c:0x%.2X,  ",*txDataPtr,*txDataPtr);
  txDataPtr++;
  if(txDataPtr > txEndPtr){
    txDataPtr = &txDataPtrDummy;
  }
}

int main(void){
  //initVar();
  initCom(&commUart);
  txBufCommP[0] = 'h';
  txBufCommP[1] = 'e';
  txBufCommP[2] = 'l';
  txBufCommP[3] = 'l';
  txBufCommP[4] = 'o';
  sendData(txBufCommP,5);
  while(1){
    msgSend();
  }

  return 0;
}