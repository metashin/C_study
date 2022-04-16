#include "stdint.h"
#include "stdint.h"
#include "stdio.h"

#ifndef COMMP_H
  #define COMMP_H

  #ifndef uint8_t
    #define uint8_t unsigned char
  #endif
  typedef struct 
  {
    uint8_t ready;
  }CommProcess;
  
  void initCom(CommProcess* cp);
  void transmit(void);
#endif