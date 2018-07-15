#ifndef CLOCK_H
#define	CLOCK_H

#include "xc.h"

void SystemUnlock()
{
    /*DMAの中断*/
    if (!DMACONbits.SUSPEND)
    {
        DMACONSET = _DMACON_SUSPEND_MASK;
        while (DMACONbits.DMABUSY);
    }

    /*アンロック*/
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;    
}

void SystemLock()
{
    /*ロック*/
    SYSKEY = 0x33333333;
    
    if (!DMACONbits.SUSPEND)
    {
        DMACONCLR = _DMACON_SUSPEND_MASK;
    }
}

void SystemCoreClockUpdate()
{
    SystemUnlock();
    
    //入力をSPLLに変更。
    OSCCONbits.NOSC=0b001;
    //クロックを更新。
    OSCCONbits.OSWEN=1;
    while(OSCCONbits.OSWEN);
    
    SystemLock();
}

void AccelerationBoost()
{
    SystemUnlock();
    
    //SystemPLLの入力をFRCオシレータに変更
    SPLLCONbits.PLLICLK=1;
    //8/2=4MHz
    SPLLCONbits.PLLIDIV=0b001;
    //入力は8MHzなので0~5MHz
    SPLLCONbits.PLLRANGE=0b001;
    //4*50=200MHz
    SPLLCONbits.PLLMULT=0b110001;
    //ホントは1/2倍なんやけどわからん。
    SPLLCONbits.PLLODIV=0b001;
    
    SystemLock();
}

/*unsigned int GetSystemClock()
{
    unsigned char i, j;
    
    switch(OSCCONbits.COSC)
    {
        case 0b000:
        case 0b111:
            i=0;
            j=1;
            while(1)
            {
                if(i==OSCCONbits.FRCDIV)
                {
                    break;
                }
                i=i+1;
                j=j*2;
            }
            return 8000/j;
        case 0b001:
            
            
    }
}*/

#endif	/* CLOCK_H */

