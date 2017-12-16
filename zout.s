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
	.data
xis:
	.quad	0
	.data
ypsilo:
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

### STRINGS ###

stringgod:		#nosso compilador só lida com variaveis do tipo LONG por enquanto
	.string	"%ld"

string18:
	.string	"\n"

string24:
	.string	"\t"


### CÓDIGO ###




	.text
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp


#TAC PRINT
	movq	c(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string18, %edi
	call	puts


#TAC ARG
	movq	a(%rip), %rax

	movq	%rax, xis(%rip)


#TAC ARG
	movq	$8923, ypsilo(%rip)

#TAC FUNCALL
	movl	$0, %eax
	call	funcao
	movq	%rax, ___variavelTemporaria_0___(%rip)

#TAC ASS
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



#TAC ADD
	movq	$1, %rdx
	movq	$2, %rax
	addq	%rdx, %rax
	movq	%rax, ___variavelTemporaria_1___(%rip)


#TAC ADD
	movq	___variavelTemporaria_1___(%rip), %rax
	addq	$3, %rax
	movq	%rax, ___variavelTemporaria_2___(%rip)


#TAC ADD
	movq	___variavelTemporaria_2___(%rip), %rax
	addq	$4, %rax
	movq	%rax, ___variavelTemporaria_3___(%rip)

#TAC ASS
	movq	%rax, a(%rip)


#TAC PRINT
	movq	xis(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string24, %edi
	call	puts


#TAC PRINT
	movq	ypsilo(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string18, %edi
	call	puts



#TAC ADD
	movq	a(%rip), %rax
	addq	$10, %rax
	movq	%rax, ___variavelTemporaria_4___(%rip)

#TAC RETURN
	movq	___variavelTemporaria_4___(%rip), %rax

	popq	%rbp
	ret

	popq	%rbp
	ret


#FIM DO PROGRAMA
