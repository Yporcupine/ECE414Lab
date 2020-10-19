/* 
 * File:   touch_main.c
 * Author: watkinma
 *
 * Description: Prints out the detected position (x, y) of a press on the
 * touchscreen as well as the pressure (z).
 * 
 * IMPORTANT: For this example to work, you need to make the following 
 * connections from the touchpad to the PIC32:
 *  Y+ => AN1 (Pin 3)
 *  Y- => RA3 (Pin 10)
 *  X+ => RA4 (Pin 12)
 *  X- => AN0 (Pin 2)
 * 
 */

#include <xc.h>
#include <plib.h>
#include "config.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"
#include "ts_lcd.h"
#include "ts_getter.h"
#include "ts_displayCalculator.h"
#include "calculator_FSM.h"
#include "debouncer.h"


#define XM AN0
#define YP AN1
uint16_t x = 0;
uint16_t y = 0;
uint8_t pushed = 0;
uint8_t press = 0;
//uint8_t dig = 0;;
char buffer3[30];

/*
 * 
 */
int main(int argc, char** argv) {
    //ts_lcd_init(); //initialize LCD driver
    //task_2_setup();
    init_Calc();
    Debounce_init();
    while(1){
     tft_setCursor(0, 0);//20, 100 
     tft_setTextColor(ILI9341_WHITE); tft_setTextSize(4);

     //erase old text & lines
     tft_setTextColor(ILI9341_BLACK);
     //sprintf(buffer, "%d",dig); //p.x, p.y, p.z
     tft_writeString(buffer3);
     
        
        
     pushed = ts_lcd_get_ts(&x, &y);
     tft_setCursor(0, 0);//20, 100
     tft_setTextColor(ILI9341_WHITE);
     
     //sprintf(buffer, "%d",dig); //p.x, p.y, p.z
     //tft_writeString(buffer);
     press = tickFunct_Debounce(pushed);
     tickFunct_Calc(x,y,press);
     ts_displayCalc();

        //task_2();
        
        
        //task_2();
        delay_ms(100);
    }
    
    return (EXIT_SUCCESS);
}

/**
void task_2(){
    //tft_setCursor(y, x)
    tft_setCursor(0, 0);//20, 100 
     tft_setTextColor(ILI9341_WHITE); tft_setTextSize(2);

     //erase old text & lines
     tft_setTextColor(ILI9341_BLACK);
     tft_writeString(buffer);
     ts_crossHair(x, y, ILI9341_BLACK);
        
        
     ts_lcd_get_ts(&x, &y);
     tft_setCursor(0, 0);//20, 100
     tft_setTextColor(ILI9341_WHITE);
     ts_crossHair(x, y, ILI9341_WHITE);
     sprintf(buffer,"x: %d, y: %d", x, y); //p.x, p.y, p.z
     tft_writeString(buffer);
     
}

void task_2_setup(){
    SYSTEMConfigPerformance(PBCLK);
    
    configureADC();
    
    //initialize screen
    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9341_BLACK); 
}
 * **/