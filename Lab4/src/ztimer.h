#ifndef ZTIMER_H
#define ZTIMER_H
#include <xc.h>
#include <inttypes.h>
#include <plib.h>
extern void zTimerSet();
extern void zTimerOn();
extern uint8_t zReadTimerFlag();
#endif