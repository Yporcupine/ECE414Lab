#include "PID_FSM.h"

static enum PID_States { Init, Calculate}PID_State;
char c;
uint16_t count;

char command, number, buf[30];

void PID_Init()
{
    uart1_init();
    PID_State = Init;
}

void tickFct_PIDFSM(int rpm)
{
    //Transitions
    switch(PID_State)
    {
        case Init:
            PID_State = Calculate;
            break;
        case Calculate:
            PID_State = Calculate;
            break;
        default:
            PID_State = Init;
            break;         
    }
    
    //Actions
    switch(PID_State)
    {
        case Init:
            Kp = 0;
            Ki = 0;
            Kd = 0;
            error = 0;
            c = 0;
            command = 0;
            number = 0;
            deriv = 0;
            integ = 0;
            max = 55;
            min = 13;
            count = 0;
            break;
        case Calculate:
            c = uart1_rxread();
            if(c == 'r') {
                sscanf(buf, &command, &number);
                inputCommand(command, number);
            }
            error = target - current;
            deriv = current - prev;
            integ = integ + error; 
            if (integ > max) { 
                integ = max; 
            } else if (integ < min) { 
                integ = min; 
            }
            prev = current;
            current = rpm;
            actuator = Kp * error + Ki * integ + Kd * deriv; // PID algorithm           
            display_rpm(current, target); //display rpm readings
            display_line(current, target, count);
            if(count < 300) count++;
            else count = 0;
            oc1_setduty_plib((uint16_t)(1.0*actuator/557)*65535);
            break;
        default:
            break;
    }
}

void inputCommand(char com, float num){
    if(com == 's') {
        target = (int)num;
        if(prev_target != target) eraseTarget(); // erase old target waveform
        tft_fillRect(160,30,160,30,ILI9341_BLACK); //erase old target display
    }
    else if(com == 'd') Kd = num;
    else if(com == 'p') Kp = num;
    else if(com == 'i') Ki = num;
    display_command(buf, 1);
    memset(buf,0,strlen(buf));
}