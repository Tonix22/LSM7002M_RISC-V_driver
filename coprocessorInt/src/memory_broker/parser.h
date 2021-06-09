#ifndef PARSER_H
#define PARSER_H
#include "LMS7002M.h"
#include "util.h"


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
    enum {
      typUndefined,
      typInt,           // 1
      typUint,
      typString,
      typLong
    } iType;

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
    } value;

}typedef Geric_Parameter;



typedef struct Action
{
    uint32_t ID;
    void* foo;
}Caller;

//void opcode_callback(struct ad9361_rf_phy *phy);
void push_special (uint32_t* mem);
void pull_special(uint32_t* mem);
void push_param(uint32_t var,unsigned char idx);
void set_opcode_to_ptypes(long opcode);



#endif