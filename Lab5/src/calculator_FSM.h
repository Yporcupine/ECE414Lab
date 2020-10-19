#ifndef CALCULATOR_FSM_H
#define CALCULATOR_FSM_H

#include "ts_lcd.h"
#include "ts_getter.h"
#include "tft_master.h"
#include <stdio.h>

extern void init_Calc();
extern void tickFunct_Calc(uint16_t x, uint16_t y, uint8_t press);
extern void calculate(uint8_t op);


#endif