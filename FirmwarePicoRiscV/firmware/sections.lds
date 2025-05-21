ENTRY(_start)

MEMORY {
    mem (rwx) : ORIGIN = 0x00000000, LENGTH = 512K
}

SECTIONS {
    .text : {
        *(.text)
        *(.text*)
    } > mem

    .rodata : {
        *(.rodata*)
    } > mem

    .data : {
        __data_start = .;
        *(.data)
        __data_end = .;
    } > mem

    .bss : {
        __bss_start = .;
        *(.bss)
        *(COMMON)
        __bss_end = .;
    } > mem

    _end = .;
    PROVIDE(__global_pointer$ = _end - 0x800); /* Typical GP assumption */
}
