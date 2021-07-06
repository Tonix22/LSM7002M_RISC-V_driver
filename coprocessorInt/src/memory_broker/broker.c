#include <stdio.h>
#include <string.h>
#include "broker.h"
#include "parser.h"
#include "isr_handler.h"
#include "aip.h"
#include "parser.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

#define YES 1
#define NO  0
#define P_idx(x) x
#define D_idx(x) x

#define Assing_double(num,data_0,data_1) merger      = (data_64[data_0]<<32 | data_64[data_1]);\
                                         interpreter = &merger;\
                                         Params[num].value.d =*interpreter;           


//external sources
extern volatile DataStat ISR_FLAG;
extern Geric_Parameter Params[MAX_PARAMETERS];

//extern Special_ids_t     Special_Opcodes[SPECIAL_SIZE];
extern uint32_t          FLIP_VALUES[2];

/*read_memory globals*/
uint32_t data[MAX_READ_SIZE];

/*interpreter globals*/
//paramaters_pair* ptypes_ref;
uint8_t data_size = 0;
InternatlStates Current_state = NORMAL;

//LOCALS
double actualSamplingFreq = 0.0;
double actualLoFreq       = 0.0;
double actualBw           = 0.0; // LMS7002M_tbb_set_filter_bw

void read_memory()
{
    uint32_t status   =  Busy;
    aip_write(0x1e, &status, 1, 0);

    /*clear buffer*/
    memset(data,0,MAX_READ_SIZE*sizeof(uint32_t));
    aip_read(0x0, data, MAX_READ_SIZE, 0);

    /* done */
	status = Done;
	aip_write(0x1e, &status, 1, 0);
}

int double_specials(uint8_t* Group_ID)
{
    int is_special = YES;
    uint64_t data_64[] = {0,data[1],data[2],data[3],data[4],data[5]};
    uint64_t merger = 0;
    double*  interpreter = NULL;

    switch (*Group_ID)
    {
        case SET_DATA_CLOCK_NUM :
            Assing_double(P_idx(0),D_idx(2),D_idx(1));
            Assing_double(P_idx(1),D_idx(4),D_idx(3));
            Params[2].value.d_pointer = &actualSamplingFreq;
        break; 
        
        case SET_NCO_FREQ_NUM : 
            Params[0].value.enum_type = data[1];
            Params[1].value.enum_type = data[2];
            Assing_double(P_idx(2),D_idx(4),D_idx(3));
        break; 
        
        case SET_LO_FREQ_NUM : 
            Params[0].value.enum_type = data[1];
            Assing_double(P_idx(1),D_idx(3),D_idx(2));
            Assing_double(P_idx(2),D_idx(5),D_idx(4));
            Params[3].value.d_pointer = &actualLoFreq;
        break; 
        
        case TXSTP_CORRECTION_NUM : 
            Params[0].value.enum_type = data[1];
            Assing_double(P_idx(1),D_idx(3),D_idx(2));
            Assing_double(P_idx(2),D_idx(5),D_idx(4));
        break; 
        
        case BB_FILER_SET_NUM : 
            Params[0].value.enum_type = data[1];
            Assing_double(P_idx(1),D_idx(3),D_idx(2));
            Params[2].value.d_pointer = &actualBw;
        break; 
        
        case TRF_RBB_RFE_NUM : 
            Params[0].value.enum_type = data[1];
            Assing_double(P_idx(1),D_idx(3),D_idx(2));
        break; 

    default:
        is_special = NO;
        break;
    }
    return is_special;
}

void interpreter()
{
    uint8_t Group_ID = data[0] & 31; // only get first 5 bits
    if(NO == double_specials(&Group_ID)) // not special 
    {
        for(int i=0;i < MAX_PARAMETERS; i++)
        {
            Params[i].value.bit_32 = data[i+1];
        }
    }
}

void send_ACK()
{
    uint32_t code[4] = {0};
    code[0]='A';
    code[1]='C';
    code[2]='K';
    aip_write(0x2, &code[0], 4, 0);
}
void send_EOF()
{
    uint32_t code[4] = {0};
    code[0]='E';
    code[1]='O';
    code[2]='F';
    aip_write(0x2, &code[0], 4, 0);
}
/*Set memory with 0s*/
void clear_OUT_BUFF()
{
    uint32_t code[MAX_READ_SIZE] = {0};
    aip_write(0x2, &code[0], MAX_READ_SIZE, 0);
}

void send_response()
{
    /*
    uint32_t set_get;
    uint32_t cnt = 0;

    ptypes_ref    = get_opcode_types();
    set_get = ptypes_ref->opcode & 3;
    if(Current_state == SPECIAL_GET)
    {
        clear_OUT_BUFF();
        ISR_FLAG = IDLE;
        send_ACK();
        while(ISR_FLAG != READ && cnt++ < 60000000);
        cnt = 0;
        clear_OUT_BUFF();
        while(Current_state == SPECIAL_GET)
        {
            if(ISR_FLAG == READ) // wait a start as ACK
            {
                ISR_FLAG = IDLE;
                read_memory();
                clear_OUT_BUFF();
                pull_special(data);//update state internally
                aip_write(0x2, &data[0], MAX_READ_SIZE, 0);
            }
        }
        while(ISR_FLAG != READ && cnt++ < 60000000);
        ISR_FLAG = IDLE;
        send_EOF();
    }
    else
    {
        ISR_FLAG = IDLE;
        if(set_get == GET && ptypes_ref->P2 == EMPTY_PARAM)
        {
            aip_write(0x2, &FLIP_VALUES[0], 1, 0);
            while(ISR_FLAG != READ && cnt++ < 36000000);// wait respose from GUI
        }
        else if(set_get == GET)
        {
            // two parameter functions work with one parameter as input
            // the other one as ouput. That's the reason for FLIP_VALUES[1]
            aip_write(0x2, &FLIP_VALUES[1], 1, 0);
            while(ISR_FLAG != READ && cnt++ < 60000000);// wait respose from GUI
        }
    }
    */
}
void Broker(LMS7002M_t *lms)
{
    int_isr();
    clear_OUT_BUFF();
	for(;;)
	{
		if(ISR_FLAG == READ) // when an start is sent
		{
            clear_OUT_BUFF(); // clear MDATA OUT
            read_memory();
            interpreter();
			search_by_ID(lms, data[0]);
            send_response();
            memset(FLIP_VALUES,0,2*sizeof(uint32_t));   
            ISR_FLAG = IDLE;
		}
	}
}

