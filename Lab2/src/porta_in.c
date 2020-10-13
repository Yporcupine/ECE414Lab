#include <xc.h>
#include <inttypes.h>
#include "porta_in.h"
#include <plib.h>
void porta_in_init() {
 // low-level code to
 // initialize port
    ANSELA = 0;
    TRISA = 0x1F; 
    //mPORTASetPinsDigitalIn(0x1F);
    CNPUA = 0x1F;
}
uint8_t porta_in_read() {
 // low-level code to
 // read port
    return PORTA & 0x1F;
    //mPORTARead(); //0x1F
}
