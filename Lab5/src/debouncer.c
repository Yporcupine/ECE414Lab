


#include <xc.h>
#include <inttypes.h>


static enum deb_States{init, pressed, debounce} deb_State;

void Debounce_init()
{
    deb_State = init;
    
}

uint8_t tickFunct_Debounce(uint8_t press)
{
       
    uint8_t out; 
    switch(deb_State){
        //left switch
        case init:
            if(press){
                deb_State = pressed;
            }
            else{
                deb_State = init;
            }
            break;
        case pressed:
            deb_State = debounce;
            break;
        case debounce:
            if(!press){
                deb_State = init;
            }
            else{
                deb_State = debounce;
            }
            break;
        default:
            deb_State = init;
            break;
           
    }
    
    switch(deb_State){
        case init:
            out = 0;
            break;
        case pressed:
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