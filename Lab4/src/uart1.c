#include <xc.h>
#include <inttypes.h>

uint8_t T;
const uint32_t freq = 40000000; //PBCLK frequency

void uart1_init(uint32_t baudrate)
{
    ANSELA = 0; // turn portA pin analog off
    TRISA = 0x04; // turn portA pin digital input on
    U1RXR = 0x0000; //connect RPA2 to U1RX
    RPA0R = 0x0001; //connect U1TX to RPA0
    U1BRG = 259; //(freq/(16*baudrate))-1; //set baudrate
    U1STA = 0x1400; // enable transmitter and receiver on UART1, 5120
    U1MODE = 0x8000; // turn on the UART

}

uint8_t uart1_txrdy()
{
    return !U1STAbits.UTXBF;
}

void uart1_txwrite(uint8_t c)
{
    U1TXREG = c;
}

void uart1_txwrite_str(char *c)
{
    while(*c != '\0'){
        while(!uart1_txrdy()){}
        uart1_txwrite(*c);
        c++;
    }
}

uint8_t uart1_rxrdy()
{
    return U1STAbits.URXDA;
}

uint8_t uart1_rxread()
{
    
    while(!uart1_rxrdy()) {}
    
    return U1RXREG;
    
}