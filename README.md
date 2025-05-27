# LSM7002M_RISC-V_driver

# Proyecto PicoRV32 en FPGA (DE10-Lite)

Este proyecto integra un procesador PicoRV32 con periféricos como UART, GPIOs y módulos AIP personalizados sobre una FPGA Intel MAX 10 (DE10-Lite). El flujo de trabajo permite cargar firmware sin recompilar el bitstream, facilitando una depuración rápida del software embebido.

---

## Aprendizajes y configuraciones clave

### Compilación del firmware

- El firmware en C se compila usando `riscv32-unknown-elf-gcc` con `start.S`, `print.c`, `irqb.c` y `main.c`.
- El `Makefile` genera:
  - `main_fw.elf`: ejecutable RISC-V
  - `main_fw.hex`: formato Verilog
  - `altera_out.txt`: lista hex compatible con IP Driver

```bash
make main_fw.hex
make firmware/altera_out.txt
```

---

### Carga dinámica del firmware (sin recompilar Quartus)

- El script `main_IPM_PICORV32.py` usa la librería `ipdi` y el wrapper `pyaip` para:
  - Cargar instrucciones desde `altera_out.txt`
  - Escribir en `MProgramMEMIN`
  - Controlar el reset y arranque del core PicoRV32 mediante `CCONFREG`

```bash
python3 firmware/main_IPM_PICORV32.py
```

- Esta arquitectura permite reprogramar solo la memoria de instrucciones de forma dinámica.

---

### Acceso a periféricos

#### UART
- Mapeada a:
  - `0x02000004`: baudrate divisor
  - `0x02000008`: registro de datos
- Conectada físicamente a `PIN_AB6` (GPIO_0[0] en DE10-Lite)
- Se pueden ver los `printf()` en `/dev/ttyUSB0` con:

```bash
screen /dev/ttyUSB0 115200
```

#### LEDs
- Mapeados en `0x03000000` como salida GPIO
- Se puede controlar cada bit desde el firmware

---

### 🧩 Dirección de periféricos AIP

Los periféricos AIP se controlan desde el firmware usando acceso a memoria mapeada:

```c
#define AIP_IP_IPDUMMY0 0x80000100
#define AIP_DATAIN      1
#define AIP_CONFIG      2
#define AIP_START       3

*(ptrDUMMY0 + AIP_CONFIG) = 2;
*(ptrDUMMY0 + AIP_DATAIN) = 0x12345678;
*(ptrDUMMY0 + AIP_START)  = 1;
```

---

### Problemas resueltos

- El módulo `ipdi` requería `GLIBCXX_3.4.32`, ausente en Conda.
- Se resolvió usando:

```bash
LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libstdc++.so.6 python firmware/main_IPM_PICORV32.py
```

- Para evitar escribirlo siempre, se puede definir en el `Makefile`:

```make
PYTHON = LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libstdc++.so.6 python
```

---

## Flujo de trabajo recomendado

```bash
# Compilar firmware
make main_fw.hex
make firmware/altera_out.txt

# Ejecutar y cargar al core
python3 firmware/main_IPM_PICORV32.py
```

---

## Referencias útiles

- DE10-Lite User Manual: ubicación de pines GPIO
- [PicoRV32 GitHub](https://github.com/cliffordwolf/picorv32)
- Documentación IPDI para uso de `pyaip` y control de periféricos

---
