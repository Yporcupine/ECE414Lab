#include "ts_getter.h"
#include "tft_master.h"

/**
short window = 40;
short width = 50;
short length = 80;
short intervalY = 5;
short intervalX = 3;
 **/

uint8_t pressNum(uint16_t x, uint16_t y){
    return (y>=0 && y<=235 && x>=40);
}

uint8_t getNum(uint16_t x, uint16_t y){
    uint8_t i;
    uint8_t j;
    uint8_t num = 1;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(inRange(x,y,50,80,3,5,40+i*50,j*80)){
                return num;
            }
            num++;
        }
    }
    if((y>=0 && y<=75) && (x>=190 && x<=237)){
        return 0;
    }
    
    return 0;
    
}

uint8_t pressOp(uint16_t x, uint16_t y){
    return (y>=240 && y<=315 && x >=40);
}


uint8_t getOp(uint16_t x, uint16_t y){
    
    uint8_t i;
    for(i=0; i<4; i++){
        if(inRange(x,y,50,80,3,5,40+i*50,240)){
                return i;
            }
    }
    return 2;
}

uint8_t equals(uint16_t x, uint16_t y){
    return ((y>=160 && y<=235) && (x>=190 && x<=237));
}


uint8_t clear(uint16_t x, uint16_t y){
    return ((y>=75 && y<=155) && (x>=190 && x<=237));
}

uint8_t inRange(uint16_t x, uint16_t y, uint16_t width, uint16_t length, 
        uint8_t intervalX, uint8_t intervalY, uint16_t startX, uint16_t startY){
    return ((x>=startX && x<=startX+width-intervalX) &&
            (y>=startY && y<=startY+length-intervalY));
}