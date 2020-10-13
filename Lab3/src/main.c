#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#include <xc.h>
#include <stdio.h>
#include <inttypes.h>
#include "ball_fsm.h"
#include "left_debounce.h"
#include "right_debounce.h"
#include "reset_debounce.h"
#include "portb_out.h"
#include "porta_in.h"
#include "timer1.h"

main(){
    
    uint16_t t1, t2;
    uint16_t period = 300;
    uint8_t count = 0;
    uint8_t reset, left_press, right_press;
    timer1_init();
    init_Ball();
    reset_Debounce_init();
    right_Debounce_init();
    left_Debounce_init();
    t1 = timer1_read();
    while (1) {
        t2 = timer1_read();
        count++;
        if (timer1_elapsed_ms(t1, t2) >= period) {
            t1 = t2;
            reset = reset_Debounce();
            left_press = left_Debounce();
            right_press = right_Debounce();
            tickFct_Ball(count, &period, reset, left_press, right_press);
        }
        
    }
     
    
    return (EXIT_SUCCESS);
}


