### VARIABLES ###
	.data
a:
	.quad	0
	.data
b:
	.quad	111
	.data
c:
	.quad	333

### STRINGS ###

stringgod:		#nosso compilador só lida com variaveis do tipo LONG por enquanto
	.string	"%ld"

string18:
	.string	"\n"

string30:
	.string	"oi1\n"

string94:
	.string	"tchau1\n"


### CÓDIGO ###




	.text
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp


#TAC ASS
	movq	$2, b(%rip)



#TAC AND
	movq	b(%rip), %rdx
	movq	$1, %rax
	testq	%rdx, %rdx
	je	.LogicLabel__2
	testq	%rax, %rax
	je	.LogicLabel__2
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

	popq	%rbp
	ret

	.text
	.globl	funcao
funcao:
	pushq	%rbp
	movq	%rsp, %rbp

___Label_1___:


#TAC LES
	movq	a(%rip), %rdx
	movq	$4, %rax
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
	jz	___Label_2___


#TAC PRINT
	movq	a(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string18, %edi
	call	puts



#TAC ADD
	movq	a(%rip), %rax
	addq	$1, %rax

#TAC ASS
	movq	%rax, a(%rip)

#TAC JMP
	jmp	___Label_1___

___Label_2___:
	popq	%rbp
	ret


#FIM DO PROGRAMA
