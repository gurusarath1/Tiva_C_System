

#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "General_Data.h"
#include "TivaC_TM4C123GH6PM_GPIO.h"
#include "TivaC_TM4C123GH6PM_TIMERS.h"
#include "TivaC_TM4C123GH6PM_EEPROM.h"

void delayMs(int n);


int main(void)
{
    int a;
    EEPROM_init();

   // EEPROM_EERDWRINC_R = 0x1234;
   // while(EEPROM_EEDONE_R & 0x1);
   // EEPROM_EEOFFSET_R += 1;
   // EEPROM_EERDWR_R = 0x998;
    a = 0;
    /*
    while(1)
    {
        a++;
        EEPROM_write(a);
        delayMs(100);
    }
    */

    while(1)
    {
        a = EEPROM_read();
    }



	return 0;
}


void delayMs(int n)
{
    int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3180; j++){} /* do nothing for 1 ms */
}

