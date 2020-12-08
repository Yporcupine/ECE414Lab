#ifndef PID_FSM_H
#define PID_FSM_H
#include <stdio.h>
#include <xc.h>
#include <inttypes.h>
#include "measurement.h"
#include "tft_master.h"
#include "tft_gfx.h"
#include <stdlib.h>
#include <string.h>

int target, current, prev_target, actuator, error, prev, deriv, integ, max, min;
float Kp, Ki, Kd;

extern void PID_Init();
extern void tickFct_PIDFSM(int rpm);
extern void inputCommand(char com, float num);



#endif

