#ifndef BROKER_H
#define BROKER_H


#define STANDAR_READ_SIZE 3
#define MAX_READ_SIZE 16
// AIP indexes 
#define OPCODE_IDX 0
#define P1_IDX 1
#define P2_IDX 2
// This index are for the array in the parser
#define P1_NUM 0 
#define P2_NUM 1

#include "LMS7002M.h"
void send_ACK();
void clear_OUT_BUFF();
void Broker(LMS7002M_t *lms);


typedef enum
{
    IDLE ,
    READ ,
    WRITE,
    HOLD
}DataStat;

typedef enum
{
    NORMAL,
    SPECIAL_SET,
    SPECIAL_GET,
    END_PUSH,
    END_PULL
}InternatlStates;

typedef enum
{
    Busy = 0x100,
    Done = 0x01,
}Mem_stat;



#endif