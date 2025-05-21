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
void Broker(LMS7002M_t *lms);


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

#define MAX_PARAMETERS 16

// Dummy enum for operation codes
enum {
    SET_DATA_CLOCK_NUM = 0,
    SET_NCO_FREQ_NUM,
    SET_LO_FREQ_NUM,
    TXSTP_CORRECTION_NUM,
    BB_FILER_SET_NUM,
    TRF_RBB_RFE_NUM,
};

// Dummy struct for parameter set
typedef struct {
    int id;
    float value;
} Generic_Parameter;

// External parameter list
extern Generic_Parameter Params[MAX_PARAMETERS];

// Function prototypes with (void) for strict prototypes
void read_memory(void);
int double_specials(uint8_t* cmd);
void interpreter(void);
void send_ACK(void);
void send_EOF(void);
void clear_OUT_BUFF(void);
void send_response(void);

#endif