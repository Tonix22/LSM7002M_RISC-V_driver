#ifndef BRIDGE_H
#define BRIDGE_H
#include "qtmw.h"
#include "qaip.h"

typedef enum
{
    DATA_IN,
    DATA_OUT

}Clear_type;

typedef struct
{
    uint32_t op;
    uint32_t p[9];
}Param_chunk;

class IPDI_Bridge
{
    public:
    Qmw *mw;
    qaip *aip;
    Param_chunk data_in;
    Param_chunk data_out;
    char block_size = 16;
    IPDI_Bridge();
    void ReadData();
    void WriteData();
    void clear_buff(Clear_type clr);
    void Wait_ACK();
    void Example();
    
    ~IPDI_Bridge();
};


#endif
