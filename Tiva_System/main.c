

#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "General_Data.h"
#include "TivaC_TM4C123GH6PM_GPIO.h"


void delayMs(int n);


int main(void)
{

    GPIO_mode('B',BIT3,OUTPUT);
    GPIO_mode('B',BIT2,INPUT);
    while(1)
    {

        if(GPIO_ReadBit('B',BIT2)==LOW)
        GPIO_Write('B',BIT3,TOGGLE);


           delayMs(100);
    }

	return 0;
}


void delayMs(int n)
{
    int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3180; j++){} /* do nothing for 1 ms */
}

