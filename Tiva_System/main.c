

#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "General_Data.h"
#include "TivaC_TM4C123GH6PM_GPIO.h"


void delayMs(int n);


int main(void)
{
    SYSCTL_RCGC2_R |= 0x00000020;
    GPIO_mode('F',BIT2|BIT1,OUTPUT);
    GPIO_mode('F',BIT4,INPUT);
    while(1)
    {
        GPIO_Write('F',BIT2,TOGGLE);

        delayMs(100);

        if(GPIO_ReadBit('F',BIT4) == LOW)
        {
            GPIO_Write('F',BIT1,TOGGLE);
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

