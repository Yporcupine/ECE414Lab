

#include <xc.h>
#include <plib.h>
#include "ztimer.h"

static uint32_t count, elapsedCount;
static uint32_t period, targetCount;

static uint8_t zTimerFlag = 0;

#pragma interrupt InterruptHandler ipl1 vector 0
void InterruptHandler(void)
{
    // add code to set flag when we reach target
    count++;
    elapsedCount++;
    if (count == period) {
        zTimerFlag = 1;
        count = 0;
    }
    mT2ClearIntFlag();
} // Interrupt Handler

// initialize timer to set a flag every given period (in ms)
void zTimerSet(uint32_t pdms) {
    period = pdms;
}

// enable the timer and turn on the interrupt
void zTimerOn() {
    // 1. initialize timer
    PR2 = 4999;      // Timer2 periodic reset every 5000 ticks (1ms)
    T2CON = 0x8030;  // Timer2 scaling factor of 8 (200ns)
    TMR2 = 0;        // start out at 0
    count = 0;
    elapsedCount = 0;
    zTimerFlag = 0;
    // 2. initialize interrupts
    mT2SetIntPriority(1);
    INTEnableSystemSingleVectoredInt();
    mT2IntEnable(1);
}

void zTimerOff() {
    mT2IntEnable(0);
    T2CON = 0x0;  // turn off timer
}

// read and return the timer flag value
// SIDE EFFECT: clear the flag
uint8_t zTimerReadFlag() {
    if (zTimerFlag) {
        zTimerFlag = 0;
        return 1;
    } else return 0;
}

// return elapsed time in milliseconds since last call to zTimerOn
uint32_t zTimerReadms() {
    return elapsedCount;
}