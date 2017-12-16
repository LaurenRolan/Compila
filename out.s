### VARIABLES ###
	.data
bytezao:
	.quad	1
	.data
shortzao:
	.quad	23
	.data
longzao:
	.quad	456
	.data

	.size	vetor_inicializado, 40
vetor_inicializado:
	.quad	1
	.quad	2
	.quad	3
	.quad	4
	.quad	5

	.comm	vetor_vazio,40,32
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
	.data
___variavelTemporaria_7___:
	.quad	0
	.data
___variavelTemporaria_8___:
	.quad	0
	.data
___variavelTemporaria_9___:
	.quad	0
	.data
___variavelTemporaria_10___:
	.quad	0
	.data
___variavelTemporaria_11___:
	.quad	0
	.data
___variavelTemporaria_12___:
	.quad	0
	.data
___variavelTemporaria_13___:
	.quad	0
	.data
___variavelTemporaria_14___:
	.quad	0
	.data
___variavelTemporaria_15___:
	.quad	0
	.data
___variavelTemporaria_16___:
	.quad	0
	.data
___variavelTemporaria_17___:
	.quad	0

### STRINGS ###

stringgod:		#nosso compilador só lida com variaveis do tipo LONG por enquanto
	.string	"%ld"

string18:
	.string	"\n"

string90:
	.string	"Os valores do vetor inicializado sao: "

string103:
	.string	" "

string116:
	.string	"vetor_vazio[0] = "

string167:
	.string	"Agora vamos mudar o vazio:\n"

string180:
	.string	" + "

string198:
	.string	" = "

string251:
	.string	"Eu sou um longzao de valor "


### CÓDIGO ###











	.text
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp



#TAC GE
	movq	longzao(%rip), %rdx
	movq	shortzao(%rip), %rax
	cmpq	%rax, %rdx
	jl	.LogicLabel__2
	movq	$1, ___variavelTemporaria_0___(%rip)
	jmp	.LogicLabel__3
.LogicLabel__2:
	movq	$0, ___variavelTemporaria_0___(%rip)
.LogicLabel__3:

#TAC JZ
	movq	___variavelTemporaria_0___(%rip), %rax

	movq	$0, %rdx

	cmpq	%rax, %rdx
	jz	___Label_1___


#TAC PRINT
	movl	$string251, %edi
	call	puts


#TAC PRINT
	movq	longzao(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string18, %edi
	call	puts

#TAC JMP
	jmp	___Label_0___

___Label_1___:
#TAC READ
	movl	$longzao, %esi
	movl	$stringgod, %edi
	call	__isoc99_scanf

___Label_0___:

#TAC PRINT
	movl	$string90, %edi
	call	puts


#VECTOR
	movq	vetor_inicializado+0(%rip), %r10
	movq	 %r10, ___variavelTemporaria_2___(%rip)

#TAC PRINT
	movq	___variavelTemporaria_2___(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string103, %edi
	call	puts


#VECTOR
	movq	vetor_inicializado+8(%rip), %r10
	movq	 %r10, ___variavelTemporaria_4___(%rip)

#TAC PRINT
	movq	___variavelTemporaria_4___(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string103, %edi
	call	puts


#VECTOR
	movq	vetor_inicializado+16(%rip), %r10
	movq	 %r10, ___variavelTemporaria_6___(%rip)

#TAC PRINT
	movq	___variavelTemporaria_6___(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string103, %edi
	call	puts


#VECTOR
	movq	vetor_inicializado+24(%rip), %r10
	movq	 %r10, ___variavelTemporaria_8___(%rip)

#TAC PRINT
	movq	___variavelTemporaria_8___(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string103, %edi
	call	puts


#VECTOR
	movq	vetor_inicializado+32(%rip), %r10
	movq	 %r10, ___variavelTemporaria_10___(%rip)

#TAC PRINT
	movq	___variavelTemporaria_10___(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string18, %edi
	call	puts


#TAC PRINT
	movl	$string167, %edi
	call	puts


#TAC PRINT
	movl	$string116, %edi
	call	puts

#TAC READ
	movl	$longzao, %esi
	movl	$stringgod, %edi
	call	__isoc99_scanf



#VEC ASS
	movq	longzao(%rip), %rax

	movq	%rax, vetor_vazio+0(%rip)


#VECTOR
	movq	vetor_vazio+0(%rip), %r10
	movq	 %r10, ___variavelTemporaria_11___(%rip)


#VECTOR
	movq	vetor_inicializado+0(%rip), %r10
	movq	 %r10, ___variavelTemporaria_12___(%rip)

#TAC ADD
	movq	___variavelTemporaria_11___(%rip), %rdx
	movq	___variavelTemporaria_12___(%rip), %rax
	addq	%rdx, %rax
	movq	%rax, ___variavelTemporaria_13___(%rip)

#TAC ASS
	movq	%rax, longzao(%rip)


#VECTOR
	movq	vetor_vazio+0(%rip), %r10
	movq	 %r10, ___variavelTemporaria_17___(%rip)

#TAC PRINT
	movq	___variavelTemporaria_17___(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string180, %edi
	call	puts


#VECTOR
	movq	vetor_inicializado+0(%rip), %r10
	movq	 %r10, ___variavelTemporaria_16___(%rip)

#TAC PRINT
	movq	___variavelTemporaria_16___(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string198, %edi
	call	puts


#TAC PRINT
	movq	longzao(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string18, %edi
	call	puts

	popq	%rbp
	ret


#FIM DO PROGRAMA
