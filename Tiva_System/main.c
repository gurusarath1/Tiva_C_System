

#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "General_Data.h"
#include "TivaC_TM4C123GH6PM_GPIO.h"


void delayMs(int n);


int main(void)
{
    int i = 0;

    GPIO_mode('F', BIT1, OUTPUT);
    TIMER_init(0, 'A', DOWN);
    TIMER_start(0, 'A');

    while(1){
        if((TIMER0_RIS_R & 0x1) == 1)
        {
            TIMER0_ICR_R = 1;
            GPIO_Write('F', BIT1, TOGGLE);
            i++;
            if(i == 60) break;
        }
    }

    while(1);

	return 0;
}


void delayMs(int n)
{
    int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3180; j++){} /* do nothing for 1 ms */
}

