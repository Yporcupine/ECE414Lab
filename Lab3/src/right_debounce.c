#include <xc.h>
#include <inttypes.h>
#include "porta_in.h"

static enum out3_States{init, press, debounce}out3_States;

void right_Debounce_init()
{
    out3_States = init;
    
}

uint8_t right_Debounce()
{
    uint8_t button = porta_in_read();
    uint8_t out = 0;
    
    switch(out3_States){
        //left switch
        case init:
            if(button & 0x02){
                out3_States = press;
            }
            else{
                out3_States = init;
            }
            break;
        case press:
            out3_States = debounce;
            break;
        case debounce:
            if(!button){
                out3_States = init;
            }
            else{
                out3_States = debounce;
            }
            break;
        default:
            out3_States = init;
            break;
           
    }
    
    switch(out3_States){
        case init:
            out = 0;
            break;
        case press:
            out = 1;
            break;
        case debounce:
            out = 0;
            break;
        default:
            out = 0;
            break;
    }
            
   
    return out;

}