#include "General_Data.h"
#include "TivaC_TM4C123GH6PM_GPIO.h"

char GPIO_mode(unsigned char PortSelect, BIT_LOCATION BitSelect, IO_DIRECTION DirectionSelect)
{

    if(PortSelect == 'A') {

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
        if(DirectionSelect == OUTPUT) {
            GPIO_PORTD_DIR_R |= BitSelect;
        }
        else {
            GPIO_PORTD_DIR_R &= ~((uint32_t)BitSelect);
            GPIO_PORTD_PUR_R |= BitSelect;
        }

        GPIO_PORTD_DEN_R |= BitSelect;
        return VALID;
    }

    if(PortSelect == 'E'){
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
        if(DirectionSelect == OUTPUT) {
            GPIO_PORTF_DIR_R |= BitSelect;
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
        return GPIO_Write_support(&GPIO_PORTD_DATA_R, BitSelect, operation);
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
