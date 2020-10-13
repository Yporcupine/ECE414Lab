#ifndef BALL_FSM_H
#define BALL_FSM_H
#include <inttypes.h>
#include "portb_out.h"
extern void init_Ball();
extern void tickFct_Ball(uint8_t count, uint16_t *period, uint8_t reset, uint8_t left_press,
 uint8_t right_press);
#endif