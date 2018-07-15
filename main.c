#include "pichip.h"

/*void SPI_Setup()
{
    SPI1CONbits.FRMEN=1;
    SPI1CONbits.FRMSYNC=0;//マスターに設定
    SPI1CONbits.FRMPOL=
    
    SPI1CONbits.ON=1;
}*/

void main()
{
    AccelerationBoost();
    SystemCoreClockUpdate();
    
    Chip_PPS_MovablePinAssign(U1RX, RD2);
    Chip_PPS_MovablePinAssign(U1TX, RD3);
    Chip_PPS_MovablePinAssign(OC1, RD1);
    Chip_GPIO_SetPinDIROutput(RE6);
    Chip_GPIO_SetPinDIRInput(RD4);
    
    uartSetup();
    
    uartPuts("Hello world!!!\r\n");
    uartPuts("Really?!\r\n");
    uartPuts(formItoa(114514));
    
    PwmSetup(0, OC1);
    Chip_PWM_SetPinOut(OC1, 7000);
    
    while(1)
    {
        uartPutch(uartGetch());
        if(Chip_GPIO_GetPinState(RD4))
        {
            Chip_GPIO_SetPinOutHigh(RE6);
        }
        else
        {
            Chip_GPIO_SetPinOutLow(RE6);
            uartPutch('U');
        }
    }
}
