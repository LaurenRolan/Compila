	.file	"teste_vetor.c"
	.comm	a,40,32
	.comm	epsilon,72,32
	.globl	b
	.data
	.align 8
	.type	b, @object
	.size	b, 8
b:
	.quad	6
	.globl	c
	.align 16
	.type	c, @object
	.size	c, 24
c:
	.quad	555
	.quad	444
	.quad	333
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
	movq	b(%rip), %rax
	movq	%rax, a+24(%rip)
	movq	a(%rip), %rax
	movq	%rax, b(%rip)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
