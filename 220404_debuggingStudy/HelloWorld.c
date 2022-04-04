#include "stdio.h"
#include "stdint.h"

int main(void){
    int8_t i =0;
    for(i=0;i<10;i++){
        printf("%d\r\n",10-i);    
    }
    printf("hello world!!");
    return 0;
}