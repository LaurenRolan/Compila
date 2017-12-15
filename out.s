	.data
a:
	.quad	111
	.data
b:
	.quad	222
	.data
c:
	.quad	333
	.data
d:
	.quad	1999
#STRINGS

stringgod:
	.string	"%ld"

string40:
	.string	"a = "

string103:
	.string	"Nao"

string209:
	.string	" e b = "

string229:
	.string	"/n"
#CÓDIGO

	.text
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp






	movl	$string103, %edi
	call	puts


	movl	$string40, %edi
	call	puts


	movq	a(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


	movl	$string209, %edi
	call	puts


	movq	b(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


	movq	a(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


	movq	b(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


	movq	c(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


	movq	d(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


	movl	$string229, %edi
	call	puts

	movl	$a, %esi
	movl	$stringgod, %edi
	call	__isoc99_scanf


	movq	a(%rip), %rax
	movq	%rax, %rsi
	movl	$stringgod, %edi
	call	printf


	movl	$string229, %edi
	call	puts

	popq	%rbp
	ret
#FIM DO PROGRAMA
