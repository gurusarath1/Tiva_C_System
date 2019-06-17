#include <stdint.h>
#include "inc/tm4c123gh6pm.h"

#define GPIO_PORT_UNLOCK 0x4C4F434B

char GPIO_mode(unsigned char PortSelect, BIT_LOCATION BitSelect, IO_DIRECTION DirectionSelect);
FUNCTION_ERROR_RETURN GPIO_Write(unsigned char PortSelect, BIT_LOCATION BitSelect, BIT_OP operation);
FUNCTION_ERROR_RETURN GPIO_Write_support(volatile uint32_t *Register, BIT_LOCATION BitSelect, BIT_OP operation);
BIT_STATE GPIO_ReadBit(unsigned char PortSelect, BIT_LOCATION BitSelect);
BIT_STATE GPIO_ReadBit_support(volatile uint32_t *Register, BIT_LOCATION BitSelect);
