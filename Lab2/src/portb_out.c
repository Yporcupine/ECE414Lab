#include <xc.h>
#include <inttypes.h>
#include "portb_out.h"
#include <plib.h>
void portb_out_init() {
 // low-level code to
 // initialize port
    ANSELB = 0;
    TRISB = 0;
    //mPORTBSetPinsAna
    //mPORTBSetPinsDigitalOut(0xFFFF);
}
void portb_out_write(uint16_t val)
{
 // low-level code to
 // write port
    uint16_t temp1 = val & 0x003F;
    uint16_t temp2 = (val & 0x07C0) << 1;
    uint16_t temp3 = (val & 0x3800) << 2;
    LATB = temp1 | temp2 | temp3;
    //temp3 = temp1 | temp2 | temp3;
    //mPORTBWrite(temp3);
}
