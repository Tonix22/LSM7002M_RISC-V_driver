.section .text
.global _start
.type _start, @function

_start:
    # Inicializar stack pointer a 0x80020000 (ej. para 128KB arriba de 0x80000000)
    lui sp, 0x80020 >> 12     # 0x80020000 = 128KB más allá de 0x80000000
    ori sp, sp, 0x000         # asegura que los bits bajos sean cero

    # Llamar a main
    call main

    # Loop infinito si main retorna
1:
    j 1b
