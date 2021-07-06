#ifndef PARSER_H
#define PARSER_H
#include "LMS7002M.h"
#include "util.h"

#define MAX_PARAMETERS 5
#define INT(n) Params[n].value.sint
#define STR(n) Params[n].value.string
#define ENUM(n) Params[n].value.enum_type
#define CONSINT(n) Params[n].value.const_int
#define BOOLEAN(n) Params[n].value.b
#define DOUBLE(n)  Params[n].value.d
#define DOUBLE_POINTER(n)  Params[n].value.d_pointer
#define SHORT_POINTER(n)  Params[n].value.short_p
#define SIZE_TYPE(n) Params[n].value.size


void search_by_ID(LMS7002M_t *lms, int ID);
typedef enum 
{
    CREATE_NUM,
    ONE_PARAM_LMS7002M_T_NUM,
    SPI_WRITE_NUM,
    SPI_CONFIG_NUM,
    INI_NUM,
    CONFIGURE_LML_PORT_NUM,
    ONE_PARAM_CONST_BOOL_NUM,
    ONE_PARAM_LMS7002M_CHAN_NUM,
    TWO_PARAM_LMS7002M_DIR_INT_NUM,
    LDO_ENABLE_NUM,
    AFE_ENABLE_NUM,
    SET_DATA_CLOCK_NUM,
    SET_NCO_FREQ_NUM,
    SET_GFIR_TAPS_NUM,
    SET_LO_FREQ_NUM,
    TWO_PARAM_LMS_CONST_BOOL_NUM,
    TWO_PARAM_CHANT_SIZET_NUM,
    SP_TSG_NUM,
    TXSTP_CORRECTION_NUM,
    RXTSP_NUM,
    SET_PATH_AND_BAND_NUM,
    TBB_LOOP_BACK_ENABLE_NUM,
    BB_FILER_SET_NUM,
    TRF_RBB_RFE_NUM,
    READRSSI_NUM,
    OPCODE_SIZE,
}OPCODE_enum;



struct ANYTYPE
{
    union
    {
        bool b;
        char enum_type;
        int sint;
        const int const_int;
        unsigned int uint;
        char* string;
        short* short_p;
        long l;
        double d;
        double* d_pointer;
        size_t size;
        uint32_t bit_32;
    } value;

}typedef Geric_Parameter;



typedef struct Action
{
    void* foo;
}Caller;

//void opcode_callback(struct ad9361_rf_phy *phy);
void push_special (uint32_t* mem);
void pull_special(uint32_t* mem);
void push_param(uint32_t var,unsigned char idx);
void set_opcode_to_ptypes(long opcode);



#endif