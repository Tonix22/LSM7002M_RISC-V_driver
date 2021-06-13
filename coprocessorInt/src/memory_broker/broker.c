#include <stdio.h>
#include <string.h>
#include "broker.h"
#include "parser.h"
#include "isr_handler.h"
#include "aip.h"


extern volatile DataStat ISR_FLAG;

//extern Special_ids_t     Special_Opcodes[SPECIAL_SIZE];
extern uint32_t          FLIP_VALUES[2];

/*read_memory globals*/
uint32_t data[MAX_READ_SIZE];

/*interpreter globals*/
//paramaters_pair* ptypes_ref;
uint8_t data_size = 0;
InternatlStates Current_state = NORMAL;



void read_memory()
{
    Mem_stat status   =  Busy;
    aip_write(0x1e, &status, 1, 0);

    /*clear buffer*/
    memset(data,0,MAX_READ_SIZE*sizeof(uint32_t));
    aip_read(0x0, data, MAX_READ_SIZE, 0);

    /* done */
	status = Done;
	aip_write(0x1e, &status, 1, 0);

}

void interpreter()
{
    
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
void clear_OUT_BUFF()
{
    uint32_t code[4] = {0};
    aip_write(0x2, &code[0], 4, 0);
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
			search_by_ID(lms, 0);
            send_response();
            memset(FLIP_VALUES,0,2*sizeof(uint32_t));   
            ISR_FLAG = IDLE;
		}
	}
}

