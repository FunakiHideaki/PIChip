#ifndef GPIO_H
#define	GPIO_H

#include "xc.h"


#define RB0 0x20
#define RB1 0x21
#define RB2 0x22
#define RB3 0x23
#define RB4 0x24
#define RB5 0x25
#define RB6 0x26
#define RB7 0x27
#define RB8 0x28
#define RB9 0x29
#define RB10 0x2A
#define RB11 0x2B
#define RB12 0x2C
#define RB13 0x2D
#define RB14 0x2E
#define RB15 0x2F

#define RC12 0x3C
#define RC13 0x3D
#define RC14 0x3E
#define RC15 0x3F

#define RD0 0x40
#define RD1 0x41
#define RD2 0x42
#define RD3 0x43
#define RD4 0x44
#define RD5 0x45
#define RD9 0x49
#define RD10 0x4A
#define RD11 0x4B

#define RE0 0x50
#define RE1 0x51
#define RE2 0x52
#define RE3 0x53
#define RE4 0x54
#define RE5 0x55
#define RE6 0x56
#define RE7 0x57

#define RF0 0x60
#define RF1 0x61
#define RF3 0x63
#define RF4 0x64
#define RF5 0x65

#define RG6 0x76
#define RG7 0x77
#define RG8 0x78
#define RG9 0x79




void Chip_GPIO_SetPinDIROutput(unsigned char port)
{
    switch((port>>4)&0xF)
    {
      /*  case 'A':
            ANSELA=ANSELA&(~(0x1<<num));
            TRISA=TRISA&(~(0x1<<num));
            break;*/
        case ('B'-0x40):
             ANSELB=ANSELB&(~(0x1<<(port&0xF)));
            TRISB=TRISB&(~(0x1<<(port&0xF)));
            break;
        case ('C'-0x40):
        //     ANSELC=ANSELC&(~(0x1<<num));
            TRISC=TRISC&(~(0x1<<(port&0xF)));
            break;
        case ('D'-0x40):
         //    ANSELD=ANSELD&(~(0x1<<num));
            TRISD=TRISD&(~(0x1<<(port&0xF)));
            break;
        case ('E'-0x40):
             ANSELE=ANSELE&(~(0x1<<(port&0xF)));
            TRISE=TRISE&(~(0x1<<(port&0xF)));
            break;
        case ('F'-0x40):
        //     ANSELF=ANSELF&(~(0x1<<num));
            TRISF=TRISF&(~(0x1<<(port&0xF)));
            break;
        case ('G'-0x40):
             ANSELG=ANSELG&(~(0x1<<(port&0xF)));
            TRISG=TRISG&(~(0x1<<(port&0xF)));
            break;
       /* case'H':
             ANSELH=ANSELH&(~(0x1<<num));
            TRISH=TRISH&(~(0x1<<num));
            break;
        case'I':
             ANSELI=ANSELI&(~(0x1<<num));
            TRISI=TRISI&(~(0x1<<num));
            break;
        case'J':
             ANSELJ=ANSELJ&(~(0x1<<num));
            TRISJ=TRISJ&(~(0x1<<num));
            break;
        case'K':
             ANSELK=ANSELK&(~(0x1<<num));
            TRISK=TRISK&(~(0x1<<num));
            break;*/
    }
}

void Chip_GPIO_SetPinDIRInput(unsigned char port)
{
    switch((port>>4)&0xF)
    {
        case ('B'-0x40):
             ANSELB=ANSELB&(~(0x1<<(port&0xF)));
            TRISB=TRISB|(0x1<<(port&0xF));
            break;
        case ('C'-0x40):
        //     ANSELC=ANSELC&(~(0x1<<num));
            TRISC=TRISC|(0x1<<(port&0xF));
            break;
        case ('D'-0x40):
         //    ANSELD=ANSELD&(~(0x1<<num));
            TRISD=TRISD|(0x1<<(port&0xF));
            break;
        case ('E'-0x40):
             ANSELE=ANSELE&(~(0x1<<(port&0xF)));
            TRISE=TRISE|(0x1<<(port&0xF));
            break;
        case ('F'-0x40):
        //     ANSELF=ANSELF&(~(0x1<<num));
            TRISF=TRISF|(0x1<<(port&0xF));
            break;
        case ('G'-0x40):
             ANSELG=ANSELG&(~(0x1<<(port&0xF)));
            TRISG=TRISG|(0x1<<(port&0xF));
            break;
    }
}

void Chip_GPIO_SetPinOutHigh(unsigned char port)
{
    switch((port>>4)&0xF)
    {
        case ('B'-0x40):
            LATB=LATB|(0x1<<(port&0xF));
            break;
        case ('C'-0x40):
            LATC=LATC|(0x1<<(port&0xF));
            break;
        case ('D'-0x40):
            LATD=LATD|(0x1<<(port&0xF));
            break;
        case ('E'-0x40):
            LATE=LATE|(0x1<<(port&0xF));
            break;
        case ('F'-0x40):
            LATF=LATF|(0x1<<(port&0xF));
            break;
        case ('G'-0x40):
            LATG=LATG|(0x1<<(port&0xF));
            break;
    }
}

void Chip_GPIO_SetPinOutLow(unsigned char port)
{
    switch((port>>4)&0xF)
    {
        case ('B'-0x40):
            LATB=LATB&(~(0x1<<(port&0xF)));
            break;
        case ('C'-0x40):
            LATC=LATC&(~(0x1<<(port&0xF)));
            break;
        case ('D'-0x40):
            LATD=LATD&(~(0x1<<(port&0xF)));
            break;
        case ('E'-0x40):
            LATE=LATE&(~(0x1<<(port&0xF)));
            break;
        case ('F'-0x40):
            LATF=LATF&(~(0x1<<(port&0xF)));
            break;
        case ('G'-0x40):
            LATG=LATG&(~(0x1<<(port&0xF)));
            break;
    }    
}

void Chip_GPIO_SetPinToggle(unsigned char port)
{
    switch((port>>4)&0xF)
    {
        case ('B'-0x40):
            LATB=LATB^(0x1<<(port&0xF));
            break;
        case ('C'-0x40):
            LATC=LATC^(0x1<<(port&0xF));
            break;
        case ('D'-0x40):
            LATD=LATD^(0x1<<(port&0xF));
            break;
        case ('E'-0x40):
            LATE=LATE^(0x1<<(port&0xF));
            break;
        case ('F'-0x40):
            LATF=LATF^(0x1<<(port&0xF));
            break;
        case ('G'-0x40):
            LATG=LATG^(0x1<<(port&0xF));
            break;
    }
}

void Chip_GPIO_SetPinState(unsigned char port, unsigned char state)
{
    switch(state)
    {
        case 0:
            switch((port>>4)&0xF)
            {
                case ('B'-0x40):
                    LATB=LATB&(~(0x1<<(port&0xF)));
                    break;
                case ('C'-0x40):
                    LATC=LATC&(~(0x1<<(port&0xF)));
                    break;
                case ('D'-0x40):
                    LATD=LATD&(~(0x1<<(port&0xF)));
                    break;
                case ('E'-0x40):
                    LATE=LATE&(~(0x1<<(port&0xF)));
                    break;
                case ('F'-0x40):
                    LATF=LATF&(~(0x1<<(port&0xF)));
                    break;
                case ('G'-0x40):
                    LATG=LATG&(~(0x1<<(port&0xF)));
                    break;
            }
        case 1:
            switch((port>>4)&0xF)
            {
                case ('B'-0x40):
                    LATB=LATB|(0x1<<(port&0xF));
                    break;
                case ('C'-0x40):
                    LATC=LATC|(0x1<<(port&0xF));
                    break;
                case ('D'-0x40):
                    LATD=LATD|(0x1<<(port&0xF));
                    break;
                case ('E'-0x40):
                    LATE=LATE|(0x1<<(port&0xF));
                    break;
                case ('F'-0x40):
                    LATF=LATF|(0x1<<(port&0xF));
                    break;
                case ('G'-0x40):
                    LATG=LATG|(0x1<<(port&0xF));
                    break;
            }
    }
}
            
unsigned char Chip_GPIO_GetPinState(unsigned char port)
{
    switch((port>>4)&0xF)
    {
        case ('B'-0x40):
            return ((PORTB>>(port&0xF))&0x1);
        case ('C'-0x40):
            return ((PORTC>>(port&0xF))&0x1);
        case ('D'-0x40):
            return ((PORTD>>(port&0xF))&0x1);
        case ('E'-0x40):
            return ((PORTE>>(port&0xF))&0x1);
        case ('F'-0x40):
            return ((PORTF>>(port&0xF))&0x1);
        case ('G'-0x40):
            return ((PORTG>>(port&0xF))&0x1);
    }
}





/*#define AN0 
#define AN1
#define AN2
#define AN3 
#define AN4
#define AN5
#define AN6
#define AN7
#define AN8
#define AN9 
#define AN10
#define AN11
#define AN12
#define AN13 
#define AN14
#define AN15
#define AN16
#define AN17
#define AN18
#define AN45
#define AN46
#define AN47
#define AN48
#define AN49 

#define CLKI
#define CLKO
#define OSC1
#define OSC2
#define SOSCI
#define SOSCO*/
#define REFCLKI1 0x00
#define REFCLKI3 0x01
#define REFCLKI4 0x02
#define REFCLKO1 0x03
#define REFCLKO3 0x04
#define REFCLKO4 0x05

#define IC1 0x10
#define IC2 0x11
#define IC3 0x12
#define IC4 0x13
#define IC5 0x14
#define IC6 0x15
#define IC7 0x16
#define IC8 0x17
#define IC9 0x18

#define OC1 0x20
#define OC2 0x21
#define OC3 0x22
#define OC4 0x23
#define OC5 0x24
#define OC6 0x25
#define OC7 0x26
#define OC8 0x27
#define OC9 0x28
#define OCFA 0x29

#define INT1 0x30
#define INT2 0x31
#define INT3 0x32
#define INT4 0x33

#define T2CK 0x40
#define T3CK 0x41
#define T4CK 0x42
#define T5CK 0x43
#define T6CK 0x44
#define T7CK 0x45
#define T8CK 0x46
#define T9CK 0x47

#define U1RX 0x100
#define U1TX 0x101
#define U1CTS 0x102
#define U1RTS 0x103
#define U2RX 0x104
#define U2TX 0x105
#define U2CTS 0x106
#define U2RTS 0x107
#define U3RX 0x108
#define U3TX 0x109
#define U3CTS 0x10A
#define U3RTS 0x10B
#define U4RX 0x10C
#define U4TX 0x10D
#define U4CTS 0x10E
#define U4RTS 0x10F
#define U5RX 0x110
#define U5TX 0x111
#define U5CTS 0x112
#define U5RTS 0x113
#define U6RX 0x114
#define U6TX 0x115
#define U6CTS 0x116
#define U6RTS 0x117

#define SCK1 0x50
#define SDI1 0x51
#define SDO1 0x52
#define SS1 0x53
#define SCK2 0x54
#define SDI2 0x55
#define SDO2 0x56
#define SS2 0x57
#define SCK3 0x58
#define SDI3 0x59
#define SDO3 0x5A
#define SS3 0x5B
#define SCK4 0x5C
#define SDI4 0x5D
#define SDO4 0x5E
#define SS4 0x5F

#define C1OUT 0x60
#define C2OUT 0x61

#define C1TX 0x70
#define C1RX 0x71
#define C2TX 0x72
#define C2RX 0x73

#define NC 0xFF

unsigned char InputPinSelection_A(unsigned char port)
{
    switch(port)
    {
        case RD2:
            return 0x0;
        case RG8:
            return 0x1;
        case RF4:
            return 0x2;
        case RD10:
            return 0x3;
        case RF1:
            return 0x4;
        case RB9:
            return 0x5;
        case RB10:
            return 0x6;
        case RC14:
            return 0x7;
        case RB5:
            return 0x8;
/*        case RC1:
            return 0xA;
        case RD14:
            return 0xB;
        case RG1:
            return 0xC;
        case RA14:
            return 0xD;
        case RD6:
            return 0xE;*/
        default:
            return 0xFF;
    }
}

unsigned char InputPinSelection_B(unsigned char port)
{
    switch(port)
    {
        case RD3:
            return 0x0;
        case RG7:
            return 0x1;
        case RF5:
            return 0x2;
        case RD11:
            return 0x3;
        case RF0:
            return 0x4;
        case RB1:
            return 0x5;
        case RE5:
            return 0x6;
        case RC13:
            return 0x7;
        case RB3:
            return 0x8;
 /*       case RC4:
            return 0xA;
        case RD15:
            return 0xB;
        case RG0:
            return 0xC;
        case RA15:
            return 0xD;
        case RD7:
            return 0xE;*/
        default:
            return 0xFF;
    }
}

unsigned char InputPinSelection_C(unsigned char port)
{
    switch(port)
    {
        case RD9:
            return 0x0;
        case RG6:
            return 0x1;
        case RB8:
            return 0x2;
        case RB15:
            return 0x3;
        case RD4:
            return 0x4;
        case RB0:
            return 0x5;
        case RE3:
            return 0x6;
        case RB7:
            return 0x7;
/*        case RF12:
            return 0x9;
        case RD12:
            return 0xA;
        case RF8:
            return 0xB;
        case RC3:
            return 0xC;
        case RE9:
            return 0xD;*/
        default:
            return 0xFF;
    }
}

unsigned char InputPinSelection_D(unsigned char port)
{
    switch(port)
    {
        case RD1:
            return 0x0;
        case RG9:
            return 0x1;
        case RB14:
            return 0x2;
        case RD0:
            return 0x3;
        case RB6:
            return 0x5;
        case RD5:
            return 0x6;
        case RB2:
            return 0x7;
        case RF3:
            return 0x8;
/*        case RF13:
            return 0x9;*/
        case NC:
            return 0xA;
/*        case RF2:
            return 0xB;
        case RC2:
            return 0xC;
        case RE8:
            return 0xD;*/
        default:
            return 0xFF;
    }
}

unsigned char InputPinSelection(unsigned char port)
{
    switch(port)
    {
        case RD2:
            return 0x0;
        case RG8:
            return 0x1;
        case RF4:
            return 0x2;
        case RD10:
            return 0x3;
        case RF1:
            return 0x4;
        case RB9:
            return 0x5;
        case RB10:
            return 0x6;
        case RC14:
            return 0x7;
        case RB5:
            return 0x8;
/*        case RC1:
            return 0xA;
        case RD14:
            return 0xB;
        case RG1:
            return 0xC;
        case RA14:
            return 0xD;
        case RD6:
            return 0xE;*/
            
        case RD3:
            return 0x0;
        case RG7:
            return 0x1;
        case RF5:
            return 0x2;
        case RD11:
            return 0x3;
        case RF0:
            return 0x4;
        case RB1:
            return 0x5;
        case RE5:
            return 0x6;
        case RC13:
            return 0x7;
        case RB3:
            return 0x8;
 /*       case RC4:
            return 0xA;
        case RD15:
            return 0xB;
        case RG0:
            return 0xC;
        case RA15:
            return 0xD;
        case RD7:
            return 0xE;*/
            
        case RD9:
            return 0x0;
        case RG6:
            return 0x1;
        case RB8:
            return 0x2;
        case RB15:
            return 0x3;
        case RD4:
            return 0x4;
        case RB0:
            return 0x5;
        case RE3:
            return 0x6;
        case RB7:
            return 0x7;
/*        case RF12:
            return 0x9;
        case RD12:
            return 0xA;
        case RF8:
            return 0xB;
        case RC3:
            return 0xC;
        case RE9:
            return 0xD;*/
            
        case RD1:
            return 0x0;
        case RG9:
            return 0x1;
        case RB14:
            return 0x2;
        case RD0:
            return 0x3;
        case RB6:
            return 0x5;
        case RD5:
            return 0x6;
        case RB2:
            return 0x7;
        case RF3:
            return 0x8;
/*        case RF13:
            return 0x9;*/
        case NC:
            return 0xA;
/*        case RF2:
            return 0xB;
        case RC2:
            return 0xC;
        case RE8:
            return 0xD;*/
        default:
            return 0xA;
    }
}

unsigned char OutputPinSelection_A(unsigned int sel)
{
    switch(sel)
    {    
         case NC:
            return 0x0;
        case U3TX:
            return 0x1;
        case U4RTS:
            return 0x2;
        case SDO1:
            return 0x5;
        case SDO2:
            return 0x6;
        case SDO3:
            return 0x7;
/*        case SDO5:
            return 0x9;
        case SS6:
            return 0xA;*/
        case OC3:
            return 0xB;
        case OC6:
            return 0xC;
        case REFCLKO4:
            return 0xD;
        case C2OUT:
            return 0xE;
        case C1TX:
            return 0xF;
        default:
            return 0xFF;
    }
}

unsigned char OutputPinSelection_B(unsigned int sel)
{
    switch(sel)
    {
        case U1TX:
            return 0x1;
        case U2RTS:
            return 0x2;
        case U5TX:
            return 0x3;
        case U6RTS:
            return 0x4;
        case SDO1:
            return 0x5;
        case SDO2:
            return 0x6;
        case SDO3:
            return 0x7;
        case SDO4:
            return 0x8;
/*        case SDO5:
            return 0x9;*/
        case OC4:
            return 0xB;
        case OC7:
            return 0xC;
        case REFCLKO1:
            return 0xF;
        default:
            return 0xFF;
    }
}

unsigned char OutputPinSelection_C(unsigned int sel)
{
    switch(sel)
    {
        case U3RTS:
            return 0x1;
        case U4TX:
            return 0x2;
        case U6TX:
            return 0x4;
        case SS1:
            return 0x5;
        case SS3:
            return 0x7;
        case SS4:
            return 0x8;
/*        case SS5:
            return 0x9;
        case SDO6:
            return 0xA;*/
        case OC5:
            return 0xB;
        case OC8:
            return 0xC;
        case C1OUT:
            return 0xE;
        case REFCLKO3:
            return 0xF;
        default:
            return 0xFF;
    }
}

unsigned char OutputPinSelection_D(unsigned int sel)
{
    switch(sel)
    {
        case U1RTS:
            return 0x1;
        case U2TX:
            return 0x2;
        case U5RTS:
            return 0x3;
        case U6TX:
            return 0x4;
        case SS2:
            return 0x6;
        case SDO4:
            return 0x8;
/*        case SDO6:
            return 0xA;*/
        case OC2:
            return 0xB;
        case OC1:
            return 0xC;
        case OC9:
            return 0xD;
        case C2TX:
            return 0xF;
        default:
            return 0xFF;
    }
}

unsigned char OutputPinSelection(unsigned int sel)
{
    switch(sel)
    {
        case NC:
            return 0x0;
        case U3TX:
            return 0x1;
        case U4RTS:
            return 0x2;
        case SDO1:
            return 0x5;
        case SDO2:
            return 0x6;
        case SDO3:
            return 0x7;
/*        case SDO5:
            return 0x9;
        case SS6:
            return 0xA;*/
        case OC3:
            return 0xB;
        case OC6:
            return 0xC;
        case REFCLKO4:
            return 0xD;
        case C2OUT:
            return 0xE;
        case C1TX:
            return 0xF;
            
        case U1TX:
            return 0x1;
        case U2RTS:
            return 0x2;
        case U5TX:
            return 0x3;
        case U6RTS:
            return 0x4;
/*        case SDO1:
            return 0x5;
        case SDO2:
            return 0x6;
        case SDO3:
            return 0x7;
        case SDO4:
            return 0x8;*/
/*        case SDO5:
            return 0x9;*/
        case OC4:
            return 0xB;
        case OC7:
            return 0xC;
        case REFCLKO1:
            return 0xF;
            
        case U3RTS:
            return 0x1;
        case U4TX:
            return 0x2;
        case U6TX:
            return 0x4;
        case SS1:
            return 0x5;
        case SS3:
            return 0x7;
        case SS4:
            return 0x8;
/*        case SS5:
            return 0x9;
        case SDO6:
            return 0xA;*/
        case OC5:
            return 0xB;
        case OC8:
            return 0xC;
        case C1OUT:
            return 0xE;
        case REFCLKO3:
            return 0xF;
            
        case U1RTS:
            return 0x1;
        case U2TX:
            return 0x2;
        case U5RTS:
            return 0x3;
/*        case U6TX:
            return 0x4;*/
        case SS2:
            return 0x6;
/*        case SDO4:
            return 0x8;*/
/*        case SDO6:
            return 0xA;*/
        case OC2:
            return 0xB;
        case OC1:
            return 0xC;
        case OC9:
            return 0xD;
        case C2TX:
            return 0xF;
            
        default:
            return 0x0;
    }
}


/*void Chip_SWM_MovablePinAssign(unsigned int sel, unsigned char port)
{
    switch(sel)
    {
        case INT3:
            INT3Rbits.INT3R=InputPinSelection(port);
            break;
        case T2CK:
            T2CKRbits.T2CKR=InputPinSelection(port);
            break;
        case T6CK:
            T6CKRbits.T6CKR=InputPinSelection(port);
            break;
        case IC3:
            IC3Rbits.IC3R=InputPinSelection(port);
            break;
        case IC7:
            IC7Rbits.IC7R=InputPinSelection(port);
            break;
        case U1RX:
            U1RXRbits.U1RXR=InputPinSelection(port);
            break;
        case U2CTS:
            U2CTSRbits.U2CTSR=InputPinSelection(port);
            break;
        case U5RX:
            U5RXRbits.U5RXR=InputPinSelection(port);
            break;
        case U6CTS:
            U6CTSRbits.U6CTSR=InputPinSelection(port);
            break;
        case SDI1:
            SDI1Rbits.SDI1R=InputPinSelection(port);
            break;
        case SDI3:
            SDI3Rbits.SDI3R=InputPinSelection(port);
            break;*/
/*        case SDI5:
            SDI5Rbits.SDI5R=InputPinSelection(port);
        case SS6:
            SS6Rbits.SS6R=InputPinSelection(port);*/
/*        case REFCLKI1:
            REFCLKI1Rbits.REFCLKI1R=InputPinSelection(port);
            break;
        case INT4:
            INT4Rbits.INT4R=InputPinSelection(port);
            break;
        case T5CK:
            T5CKRbits.T5CKR=InputPinSelection(port);
            break;
        case T7CK:
            T7CKRbits.T7CKR=InputPinSelection(port);
            break;
        case IC4:
            IC4Rbits.IC4R=InputPinSelection(port);
            break;
        case IC8:
            IC8Rbits.IC8R=InputPinSelection(port);
            break;
        case U3RX:
            U3RXRbits.U3RXR=InputPinSelection(port);
            break;
        case U4CTS:
            U4CTSRbits.U4CTSR=InputPinSelection(port);
            break;
        case SDI2:
            SDI2Rbits.SDI2R=InputPinSelection(port);
            break;
        case SDI4:
            SDI4Rbits.SDI4R=InputPinSelection(port);
            break;
        case C1RX:
            C1RXRbits.C1RXR=InputPinSelection(port);
            break;
        case REFCLKI4:
            REFCLKI4Rbits.REFCLKI4R=InputPinSelection(port);
            break;
        case INT2:
            INT2Rbits.INT2R=InputPinSelection(port);
            break;
        case T3CK:
            T3CKRbits.T3CKR=InputPinSelection(port);
            break;
        case T8CK:
            T8CKRbits.T8CKR=InputPinSelection(port);
            break;
        case IC2:
            IC2Rbits.IC2R=InputPinSelection(port);
            break;
        case IC5:
            IC5Rbits.IC5R=InputPinSelection(port);
            break;
        case IC9:
            IC9Rbits.IC9R=InputPinSelection(port);
            break;
        case U1CTS:
            U1CTSRbits.U1CTSR=InputPinSelection(port);
            break;
        case U2RX:
            U2RXRbits.U2RXR=InputPinSelection(port);
            break;
        case U5CTS:
            U5CTSRbits.U5CTSR=InputPinSelection(port);
            break;
        case SS1:
            SS1Rbits.SS1R=InputPinSelection(port);
            break;
        case SS3:
            SS3Rbits.SS3R=InputPinSelection(port);
            break;
        case SS4:
            SS4Rbits.SS4R=InputPinSelection(port);
            break;*/
/*        case SS5:
            SS5Rbits.SS5R=InputPinSelection(port);
            break;*/
/*        case C2RX:
            C2RXRbits.C2RXR=InputPinSelection(port);
            break;
        case INT1:
            INT1Rbits.INT1R=InputPinSelection(port);
            break;
        case T4CK:
            T4CKRbits.T4CKR=InputPinSelection(port);
            break;
        case T9CK:
            T9CKRbits.T9CKR=InputPinSelection(port);
            break;
        case IC1:
            IC1Rbits.IC1R=InputPinSelection(port);
            break;
        case IC6:
            IC6Rbits.IC6R=InputPinSelection(port);
            break;
        case U3CTS:
            U3CTSRbits.U3CTSR=InputPinSelection(port);
            break;
        case U4RX:
            U4RXRbits.U4RXR=InputPinSelection(port);
            break;
        case U6RX:
            U6RXRbits.U6RXR=InputPinSelection(port);
            break;
        case SS2:
            SS2Rbits.SS2R=InputPinSelection(port);
            break;*/
/*        case SDI6:
            SDI6Rbits.SDI6R=InputPinSelection(port);
            break;
        case OFCA:
            OFCARbits.OFCAR=InputPinSelection(port);
            break;*/
/*        case REFCLKI3:
            REFCLKI3Rbits.REFCLKI3R=InputPinSelection(port);
            break;
        default:
            switch(port)
            {
                case RD2:
                    RPD2Rbits.RPD2R=OutputPinSelection(sel);
                    break;
                case RG8:
                    RPG8Rbits.RPG8R=OutputPinSelection(sel);
                    break;
                case RF4:
                    RPF4Rbits.RPF4R=OutputPinSelection(sel);
                    break;
                case RD10:
                    RPD10Rbits.RPD10R=OutputPinSelection(sel);
                    break;
                case RF1:
                    RPF1Rbits.RPF1R=OutputPinSelection(sel);
                    break;
                case RB9:
                    RPB9Rbits.RPB9R=OutputPinSelection(sel);
                case RB10:
                    RPB10Rbits.RPB10R=OutputPinSelection(sel);
                    break;
                case RC14:
                    RPC14Rbits.RPC14R=OutputPinSelection(sel);
                    break;
                case RB5:
                    RPB5Rbits.RPB5R=OutputPinSelection(sel);
                    break;*/
/*                case RC1:
                    RPC1Rbits.RPC1R=OutputPinSelection(sel);
                    break;
                case RD14:
                    RPD14Rbits.RPD14R=OutputPinSelection(sel);
                    break;
                case RG1:
                    RPG1Rbits.RPG1R=OutputPinSelection(sel);
                    break;
                case RA14:
                    RPA14Rbits.RPA14R=OutputPinSelection(sel);
                    break;
                case RD6:
                    RPD6Rbits.RPD6R=OutputPinSelection(sel);
                    break;*/
/*                case RD3:
                    RPD3Rbits.RPD3R=OutputPinSelection(sel);
                    break;
                case RG7:
                    RPG7Rbits.RPG7R=OutputPinSelection(sel);
                    break;
                case RF5:
                    RPF5Rbits.RPF5R=OutputPinSelection(sel);
                    break;
                case RD11:
                    RPD11Rbits.RPD11R=OutputPinSelection(sel);
                case RF0:
                    RPF0Rbits.RPF0R=OutputPinSelection(sel);
                    break;
                case RB1:
                    RPB1Rbits.RPB1R=OutputPinSelection(sel);
                    break;
                case RE5:
                    RPE5Rbits.RPE5R=OutputPinSelection(sel);
                    break;
                case RC13:
                    RPC13Rbits.RPC13R=OutputPinSelection(sel);
                    break;
                case RB3:
                    RPB3Rbits.RPB3R=OutputPinSelection(sel);
                    break;*/
/*                case RC4:
                    RPC4Rbits.RPC4R=OutputPinSelection(sel);
                    break;
                case RD15:
                    RPD15Rbits.RPD15R=OutputPinSelection(sel);
                    break;
                case RG0:
                    RPG0Rbits.RPG0R=OutputPinSelection(sel);
                    break;
                case RA15:
                    RPA15Rbits.RPA15R=OutputPinSelection(sel);
                    break;
                case RD7:
                    RPD7Rbits.RPD7R=OutputPinSelection(sel);
                    break;*/
/*                case RD9:
                    RPD9Rbits.RPD9R=OutputPinSelection(sel);
                case RG6:
                    RPG6Rbits.RPG6R=OutputPinSelection(sel);
                    break;
                case RB8:
                    RPB8Rbits.RPB8R=OutputPinSelection(sel);
                    break;
                case RB15:
                    RPB15Rbits.RPB15R=OutputPinSelection(sel);
                    break;
                case RD4:
                    RPD4Rbits.RPD4R=OutputPinSelection(sel);
                    break;
                case RB0:
                    RPB0Rbits.RPB0R=OutputPinSelection(sel);
                    break;
                case RE3:
                    RPE3Rbits.RPE3R=OutputPinSelection(sel);
                    break;
                case RB7:
                    RPB7Rbits.RPB7R=OutputPinSelection(sel);
                    break;*/
/*                case RF12:
                    RPF12Rbits.RPF12R=OutputPinSelection(sel);
                    break;
                case RD12:
                    RPD12Rbits.RPD12R=OutputPinSelection(sel);
                    break;
                case RF8:
                    RPF8Rbits.RPF8R=OutputPinSelection(sel);
                    break;
                case RC3:
                    RPC3Rbits.RPC3R=OutputPinSelection(sel);
                    break;
                case RE9:
                    RPE9Rbits.RPE9R=OutputPinSelection(sel);
                    break;*/
/*                case RD1:
                    RPD1Rbits.RPD1R=OutputPinSelection(sel);
                    break;
                case RG9:
                    RPG9Rbits.RPG9R=OutputPinSelection(sel);
                    break;
                case RB14:
                    RPB14Rbits.RPB14R=OutputPinSelection(sel);
                    break;
                case RD0:
                    RPD0Rbits.RPD0R=OutputPinSelection(sel);
                    break;
                case RB6:
                    RPB6Rbits.RPB6R=OutputPinSelection(sel);
                    break;
                case RD5:
                    RPD5Rbits.RPD5R=OutputPinSelection(sel);
                    break;
                case RB2:
                    RPB2Rbits.RPB2R=OutputPinSelection(sel);
                    break;
                case RF3:
                    RPF3Rbits.RPF3R=OutputPinSelection(sel);
                    break;*/
/*                case RF13:
                    RPF13Rbits.RPF13R=OutputPinSelection(sel);
                    break;
                case RC2:
                    RPC2Rbits.RPC2R=OutputPinSelection(sel);
                    break;
                case RE8:
                    RPE8Rbits.RPE8R=OutputPinSelection(sel);
                    break;
                case RF2:
                    RPF2Rbits.RPF2R=OutputPinSelection(sel);
                    break;*/
/*            }
    }
}*/

unsigned char Chip_PPS_MovablePinAssign(unsigned int sel, unsigned char port)
{
    unsigned char i;
    
    switch(sel)
    {
        case INT3:
            i=InputPinSelection_A(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                INT3Rbits.INT3R=i;
                return 0;
            }
        case T2CK:
            i=InputPinSelection_A(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                T2CKRbits.T2CKR=i;
                return 0;
            }
        case T6CK:
            i=InputPinSelection_A(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                T6CKRbits.T6CKR=i;
                return 0;
            }
        case IC3:
            i=InputPinSelection_A(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                IC3Rbits.IC3R=i;
                return 0;
            }
        case IC7:
            i=InputPinSelection_A(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                IC7Rbits.IC7R=i;
                return 0;
            }
        case U1RX:
            i=InputPinSelection_A(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                U1RXRbits.U1RXR=i;
                return 0;
            }
        case U2CTS:
            i=InputPinSelection_A(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                U2CTSRbits.U2CTSR=i;
                return 0;
            }
        case U5RX:
            i=InputPinSelection_A(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                U5RXRbits.U5RXR=i;
                return 0;
            }
        case U6CTS:
            i=InputPinSelection_A(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                U6CTSRbits.U6CTSR=i;
                return 0;
            }
            break;
        case SDI1:
            i=InputPinSelection_A(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                SDI1Rbits.SDI1R=i;
                return 0;
            }
        case SDI3:
            i=InputPinSelection_A(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                SDI3Rbits.SDI3R=i;
                return 0;
            }
/*        case SDI5:
            SDI5Rbits.SDI5R=InputPinSelection(port);
        case SS6:
            SS6Rbits.SS6R=InputPinSelection(port);*/
        case REFCLKI1:
            i=InputPinSelection_A(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                REFCLKI1Rbits.REFCLKI1R=i;
                return 0;
            }
        case INT4:
            i=InputPinSelection_B(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                INT4Rbits.INT4R=i;
                return 0;
            }
            break;
        case T5CK:
            i=InputPinSelection_B(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                T5CKRbits.T5CKR=i;
                return 0;
            }
        case T7CK:
            i=InputPinSelection_B(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                T7CKRbits.T7CKR=i;
                return 0;
            }
        case IC4:
            i=InputPinSelection_B(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                IC4Rbits.IC4R=i;
                return 0;
            }
        case IC8:
            i=InputPinSelection_B(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                IC8Rbits.IC8R=i;
                return 0;
            }
        case U3RX:
            i=InputPinSelection_B(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                U3RXRbits.U3RXR=i;
                return 0;
            }
        case U4CTS:
            i=InputPinSelection_B(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                U4CTSRbits.U4CTSR=i;
                return 0;
            }
        case SDI2:
            i=InputPinSelection_B(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                SDI2Rbits.SDI2R=i;
                return 0;
            }
        case SDI4:
            i=InputPinSelection_B(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                SDI4Rbits.SDI4R=i;
                return 0;
            }
        case C1RX:
            i=InputPinSelection_B(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                C1RXRbits.C1RXR=i;
                return 0;
            }
        case REFCLKI4:
            i=InputPinSelection_B(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                REFCLKI4Rbits.REFCLKI4R=i;
                return 0;
            }
        case INT2:
            i=InputPinSelection_C(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                INT2Rbits.INT2R=i;
                return 0;
            }
        case T3CK:
            i=InputPinSelection_C(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                T3CKRbits.T3CKR=i;
                return 0;
            }
        case T8CK:
            i=InputPinSelection_C(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                T8CKRbits.T8CKR=i;
                return 0;
            }
        case IC2:
            i=InputPinSelection_C(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                IC2Rbits.IC2R=i;
                return 0;
            }
        case IC5:
            i=InputPinSelection_C(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                IC5Rbits.IC5R=i;
                return 0;
            }
        case IC9:
            i=InputPinSelection_C(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                IC9Rbits.IC9R=i;
                return 0;
            }
        case U1CTS:
            i=InputPinSelection_C(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                U1CTSRbits.U1CTSR=i;
                return 0;
            }
        case U2RX:
            i=InputPinSelection_C(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                U2RXRbits.U2RXR=i;
                return 0;
            }
        case U5CTS:
            i=InputPinSelection_C(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                U5CTSRbits.U5CTSR=i;
                return 0;
            }
        case SS1:
            i=InputPinSelection_C(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                SS1Rbits.SS1R=i;
                return 0;
            }
        case SS3:
            i=InputPinSelection_C(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                SS3Rbits.SS3R=i;
                return 0;
            }
        case SS4:
            i=InputPinSelection_C(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                SS4Rbits.SS4R=i;
                return 0;
            }
/*        case SS5:
            SS5Rbits.SS5R=InputPinSelection(port);
            break;*/
        case C2RX:
            i=InputPinSelection_C(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                C2RXRbits.C2RXR=i;
                return 0;
            }
        case INT1:
            i=InputPinSelection_D(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                INT1Rbits.INT1R=i;
                return 0;
            }
        case T4CK:
            i=InputPinSelection_D(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                T4CKRbits.T4CKR=i;
                return 0;
            }
        case T9CK:
            i=InputPinSelection_D(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                T9CKRbits.T9CKR=i;
                return 0;
            }
        case IC1:
            i=InputPinSelection_D(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                IC1Rbits.IC1R=i;
                return 0;
            }
        case IC6:
            i=InputPinSelection_D(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                IC6Rbits.IC6R=i;
                return 0;
            }
        case U3CTS:
            i=InputPinSelection_D(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                U3CTSRbits.U3CTSR=i;
                return 0;
            }
        case U4RX:
            i=InputPinSelection_D(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                U4RXRbits.U4RXR=i;
                return 0;
            }
        case U6RX:
            i=InputPinSelection_D(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                U6RXRbits.U6RXR=i;
                return 0;
            }
        case SS2:
            i=InputPinSelection_D(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                SS2Rbits.SS2R=i;
                return 0;
            }
/*        case SDI6:
            SDI6Rbits.SDI6R=InputPinSelection(port);
            break;
        case OFCA:
            OFCARbits.OFCAR=InputPinSelection(port);
            break;*/
        case REFCLKI3:
            i=InputPinSelection_D(port);
            if(i==0xFF)
            {
                return 1;
            }
            else
            {
                REFCLKI3Rbits.REFCLKI3R=i;
                return 0;
            }
        default:
            switch(port)
            {
                case RD2:
                    i=OutputPinSelection_A(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPD2Rbits.RPD2R=i;
                        return 0;
                    }
                case RG8:
                    i=OutputPinSelection_A(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPG8Rbits.RPG8R=i;
                        return 0;
                    }
                case RF4:
                    i=OutputPinSelection_A(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPF4Rbits.RPF4R=i;
                        return 0;
                    }
                case RD10:
                    i=OutputPinSelection_A(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPD10Rbits.RPD10R=i;
                        return 0;
                    }
                case RF1:
                    i=OutputPinSelection_A(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPF1Rbits.RPF1R=i;
                        return 0;
                    }
                case RB9:
                    i=OutputPinSelection_A(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPB9Rbits.RPB9R=i;
                        return 0;
                    }
                case RB10:
                    i=OutputPinSelection_A(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPB10Rbits.RPB10R=i;
                        return 0;
                    }
                case RC14:
                    i=OutputPinSelection_A(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPC14Rbits.RPC14R=i;
                        return 0;
                    }
                case RB5:
                    i=OutputPinSelection_A(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPB5Rbits.RPB5R=i;
                        return 0;
                    }
/*                case RC1:
                    RPC1Rbits.RPC1R=OutputPinSelection(sel);
                    break;
                case RD14:
                    RPD14Rbits.RPD14R=OutputPinSelection(sel);
                    break;
                case RG1:
                    RPG1Rbits.RPG1R=OutputPinSelection(sel);
                    break;
                case RA14:
                    RPA14Rbits.RPA14R=OutputPinSelection(sel);
                    break;
                case RD6:
                    RPD6Rbits.RPD6R=OutputPinSelection(sel);
                    break;*/
                case RD3:
                    i=OutputPinSelection_B(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPD3Rbits.RPD3R=i;
                        return 0;
                    }
                case RG7:
                    i=OutputPinSelection_B(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPG7Rbits.RPG7R=i;
                        return 0;
                    }
                case RF5:
                    i=OutputPinSelection_B(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPF5Rbits.RPF5R=i;
                        return 0;
                    }
                case RD11:
                    i=OutputPinSelection_B(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPD11Rbits.RPD11R=i;
                        return 0;
                    }
                case RF0:
                    i=OutputPinSelection_B(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPF0Rbits.RPF0R=i;
                        return 0;
                    }
                case RB1:
                    i=OutputPinSelection_B(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPB1Rbits.RPB1R=i;
                        return 0;
                    }
                case RE5:
                    i=OutputPinSelection_B(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPE5Rbits.RPE5R=i;
                        return 0;
                    }
                case RC13:
                    i=OutputPinSelection_B(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPC13Rbits.RPC13R=i;
                        return 0;
                    }
                case RB3:
                    i=OutputPinSelection_B(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPB3Rbits.RPB3R=i;
                        return 0;
                    }
/*                case RC4:
                    RPC4Rbits.RPC4R=OutputPinSelection(sel);
                    break;
                case RD15:
                    RPD15Rbits.RPD15R=OutputPinSelection(sel);
                    break;
                case RG0:
                    RPG0Rbits.RPG0R=OutputPinSelection(sel);
                    break;
                case RA15:
                    RPA15Rbits.RPA15R=OutputPinSelection(sel);
                    break;
                case RD7:
                    RPD7Rbits.RPD7R=OutputPinSelection(sel);
                    break;*/
                case RD9:
                    i=OutputPinSelection_C(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPD9Rbits.RPD9R=i;
                        return 0;
                    }
                case RG6:
                    i=OutputPinSelection_C(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPG6Rbits.RPG6R=i;
                        return 0;
                    }
                case RB8:
                    i=OutputPinSelection_C(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPB8Rbits.RPB8R=i;
                        return 0;
                    }
                case RB15:
                    i=OutputPinSelection_C(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPB15Rbits.RPB15R=i;
                        return 0;
                    }
                case RD4:
                    i=OutputPinSelection_C(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPD4Rbits.RPD4R=i;
                        return 0;
                    }
                case RB0:
                    i=OutputPinSelection_C(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPB0Rbits.RPB0R=i;
                        return 0;
                    }
                case RE3:
                    i=OutputPinSelection_C(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPE3Rbits.RPE3R=i;
                        return 0;
                    }
                case RB7:
                    i=OutputPinSelection_C(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPB7Rbits.RPB7R=i;
                        return 0;
                    }
/*                case RF12:
                    RPF12Rbits.RPF12R=OutputPinSelection(sel);
                    break;
                case RD12:
                    RPD12Rbits.RPD12R=OutputPinSelection(sel);
                    break;
                case RF8:
                    RPF8Rbits.RPF8R=OutputPinSelection(sel);
                    break;
                case RC3:
                    RPC3Rbits.RPC3R=OutputPinSelection(sel);
                    break;
                case RE9:
                    RPE9Rbits.RPE9R=OutputPinSelection(sel);
                    break;*/
                case RD1:
                    i=OutputPinSelection_D(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPD1Rbits.RPD1R=i;
                        return 0;
                    }
                case RG9:
                    i=OutputPinSelection_D(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPG9Rbits.RPG9R=i;
                        return 0;
                    }
                case RB14:
                    i=OutputPinSelection_D(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPB14Rbits.RPB14R=i;
                        return 0;
                    }
                case RD0:
                    i=OutputPinSelection_D(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPD0Rbits.RPD0R=i;
                        return 0;
                    }
                case RB6:
                    i=OutputPinSelection_D(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPB6Rbits.RPB6R=i;
                        return 0;
                    }
                case RD5:
                    i=OutputPinSelection_D(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPD5Rbits.RPD5R=i;
                        return 0;
                    }
                case RB2:
                    i=OutputPinSelection_D(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPB2Rbits.RPB2R=i;
                        return 0;
                    }
                case RF3:
                    i=OutputPinSelection_D(sel);
                    if(i==0xFF)
                    {
                        return 1;
                    }
                    else
                    {
                        RPF3Rbits.RPF3R=i;
                        return 0;
                    }
/*                case RF13:
                    RPF13Rbits.RPF13R=OutputPinSelection(sel);
                    break;
                case RC2:
                    RPC2Rbits.RPC2R=OutputPinSelection(sel);
                    break;
                case RE8:
                    RPE8Rbits.RPE8R=OutputPinSelection(sel);
                    break;
                case RF2:
                    RPF2Rbits.RPF2R=OutputPinSelection(sel);
                    break;*/
            }
    }
}


#endif	/* GPIO_H */

