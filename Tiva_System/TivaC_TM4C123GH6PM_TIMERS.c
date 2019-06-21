#include "TivaC_TM4C123GH6PM_TIMERS.h"

void TIMER_init(int timerX, char timerX_Y , DIRECTION dir)
{
    switch(timerX)
    {
    case 0:

        SYSCTL_RCGCTIMER_R |= BIT0;
        TIMER0_CFG_R = 0x0;

        if(timerX_Y == 'A')
        {
            TIMER0_CTL_R &= ~(TIMER_CTL_TAEN); //Disable Timer
            TIMER0_TAMR_R = TIMER_TAMR_TAMR_PERIOD;
            TIMER0_TAILR_R = 0x7A1200;

            if(dir == UP)
            {
                TIMER0_TAMR_R |= TIMER_TAMR_TACDIR;
            } else {

                TIMER0_TAMR_R &= ~TIMER_TAMR_TACDIR;
            }


        } else if (timerX_Y == 'B')
        {
            TIMER0_CTL_R &= ~(TIMER_CTL_TBEN); //Disable Timer
            TIMER0_TBMR_R = TIMER_TBMR_TBMR_PERIOD;
            TIMER0_TBILR_R = 0x7A1200;

            if(dir == UP)
            {
                TIMER0_TBMR_R |= TIMER_TBMR_TBCDIR;
            } else {
                TIMER0_TBMR_R &= ~TIMER_TBMR_TBCDIR;
            }
        }

        break;
    }
}

void TIMER_start(int timerX, char timerX_Y)
{
    switch(timerX)
    {
    case 0:
        if(timerX_Y == 'A')
        {
            TIMER0_CTL_R |= TIMER_CTL_TAEN;
        } else if (timerX_Y == 'B')
        {
            TIMER0_CTL_R |= TIMER_CTL_TBEN;
        }

    }
}


int TIMER_read(int timerX)
{
    switch(timerX)
    {
    case 0:
        return TIMER0_TAV_R & (TIMER0_TBV_R << 31);
    case 1:
        return 0;
    case 2:
        return 0;
    case 3:
        return 0;
    default:
        return 0;
    }

    return 0;
}

int TIMER_stop(int timerX)
{
    switch(timerX)
    {
    case 0:
        TIMER0_CTL_R &= ~(TIMER_CTL_TAEN);
        return 0;
    }

    return 0;
}
