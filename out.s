### VARIABLES ###

	.data
a:
	.quad	2

	.data
b:
	.quad	2

	.data
c:
	.quad	2

	.data
d:
	.quad	3

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
___variavelTemporaria_20___:
	.quad	0
	.data
___variavelTemporaria_11___:
	.quad	0
	.data
___variavelTemporaria_21___:
	.quad	0
	.data
___variavelTemporaria_12___:
	.quad	0
	.data
___variavelTemporaria_22___:
	.quad	0
	.data
___variavelTemporaria_13___:
	.quad	0
	.data
___variavelTemporaria_23___:
	.quad	0
	.data
___variavelTemporaria_14___:
	.quad	0
	.data
___variavelTemporaria_24___:
	.quad	0
	.data
___variavelTemporaria_15___:
	.quad	0
	.data
___variavelTemporaria_25___:
	.quad	0
	.data
___variavelTemporaria_16___:
	.quad	0
	.data
___variavelTemporaria_26___:
	.quad	0
	.data
___variavelTemporaria_17___:
	.quad	0
	.data
___variavelTemporaria_27___:
	.quad	0
	.data
___variavelTemporaria_18___:
	.quad	0
	.data
___variavelTemporaria_28___:
	.quad	0
	.data
___variavelTemporaria_19___:
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


#TAC ASS
	movq	$6, a(%rip)


#TAC ASS
	movq	$3, b(%rip)






#TAC ADD
	movq	a(%rip), %rax
	addq	$3, %rax
	movq	%rax, ___variavelTemporaria_1___(%rip)

#TAC ASS
	movq	%rax, a(%rip)











#TAC SUB
	movq	$3, %rax
	movq	%rax, ___variavelTemporaria_6___(%rip)

#TAC ASS
	movq	%rax, a(%rip)















#TAC DIV
	movq	$2, %rax
	movq	%rax, ___variavelTemporaria_13___(%rip)

#TAC ASS
	movq	%rax, b(%rip)



#TAC GE
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jl	.LogicLabel__2
	movq	$1, ___variavelTemporaria_14___(%rip)
	jmp	.LogicLabel__3
.LogicLabel__2:
	movq	$0, ___variavelTemporaria_14___(%rip)
.LogicLabel__3:

#TAC JZ
	movq	___variavelTemporaria_14___(%rip), %rax

	movq	$0, %rdx

	cmpq	%rax, %rdx
	jz	___Label_0___



___Label_0___:


#TAC LE
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jg	.LogicLabel__4
	movq	$1, ___variavelTemporaria_16___(%rip)
	jmp	.LogicLabel__5
.LogicLabel__4:
	movq	$0, ___variavelTemporaria_16___(%rip)
.LogicLabel__5:

#TAC JZ
	movq	___variavelTemporaria_16___(%rip), %rax

	movq	$0, %rdx

	cmpq	%rax, %rdx
	jz	___Label_1___



___Label_1___:


#TAC GRE
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jle	.LogicLabel__6
	movq	$1, ___variavelTemporaria_18___(%rip)
	jmp	.LogicLabel__7
.LogicLabel__6:
	movq	$0, ___variavelTemporaria_18___(%rip)
.LogicLabel__7:

#TAC JZ
	movq	___variavelTemporaria_18___(%rip), %rax

	movq	$0, %rdx

	cmpq	%rax, %rdx
	jz	___Label_2___



___Label_2___:


#TAC LES
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jge	.LogicLabel__8
	movq	$1, ___variavelTemporaria_20___(%rip)
	jmp	.LogicLabel__9
.LogicLabel__8:
	movq	$0, ___variavelTemporaria_20___(%rip)
.LogicLabel__9:

#TAC JZ
	movq	___variavelTemporaria_20___(%rip), %rax

	movq	$0, %rdx

	cmpq	%rax, %rdx
	jz	___Label_3___



___Label_3___:


#TAC EQ
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	cmpq	%rax, %rdx
	jne	.LogicLabel__10
	movq	$1, ___variavelTemporaria_22___(%rip)
	jmp	.LogicLabel__11
.LogicLabel__10:
	movq	$0, ___variavelTemporaria_22___(%rip)
.LogicLabel__11:

#TAC JZ
	movq	___variavelTemporaria_22___(%rip), %rax

	movq	$0, %rdx

	cmpq	%rax, %rdx
	jz	___Label_4___



___Label_4___:


#TAC AND
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	testq	%rdx, %rdx
	je	.LogicLabel__12
	testq	%rax, %rax
	je	.LogicLabel__12
	movq	$1, ___variavelTemporaria_24___(%rip)
	jmp	.LogicLabel__13
.LogicLabel__12:
	movq	$0, ___variavelTemporaria_24___(%rip)
.LogicLabel__13:

#TAC JZ
	movq	___variavelTemporaria_24___(%rip), %rax

	movq	$0, %rdx

	cmpq	%rax, %rdx
	jz	___Label_5___



___Label_5___:


#TAC OR
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	testq	%rdx, %rdx
	jne	.LogicLabel__14
	testq	%rax, %rax
	je	.LogicLabel__15
.LogicLabel__14:
	movq	$1, ___variavelTemporaria_26___(%rip)
	jmp	.LogicLabel__16
.LogicLabel__15:
	movq	$0, ___variavelTemporaria_26___(%rip)
.LogicLabel__16:

#TAC JZ
	movq	___variavelTemporaria_26___(%rip), %rax

	movq	$0, %rdx

	cmpq	%rax, %rdx
	jz	___Label_6___



___Label_6___:


#TAC ADD
	movq	a(%rip), %rdx
	movq	b(%rip), %rax
	addq	%rdx, %rax
	movq	%rax, ___variavelTemporaria_28___(%rip)

#TAC RETURN
	movq	___variavelTemporaria_28___(%rip), %rax

	popq	%rbp
	ret

	popq	%rbp
	ret


#FIM DO PROGRAMA
