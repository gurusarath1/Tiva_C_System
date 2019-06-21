typedef enum {
    INPUT = 0,
    OUTPUT = 1
}IO_DIRECTION;

typedef enum{
    HIGH = 1,
    LOW = 0,
    UNKNOWN = 2
}BIT_STATE;

typedef enum{
    TRUE = 1,
    FALSE = 0
}BOOL_STATE;

typedef enum{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
}DIRECTION;

typedef enum{
    ACTIVE = 1,
    INACTIVE = 0
}STATUS;

typedef enum{
    CLEAR = 0,
    SET = 1,
    TOGGLE = 2
}BIT_OP;

typedef enum {
    VALID = 0,
    INVALID = 1,
    INVALID_OPERATION = 2,
    INVALID_DATA = 3,
    INVALID_PORT = 4
}FUNCTION_ERROR_RETURN;

typedef enum{
    BIT0  = 0x1,
    BIT1  = 0x2,
    BIT2  = 0x4,
    BIT3  = 0x8,
    BIT4  = 0x10,
    BIT5  = 0x20,
    BIT6  = 0x40,
    BIT7  = 0x80,
    BIT8  = 0x100,
    BIT9  = 0x200,
    BIT10 =  0x400,
    BIT11 =  0x800,
    BIT12 =  0x1000,
    BIT13 =  0x2000,
    BIT14 =  0x4000,
    BIT15 =  0x8000,
    BIT16 =  0x10000,
    BIT17 =  0x20000,
    BIT18 =  0x40000,
    BIT19 =  0x80000,
    BIT20 =  0x100000,
    BIT21 =  0x200000,
    BIT22 =  0x400000,
    BIT23 =  0x800000,
    BIT24 =  0x1000000,
    BIT25 =  0x2000000,
    BIT26 =  0x4000000,
    BIT27 =  0x8000000,
    BIT28 =  0x10000000,
    BIT29 =  0x20000000,
    BIT30 =  0x40000000,
    BIT31 =  0x80000000
}BIT_LOCATION;

#define ALL_F 0xFFFFFFFF

