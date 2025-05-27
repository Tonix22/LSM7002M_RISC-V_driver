##############################################################################
#                    Minimal build – firmware/firmware.hex                   #
##############################################################################
# ─── 1.  add after the firmware source lists ────────────────────────────
HEX_WORDS := 65536
TEST_SRCS  := $(wildcard RiscvChecks/*.S)
TEST_OBJS  := $(patsubst RiscvChecks/%.S,RiscvChecks/%.o,$(TEST_SRCS))
INC_DIRS := firmware \
            firmware/LMS7002M \
            firmware/platform_generic \
			firmware/Memory_broker \
			firmware/Parser

INCS     := $(addprefix -I,$(INC_DIRS))

# ─────────────── Global config ─────────────────────────────────────────────
RISCV_GNU_TOOLCHAIN_INSTALL_PREFIX ?= /opt/riscv
TOOLCHAIN_PREFIX := $(RISCV_GNU_TOOLCHAIN_INSTALL_PREFIX)/bin/riscv32-unknown-elf-
PYTHON := python3

# ─────────────── ISA / ABI / warnings ─────────────────────────────────────
ABI := ilp32
ISA := rv32imc                        # change to rv32i / rv32im if needed

WARN = -Werror -Wall -Wextra -Wshadow -Wundef -Wpointer-arith \
       -Wcast-qual -Wcast-align -Wwrite-strings -Wredundant-decls \
       -Wstrict-prototypes -Wmissing-prototypes -pedantic

CFLAGS = -Os -mabi=$(ABI) -march=$(ISA) --std=c99 $(WARN) \
         $(INCS)

ASFLAGS = -mabi=$(ABI) -march=$(ISA)

# ─────────────── Source/object lists ──────────────────────────────────────
FW_C_SRCS := $(wildcard firmware/*.c) \
             $(wildcard firmware/LMS7002M_lib/*.c) \
             $(wildcard firmware/platform_generic/*.c) \
             $(wildcard firmware/Memory_broker/*.c) \
			 $(wildcard firmware/Parser/*.c)

FW_S_SRCS := $(wildcard firmware/*.S)
FIRMWARE_OBJS = $(patsubst firmware/%.c,firmware/%.o,$(FW_C_SRCS)) \
                $(patsubst firmware/%.S,firmware/%.o,$(FW_S_SRCS))

# ─────────────── Artefacts ────────────────────────────────────────────────
ELF := firmware/firmware.elf
BIN := firmware/firmware.bin
HEX := firmware/firmware.hex
MAP := firmware/firmware.map
LDS := firmware/sections.lds
MAKEHEX := firmware/makehex.py

# ─────────────── Default target ───────────────────────────────────────────
all: $(HEX)

# ─────────────── Build rules ──────────────────────────────────────────────
# ─── 2.  compile rule for RiscvChecks/*.S  (put with the other pattern rules) ─
RiscvChecks/%.o : RiscvChecks/%.S RiscvChecks/riscv_test.h RiscvChecks/test_macros.h
	$(TOOLCHAIN_PREFIX)gcc -c -mabi=$(ABI) -march=$(ISA) -Itests \
		-DTEST_FUNC_NAME=$(notdir $(basename $<)) \
		-DTEST_FUNC_TXT=\"$(notdir $(basename $<))\" \
		-DTEST_FUNC_RET=$(notdir $(basename $<))_ret \
		-o $@ $<

firmware/Memory_broker/%.o : CFLAGS += \
    -Wno-unused-parameter -Wno-unused-variable -Wno-char-subscripts \
    -Wno-missing-prototypes -Wno-maybe-uninitialized -Wno-sign-compare -Wno-unused-parameter \
	-Wno-unused-function -Wno-sign-compare -Wno-uninitialized

# Ignore warnings in the platformgeneric library
firmware/platform_generic/%.o : CFLAGS += \
    -Wno-unused-parameter -Wno-unused-variable -Wno-char-subscripts \
    -Wno-missing-prototypes -Wno-maybe-uninitialized -Wno-sign-compare -Wno-unused-parameter

# Ignore warnings in the LMS7002M library
# Adding PI to the LMS7002M library
# This is a workaround for the LMS7002M library, which uses a non-standard
firmware/LMS7002M_lib/%.o : CFLAGS += \
    -Wno-unused-parameter -Wno-unused-variable -Wno-char-subscripts \
    -Wno-missing-prototypes -Wno-maybe-uninitialized -Wno-nonnull\
    -DM_PI=3.14159265358979323846

# 1. C → object
firmware/%.o : firmware/%.c
	$(TOOLCHAIN_PREFIX)gcc $(CFLAGS) -c -o $@ $<

# 2. S → object
firmware/%.o : firmware/%.S
	$(TOOLCHAIN_PREFIX)gcc $(ASFLAGS) -c -o $@ $<

# 3. link ELF
$(ELF): $(FIRMWARE_OBJS) $(TEST_OBJS) $(LDS)
	$(TOOLCHAIN_PREFIX)gcc $(CFLAGS) \
	    -Wl,--build-id=none,-Bstatic,-T,$(LDS),-Map,$(MAP),--strip-debug \
	    -o $@ $(FIRMWARE_OBJS) $(TEST_OBJS) -lm

# 4. ELF → BIN
$(BIN): $(ELF)
	$(TOOLCHAIN_PREFIX)objcopy -O binary $< $@
	chmod -x $@

# 5. BIN → HEX
$(HEX): $(BIN) $(MAKEHEX)
	$(PYTHON) $(MAKEHEX) $< $(HEX_WORDS) > $@

# ─── 4.  clean rule – add $(TEST_OBJS) so “make clean” wipes them ───────
clean:
	rm -f $(FIRMWARE_OBJS) $(TEST_OBJS) $(ELF) $(BIN) $(HEX) $(MAP)

.PHONY: all clean
