### VARIABLES ###

	.data
a:
	.quad	9

	.data
b:
	.quad	8
	.data

	.size	c, 40
c:
	.quad	0
	.quad	1
	.quad	2
	.quad	3
	.quad	4

	.comm	resul,80,32
	.data
soma:
	.quad	0

	.data
i:
	.quad	0
	.data
op1s:
	.quad	0
	.data
op2s:
	.quad	0
	.data
lido:
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

### STRINGS ###

stringgod:		#nosso compilador só lida com variaveis do tipo LONG por enquanto
	.string	"%ld"

string18:
	.string	"\n"

string24:
	.string	"\t"

string77:
	.string	":\n"

string102:
	.string	"A soma da "

string115:
	.string	"Estou lendo b: "

string149:
	.string	"Estou somando "

string192:
	.string	"b tem o valor\t"

string202:
	.string	" com "

string225:
	.string	"b tem o valor \t"


### CÓDIGO ###












	.text
	.globl	funcao_soma
funcao_soma:
	pushq	%rbp
	movq	%rsp, %rbp


#TAC PRINT
	movl	$string149, %edi
	call	puts


#TAC PRINT
	movq	op1s(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string202, %edi
	call	puts


#TAC PRINT
	movq	op2s(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string77, %edi
	call	puts



#TAC ADD
	movq	op1s(%rip), %rdx
	movq	op2s(%rip), %rax
	addq	%rdx, %rax
	movq	%rax, ___variavelTemporaria_0___(%rip)

#TAC RETURN
	movq	___variavelTemporaria_0___(%rip), %rax

	popq	%rbp
	ret

	popq	%rbp
	ret

	.text
	.globl	funcao_le
funcao_le:
	pushq	%rbp
	movq	%rsp, %rbp


#TAC PRINT
	movl	$string115, %edi
	call	puts

#TAC READ
	movl	$b, %esi
	movl	$stringgod, %edi
	call	__isoc99_scanf


#TAC RETURN
	movq	b(%rip), %rax

	popq	%rbp
	ret

	popq	%rbp
	ret

	.text
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp



#TAC ARG
	movq	a(%rip), %rax

	movq	%rax, op1s(%rip)


#VECTOR
	movq	c+8(%rip), %r10
	movq	 %r10, ___variavelTemporaria_3___(%rip)

#TAC ARG
	movq	___variavelTemporaria_3___(%rip), %rax

	movq	%rax, op2s(%rip)

#TAC FUNCALL
	movl	$0, %eax
	call	funcao_soma
	movq	%rax, ___variavelTemporaria_2___(%rip)

#VEC ASS
	movq	___variavelTemporaria_2___(%rip), %rax

	movq	%rax, resul+0(%rip)


#TAC PRINT
	movl	$string102, %edi
	call	puts


#VECTOR
	movq	resul+0(%rip), %r10
	movq	 %r10, ___variavelTemporaria_5___(%rip)

#TAC PRINT
	movq	___variavelTemporaria_5___(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string18, %edi
	call	puts


#VECTOR
	movq	resul+0(%rip), %r10
	movq	 %r10, ___variavelTemporaria_6___(%rip)


#TAC GE
	movq	___variavelTemporaria_6___(%rip), %rdx
	movq	$10, %rax
	cmpq	%rax, %rdx
	jl	.LogicLabel__2
	movq	$1, ___variavelTemporaria_7___(%rip)
	jmp	.LogicLabel__3
.LogicLabel__2:
	movq	$0, ___variavelTemporaria_7___(%rip)
.LogicLabel__3:

#TAC JZ
	movq	___variavelTemporaria_7___(%rip), %rax

	movq	$0, %rdx

	cmpq	%rax, %rdx
	jz	___Label_1___


#TAC ARG
	movq	b(%rip), %rax

	movq	%rax, lido(%rip)

#TAC FUNCALL
	movl	$0, %eax
	call	funcao_le
	movq	%rax, ___variavelTemporaria_8___(%rip)

#TAC ASS
	movq	%rax, b(%rip)


#TAC PRINT
	movl	$string225, %edi
	call	puts


#TAC PRINT
	movq	b(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf

#TAC JMP
	jmp	___Label_0___

___Label_1___:

#TAC ARG
	movq	a(%rip), %rax

	movq	%rax, op1s(%rip)


#VECTOR
	movq	c+16(%rip), %r10
	movq	 %r10, ___variavelTemporaria_11___(%rip)

#TAC ARG
	movq	___variavelTemporaria_11___(%rip), %rax

	movq	%rax, op2s(%rip)

#TAC FUNCALL
	movl	$0, %eax
	call	funcao_soma
	movq	%rax, ___variavelTemporaria_10___(%rip)

#TAC ASS
	movq	%rax, b(%rip)


#TAC PRINT
	movl	$string192, %edi
	call	puts


#TAC PRINT
	movq	b(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf

___Label_0___:
___Label_2___:


#TAC GRE
	movq	b(%rip), %rdx
	movq	$1, %rax
	cmpq	%rax, %rdx
	jle	.LogicLabel__4
	movq	$1, ___variavelTemporaria_12___(%rip)
	jmp	.LogicLabel__5
.LogicLabel__4:
	movq	$0, ___variavelTemporaria_12___(%rip)
.LogicLabel__5:

#TAC JZ
	movq	___variavelTemporaria_12___(%rip), %rax

	movq	$0, %rdx

	cmpq	%rax, %rdx
	jz	___Label_3___


#TAC PRINT
	movq	b(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


#TAC PRINT
	movl	$string24, %edi
	call	puts



#TAC SUB
	movq	b(%rip), %rax
	subq	$1, %rax
	movq	%rax, ___variavelTemporaria_13___(%rip)

#TAC ASS
	movq	%rax, b(%rip)

#TAC JMP
	jmp	___Label_2___

___Label_3___:
	popq	%rbp
	ret


#FIM DO PROGRAMA
