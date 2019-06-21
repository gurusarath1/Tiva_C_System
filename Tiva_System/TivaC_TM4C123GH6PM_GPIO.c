#include "General_Data.h"
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "TivaC_TM4C123GH6PM_GPIO.h"

char GPIO_mode(unsigned char PortSelect, BIT_LOCATION BitSelect, IO_DIRECTION DirectionSelect)
{

    if(PortSelect == 'A') {

        SYSCTL_RCGC2_R |= BIT0; //Run Mode Clock gating control register

        if(DirectionSelect == OUTPUT) {
            GPIO_PORTA_DIR_R |= BitSelect;
        }
        else {
            GPIO_PORTA_DIR_R &= ~((uint32_t)BitSelect);
            GPIO_PORTA_PUR_R |= BitSelect;
        }

        GPIO_PORTA_DEN_R |= BitSelect;
        return VALID;
    }

    if(PortSelect == 'B'){

        SYSCTL_RCGC2_R |= BIT1; //Enable Port B

        if(DirectionSelect == OUTPUT) {
            GPIO_PORTB_DIR_R |= BitSelect;
        }
        else {
            GPIO_PORTB_DIR_R &= ~((uint32_t)BitSelect);
            GPIO_PORTB_PUR_R |= BitSelect;
        }

        GPIO_PORTB_DEN_R |= BitSelect;
        return VALID;
    }

    if(PortSelect == 'C'){

        SYSCTL_RCGC2_R |= BIT2; //Enable Port C

        if(DirectionSelect == OUTPUT) {
            GPIO_PORTC_DIR_R |= BitSelect;
        }
        else {
            GPIO_PORTC_DIR_R &= ~((uint32_t)BitSelect);
            GPIO_PORTC_PUR_R |= BitSelect;
        }

        GPIO_PORTC_DEN_R |= BitSelect;
        return VALID;
    }

    if(PortSelect == 'D'){

        SYSCTL_RCGC2_R |= BIT3; //Enable Port D

        if(DirectionSelect == OUTPUT) {

            if(BitSelect == BIT7)
            {
                GPIO_PORTD_LOCK_R = GPIO_PORT_UNLOCK; //Unlock Port
                GPIO_PORTD_CR_R = 0xFF;
            }

            GPIO_PORTD_DIR_R |= BitSelect;
            GPIO_PORTD_DEN_R |= BitSelect;

            if(BitSelect == BIT7)
            {
                GPIO_PORTD_CR_R = 0x00; //Commit
            }
        }
        else {
            GPIO_PORTD_LOCK_R = GPIO_PORT_UNLOCK; //Unlock Port
            GPIO_PORTD_CR_R = 0xFF;

            GPIO_PORTD_DIR_R &= ~((uint32_t)BitSelect);
            GPIO_PORTD_PUR_R |= BitSelect;
            GPIO_PORTD_DEN_R |= BitSelect;

            GPIO_PORTD_CR_R = 0x00; //Commit
        }


        return VALID;
    }

    if(PortSelect == 'E'){

        SYSCTL_RCGC2_R |= BIT4; //Enable Port E

        if(DirectionSelect == OUTPUT) {
            GPIO_PORTE_DIR_R |= BitSelect;
        }
        else {
            GPIO_PORTE_DIR_R &= ~((uint32_t)BitSelect);
            GPIO_PORTE_PUR_R |= BitSelect;
        }

        GPIO_PORTE_DEN_R |= BitSelect;
        return VALID;
    }

    if(PortSelect == 'F'){

        SYSCTL_RCGC2_R |= BIT5; //Enable Port F

        if(DirectionSelect == OUTPUT) {

            if(BitSelect == BIT0)
            {
                GPIO_PORTF_LOCK_R = GPIO_PORT_UNLOCK; //Unlock Port
                GPIO_PORTF_CR_R = 0xFF;
            }

            GPIO_PORTF_DIR_R |= BitSelect;

            if(BitSelect == BIT0)
            {
                GPIO_PORTF_CR_R = 0x00; //Commit
            }

        }
        else {
            GPIO_PORTF_DIR_R &= ~((uint32_t)BitSelect);
            GPIO_PORTF_PUR_R |= BitSelect;
        }

        GPIO_PORTF_DEN_R |= BitSelect;
        return VALID;
    }

    return INVALID_PORT; //invalid port
}


FUNCTION_ERROR_RETURN GPIO_Write(unsigned char PortSelect, BIT_LOCATION BitSelect, BIT_OP operation)
{
    if(PortSelect == 'A') {
        return GPIO_Write_support(&GPIO_PORTA_DATA_R, BitSelect, operation);
    }

    if(PortSelect == 'B'){
        return GPIO_Write_support(&GPIO_PORTB_DATA_R, BitSelect, operation);
    }

    if(PortSelect == 'C'){
        return GPIO_Write_support(&GPIO_PORTC_DATA_R, BitSelect, operation);
    }

    if(PortSelect == 'D'){
        //GPIO_PORTD_LOCK_R = GPIO_PORT_UNLOCK;
        //GPIO_PORTD_CR_R = 0xFF;
        GPIO_Write_support(&GPIO_PORTD_DATA_R, BitSelect, operation);
        //GPIO_PORTD_CR_R = 0x0;
        return 1;
    }

    if(PortSelect == 'E'){
        return GPIO_Write_support(&GPIO_PORTE_DATA_R, BitSelect, operation);
    }

    if(PortSelect == 'F'){
        return GPIO_Write_support(&GPIO_PORTF_DATA_R, BitSelect, operation);
    }

    return INVALID_PORT; //invalid port
}

FUNCTION_ERROR_RETURN GPIO_Write_support(volatile uint32_t *Register, BIT_LOCATION BitSelect, BIT_OP operation)
{
    if(operation == SET)
    {
        *Register |= BitSelect;
        return VALID;
    } else if (operation == CLEAR)
    {
        *Register &= ~((uint32_t)BitSelect);
        return VALID;
    } else if (operation == TOGGLE)
    {
        *Register ^= BitSelect;
        return VALID;
    }

    return INVALID_OPERATION; //Invalid opeartion
}


BIT_STATE GPIO_ReadBit(unsigned char PortSelect, BIT_LOCATION BitSelect)
{
    if(PortSelect == 'A') {
        return GPIO_ReadBit_support(&GPIO_PORTA_DATA_R, BitSelect);
    }

    if(PortSelect == 'B'){
        return GPIO_ReadBit_support(&GPIO_PORTB_DATA_R, BitSelect);
    }

    if(PortSelect == 'C'){
        return GPIO_ReadBit_support(&GPIO_PORTC_DATA_R, BitSelect);
    }

    if(PortSelect == 'D'){
        return GPIO_ReadBit_support(&GPIO_PORTD_DATA_R, BitSelect);
    }

    if(PortSelect == 'E'){
        return GPIO_ReadBit_support(&GPIO_PORTE_DATA_R, BitSelect);
    }

    if(PortSelect == 'F'){
        return GPIO_ReadBit_support(&GPIO_PORTF_DATA_R, BitSelect);
    }

    return UNKNOWN; //invalid port
}

BIT_STATE GPIO_ReadBit_support(volatile uint32_t *Register, BIT_LOCATION BitSelect)
{
    if ((*Register) & BitSelect)
    {
        return HIGH;
    } else {
        return LOW;
    }
}
