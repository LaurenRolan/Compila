	.data
a:
	.quad	2
	.data
b:
	.quad	2
	.data
c:
	.quad	2
	.data
d:
	.quad	3
#STRINGS
#CÓDIGO

	.text
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp






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



	movq	$6, %rdx
	movq	$3, %rax
	addq	%rdx, %rax
	movq	%rax, a(%rip)



	movq	c(%rip), %rdx
	movq	a(%rip), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, b(%rip)



	movq	b(%rip), %rax
	subq	$3, %rax
	movq	%rax, a(%rip)



	movq	b(%rip), %rax
	subq	$3, %rax
	movq	%rax, a(%rip)



	movq	$6, %rdx
	movq	$3, %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, a(%rip)



	movq	a(%rip), %rdx
	movq	c(%rip), %rax
	imulq	%rdx, %rax
	movq	%rax, b(%rip)



	movq	a(%rip), %rax
	imulq	$3, %rax
	movq	%rax, b(%rip)



	movq	a(%rip), %rax
	imulq	$6, %rax
	movq	%rax, b(%rip)



	movq	$6, %rdx
	movq	$3, %rax
	imulq	%rdx, %rax
	movq	%rax, b(%rip)



	movq	a(%rip), %rdx
	movq	d(%rip), %rsi
	cqto
	idivq	%rsi
	movq	%rax, b(%rip)



	movq	a(%rip), %rax
	movl	$3, %eax
	cqto
	idivq	%rdi
	movq	%rax, b(%rip)



	movq	d(%rip), %rax
	movl	$6, %eax
	cqto
	idivq	%rdi
	movq	%rax, b(%rip)



	movq	$6, %rdx
	movq	$3, %rax
	cqto
	idivq	%rdi
	movq	%rax, b(%rip)





	movq	a(%rip), %rdx
	movq	b(%rip), %rsi
	cqto
	idivq	%rsi
	movq	%rax, c(%rip)





	movq	a(%rip), %rdx
	movq	b(%rip), %rsi
	cqto
	idivq	%rsi
	movq	%rax, c(%rip)





	movq	a(%rip), %rdx
	movq	b(%rip), %rsi
	cqto
	idivq	%rsi
	movq	%rax, c(%rip)





	movq	a(%rip), %rdx
	movq	b(%rip), %rsi
	cqto
	idivq	%rsi
	movq	%rax, c(%rip)





	movq	a(%rip), %rdx
	movq	b(%rip), %rsi
	cqto
	idivq	%rsi
	movq	%rax, c(%rip)





	movq	a(%rip), %rdx
	movq	b(%rip), %rsi
	cqto
	idivq	%rsi
	movq	%rax, c(%rip)





	movq	a(%rip), %rdx
	movq	b(%rip), %rsi
	cqto
	idivq	%rsi
	movq	%rax, c(%rip)

	popq	%rbp
	ret
#FIM DO PROGRAMA
