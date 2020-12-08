#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF


//#include <plib.h>
#include <xc.h>
#include <inttypes.h>
//#include "tft_master.h"
//#include "uart1.h" 
#include "ztimer.h"
#include "ic1.h"
#include "oc1.h"
#include "measurement.h"
#include "PID_FSM.h"



int main() { 
    zTimerSet(10);
    zTimerOn();
    PID_Init();
    ic1_init();
    oc1_init_plib(0x8000);
    display_init();
    display_plot();
    int rpm = 0;
    int rpm_p = 0;
    while(1) {
        if (zTimerReadFlag()) {
            rpm_p = ic1_getrpm();
            if(rpm_p != 0) rpm = (int)(1.0*178890/rpm_p);
            else rpm = 0;
            tickFct_PIDFSM(rpm);
        }
    }
}