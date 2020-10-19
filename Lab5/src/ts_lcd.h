#include <xc.h>
#include <inttypes.h>
#include "plib.h"

#ifndef TS_LCD_H    
#define TS_LCD_H

extern uint8_t ts_lcd_get_ts(uint16_t *x, uint16_t *y);
extern void ts_lcd_init();

#endif 