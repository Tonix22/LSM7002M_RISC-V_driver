	.file	"main.c"
	.option nopic
	.attribute arch, "rv32i2p1_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	delay
	.type	delay, @function
delay:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	addi	s0,sp,32
	sw	zero,-20(s0)
	j	.L2
.L3:
 #APP
# 24 "firmware/main.c" 1
	nop
# 0 "" 2
 #NO_APP
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L2:
	lw	a4,-20(s0)
	li	a5,299008
	addi	a5,a5,991
	ble	a4,a5,.L3
	nop
	nop
	lw	ra,28(sp)
	lw	s0,24(sp)
	addi	sp,sp,32
	jr	ra
	.size	delay, .-delay
	.section	.rodata
	.align	2
.LC0:
	.string	"Reading IPID !\n"
	.align	2
.LC1:
	.string	"\n"
	.align	2
.LC2:
	.string	"aip_writing to IPDUMMY0 - initialized to zero !\n"
	.align	2
.LC3:
	.string	"Configuring IPDummy0 !\n"
	.align	2
.LC4:
	.string	"Configuring IPDummy0  !\n"
	.align	2
.LC5:
	.string	"Reading IPID GPIO !\n"
	.align	2
.LC6:
	.string	"aip_writing to IPGPIO !\n"
	.align	2
.LC7:
	.string	"aip_reading from IPGPIO !\n"
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-48
	sw	ra,44(sp)
	sw	s0,40(sp)
	addi	s0,sp,48
	li	a5,-2147483648
	addi	a5,a5,256
	sw	a5,-24(s0)
	li	a5,-2130706432
	addi	a5,a5,256
	sw	a5,-28(s0)
	li	a5,-2113929216
	addi	a5,a5,256
	sw	a5,-32(s0)
	li	a5,-2097152000
	addi	a5,a5,256
	sw	a5,-36(s0)
	li	a5,33554432
	addi	a5,a5,4
	li	a4,104
	sw	a4,0(a5)
	li	a5,50331648
	li	a4,170
	sw	a4,0(a5)
	sw	zero,-40(s0)
	lui	a5,%hi(.LC0)
	addi	a0,a5,%lo(.LC0)
	call	print
	lw	a5,-24(s0)
	addi	a5,a5,8
	li	a4,5
	sw	a4,0(a5)
	lw	a5,-24(s0)
	lw	a5,0(a5)
	sw	a5,-40(s0)
	li	a1,8
	lw	a0,-40(s0)
	call	print_hex
	lui	a5,%hi(.LC1)
	addi	a0,a5,%lo(.LC1)
	call	print
	lui	a5,%hi(.LC1)
	addi	a0,a5,%lo(.LC1)
	call	print
	lui	a5,%hi(.LC2)
	addi	a0,a5,%lo(.LC2)
	call	print
	lw	a5,-24(s0)
	addi	a5,a5,8
	li	a4,3
	sw	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,4
	li	a4,7
	sw	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,8
	li	a4,2
	sw	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,4
	sw	zero,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,12
	li	a4,1
	sw	a4,0(a5)
	lui	a5,%hi(.LC3)
	addi	a0,a5,%lo(.LC3)
	call	print
	lw	a5,-24(s0)
	addi	a5,a5,8
	li	a4,3
	sw	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,4
	sw	zero,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,8
	li	a4,2
	sw	a4,0(a5)
	lui	a5,%hi(.LC4)
	addi	a0,a5,%lo(.LC4)
	call	print
	lw	a5,-24(s0)
	addi	a5,a5,4
	li	a4,61865984
	addi	a4,a4,-1
	sw	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,4
	li	a4,3145728
	addi	a4,a4,-1
	sw	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,4
	li	a4,1024
	sw	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,4
	li	a4,1024
	sw	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,4
	li	a4,10
	sw	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,4
	li	a4,32
	sw	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,4
	li	a4,8
	sw	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,4
	li	a4,16
	sw	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,8
	li	a4,6
	sw	a4,0(a5)
	lui	a5,%hi(.LC5)
	addi	a0,a5,%lo(.LC5)
	call	print
	lw	a5,-36(s0)
	addi	a5,a5,8
	li	a4,5
	sw	a4,0(a5)
	lw	a5,-36(s0)
	lw	a5,0(a5)
	sw	a5,-40(s0)
	li	a1,8
	lw	a0,-40(s0)
	call	print_hex
	lui	a5,%hi(.LC1)
	addi	a0,a5,%lo(.LC1)
	call	print
	lui	a5,%hi(.LC1)
	addi	a0,a5,%lo(.LC1)
	call	print
	lui	a5,%hi(.LC6)
	addi	a0,a5,%lo(.LC6)
	call	print
	lw	a5,-36(s0)
	addi	a5,a5,8
	li	a4,5
	sw	a4,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,4
	sw	zero,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,8
	li	a4,4
	sw	a4,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,4
	li	a4,45056
	addi	a4,a4,-1366
	sw	a4,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,8
	li	a4,1
	sw	a4,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,4
	sw	zero,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,8
	sw	zero,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,4
	li	a4,4096
	addi	a4,a4,682
	sw	a4,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,12
	li	a4,1
	sw	a4,0(a5)
	lui	a5,%hi(.LC7)
	addi	a0,a5,%lo(.LC7)
	call	print
	lw	a5,-36(s0)
	addi	a5,a5,8
	li	a4,3
	sw	a4,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,4
	sw	zero,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,8
	li	a4,2
	sw	a4,0(a5)
	sw	zero,-44(s0)
	lw	a5,-36(s0)
	lw	a5,0(a5)
	sw	a5,-44(s0)
	li	a1,8
	lw	a0,-44(s0)
	call	print_hex
	lui	a5,%hi(.LC1)
	addi	a0,a5,%lo(.LC1)
	call	print
	lui	a5,%hi(.LC1)
	addi	a0,a5,%lo(.LC1)
	call	print
	li	a5,1
	sb	a5,-45(s0)
.L7:
	li	a5,200704
	addi	a5,a5,-704
	sw	a5,-20(s0)
	j	.L5
.L6:
 #APP
# 132 "firmware/main.c" 1
	nop
# 0 "" 2
 #NO_APP
	lw	a5,-20(s0)
	addi	a5,a5,-1
	sw	a5,-20(s0)
.L5:
	lw	a5,-20(s0)
	bgt	a5,zero,.L6
	j	.L7
	.size	main, .-main
	.ident	"GCC: (g04696df09) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
