#ifndef UART_H
#define	UART_H

#include "xc.h"
#include "clock.h"

void uartSetup()
{
    /*ピン設定*/
//    U1RXRbits.U1RXR=0b0000;
//    RPD3Rbits.RPD3R=0b0001;
    
    /*クロック分周率*/
    SystemUnlock();

    while(!PB2DIVbits.PBDIVRDY);
//    PB2DIVbits.PBDIV = 0;
    PB2DIVbits.PBDIV = 9;
    PB2DIVbits.ON=0b1;
    
    SystemLock();
    
    /*U1MODE設定*/
    U1MODEbits.ON=0b1;
    U1MODEbits.BRGH=0b1;
    
    /*U1STA設定*/
    U1STAbits.URXEN=0b1;
    U1STAbits.UTXEN=0b1;
    
    /*U1BRG設定*/
//    U1BRG=16;
    U1BRG=42;
}

void uartPutch(char c)
{
    U1TXREG=c;
    
    while(U1STAbits.UTXBF);
    while(!U1STAbits.TRMT);
}

void uartPuts(char *c)
{
    unsigned short int i;
    
    for(i=0;;i++)
    {
        if(c[i]=='\0')
        {
            break;
        }
        uartPutch(c[i]);
    }
}

char uartGetch()
{
    while(U1STAbits.RIDLE);
    while(!U1STAbits.URXDA);
    
    return U1RXREG;
}


#endif	/* UART_H */

