#include <xc.h>
#include <inttypes.h>
#include "portb_out.h"


static enum Ball_States { Ball_SMStart, Ball_init, Ball_leftserve, Ball_rightserve, 
Ball_leftshift, Ball_rightshift, Ball_leftloss, Ball_rightloss, Ball_flashleft,
Ball_flashright}Ball_State;

//variables
uint8_t i;
uint8_t ball;
uint8_t dir;


void init_Ball(){
    Ball_State = Ball_SMStart;
    portb_out_init();
}



void tickFct_Ball(uint8_t count, uint16_t *period, uint8_t reset, uint8_t left_press,
 uint8_t right_press)
{
   
    //reset
    if(reset){
        Ball_State = Ball_SMStart;
    }
    
    //Transition 
    switch (Ball_State) {
        case Ball_SMStart:
            Ball_State = Ball_init;
            break;
        case Ball_init:
            if(!dir){
                Ball_State = Ball_leftserve;
            }else{
                Ball_State = Ball_rightserve;
            }
            break;
        case Ball_leftserve:
            if(left_press){
                Ball_State = Ball_rightshift;
            }else{
                Ball_State = Ball_leftserve;
            }
            break;
        case Ball_rightserve:
            if(right_press){
                Ball_State = Ball_leftshift;
            }else{
                Ball_State = Ball_rightserve;
            }
            break;
        case Ball_leftshift:
            if((ball==0x80) && left_press){
                Ball_State = Ball_rightshift;
            }else if(right_press){
                Ball_State = Ball_rightloss;
            }else if((ball==0x80)^left_press){
                Ball_State = Ball_leftloss;
            }else{
                Ball_State = Ball_leftshift;
            }
            break;
        case Ball_rightshift:
            if((ball == 0x01) && right_press){
                Ball_State = Ball_leftshift;
            }else if(left_press){
                Ball_State = Ball_leftloss;
            }else if((ball == 0x01)^right_press){
                Ball_State = Ball_rightloss;
            }else{
                Ball_State = Ball_rightshift;
            }
            break;
        case Ball_leftloss:
            Ball_State = Ball_flashleft;
            break;
        case Ball_rightloss:
            Ball_State = Ball_flashright;
            break;
        case Ball_flashleft:
            if(i<3){
                Ball_State = Ball_leftloss;
            }else{
                Ball_State = Ball_init;
            }
            break;
        case Ball_flashright:
            if(i<3){
                Ball_State = Ball_rightloss;
            }else{
                Ball_State = Ball_init;
            }
            break;
        default:
            Ball_State = Ball_SMStart;
            break;
    }
    
     //Action
    switch(Ball_State){
        case Ball_SMStart:
            ball = 0xFF;
            portb_out_write(ball);
            break;
        case Ball_init:
            dir = count & 0x01;
            i = 0;
            *period = 300;
            ball = 0;
            portb_out_write(ball);
            break;
        case Ball_leftserve:
            ball = 0x80;
            portb_out_write(ball);
            break;
        case Ball_rightserve:
            ball = 0x01;
            portb_out_write(ball);
            break;
        case Ball_leftshift:
            ball = ball << 1;
            portb_out_write(ball);
            if(*period > 100){
                *period = *period - 5;
            }
            break;
        case Ball_rightshift:
            ball = ball >> 1;
            portb_out_write(ball);
            if(*period > 100){
                *period = *period - 5;
            }
            break;
        case Ball_leftloss:
            ball = 0;//0x00
            portb_out_write(ball);
            break;
        case Ball_rightloss:
            ball = 0;//0x00
            portb_out_write(ball);
            break;
        case Ball_flashleft:
            ball = 0x80;
            portb_out_write(ball);
            i++;
            break;
        case Ball_flashright:
            ball = 0x01;
            portb_out_write(ball);
            i++;
            break;
        default:
            ball = 0;
            i = 0;
            break;
    }
   
}










