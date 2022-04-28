#include "stdio.h"
#include "stdint.h"

#include "main.h"
#include "timerr.h"
timerr_t t1 = {0,};
int main(void){

  
  for(uint16_t caseN = 65534; caseN != 0xFFFF; caseN++){
    for(uint16_t testTime=0;testTime!=0xFFFF;testTime++){
      timer1ms=caseN;//end test, overFlow = 0;
      initTimer(&t1,testTime);
    
      for(uint8_t i =0; i<2; i++){
        if(t1.outputCode != WAITING){break;}
        do{
          //printf("%d, overflowFlag : %d, stopVar : %d \r\n",timer1ms,t1.overFlowFlag,t1.stopVar);
          t1.outputCode = checkTimer(&t1);
          if(t1.outputCode != WAITING){break;}
          timer1ms++;
          //test code skip the Zero(0)
          if(timer1ms == 0){
            timer1ms+=2;
          }
        }while(timer1ms != 0);
      }
      if((timer1ms>65531)||(timer1ms<4)){
        printf("Case N: %d, testTime: %d \r\n",caseN,testTime);
        printf("Check Point : %d, overflowFlag : %d, stopVar : %d \r\n",timer1ms,t1.overFlowFlag,t1.stopVar);
      }
    }
  }
  return 0;
}