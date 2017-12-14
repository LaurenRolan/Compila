#	.file	"to_asm.c"
	.comm	a,8,8
	.comm	b,8,8
	.comm	c,8,8
#	.section	.rodata
printable:
	.string	"%ld"
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
	#ATRIBUICOES
	movq	$5, a(%rip)
	movq	$120, b(%rip)
	#ADD
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	addq	%rdx, %rax

	#ATRIBUICAO
	movq	%rax, c(%rip)

	#PRINT
	movq	c(%rip), %rax
	movq	%rax, %rsi
	movl	$printable, %edi
	movl	$0, %eax
	call	printf
#	movl	$0, %eax
	popq	%rbp
#	.cfi_def_cfa 7, 8
	ret
#	.cfi_endproc
#.LFE2:
#	.size	main, .-main
#	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
#	.section	.note.GNU-stack,"",@progbits
