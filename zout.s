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
	.data
n:
	.quad	0
	.data
k:
	.quad	0

### TEMP VARS ###
	.data
___variavelTemporaria_0___:
	.quad	0
	.data
___variavelTemporaria_1___:
	.quad	0
	.data
___variavelTemporaria_2___:
	.quad	0
	.data
___variavelTemporaria_3___:
	.quad	0
	.data
___variavelTemporaria_4___:
	.quad	0
	.data
___variavelTemporaria_5___:
	.quad	0
	.data
___variavelTemporaria_6___:
	.quad	0

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



#TAC OR
	movq	b(%rip), %rdx
	movq	$1, %rax
	testq	%rdx, %rdx
	jne	.LogicLabel__2
	testq	%rax, %rax
	je	.LogicLabel__3
.LogicLabel__2:
	movq	$1, ___variavelTemporaria_0___(%rip)
	jmp	.LogicLabel__4
.LogicLabel__3:
	movq	$0, ___variavelTemporaria_0___(%rip)
.LogicLabel__4:

#TAC JZ
	movq	___variavelTemporaria_0___(%rip), %rax

	movq	$0, %rdx

	cmpq	%rax, %rdx
	jz	___Label_0___


#TAC PRINT
	movl	$string30, %edi
	call	puts

___Label_0___:

#TAC PRINT
	movl	$string94, %edi
	call	puts


#TAC PRINT
	movq	2(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf

#TAC FUNCALL
	movl	$0, %eax
	call	funcao
	movq	%rax, ___variavelTemporaria_1___(%rip)

#TAC ASS
	movq	___variavelTemporaria_1___(%rip), %rax

	movq	%rax, c(%rip)


#TAC PRINT
	movq	c(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string18, %edi
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
	jge	.LogicLabel__5
	movq	$1, ___variavelTemporaria_2___(%rip)
	jmp	.LogicLabel__6
.LogicLabel__5:
	movq	$0, ___variavelTemporaria_2___(%rip)
.LogicLabel__6:

#TAC JZ
	movq	___variavelTemporaria_2___(%rip), %rax

	movq	$0, %rdx

	cmpq	%rax, %rdx
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
	movq	%rax, ___variavelTemporaria_3___(%rip)

#TAC ASS
	movq	___variavelTemporaria_3___(%rip), %rax

	movq	%rax, a(%rip)

#TAC JMP
	jmp	___Label_1___

___Label_2___:


#TAC ADD
	movq	$1, %rdx
	movq	$2, %rax
	addq	%rdx, %rax
	movq	%rax, ___variavelTemporaria_4___(%rip)


#TAC ADD
	movq	___variavelTemporaria_4___(%rip), %rax
	addq	$3, %rax
	movq	%rax, ___variavelTemporaria_5___(%rip)


#TAC ADD
	movq	___variavelTemporaria_5___(%rip), %rax
	addq	$4, %rax
	movq	%rax, ___variavelTemporaria_6___(%rip)

#TAC ASS
	movq	___variavelTemporaria_6___(%rip), %rax

	movq	%rax, a(%rip)


#TAC PRINT
	movq	a(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string18, %edi
	call	puts


#TAC RETURN
	movq	a(%rip), %rax

	popq	%rbp
	ret

	popq	%rbp
	ret


#FIM DO PROGRAMA
