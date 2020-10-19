
#include "calculator_FSM.h"
static enum Calc_States {start, opA, operator, opB, Equals, divError, Overflow}Calc_State;

int64_t A;
int64_t B;
int64_t C;
uint8_t op;
uint8_t div_0;
uint8_t finish;
uint8_t reenterO;
uint8_t overflow;
char buffer3[30];

void init_Calc(){
    SYSTEMConfigPerformance(PBCLK);
    
    configureADC();
    
    //initialize screen
    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9341_BLACK); 
    
    //initialize LCD driver
    ts_lcd_init();
    
    //initialize FSM
    Calc_State = start;
    A = 0;
    B = 0;
    C = 1;
    op = 0;
    finish = 0;
    reenterO = 0;
    
    div_0 = 0;
    overflow = 0;
}


void tickFunct_Calc(uint16_t x, uint16_t y, uint8_t press){
    
    //Transitions
    switch(Calc_State){
        case(start):
            if(pressNum(x,y)){
                Calc_State = opA;
            }else{
                Calc_State = start;
            }
            break;
         
        case(opA):
            if(pressOp(x,y)){
                Calc_State = operator;
            }else if(clear(x,y)){
                Calc_State = start;
            }else if(overflow){
                Calc_State = Overflow;
            }else{
                Calc_State = opA;
            }
            break;
          
        case(operator):
            if(div_0){
                Calc_State = divError;
            }else if(clear(x,y)){
                Calc_State = start;
            }else if(overflow){
                Calc_State = Overflow;
            }else if(pressNum(x,y)){
                Calc_State = opB;
            }else{
                Calc_State = operator;
            }
            break;
        case(opB):
            if(pressOp(x,y)){
                Calc_State = operator;
            }else if(clear(x,y)){
                Calc_State = start;
            }else if(equals(x,y)){
                Calc_State = Equals;
            }else if(overflow){
                Calc_State = Overflow;
            }else{
                Calc_State = opB;
            }
            break;
        case(Equals):
            if(div_0){
                Calc_State = divError;
            }else if(overflow){
                Calc_State = Overflow;
            }else if(clear(x,y)){
                Calc_State = start;
            }else{
                Calc_State = Equals;
            }
            break;
        case(divError):
            if(clear(x,y)){
                Calc_State = start;
            }else{
                Calc_State = divError;
            }
            break;
        case(Overflow):
            if(clear(x,y)){
                Calc_State = start;
            }else{
                Calc_State = Overflow;
            }
            break;
             
        default:
            break;
    
    }
    
    //Actions
    switch(Calc_State){
        case(start):
            A = 0;
            B = 0;
            C = 1;
            op = 0;
            div_0 = 0;
            overflow = 0;
            finish = 0; 
            reenterO = 0;
            sprintf(buffer3, "%d", A);
            tft_writeString(buffer3);
            break;
        case(opA):
            if(press){
                A = A*10 + (int32_t)getNum(x,y);
            }
            checkOverFlow(A);
            if(!overflow) sprintf(buffer3, "%d", A);
            tft_writeString(buffer3);
            break;
        case(operator):
            if(!reenterO){
                op = getOp(x,y);
                reenterO = 1;
            }
            if(press && !finish){
                calculate(op);
                finish = 1; 
            }
            if(reenterO) op = getOp(x,y);
            sprintf(buffer3, "%d", A);
            tft_writeString(buffer3);
            break;
        case(opB):
            if(press){
                B = B*10 + (int32_t)getNum(x,y);
            }
            C = B;
            finish = 0;
            checkOverFlow(C);
            if(!overflow) sprintf(buffer3, "%d", C);
            tft_writeString(buffer3);
            break;
        case(Equals):
            if(press && !finish){
                calculate(op);
                finish = 1;
            }
            sprintf(buffer3, "%d",A);
            tft_writeString(buffer3);
            break;
        case(divError):
            sprintf(buffer3, "DIV0 ERROR");
            tft_writeString(buffer3);
            break;
        case(Overflow):
            sprintf(buffer3, "OVERFLOW");
            tft_writeString(buffer3);
            break;
    }
    
    
    
}


void calculate(uint8_t op){
    switch(op){
        case(0):
            A = A + B;
            B = 0;
            checkOverFlow(A);
            break;
        case(1):
            A = A - B;
            B = 0;
            checkOverFlow(A);
            break;
        case(2):
            A = A * C;
            B = 0;
            checkOverFlow(A);
            break;
        case(3):
            if(C == 0) div_0 = 1;
            else{
                A = A / C;
                B = 0;
                checkOverFlow(A);
            }
            break;
        default:
            break;
    }
}

void checkOverFlow(int64_t v){
    if((v > (int64_t)INT32_MAX) || (v < (int64_t)INT32_MIN)) overflow = 1;
}