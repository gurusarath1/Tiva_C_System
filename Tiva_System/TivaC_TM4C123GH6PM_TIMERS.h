typedef enum{
    TIMER_16BIT = 0,
    TIMER_32BIT,
    TIMER_64BIT
}TIMER_SIZE;

typedef enum{
    TIMER_SUCCESS,
    INVALID_CONFIG
}TIMER_ERROR_CODE;



TIMER_ERROR_CODE TIMER_init(int timerX, char timerX_Y, TIMER_SIZE timerSize, int LoadValue, DIRECTION dir);
TIMER_ERROR_CODE TIMER_start(int timerX, char timerX_Y);
TIMER_ERROR_CODE TIMER_pause(int timerX, char timerX_Y);
BOOL_STATE TIMER_checkTimeOut(int timerX, char timerX_Y);
TIMER_ERROR_CODE TIMER_clearRawInterrupt(int timerX, char timerX_Y);

