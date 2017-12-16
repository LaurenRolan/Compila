	.file	"ZARAKI.c"
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	1130246963
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	1121858355
	.globl	x
	.align 4
	.type	x, @object
	.size	x, 4
x:
	.long	1134995046
	.section	.rodata
.LC0:
	.string	"oi"
.LC1:
	.string	"tchau"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	a(%rip), %xmm0
	movss	b(%rip), %xmm1
	ucomiss	%xmm1, %xmm0
	jbe	.L2
	movl	$.LC0, %edi
	call	puts
.L2:
	movl	$.LC1, %edi
	call	puts
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
