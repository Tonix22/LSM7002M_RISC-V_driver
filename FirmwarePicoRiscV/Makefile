# Replace toolchain and firmware-specific parts to compile natively on Linux

# ─────────────── Global config for native GCC ─────────────────────────────
CC := gcc
PYTHON := python3
HEX_WORDS := 65536

# ─────────────── Source lists ─────────────────────────────────────────────
FW_C_SRCS := $(wildcard firmware/*.c)

FIRMWARE_OBJS = $(patsubst firmware/%.c,firmware/%.o,$(FW_C_SRCS))

# ─────────────── Artefacts ────────────────────────────────────────────────
ELF := firmware/firmware.elf
MAP := firmware/firmware.map

# ─────────────── Compiler flags ───────────────────────────────────────────
CFLAGS := -g -O0 -Wall -Wextra --std=c99 -I firmware
LDFLAGS := -Wl,-Map,$(MAP)

# ─────────────── Default target ───────────────────────────────────────────
all: $(ELF)

# ─────────────── Build rules ──────────────────────────────────────────────
firmware/%.o : firmware/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

firmware/%.o : firmware/%.S
	$(CC) -c -o $@ $<

$(ELF): $(FIRMWARE_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Optional: run & debug
run: $(ELF)
	./$(ELF)

debug: $(ELF)
	gdb $(ELF)

clean:
	rm -f $(FIRMWARE_OBJS) $(ELF) $(MAP)

.PHONY: all clean run debug
