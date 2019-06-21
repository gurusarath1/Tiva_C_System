#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "General_Data.h"
#include "TivaC_TM4C123GH6PM_TIMERS.h"


TIMER_ERROR_CODE TIMER_init(int timerX, char timerX_Y, TIMER_SIZE timerSize, int LoadValue, DIRECTION dir)
{
    volatile uint32_t * TIMER_X_CONFIG_REGISTER;
    volatile uint32_t * TIMER_X_CONTROL_REGISTER;
    volatile uint32_t * TIMER_XY_INTERVAL_LOAD_REGISTER;
    volatile uint32_t * TIMER_XY_MODE_REGISTER;

    if(timerSize == TIMER_64BIT || (timerSize == TIMER_32BIT && timerX_Y == 'B'))
    {
        return INVALID_CONFIG;
    }

    switch(timerX)
    {
    case 0:
        SYSCTL_RCGCTIMER_R |= BIT0;
        TIMER_X_CONFIG_REGISTER = &TIMER0_CFG_R;
        TIMER_X_CONTROL_REGISTER = &TIMER0_CTL_R;

        if(timerX_Y == 'A')
        {
            TIMER_XY_INTERVAL_LOAD_REGISTER = &TIMER0_TAILR_R;
            TIMER_XY_MODE_REGISTER = &TIMER0_TAMR_R;

        } else if (timerX_Y == 'B') {

            TIMER_XY_INTERVAL_LOAD_REGISTER = &TIMER0_TBILR_R;
            TIMER_XY_MODE_REGISTER = &TIMER0_TBMR_R;
        }
        break;


    case 1:
        SYSCTL_RCGCTIMER_R |= BIT1;
        TIMER_X_CONFIG_REGISTER = &TIMER1_CFG_R;
        TIMER_X_CONTROL_REGISTER = &TIMER1_CTL_R;

        if(timerX_Y == 'A')
        {
            TIMER_XY_INTERVAL_LOAD_REGISTER = &TIMER1_TAILR_R;
            TIMER_XY_MODE_REGISTER = &TIMER1_TAMR_R;

        } else if (timerX_Y == 'B') {

            TIMER_XY_INTERVAL_LOAD_REGISTER = &TIMER1_TBILR_R;
            TIMER_XY_MODE_REGISTER = &TIMER1_TBMR_R;
        }
        break;



    case 2:
        SYSCTL_RCGCTIMER_R |= BIT2;
        TIMER_X_CONFIG_REGISTER = &TIMER2_CFG_R;
        TIMER_X_CONTROL_REGISTER = &TIMER2_CTL_R;

        if(timerX_Y == 'A')
        {
            TIMER_XY_INTERVAL_LOAD_REGISTER = &TIMER2_TAILR_R;
            TIMER_XY_MODE_REGISTER = &TIMER2_TAMR_R;

        } else if (timerX_Y == 'B') {

            TIMER_XY_INTERVAL_LOAD_REGISTER = &TIMER2_TBILR_R;
            TIMER_XY_MODE_REGISTER = &TIMER2_TBMR_R;
        }
        break;


    case 3:
        SYSCTL_RCGCTIMER_R |= BIT3;
        TIMER_X_CONFIG_REGISTER = &TIMER3_CFG_R;
        TIMER_X_CONTROL_REGISTER = &TIMER3_CTL_R;

        if(timerX_Y == 'A')
        {
            TIMER_XY_INTERVAL_LOAD_REGISTER = &TIMER3_TAILR_R;
            TIMER_XY_MODE_REGISTER = &TIMER3_TAMR_R;

        } else if (timerX_Y == 'B') {

            TIMER_XY_INTERVAL_LOAD_REGISTER = &TIMER3_TBILR_R;
            TIMER_XY_MODE_REGISTER = &TIMER3_TBMR_R;
        }
        break;

    case 4:
        SYSCTL_RCGCTIMER_R |= BIT4;
        TIMER_X_CONFIG_REGISTER = &TIMER4_CFG_R;
        TIMER_X_CONTROL_REGISTER = &TIMER4_CTL_R;

        if(timerX_Y == 'A')
        {
            TIMER_XY_INTERVAL_LOAD_REGISTER = &TIMER4_TAILR_R;
            TIMER_XY_MODE_REGISTER = &TIMER4_TAMR_R;

        } else if (timerX_Y == 'B') {

            TIMER_XY_INTERVAL_LOAD_REGISTER = &TIMER4_TBILR_R;
            TIMER_XY_MODE_REGISTER = &TIMER4_TBMR_R;
        }
        break;



    case 5:
        SYSCTL_RCGCTIMER_R |= BIT5;
        TIMER_X_CONFIG_REGISTER = &TIMER5_CFG_R;
        TIMER_X_CONTROL_REGISTER = &TIMER5_CTL_R;

        if(timerX_Y == 'A')
        {
            TIMER_XY_INTERVAL_LOAD_REGISTER = &TIMER5_TAILR_R;
            TIMER_XY_MODE_REGISTER = &TIMER5_TAMR_R;

        } else if (timerX_Y == 'B') {

            TIMER_XY_INTERVAL_LOAD_REGISTER = &TIMER5_TBILR_R;
            TIMER_XY_MODE_REGISTER = &TIMER5_TBMR_R;
        }
        break;

    }

    // SET TO MODE

    if(timerX_Y == 'A')
    {
        *TIMER_X_CONTROL_REGISTER &= ~(TIMER_CTL_TAEN); //Disable Timer
        *TIMER_X_CONFIG_REGISTER = 0x0;
        *TIMER_XY_MODE_REGISTER = TIMER_TAMR_TAMR_PERIOD;
        *TIMER_XY_INTERVAL_LOAD_REGISTER = LoadValue;

        if(dir == UP)
        {
            *TIMER_XY_MODE_REGISTER |= TIMER_TAMR_TACDIR;
        } else {
            *TIMER_XY_MODE_REGISTER &= ~TIMER_TAMR_TACDIR;
        }

    } else if (timerX_Y == 'B')
    {
        *TIMER_X_CONTROL_REGISTER &= ~(TIMER_CTL_TBEN); //Disable Timer

        if(timerSize == TIMER_32BIT)
        {
            *TIMER_X_CONFIG_REGISTER = TIMER_CFG_32_BIT_TIMER;

        } else if(timerSize == TIMER_16BIT)
        {
            *TIMER_X_CONFIG_REGISTER = TIMER_CFG_16_BIT;
        }

        *TIMER_XY_MODE_REGISTER = TIMER_TBMR_TBMR_PERIOD;
        *TIMER_XY_INTERVAL_LOAD_REGISTER = LoadValue;

        if(dir == UP)
        {
            *TIMER_XY_MODE_REGISTER |= TIMER_TBMR_TBCDIR;
        } else {
            *TIMER_XY_MODE_REGISTER &= ~TIMER_TBMR_TBCDIR;
        }
    }

    return TIMER_SUCCESS;

}

TIMER_ERROR_CODE TIMER_start(int timerX, char timerX_Y)
{
    if( (timerX > 5 || timerX < 0) || (timerX_Y != 'A' && timerX_Y != 'B') )
    {
        return INVALID_CONFIG;
    }

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
        break;

    case 1:
        if(timerX_Y == 'A')
        {
            TIMER1_CTL_R |= TIMER_CTL_TAEN;
        } else if (timerX_Y == 'B')
        {
            TIMER1_CTL_R |= TIMER_CTL_TBEN;
        }
        break;

    case 2:
        if(timerX_Y == 'A')
        {
            TIMER2_CTL_R |= TIMER_CTL_TAEN;
        } else if (timerX_Y == 'B')
        {
            TIMER2_CTL_R |= TIMER_CTL_TBEN;
        }
        break;

    case 3:
        if(timerX_Y == 'A')
        {
            TIMER3_CTL_R |= TIMER_CTL_TAEN;
        } else if (timerX_Y == 'B')
        {
            TIMER3_CTL_R |= TIMER_CTL_TBEN;
        }
        break;


    case 4:
        if(timerX_Y == 'A')
        {
            TIMER4_CTL_R |= TIMER_CTL_TAEN;
        } else if (timerX_Y == 'B')
        {
            TIMER4_CTL_R |= TIMER_CTL_TBEN;
        }
        break;

    case 5:
        if(timerX_Y == 'A')
        {
            TIMER5_CTL_R |= TIMER_CTL_TAEN;
        } else if (timerX_Y == 'B')
        {
            TIMER5_CTL_R |= TIMER_CTL_TBEN;
        }
        break;
    }

    return TIMER_SUCCESS;

}


TIMER_ERROR_CODE TIMER_pause(int timerX, char timerX_Y)
{

    if( (timerX > 5 || timerX < 0) || (timerX_Y != 'A' && timerX_Y != 'B') )
    {
        return INVALID_CONFIG;
    }

    switch(timerX)
    {
    case 0:
        if(timerX_Y == 'A')
        {
            TIMER0_CTL_R &= ~TIMER_CTL_TAEN;
        } else if (timerX_Y == 'B')
        {
            TIMER0_CTL_R &= ~TIMER_CTL_TBEN;
        }
        break;

    case 1:
        if(timerX_Y == 'A')
        {
            TIMER1_CTL_R &= ~TIMER_CTL_TAEN;
        } else if (timerX_Y == 'B')
        {
            TIMER1_CTL_R &= ~TIMER_CTL_TBEN;
        }
        break;

    case 2:
        if(timerX_Y == 'A')
        {
            TIMER2_CTL_R &= ~TIMER_CTL_TAEN;
        } else if (timerX_Y == 'B')
        {
            TIMER2_CTL_R &= ~TIMER_CTL_TBEN;
        }
        break;

    case 3:
        if(timerX_Y == 'A')
        {
            TIMER3_CTL_R &= ~TIMER_CTL_TAEN;
        } else if (timerX_Y == 'B')
        {
            TIMER3_CTL_R &= ~TIMER_CTL_TBEN;
        }
        break;


    case 4:
        if(timerX_Y == 'A')
        {
            TIMER4_CTL_R &= ~TIMER_CTL_TAEN;
        } else if (timerX_Y == 'B')
        {
            TIMER4_CTL_R &= ~TIMER_CTL_TBEN;
        }
        break;

    case 5:
        if(timerX_Y == 'A')
        {
            TIMER5_CTL_R &= ~TIMER_CTL_TAEN;
        } else if (timerX_Y == 'B')
        {
            TIMER5_CTL_R &= ~TIMER_CTL_TBEN;
        }
        break;
    }

    return TIMER_SUCCESS;

}

BOOL_STATE TIMER_checkTimeOut(int timerX, char timerX_Y)
{
    BOOL_STATE state;

    switch(timerX)
    {
    case 0:
        if(timerX_Y == 'A')
        {
            state = (TIMER0_RIS_R & TIMER_RIS_TATORIS);
        } else if (timerX_Y == 'B')
        {
            state = (TIMER0_RIS_R & TIMER_RIS_TBTORIS);
        }
        break;

    case 1:
        if(timerX_Y == 'A')
        {
            state = (TIMER1_RIS_R & TIMER_RIS_TATORIS);
        } else if (timerX_Y == 'B')
        {
            state = (TIMER1_RIS_R & TIMER_RIS_TBTORIS);
        }
        break;

    case 2:
        if(timerX_Y == 'A')
        {
            state = (TIMER2_RIS_R & TIMER_RIS_TATORIS);
        } else if (timerX_Y == 'B')
        {
            state = (TIMER2_RIS_R & TIMER_RIS_TBTORIS);
        }
        break;

    case 3:
        if(timerX_Y == 'A')
        {
            state = (TIMER3_RIS_R & TIMER_RIS_TATORIS);
        } else if (timerX_Y == 'B')
        {
            state = (TIMER3_RIS_R & TIMER_RIS_TBTORIS);
        }
        break;

    case 4:
        if(timerX_Y == 'A')
        {
            state = (TIMER4_RIS_R & TIMER_RIS_TATORIS);
        } else if (timerX_Y == 'B')
        {
            state = (TIMER4_RIS_R & TIMER_RIS_TBTORIS);
        }
        break;

    case 5:
        if(timerX_Y == 'A')
        {
            state = (TIMER5_RIS_R & TIMER_RIS_TATORIS);
        } else if (timerX_Y == 'B')
        {
            state = (TIMER5_RIS_R & TIMER_RIS_TBTORIS);
        }
        break;
    }

    if(state > 0)
    {
        return TRUE;
    }

    return FALSE;
}

TIMER_ERROR_CODE TIMER_clearRawInterrupt(int timerX, char timerX_Y)
{
    if( (timerX > 5 || timerX < 0) || (timerX_Y != 'A' && timerX_Y != 'B') )
    {
        return INVALID_CONFIG;
    }

    switch(timerX)
    {
    case 0:

        if(timerX_Y == 'A')
        {
            TIMER0_ICR_R |= TIMER_ICR_TATOCINT;

        } else if (timerX_Y == 'B')
        {
            TIMER0_ICR_R |= TIMER_ICR_TBTOCINT;
        }

        break;

    case 1:

        if(timerX_Y == 'A')
        {
            TIMER1_ICR_R |= TIMER_ICR_TATOCINT;

        } else if (timerX_Y == 'B')
        {
            TIMER1_ICR_R |= TIMER_ICR_TBTOCINT;
        }

        break;

    case 2:

        if(timerX_Y == 'A')
        {
            TIMER2_ICR_R |= TIMER_ICR_TATOCINT;

        } else if (timerX_Y == 'B')
        {
            TIMER2_ICR_R |= TIMER_ICR_TBTOCINT;
        }

        break;

    case 3:

        if(timerX_Y == 'A')
        {
            TIMER3_ICR_R |= TIMER_ICR_TATOCINT;

        } else if (timerX_Y == 'B')
        {
            TIMER3_ICR_R |= TIMER_ICR_TBTOCINT;
        }

        break;

    case 4:

        if(timerX_Y == 'A')
        {
            TIMER4_ICR_R |= TIMER_ICR_TATOCINT;

        } else if (timerX_Y == 'B')
        {
            TIMER4_ICR_R |= TIMER_ICR_TBTOCINT;
        }

        break;

    case 5:

        if(timerX_Y == 'A')
        {
            TIMER5_ICR_R |= TIMER_ICR_TATOCINT;

        } else if (timerX_Y == 'B')
        {
            TIMER5_ICR_R |= TIMER_ICR_TBTOCINT;
        }

        break;
    }


    return TIMER_SUCCESS;
}
