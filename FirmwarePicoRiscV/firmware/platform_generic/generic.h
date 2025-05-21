#ifndef GENERIC_H
#define GENERIC_H

#include <stdint.h>

/* Dummy GPIO and SPI base structs */
typedef struct {
    volatile uint32_t OUTPUT_ENABLE;
    volatile uint32_t OUTPUT;
    volatile uint32_t INPUT;
} gpio_regs_t;

typedef struct {
    volatile uint32_t dummy;
} spi_regs_t;

/* Dummy pointers to pretend hardware memory-mapped registers */
#define GPIO1 ((gpio_regs_t *)0xDEADBEEF)
#define SPI0_BASE ((spi_regs_t *)0xDEADC0DE)

/* Placeholder for missing constants */
#define MICRO_DELAY_FACTOR 1
#define MILLI_DELAY_FACTOR 1000

/* SPI config struct */
typedef struct {
    int cpol;
    int cpha;
    int mode;
    int clkDivider;
    int ssSetup;
    int ssHold;
    int ssDisable;
} spi_config_reg;

/* Dummy API functions */
static inline void spi_configure(spi_regs_t *base, spi_config_reg *cfg) {}
static inline void spi_select_device(spi_regs_t *base, int dev) {}
static inline void spi_deselect_device(spi_regs_t *base, int dev) {}
static inline uint8_t spi_rxdat(spi_regs_t *base) { return 0xFF; }
static inline void spi_txbyte(spi_regs_t *base, uint8_t byte) {}

#endif // GENERIC_H
