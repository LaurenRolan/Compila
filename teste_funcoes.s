	.file	"teste_funcoes.c"
	.comm	a,8,8
	.comm	b,8,8
	.comm	c,8,8
	.text
	.globl	funcao1
	.type	funcao1, @function
funcao1:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	funcao1, .-funcao1
	.globl	funcao2
	.type	funcao2, @function
funcao2:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$3333, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	funcao2, .-funcao2
	.globl	main
	.type	main, @function
main:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	.cfi_offset 3, -24
	movl	$3, %edx
	movl	$2, %esi
	movl	$1, %edi
	call	funcao1
	movq	%rax, a(%rip)
	movl	$0, %eax
	call	funcao2
	movq	%rax, b(%rip)
	movl	$3, %edx
	movl	$2, %esi
	movl	$1, %edi
	call	funcao1
	movq	%rax, %rbx
	movl	$0, %eax
	call	funcao2
	addq	%rbx, %rax
	movq	%rax, c(%rip)
	movl	$0, %eax
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
