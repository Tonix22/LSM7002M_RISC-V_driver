#ifndef ISR_HANDLER_H
#define ISR_HANDLER_H

typedef enum
{
    IDLE ,
    READ ,
    WRITE,
    HOLD
}DataStat;


void int_isr(void);
void dummy (void);

#endif