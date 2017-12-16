	.file	"ZARAKI.c"
	.globl	a
	.data
	.align 8
	.type	a, @object
	.size	a, 8
a:
	.quad	222
	.globl	b
	.align 8
	.type	b, @object
	.size	b, 8
b:
	.quad	111
	.globl	c
	.bss
	.align 8
	.type	c, @object
	.size	c, 8
c:
	.zero	8
	.globl	x
	.data
	.align 8
	.type	x, @object
	.size	x, 8
x:
	.quad	333
	.section	.rodata
.LC0:
	.string	"oi1"
.LC1:
	.string	"tchau1"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	c(%rip), %rax
	testq	%rax, %rax
	je	.L2
	movq	a(%rip), %rax
	testq	%rax, %rax
	je	.L2
	movl	$.LC0, %edi
	call	puts
	jmp	.L4
.L2:
	movl	$.LC1, %edi
	call	puts
.L4:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC2:
	.string	"OI EU SOU GOKU"
	.text
	.globl	func
	.type	func, @function
func:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	func, .-func
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
