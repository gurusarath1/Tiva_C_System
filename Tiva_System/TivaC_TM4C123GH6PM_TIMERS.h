#include "General_Data.h"
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"

void TIMER_init(int timerX, char timerX_Y , DIRECTION dir);
void TIMER_start(int timerX, char timerX_Y);
int TIMER_read(int timerX);
int TIMER_stop(int timerX);
