etapa1: lex.yy.o hash.o
	gcc -Wall -o etapa1 lex.yy.o hash.o
hash.o: hash.c
	gcc -Wall -c hash.c
lex.yy.o: lex.yy.c
	gcc -Wall -c lex.yy.c
lex.yy.c: scanner.l
	lex scanner.l
clean:
	rm *.o lex.yy.c etapa1
