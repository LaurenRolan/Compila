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
	.section	.rodata
.LC0:
	.string	"Nao"
.LC1:
	.string	"a = %ld e b = %ld"
.LC2:
	.string	"%ld %ld %ld"
.LC3:
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
	movl	$0, %eax
	call	printf
	movq	b(%rip), %rdx
	movq	a(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movq	c(%rip), %rcx
	movq	b(%rip), %rdx
	movq	a(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$a, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
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
