#ifndef GENERIC_H
#define GENERIC_H

#include <stdint.h>

#define DUPIN_SOC_PLIC_DUPIN_SOC_GPIO0_INTERRUPTS_0 32
#define DUPIN_SOC_PLIC_DUPIN_SOC_GPIO0_INTERRUPTS_1 33
#define DUPIN_SOC_PLIC_DUPIN_SOC_GPIO0_INTERRUPTS_2 34
#define DUPIN_SOC_PLIC_DUPIN_SOC_GPIO0_INTERRUPTS_3 35

/* ──────────────────────────────────────── */
/* Dummy structs for memory-mapped hardware */
/* ──────────────────────────────────────── */
typedef struct {
    volatile uint32_t OUTPUT_ENABLE;
    volatile uint32_t OUTPUT;
    volatile uint32_t INPUT;
} gpio_regs_t;

typedef struct {
    volatile uint32_t dummy;
} spi_regs_t;

typedef struct {
    volatile uint32_t start;
    volatile uint32_t write_conf;
    volatile uint32_t write_data;
    volatile uint32_t read_data;
} noc_regs_t;

/* ─────────────────────── */
/* Dummy memory addresses  */
/* ─────────────────────── */
#define GPIO1       ((gpio_regs_t *)0xDEADBEEF)
#define SPI0_BASE   ((spi_regs_t *)0xDEADC0DE)
#define NOC_BASE    ((noc_regs_t  *)0xDEADFA11)
#define UART_CONSOLE ((void *)0xFEEDC0DE)
#define PLIC        ((void *)0xCAFEBABE)
#define PLIC_CPU_0  0

/* ─────────────────────────── */
/* SPI configuration structure */
/* ─────────────────────────── */
typedef struct {
    int cpol;
    int cpha;
    int mode;
    int clkDivider;
    int ssSetup;
    int ssHold;
    int ssDisable;
} spi_config_reg;

/* ───────────────────────────── */
/* Dummy SPI interface functions */
/* ───────────────────────────── */
static inline void spi_configure(spi_regs_t *base __attribute__((unused)),
                                 spi_config_reg *cfg __attribute__((unused))) {}

static inline void spi_select_device(spi_regs_t *base __attribute__((unused)),
                                     int dev __attribute__((unused))) {}

static inline void spi_deselect_device(spi_regs_t *base __attribute__((unused)),
                                       int dev __attribute__((unused))) {}

static inline uint8_t spi_rxdat(spi_regs_t *base __attribute__((unused))) { return 0xFF; }

static inline void spi_txbyte(spi_regs_t *base __attribute__((unused)),
                              uint8_t byte __attribute__((unused))) {}

/* ────────────────────────────── */
/* Delay and constants placeholders */
/* ────────────────────────────── */
#define MICRO_DELAY_FACTOR 1
#define MILLI_DELAY_FACTOR 1000

/* ───────────────────────────── */
/* Dummy interrupt support       */
/* ───────────────────────────── */
#define CAUSE_MACHINE_TIMER     0x80000007
#define CAUSE_MACHINE_EXTERNAL  0x8000000B

static inline uint32_t csr_read(uint32_t reg __attribute__((unused))) { return 0; }

void timerInterrupt(void);
void externalInterrupt(void);
static inline void crash(void) {}
static inline void scheduleTimer(void) {}

static inline uint32_t plic_claim(void *plic __attribute__((unused)),
                                  int cpu __attribute__((unused))) { return 0; }

static inline void plic_release(void *plic __attribute__((unused)),
                                int cpu __attribute__((unused)),
                                uint32_t claim __attribute__((unused))) {}

static inline void bsp_uart_write(void *uart __attribute__((unused)),
                                  char c __attribute__((unused))) {}

static inline void configure_interrupts(void) {}

#endif // GENERIC_H
