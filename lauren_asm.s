	#.file	"to_asm.c"
	#.section	.rodata
#Define string
printable:
	.string	"%ld"
	.text

#Define função
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
#	subq	$32, %rsp
	#Atribuicao 1
	movq	$5, -24(%rbp)
	#Atribuicao 2
	movq	$120, -16(%rbp)
	#Soma
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -8(%rbp)

	#print
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$printable, %edi
	movl	$0, %eax
	call	printf

#	movl	$0, %eax
#	leave
#	.cfi_def_cfa 7, 8
	ret
#	.cfi_endproc
#.LFE2:
#	.size	main, .-main
#	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
#	.section	.note.GNU-stack,"",@progbits
