#include <msp430.h>
#define FAST 100000
#define SLOW 1000000

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
    P1DIR |= BIT0;            // set P1.0 as the output
    while (1)
    {
        P1OUT |= BIT0;  // P1.0 outputs a high level
        __delay_cycles(FAST); // delay 500,000 clock cycles, approximately 0.5s
        P1OUT &= ~BIT0;         // P1.0 outputs a low level
        __delay_cycles(SLOW); // delay 500,000 clock cycles, approximately 0.5s
    }  
    return 0;
    
}