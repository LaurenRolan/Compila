### VARIABLES ###
	.data
b:
	.quad	6

### TEMP VARS ###
	.data
___variavelTemporaria_0___:
	.quad	0

### STRINGS ###

stringgod:		#nosso compilador só lida com variaveis do tipo LONG por enquanto
	.string	"%ld"


### CÓDIGO ###



	.text
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp



#VEC ASS
	movq	b(%rip), %rax

	movq	%rax, a+24(%rip)



#VEC ASS
	movq	$11, %rax
	movq	%rax, a+16(%rip)

#VECTOR
	movq	a+0(%rip), ___variavelTemporaria_0___(%rip)

#TAC ASS
	movq	___variavelTemporaria_0___(%rip), %rax

	movq	%rax, b(%rip)

	popq	%rbp
	ret


#FIM DO PROGRAMA
