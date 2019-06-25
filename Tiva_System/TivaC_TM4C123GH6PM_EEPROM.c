#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "TivaC_TM4C123GH6PM_EEPROM.h"



static int TOTAL_EEPROM_SIZE; // Total number of 32 bit words
static int NUMBER_OF_BLOCKS;
static int NUMBER_OF_WORDS; // Number of words in each block

void EEPROM_init()
{
    SYSCTL_RCGCEEPROM_R |= 0x01;
    EEPROM_waitUntilFree();

    NUMBER_OF_BLOCKS = (EEPROM_EESIZE_R & 0x000007FF0000) >> 16;
    NUMBER_OF_WORDS = (EEPROM_EESIZE_R & 0xFFFF) / NUMBER_OF_BLOCKS; // (EEPROM_EESIZE_R & 0xFFFF) = Total number of 32 bit words

    TOTAL_EEPROM_SIZE = NUMBER_OF_BLOCKS * NUMBER_OF_WORDS;
}

int EEPROM_getSize()
{
    return TOTAL_EEPROM_SIZE;
}

int EEPROM_getBlockNum()
{
    return EEPROM_EEBLOCK_R;
}

int EEPROM_getOffsetNum()
{
    return EEPROM_EEOFFSET_R;
}

void EEPROM_waitUntilFree()
{
    while(EEPROM_EEDONE_R & 0x1);
}

int EEPROM_read()
{
    int data,offset,block;
    unsigned char endOfBlock = 0;

    offset = EEPROM_EEOFFSET_R;
    block = EEPROM_EEBLOCK_R;

    if(EEPROM_EEOFFSET_R == 0x0F)
    {
        endOfBlock = 1;
    }

    data = EEPROM_EERDWRINC_R;
    EEPROM_waitUntilFree();

    if(endOfBlock && (EEPROM_EEBLOCK_R < NUMBER_OF_BLOCKS) )
    {
        EEPROM_EEBLOCK_R += 1;
    } else if (endOfBlock && (EEPROM_EEBLOCK_R < NUMBER_OF_BLOCKS) )
    {
        EEPROM_EEBLOCK_R = 0;
    }

    return data;
}

int EEPROM_write(int data)
{
    int offset,block;
    unsigned char endOfBlock = 0;

    offset = EEPROM_EEOFFSET_R;
    block = EEPROM_EEBLOCK_R;

    if(EEPROM_EEOFFSET_R == 0x0F)
    {
        endOfBlock = 1;
    }

    EEPROM_EERDWRINC_R = data;
    EEPROM_waitUntilFree();

    if(endOfBlock && (EEPROM_EEBLOCK_R < NUMBER_OF_BLOCKS) )
    {
        EEPROM_EEBLOCK_R += 1;
    } else if (endOfBlock && (EEPROM_EEBLOCK_R < NUMBER_OF_BLOCKS) )
    {
        EEPROM_EEBLOCK_R = 0;
    }

    return data;
}


