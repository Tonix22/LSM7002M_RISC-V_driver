#ifndef __DUPIN_CSR_H__
#define __DUPIN_CSR_H__

struct dupin_core_reg_init {
    const char *name;
    uint32_t csr_num;    /* Number in architecture's CSR space */
    uint32_t inHaltOnly;
    uint32_t is_csr;
    const char *description;
    const char *versions;
};

const struct dupin_core_reg_init dupin_init_reg_list[] = {
{
    .name = "x0",
    .csr_num = 0,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = "Zero register",
    .versions = NULL,
},
{
    .name = "x1",
    .csr_num = 1*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x2",
    .csr_num = 2*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x3",
    .csr_num = 3*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x4",
    .csr_num = 4*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x5",
    .csr_num = 5*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x6",
    .csr_num = 6*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x7",
    .csr_num = 7*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x8",
    .csr_num = 8*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x9",
    .csr_num = 9*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x10",
    .csr_num = 10*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x11",
    .csr_num = 11*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x12",
    .csr_num = 12*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x13",
    .csr_num = 13*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x14",
    .csr_num = 14*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x15",
    .csr_num = 15*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x16",
    .csr_num = 16*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x17",
    .csr_num = 17*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x18",
    .csr_num = 18*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x19",
    .csr_num = 19*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x20",
    .csr_num = 20*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x21",
    .csr_num = 21*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x22",
    .csr_num = 22*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x23",
    .csr_num = 23*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x24",
    .csr_num = 24*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x25",
    .csr_num = 25*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x26",
    .csr_num = 26*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x27",
    .csr_num = 27*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x28",
    .csr_num = 28*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x29",
    .csr_num = 29*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x30",
    .csr_num = 30*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "x31",
    .csr_num = 31*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "pc",
    .csr_num = 512 + 1*4,
    .inHaltOnly = FALSE,
    .is_csr = FALSE,
    .description = NULL,
    .versions = NULL,
},
{
    .name = "ustatus",
    .csr_num = 0x000,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "User status register",
    .versions = "1.9-",
},
{
    .name = "uie",
    .csr_num = 0x004,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "User interrupt-enable register",
    .versions = "1.9-",
},
{
    .name = "utvec",
    .csr_num = 0x005,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "User trap handler base address",
    .versions = "1.9-",
},
{
    .name = "uscratch",
    .csr_num = 0x040,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Scratch handler for user trap handlers",
    .versions = "1.9-",
},
{
    .name = "uepc",
    .csr_num = 0x041,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "User exception program counter",
    .versions = "1.9-",
},
{
    .name = "ucause",
    .csr_num = 0x042,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "User trap cause",
    .versions = "1.9-",
},
{
    .name = "utval",
    .csr_num = 0x043,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "User bad address or instruction",
    .versions = "1.10-",
},
{
    .name = "uip",
    .csr_num = 0x044,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "User interrupt pending",
    .versions = "1.9-",
},
{
    .name = "fflags",
    .csr_num = 0x001,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Floating-Point Accrued Exceptions",
    .versions = "1.7-",
},
{
    .name = "frm",
    .csr_num = 0x002,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Floating-Point Dynamic Rounding Mode",
    .versions = "1.7-",
},
{
    .name = "fcsr",
    .csr_num = 0x003,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Floating-Point Control and Status (frm + fflags)",
    .versions = "1.7-",
},
{
    .name = "cycle",
    .csr_num = 0xC00,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Cycle counter (for RDCYCLE)",
    .versions = "1.7-",
},
{
    .name = "time",
    .csr_num = 0xC01,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Wall-clock time (for RDTIME)",
    .versions = "1.7-",
},
{
    .name = "instret",
    .csr_num = 0xC02,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Instructions-retired counter (for RDINSTRET)",
    .versions = "1.7-",
},
{
    .name = "cycleh",
    .csr_num = 0xC80,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of cycle, RV32I only",
    .versions = "1.7-,rv32",
},
{
    .name = "timeh",
    .csr_num = 0xC81,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of time, RV32I only",
    .versions = "1.7-,rv32",
},
{
    .name = "instreth",
    .csr_num = 0xC82,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of instret, RV32I only",
    .versions = "1.7-,rv32",
},

/*
{
    .name = "sstatus",
    .csr_num = 0x100,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor status register",
    .versions = "1.7-",
},
{
    .name = "sedeleg",
    .csr_num = 0x102,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor exception delegation register",
    .versions = "1.9-",
},
{
    .name = "sideleg",
    .csr_num = 0x103,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor interrupt delegation register",
    .versions = "1.9-",
},
{
    .name = "sie",
    .csr_num = 0x104,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor interrupt-enable register",
    .versions = "1.7-",
},
{
    .name = "stvec",
    .csr_num = 0x105,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor trap handler base address",
    .versions = "1.7-",
},
{
    .name = "scounteren",
    .csr_num = 0x106,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor counter enable",
    .versions = "1.10-",
},
{
    .name = "sscratch",
    .csr_num = 0x140,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Scratch register for supervisor trap handlers",
    .versions = "1.7-",
},
{
    .name = "sepc",
    .csr_num = 0x141,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor exception program counter",
    .versions = "1.7-",
},
{
    .name = "scause",
    .csr_num = 0x142,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor trap cause",
    .versions = "1.7-",
},
{
    .name = "stval",
    .csr_num = 0x143,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor bad address or instruction",
    .versions = "1.10-",
},
{
    .name = "sip",
    .csr_num = 0x144,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor interrupt pending",
    .versions = "1.7-",
},
{
    .name = "sptbr",
    .csr_num = 0x180,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Page-table base register",
    .versions = "1.7-1.9.1",
},
{
    .name = "satp",
    .csr_num = 0x180,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor address translation and protection",
    .versions = "1.10-",
},
*/


/*
{
    .name = "scycle",
    .csr_num = 0xD00,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor cycle counter",
    .versions = "1.9-",
},
{
    .name = "stime",
    .csr_num = 0xD01,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor wall-clock time",
    .versions = "1.7-1.9",
},
{
    .name = "sinstret",
    .csr_num = 0xD02,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Supervisor instructions-retired counter",
    .versions = "1.9-",
},
{
    .name = "scycleh",
    .csr_num = 0xD80,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of scycle, RV32I only",
    .versions = "1.9-,rv32",
},
{
    .name = "stimeh",
    .csr_num = 0xD81,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of stime, RV32I only",
    .versions = "1.7-,rv32",
},
{
    .name = "sinstreth",
    .csr_num = 0xD82,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of sinstret, RV32I only",
    .versions = "1.9-,rv32",
},
*/



{
    .name = "mvendorid",
    .csr_num = 0xF11,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Vendor ID",
    .versions = "1.9-",
},
{
    .name = "marchid",
    .csr_num = 0xF12,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Architecture ID",
    .versions = "1.9-",
},
{
    .name = "mimpid",
    .csr_num = 0xF13,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Implementation ID",
    .versions = "1.9-",
},
{
    .name = "mhartid",
    .csr_num = 0xF14,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Hardware thread ID",
    .versions = "1.7-",
},



{
    .name = "mstatus",
    .csr_num = 0x300,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine status register",
    .versions = "1.7-",
},
{
    .name = "misa",
    .csr_num = 0x301,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "ISA and extensions supported",
    .versions = "1.7-",
},
{
    .name = "medeleg",
    .csr_num = 0x302,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine exception delegation register",
    .versions = "1.9-",
},
{
    .name = "mideleg",
    .csr_num = 0x303,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine interrupt delegation register",
    .versions = "1.9-",
},
{
    .name = "mie",
    .csr_num = 0x304,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine interrupt-enable register",
    .versions = "1.7-",
},
{
    .name = "mtvec",
    .csr_num = 0x305,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine trap-handler base address",
    .versions = "1.7-",
},
{
    .name = "mcounteren",
    .csr_num = 0x306,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine counter enable",
    .versions = "1.10-",
},
{
    .name = "mscratch",
    .csr_num = 0x340,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Scratch register for machine trap handlers",
    .versions = "1.7-",
},
{
    .name = "mepc",
    .csr_num = 0x341,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine exception program counter",
    .versions = "1.7-",
},
{
    .name = "mcause",
    .csr_num = 0x342,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine trap cause",
    .versions = "1.7-",
},
{
    .name = "mtval",
    .csr_num = 0x343,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine bad address or instruction",
    .versions = "1.10-",
},
{
    .name = "mip",
    .csr_num = 0x344,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine interrupt pending",
    .versions = "1.7-",
},


/*
{
    .name = "pmpcfg0",
    .csr_num = 0x3A0,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection configuration",
    .versions = "1.10-",
},
{
    .name = "pmpcfg1",
    .csr_num = 0x3A0,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection configuration (RV32 only)",
    .versions = "1.10-",
},
{
    .name = "pmpcfg2",
    .csr_num = 0x3A0,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection configuration",
    .versions = "1.10-",
},
{
    .name = "pmpcfg3",
    .csr_num = 0x3A0,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection configuration (RV32 only)",
    .versions = "1.10-",
},
{
    .name = "pmpaddr0",
    .csr_num = 0x3B0,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr1",
    .csr_num = 0x3B1,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr2",
    .csr_num = 0x3B2,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr3",
    .csr_num = 0x3B3,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr4",
    .csr_num = 0x3B4,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr5",
    .csr_num = 0x3B5,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr6",
    .csr_num = 0x3B6,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr7",
    .csr_num = 0x3B7,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr8",
    .csr_num = 0x3B8,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr9",
    .csr_num = 0x3B9,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr10",
    .csr_num = 0x3BA,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr11",
    .csr_num = 0x3BB,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr12",
    .csr_num = 0x3BC,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr13",
    .csr_num = 0x3BE,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr14",
    .csr_num = 0x3BD,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
{
    .name = "pmpaddr15",
    .csr_num = 0x3BF,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Physical memory protection address register",
    .versions = "1.10-",
},
*/

/*
{
    .name = "mbase",
    .csr_num = 0x380,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Base register",
    .versions = "1.7-",
},
{
    .name = "mbound",
    .csr_num = 0x381,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Bound register",
    .versions = "1.7-",
},
{
    .name = "mibase",
    .csr_num = 0x382,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Instruction base register",
    .versions = "1.7-",
},
{
    .name = "mibound",
    .csr_num = 0x383,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Instruction bound register",
    .versions = "1.7-",
},
{
    .name = "mdbase",
    .csr_num = 0x384,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Data base register",
    .versions = "1.7-",
},
{
    .name = "mdbound",
    .csr_num = 0x385,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Data bound register",
    .versions = "1.7-",
},
*/

/*
{
    .name = "mcycle",
    .csr_num = 0xB00,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine cycle counter",
    .versions = "1.7-",
},
{
    .name = "minstret",
    .csr_num = 0xB02,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine instructions-retired counter",
    .versions = "1.7-",
},
{
    .name = "mhpmcounter3",
    .csr_num = 0xB03,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter4",
    .csr_num = 0xB04,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter5",
    .csr_num = 0xB05,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter6",
    .csr_num = 0xB06,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter7",
    .csr_num = 0xB07,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter8",
    .csr_num = 0xB08,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter9",
    .csr_num = 0xB09,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter10",
    .csr_num = 0xB0A,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter11",
    .csr_num = 0xB0B,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter12",
    .csr_num = 0xB0C,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter13",
    .csr_num = 0xB0D,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter14",
    .csr_num = 0xB0E,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter15",
    .csr_num = 0xB0F,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter16",
    .csr_num = 0xB10,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter17",
    .csr_num = 0xB11,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter18",
    .csr_num = 0xB12,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter19",
    .csr_num = 0xB13,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter20",
    .csr_num = 0xB14,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter21",
    .csr_num = 0xB15,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter22",
    .csr_num = 0xB16,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter23",
    .csr_num = 0xB17,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter24",
    .csr_num = 0xB18,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter25",
    .csr_num = 0xB19,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter26",
    .csr_num = 0xB1A,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter27",
    .csr_num = 0xB1B,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter28",
    .csr_num = 0xB1C,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter29",
    .csr_num = 0xB1D,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter30",
    .csr_num = 0xB1E,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter31",
    .csr_num = 0xB1F,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring counter",
    .versions = "1.9.1-",
},
*/

/*
{
    .name = "mcycleh",
    .csr_num = 0xB80,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mcycle, RV32I only",
    .versions = "1.7-,rv32",
},
{
    .name = "minstreth",
    .csr_num = 0xB82,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of minstret, RV32I only",
    .versions = "1.7-,rv32",
},
{
    .name = "mhpmcounter3h",
    .csr_num = 0xB83,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter3, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter4h",
    .csr_num = 0xB84,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter4, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter5h",
    .csr_num = 0xB85,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter5, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter6h",
    .csr_num = 0xB86,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter6, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter7h",
    .csr_num = 0xB87,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter7, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter8h",
    .csr_num = 0xB88,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter8, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter9h",
    .csr_num = 0xB89,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter9, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter10h",
    .csr_num = 0xB8A,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter10, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter11h",
    .csr_num = 0xB8B,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter11, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter12h",
    .csr_num = 0xB8C,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter12, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter13h",
    .csr_num = 0xB8D,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter13, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter14h",
    .csr_num = 0xB8E,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter14, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter15h",
    .csr_num = 0xB8F,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter15, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter16h",
    .csr_num = 0xB90,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter16, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter17h",
    .csr_num = 0xB91,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter17, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter18h",
    .csr_num = 0xB92,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter18, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter19h",
    .csr_num = 0xB93,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter19, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter20h",
    .csr_num = 0xB94,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter20, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter21h",
    .csr_num = 0xB95,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter21, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter22h",
    .csr_num = 0xB96,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter22, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter23h",
    .csr_num = 0xB97,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter23, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter24h",
    .csr_num = 0xB98,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter24, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter25h",
    .csr_num = 0xB99,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter25, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter26h",
    .csr_num = 0xB9A,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter26, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter27h",
    .csr_num = 0xB9B,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter27, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter28h",
    .csr_num = 0xB9C,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter28, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter29h",
    .csr_num = 0xB9D,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter29, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter30h",
    .csr_num = 0xB9E,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter30, RV32I only",
    .versions = "1.9.1-",
},
{
    .name = "mhpmcounter31h",
    .csr_num = 0xB9F,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Upper 32 bits of mhpmcounter31, RV32I only",
    .versions = "1.9.1-",
},
*/

/*
{
    .name = "mhpmevent3",
    .csr_num = 0x323,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent4",
    .csr_num = 0x324,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent5",
    .csr_num = 0x325,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent6",
    .csr_num = 0x326,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent7",
    .csr_num = 0x327,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent8",
    .csr_num = 0x328,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent9",
    .csr_num = 0x329,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent10",
    .csr_num = 0x32A,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent11",
    .csr_num = 0x32B,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent12",
    .csr_num = 0x32C,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent13",
    .csr_num = 0x32D,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent14",
    .csr_num = 0x32E,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent15",
    .csr_num = 0x32F,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent16",
    .csr_num = 0x330,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent17",
    .csr_num = 0x331,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent18",
    .csr_num = 0x332,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent19",
    .csr_num = 0x333,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent20",
    .csr_num = 0x334,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent21",
    .csr_num = 0x335,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent22",
    .csr_num = 0x336,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent23",
    .csr_num = 0x337,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent24",
    .csr_num = 0x338,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent25",
    .csr_num = 0x339,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent26",
    .csr_num = 0x33A,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent27",
    .csr_num = 0x33B,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent28",
    .csr_num = 0x33C,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent29",
    .csr_num = 0x33D,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent30",
    .csr_num = 0x33E,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
{
    .name = "mhpmevent31",
    .csr_num = 0x33F,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Machine performance-monitoring event selector",
    .versions = "1.9.1-",
},
*/

/*
{
    .name = "tselect",
    .csr_num = 0x7A0,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Debug/Trace trigger register select",
    .versions = "1.9.1-",
},
{
    .name = "tdata1",
    .csr_num = 0x7A1,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "First Debug/Trace trigger data register",
    .versions = "1.9.1-",
},
{
    .name = "tdata2",
    .csr_num = 0x7A2,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Second Debug/Trace trigger data register",
    .versions = "1.9.1-",
},
{
    .name = "tdata3",
    .csr_num = 0x7A3,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Third Debug/Trace trigger data register",
    .versions = "1.9.1-",
},
{
    .name = "dcsr",
    .csr_num = 0x7B0,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Debug control and status register",
    .versions = "1.9.1-",
},
{
    .name = "dpc",
    .csr_num = 0x7B1,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Debug program counter",
    .versions = "1.9.1-",
},
{
    .name = "dscratch",
    .csr_num = 0x7B2,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Debug scratch register",
    .versions = "1.9.1-",
},
*/

{
    .name = "mtohost",
    .csr_num = 0x780,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "IO to Host",
    .versions = "1.7-",
},
{
    .name = "mfromhost",
    .csr_num = 0x781,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "IO from Host",
    .versions = "1.7-",
},
{
    .name = "mreset",
    .csr_num = 0x782,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Reset",
    .versions = "1.7-",
},
{
    .name = "mipi",
    .csr_num = 0x783,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "Inter Processor Interrupt",
    .versions = "1.7-",
},
{
    .name = "miobase",
    .csr_num = 0x784,
    .inHaltOnly = FALSE,
    .is_csr = TRUE,
    .description = "IO Base",
    .versions = "1.7-",
},
};

#endif /* __DUPIN_CSR_H__ */
