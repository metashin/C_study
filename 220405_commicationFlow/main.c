#include "stdio.h"
#include "stdint.h"

#include "main.h"
#include "commP.h"

CommProcess commP;

int main(void){
//  initVar();
//  initCom(&commP);
  int8_t i =0;
    for(i=0;i<10;i++){
        printf("%d\r\n",10-i); 
        
        printf("%d\r\n",9-i);   
    }
  transmit();
/*  commP.ready = 0;
  while (1)
  {
    if(commP.ready != 0){
        transmit();
    }
  } 
  */
  return 0;
}