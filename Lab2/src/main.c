
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#include <xc.h>
#include <inttypes.h>
#include "porta_in.h"
#include "portb_out.h"


uint16_t output(uint8_t in){
    uint16_t out;
    out = 0;
    switch(in){
        case 0x01: 
            out = 0x0001;
            break;
        case 2: 
            out = 0x0002;
            break;
        case 3: 
            out = 0x0004;
            break;
        case 4: 
            out = 0x0008;
            break;
        case 5: 
            out = 0x0010;
            break;
        case 6: 
            out = 0x0020;
            break;
        case 7: 
            out = 0x0040;
            break;
        case 8: 
            out = 0x0080;
            break;
        case 9: 
            out = 0x0100;
            break;
        case 10: 
            out = 0x0200;
            break;
        case 11: 
            out = 0x0400;
            break;
        case 12: 
            out = 0x0800;
            break;
        case 13: 
            out = 0x1000;
            break;
        case 14: 
            out = 0x2000;
            break;
        default: 
            out = 0;  
            break;
    }
    
    return out;
         
}

main() {
 uint8_t in;
 uint16_t out;
 porta_in_init();
 portb_out_init();
 
 in = 0;
 out = 0;
 
 while (1) {
    
     in = porta_in_read();
     
             
     if(!(in & 0x10)){
         out = output(in);
     }else{
         out = ~output(in);
     }
     
  
    
     portb_out_write(out);
    
 }
}
