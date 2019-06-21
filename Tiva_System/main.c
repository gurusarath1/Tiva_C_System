

#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "General_Data.h"
#include "TivaC_TM4C123GH6PM_GPIO.h"
#include "TivaC_TM4C123GH6PM_TIMERS.h"

void delayMs(int n);


int main(void)
{

    GPIO_mode('F', BIT2, OUTPUT);
    GPIO_mode('F', BIT1, OUTPUT);
    GPIO_mode('F', BIT3, OUTPUT);

    TIMER_init(5, 'A',TIMER_16BIT ,0xFFFF ,DOWN);
    TIMER_init(5, 'B',TIMER_16BIT ,0xAAAA ,DOWN);
    TIMER_start(5, 'A');
    delayMs(100);
    TIMER_start(5, 'B');
    delayMs(100);
    delayMs(100);
    TIMER_pause(5, 'B');
    delayMs(100);
    delayMs(100);

    TIMER_init(2, 'A',TIMER_32BIT ,0x7A1200 ,DOWN);
    TIMER_start(2, 'A');
    TIMER_init(3, 'A',TIMER_32BIT ,0x9FFF00 ,DOWN);
    TIMER_start(3, 'A');
    TIMER_init(4, 'A',TIMER_32BIT ,0x10FFF00 ,UP);
    TIMER_start(4, 'A');

    while(1){
        if(TIMER_checkTimeOut(2, 'A'))
        {
            TIMER_clearRawInterrupt(2, 'A');
            GPIO_Write('F', BIT2, TOGGLE);
        }

        if(TIMER_checkTimeOut(3, 'A'))
        {
            TIMER_clearRawInterrupt(3, 'A');
            GPIO_Write('F', BIT1, TOGGLE);
        }

        if(TIMER_checkTimeOut(4, 'A'))
        {
            TIMER_clearRawInterrupt(4, 'A');
            GPIO_Write('F', BIT3, TOGGLE);
        }
    }


	return 0;
}


void delayMs(int n)
{
    int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3180; j++){} /* do nothing for 1 ms */
}

