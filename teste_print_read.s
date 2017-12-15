	.file	"teste_print_read.c"
	.globl	a
	.data
	.align 8
	.type	a, @object
	.size	a, 8
a:
	.quad	111
	.globl	b
	.align 8
	.type	b, @object
	.size	b, 8
b:
	.quad	222
	.globl	c
	.align 8
	.type	c, @object
	.size	c, 8
c:
	.quad	333
	.globl	d
	.align 8
	.type	d, @object
	.size	d, 8
d:
	.quad	19999
	.globl	e
	.align 8
	.type	e, @object
	.size	e, 8
e:
	.quad	10000
	.globl	f
	.align 8
	.type	f, @object
	.size	f, 8
f:
	.quad	2000
	.globl	g
	.align 8
	.type	g, @object
	.size	g, 8
g:
	.quad	5000
	.section	.rodata
.LC0:
	.string	"Nao"
.LC1:
	.string	"%ld\n"
.LC2:
	.string	"%ld"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %edi
	call	puts
	movq	a(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf

	movl	$a, %esi
	movl	$.LC2, %edi
#	movl	$0, %eax
	call	__isoc99_scanf

	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
