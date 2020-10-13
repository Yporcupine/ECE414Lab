#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#include <xc.h>
#include <inttypes.h>
#include "uart1.h"
#include <stdio.h> 
#include "ztimer.h"
#include "test.h"

#define NUM_ITERATIONS 100000
#define NUM_REPS 10


const uint32_t baudrate = 9600;
char c;
char str[] = "Hello: Lab Partners GuoYuan and Harry!\r\n";
uint8_t buffer[64];



void task1()
{
    uart1_init(baudrate);
    uart1_txwrite_str(str);
    while(1){
        c = uart1_rxread();
        if((c >='a' && c<='z') || (c >= 'A' && c<= 'Z')){
            if(c > 'Z'){
                c -= 0x20;
            }else{
                c += 0x20;
            }
        }
        uart1_txwrite_str('\r\n');
        uart1_txwrite(c);
        uart1_txwrite('\r\n');
    }
    
}


void task2()
{
    uint8_t j, k;
    uint32_t t1, t2;
    // !!! Add code: Initialize modules and turn on interrupts
    uart1_init(baudrate);
    zTimerOn();
    zTimerSet(1);
    uart1_txwrite_str("Performance Summary: Time per operation statistics\r\n");
    // Test multiplying bytes
    for(j=0; j<4; j++){
        t1 = zTimerReadms();
        operation_d(j,NUM_ITERATIONS);
        t2 = zTimerReadms();
        sprintf(buffer, "task double: %.06f us per operation\r\n",(double)(t2-t1)/ (double)NUM_ITERATIONS /(double)NUM_REPS*1000.0);
        uart1_txwrite_str(buffer);
    }
    
    while (1);
}

int main()
{
    //task1();
    task2();
}