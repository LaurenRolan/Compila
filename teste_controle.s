	.file	"teste_controle.c"
	.globl	a
	.data
	.align 8
	.type	a, @object
	.size	a, 8
a:
	.quad	2
	.globl	b
	.align 8
	.type	b, @object
	.size	b, 8
b:
	.quad	123
	.globl	c
	.align 8
	.type	c, @object
	.size	c, 8
c:
	.quad	456
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
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jle	.L2
	movq	a(%rip), %rax
	addq	%rax, %rax
	movq	%rax, a(%rip)
	jmp	.L3
.L2:
	movq	a(%rip), %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	movq	%rax, a(%rip)
.L3:
	movq	c(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jle	.L5
	movq	a(%rip), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	movq	%rax, a(%rip)
	jmp	.L5
.L6:
	movq	a(%rip), %rax
	subq	$1, %rax
	movq	%rax, a(%rip)
.L5:
	movq	a(%rip), %rax
	testq	%rax, %rax
	jg	.L6
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
