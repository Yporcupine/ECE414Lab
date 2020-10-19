#include "ts_lcd.h"
#include "tft_gfx.h"
#include "tft_master.h"
#include "TouchScreen.h"

/**
 * Define constants for the maximum and minimum values for 
 * interpolation.
 */
#define x1 153
#define x2 896
#define x_1 0
#define x_2 240
#define y1 110
#define y2 926
#define y_1 320
#define y_2 0


uint16_t z;


/**
 * This function shall return TRUE when a finger or stylus has been 
 * placed on the display; the two pointer parameters shall be assigned 
 * the current position of a finger or stylus on the display in 
 * LCD coordinates.
 */
uint8_t ts_lcd_get_ts(uint16_t *x, uint16_t *y)
{
    
    struct TSPoint p;
    p.x = 0;
    p.y = 0;
    p.z = 0;
    getPoint(&p);
    z = p.z;
    
    if(z > 200 && z < 600)
    {
        float tempX = ((1.0*(p.x - x1))/(x2 - x1));
        float tempY = ((1.0*(p.y - y1))/(y2 - y1));
        *x = (uint16_t)((tempX)*(x_2 - x_1))+x_1;
        *y = (uint16_t)((tempY)*(y_2 - y_1))+y_1;
        return 1;
    }
    
    
    return 0; //detect if a finger is placed on screen
    
}


void ts_lcd_init()
{
    SYSTEMConfigPerformance(PBCLK);
    configureADC();
    
    
    //initialize screen
    tft_init_hw(); //set up pin select for SDO
    tft_begin(); //open SPI1 channel
    tft_setRotation(3); 
    tft_fillScreen(ILI9341_BLACK);  
    
}

void ts_crossHair(uint16_t x, uint16_t y, unsigned short color)
{
    tft_drawLine(0,x,360,x,color);
    tft_drawLine(y,0,y,240,color);
}
    
