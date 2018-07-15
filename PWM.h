#ifndef PWM_H
#define	PWM_H

#include "xc.h"
#include "clock.h"

void PwmSetup(unsigned char octsel, unsigned int sel)
{
    SystemUnlock();

    while(!PB3DIVbits.PBDIVRDY);
    PB3DIVbits.PBDIV = 0;
    PB3DIVbits.ON=0b1;
    
//    CFGCONbits.OCACLK=1;
    
    SystemLock();
    
//    PR4=9999;
//    PR5=9999;
    PR2=9999;
    PR3=9999;
//    PR6=9999;
//    PR7=9999;
    
    T2CONbits.ON=1;
    T3CONbits.ON=1;
//    T4CONbits.ON=1;
//    T5CONbits.ON=1;
//    T6CONbits.ON=1;
//    T7CONbits.ON=1;
    
    switch(sel)
    {
        case OC1:
            OC1CONbits.ON=1;
            OC1CONbits.OCTSEL=octsel;
            OC1CONbits.OCM=0b110;
            break;
        case OC2:
            OC2CONbits.ON=1;
            OC2CONbits.OCTSEL=octsel;
            OC2CONbits.OCM=0b110;
            break;
        case OC3:
            OC3CONbits.ON=1;
            OC3CONbits.OCTSEL=octsel;
            OC3CONbits.OCM=0b110;
            break;
        case OC4:
            OC4CONbits.ON=1;
            OC4CONbits.OCTSEL=octsel;
            OC4CONbits.OCM=0b110;
            break;
        case OC5:
            OC5CONbits.ON=1;
            OC5CONbits.OCTSEL=octsel;
            OC5CONbits.OCM=0b110;
            break;
        case OC6:
            OC6CONbits.ON=1;
            OC6CONbits.OCTSEL=octsel;
            OC6CONbits.OCM=0b110;
            break;
        case OC7:
            OC7CONbits.ON=1;
            OC7CONbits.OCTSEL=octsel;
            OC7CONbits.OCM=0b110;
            break;
        case OC8:
            OC8CONbits.ON=1;
            OC8CONbits.OCTSEL=octsel;
            OC8CONbits.OCM=0b110;
            break;
        case OC9:
            OC9CONbits.ON=1;
            OC9CONbits.OCTSEL=octsel;
            OC9CONbits.OCM=0b110;
            break;  
    }
}

void Chip_PWM_SetPinOut(unsigned int sel, unsigned int duty)
{
    switch(sel)
    {
        case OC1:
            OC1RS=duty;
            break;
        case OC2:
            OC2RS=duty;
            break;
        case OC3:
            OC3RS=duty;
            break;
        case OC4:
            OC4RS=duty;
            break;
        case OC5:
            OC5RS=duty;
            break;
        case OC6:
            OC6RS=duty;
            break;
        case OC7:
            OC7RS=duty;
            break;
        case OC8:
            OC8RS=duty;
            break;
        case OC9:
            OC9RS=duty;
            break;
    }
}

#endif	/* PWM_H */

