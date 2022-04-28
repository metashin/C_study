#include "stdint.h"
#include "stdio.h"

#ifndef COMMP_H
  #define COMMP_H

  #ifndef uint8_t
    #define uint8_t unsigned char
  #endif
  
  typedef struct 
  {
    uint16_t txCount;
    uint16_t rxCount;
    uint8_t reTransCount;
  }Parameter_t;
  
  
  
  typedef struct 
  {
    uint8_t ready : 2;
    Parameter_t para;
  }CommProcess_t;

  #define READY 0
  #define TRANMITTING 1
  #define DATA_WAIT 2
  #define RECEVING 3
  
  void initCom(CommProcess_t* cp);
  void transmit(void);
#endif