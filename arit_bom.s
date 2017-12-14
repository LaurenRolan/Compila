	#.file	"teste_arit.c"
	.comm	a,8,8
	.comm	b,8,8
	.comm	c,8,8
	.comm	x,8,8
	.comm	y,8,8
	.comm	z,8,8
	#.text
	.globl	main
	#.type	main, @function
main:
#.LFB2:
#	.cfi_startproc
	pushq	%rbp
#	.cfi_def_cfa_offset 16
#	.cfi_offset 6, -16
	movq	%rsp, %rbp
#	.cfi_def_cfa_register 6
	#ATRIBUICAO
	movq	$5, a(%rip)
	movq	$3, b(%rip)

	#SOMA
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	addq	%rdx, %rax

	#ATRIBUICAO
	movq	%rax, c(%rip)
	
	#SUBTRACAO
	movq	a(%rip), %rdx
	movq	c(%rip), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	
	#ATRIBUICAO
	movq	%rax, b(%rip)

	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, x(%rip)
	movsd	x(%rip), %xmm0
	movsd	.LC1(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, y(%rip)
	movq	a(%rip), %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	movsd	y(%rip), %xmm1
	ucomisd	%xmm1, %xmm0
	jb	.L2
	movsd	y(%rip), %xmm1
	movsd	x(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, z(%rip)
.L2:
	movq	a(%rip), %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	movsd	y(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jb	.L4
	movsd	y(%rip), %xmm1
	movsd	x(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, z(%rip)
.L4:
	movq	a(%rip), %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	movsd	y(%rip), %xmm1
	ucomisd	%xmm1, %xmm0
	jbe	.L6
	movsd	y(%rip), %xmm1
	movsd	x(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, z(%rip)
.L6:
	movq	a(%rip), %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	movsd	y(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L8
	movsd	y(%rip), %xmm1
	movsd	x(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, z(%rip)
.L8:
	movq	a(%rip), %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	movsd	y(%rip), %xmm1
	ucomisd	%xmm1, %xmm0
	jp	.L10
	ucomisd	%xmm1, %xmm0
	jne	.L10
	movsd	y(%rip), %xmm1
	movsd	x(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, z(%rip)
.L10:
	movq	a(%rip), %rax
	testq	%rax, %rax
	je	.L12
	movq	b(%rip), %rax
	testq	%rax, %rax
	je	.L12
	movsd	y(%rip), %xmm1
	movsd	x(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, z(%rip)
.L12:
	movq	a(%rip), %rax
	testq	%rax, %rax
	jne	.L13
	movq	b(%rip), %rax
	testq	%rax, %rax
	je	.L14
.L13:
	movsd	y(%rip), %xmm1
	movsd	x(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, z(%rip)
.L14:
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	3435973837
	.long	1074842828
	.align 8
.LC1:
	.long	0
	.long	1074266112
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
