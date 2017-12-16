	.data
a:
	.quad	222
	.data
b:
	.quad	111
#STRINGS

stringgod:
	.string	"%ld"

string30:
	.string	"oi1\n"

string31:
	.string	"oi2\n"

string94:
	.string	"tchau1\n"

string95:
	.string	"tchau2\n"
#CÓDIGO

	.text
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp





#TAC GRE
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jle	.LogicLabel__2
	movq	$1, %rcx
	jmp	.LogicLabel__3
.LogicLabel__2:
	movq	$0, %rcx
.LogicLabel__3:

#TAC JZ
	movq	$0, %rdx

	cmpq	%rcx, %rdx
	jz	___Label_0___


#TAC PRINT
	movl	$string30, %edi
	call	puts

___Label_0___:

#TAC PRINT
	movl	$string94, %edi
	call	puts



#TAC LES
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jge	.LogicLabel__4
	movq	$1, %rcx
	jmp	.LogicLabel__5
.LogicLabel__4:
	movq	$0, %rcx
.LogicLabel__5:

#TAC JZ
	movq	$0, %rdx

	cmpq	%rcx, %rdx
	jz	___Label_1___


#TAC PRINT
	movl	$string31, %edi
	call	puts

___Label_1___:

#TAC PRINT
	movl	$string95, %edi
	call	puts

	popq	%rbp
	ret
#FIM DO PROGRAMA
