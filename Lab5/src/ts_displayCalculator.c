#include "ts_lcd.h"
#include "tft_gfx.h"
#include "tft_master.h"
#include "TouchScreen.h"
#include "ts_displayCalculator.h"
#include "ts_getter.h"
#include <stdio.h>



short window = 40;
short width = 50;
short length = 80;
short intervalY = 5;
short intervalX = 3;
uint8_t dis;
uint8_t num;
uint8_t digit;
uint8_t operator;
char buffer1[5];


void ts_displayCalc()
{
    uint8_t i;
    uint8_t j;
    short y;
    short x;
    unsigned short color;
    num = 1;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(j < 3){
                if(j == 1 && i == 3){
                    color = ILI9341_RED;
                    string(5);
                }else if(j == 2 && i == 3){
                    color = ILI9341_BLUE;
                    string(6);
                }else{
                    color = ILI9341_WHITE;
                    string(0);
                }
            }else{
                color = ILI9341_GREEN;
                string(i+1);
                num--;
            }
            y = length * j;
            x = window + width * i;
            tft_fillRect(y, x, length - intervalY, width - intervalX, color);
            tft_setCursor(y+(length-intervalY)/3, x+(width-intervalX)/3);
            tft_setTextColor(ILI9341_BLACK);
            tft_setTextSize(3);
            tft_writeString(buffer1);
            num = num<9? num+1 : 0;
        }
    }
        
}

void string(uint8_t dis)
{
    switch(dis){
        case 0:
            sprintf(buffer1, "%d", num);
            break;
        case 1:
            sprintf(buffer1, "+");
            break;
        case 2:
            sprintf(buffer1, "-");
            break;
        case 3:
            sprintf(buffer1, "x");
            break;
        case 4:
            sprintf(buffer1, "/");
            break;
        case 5:
            sprintf(buffer1, "C");
            break;
        case 6:
            sprintf(buffer1, "=");
            break;
        default:
            break;
            
    }
}



