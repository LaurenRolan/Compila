	.file	"teste_arit.c"
	.comm	a,8,8
	.comm	b,8,8
	.comm	c,8,8
	.globl	d
	.data
	.align 8
	.type	d, @object
	.size	d, 8
d:
	.quad	3
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
	movq	$6, a(%rip)
	movq	$3, b(%rip)
	movq	a(%rip), %rax
	movq	%rax, c(%rip)
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	addq	%rdx, %rax
	movq	%rax, c(%rip)
	movq	a(%rip), %rax
	addq	$3, %rax
	movq	%rax, a(%rip)
	movq	a(%rip), %rax
	addq	$6, %rax
	movq	%rax, a(%rip)
	movq	$9, a(%rip)
	movq	c(%rip), %rdx
	movq	a(%rip), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, b(%rip)
	movq	b(%rip), %rax
	subq	$3, %rax
	movq	%rax, a(%rip)
	movq	b(%rip), %rax
	movl	$3, %edx
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, a(%rip)
	movq	$3, a(%rip)
	movq	a(%rip), %rdx
	movq	c(%rip), %rax
	imulq	%rdx, %rax
	movq	%rax, b(%rip)
	movq	a(%rip), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	movq	%rax, b(%rip)
	movq	a(%rip), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rax, %rax
	movq	%rax, b(%rip)
	movq	$18, b(%rip)
	movq	a(%rip), %rax
	movq	d(%rip), %rsi
	cqto
	idivq	%rsi
	movq	%rax, b(%rip)
	movq	a(%rip), %rcx
	movabsq	$6148914691236517206, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	movq	%rcx, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, b(%rip)
	movq	d(%rip), %rdi
	movl	$6, %eax
	cqto
	idivq	%rdi
	movq	%rax, b(%rip)
	movq	$2, b(%rip)
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jl	.L2
	movq	a(%rip), %rax
	movq	b(%rip), %rsi
	cqto
	idivq	%rsi
	movq	%rax, c(%rip)
.L2:
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jg	.L3
	movq	a(%rip), %rax
	movq	b(%rip), %rdi
	cqto
	idivq	%rdi
	movq	%rax, c(%rip)
.L3:
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jle	.L4
	movq	a(%rip), %rax
	movq	b(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rax, c(%rip)
.L4:
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jge	.L5
	movq	a(%rip), %rax
	movq	b(%rip), %rsi
	cqto
	idivq	%rsi
	movq	%rax, c(%rip)
.L5:
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jne	.L6
	movq	a(%rip), %rax
	movq	b(%rip), %rdi
	cqto
	idivq	%rdi
	movq	%rax, c(%rip)
.L6:
	movq	a(%rip), %rax
	testq	%rax, %rax
	je	.L7
	movq	b(%rip), %rax
	testq	%rax, %rax
	je	.L7
	movq	a(%rip), %rax
	movq	b(%rip), %rcx
	cqto
	idivq	%rcx
	movq	%rax, c(%rip)
.L7:
	movq	a(%rip), %rax
	testq	%rax, %rax
	jne	.L8
	movq	b(%rip), %rax
	testq	%rax, %rax
	je	.L9
.L8:
	movq	a(%rip), %rax
	movq	b(%rip), %rsi
	cqto
	idivq	%rsi
	movq	%rax, c(%rip)
.L9:
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
