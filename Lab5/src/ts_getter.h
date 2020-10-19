#ifndef _TS_GETTER_H
#define _TS_GETTER_H

#include <xc.h>
#include <inttypes.h>

extern uint8_t pressNum(uint16_t x, uint16_t y);
extern uint8_t pressOp(uint16_t x, uint16_t y);
extern uint8_t getNum(uint16_t x, uint16_t y);
extern uint8_t getOp(uint16_t x, uint16_t y);
extern uint8_t equals(uint16_t x, uint16_t y);
extern uint8_t clear(uint16_t x, uint16_t y);
extern uint8_t inRange(uint16_t x, uint16_t y, uint16_t width, uint16_t length, 
        uint8_t intervalX, uint8_t intervalY, uint16_t startX, uint16_t startY); 


#endif

