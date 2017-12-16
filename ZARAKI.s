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
	.globl	nicolas
	.bss
	.align 8
	.type	nicolas, @object
	.size	nicolas, 8
nicolas:
	.zero	8
	.section	.rodata
.LC0:
	.string	"OI EU SOU GOKU"
.LC1:
	.string	"nao"
	.text
	.globl	func
	.type	func, @function
func:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	a(%rip), %rax
	testq	%rax, %rax
	je	.L2
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movq	c(%rip), %rdx
	movq	x(%rip), %rax
	addq	%rdx, %rax
	jmp	.L1
.L2:
	movq	a(%rip), %rax
	testq	%rax, %rax
	jne	.L4
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	addq	%rdx, %rax
	jmp	.L1
.L4:
.L1:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	func, .-func
	.section	.rodata
.LC2:
	.string	"oi1"
.LC3:
	.string	"tchau1"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	c(%rip), %rax
	testq	%rax, %rax
	je	.L6
	movq	a(%rip), %rax
	testq	%rax, %rax
	je	.L6
	movl	$.LC2, %edi
	call	puts
	jmp	.L7
.L6:
	movl	$.LC3, %edi
	call	puts
.L7:
	movl	$0, %eax
	call	func
	movq	%rax, c(%rip)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
