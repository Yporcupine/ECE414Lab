#include "measurement.h"

char buffer[30];

void display_plot() {
    tft_setTextColor(ILI9341_WHITE);
    tft_setTextSize(1);
    
    tft_setCursor(0, 230);
    tft_writeString("0");
    
    
    tft_setCursor(100, 230);
    tft_writeString("1");
    
    tft_setCursor(200, 230);
    tft_writeString("2");
    
    tft_setCursor(300, 230);
    tft_writeString("3");
}

void display_line(int current_rpm, int target_rpm, short current_y) {
    short current_x = (short)(240-((1.0*current_rpm)/3000)*150);
    short target_x = (short)(240-((1.0*target_rpm)/3000)*150);
    tft_drawPixel(current_y, current_x, ILI9341_RED);
    tft_drawLine(0, target_x, 300, target_x, ILI9341_DARKGREEN);
        
}

void display_init() {
    SYSTEMConfigPerformance(PBCLK);
    configureADC();
    //initialize control LCD Screen
    tft_init_hw(); //set up pin select for SDO
    tft_begin(); //open SPI1 channel
    tft_setRotation(3); 
    tft_fillScreen(ILI9341_BLACK);  
    
}

void display_rpm(int current_rpm, int target_rpm){
    tft_setTextColor(ILI9341_WHITE);
    tft_setTextSize(2);
    tft_fillRoundRect(150,0,160,30,1,ILI9341_BLACK);
    //tft_fillRoundRect(160,30,160,30,ILI9341_BLACK);
    
    //display current rpm
    tft_setCursor(20, 0);
    sprintf(buffer, "Current RPM: %d", current_rpm);
    tft_writeString(buffer);
    
    //display target rpm
    tft_setCursor(20, 30);
    sprintf(buffer, "Target RPM: %d", target_rpm);
    tft_writeString(buffer);
    
    
}

void display_command(char *ptr, int pos) {
    tft_fillRoundRect(120,120,120,30,1,ILI9341_BLACK);
    tft_setTextColor(ILI9341_WHITE);
    tft_setTextSize(2);
    tft_setCursor(20, 60);
    tft_writeString("Command: ");
    tft_setCursor(120, 120);
    buffer[pos] = '\0';
    tft_writeString(ptr);
}


void eraseTarget(int target_rpm) {
    short target_x = (short)(240-((1.0*target_rpm)/3000)*150);
    tft_drawLine(0, target_x, 300, target_x, ILI9341_BLACK);
}

