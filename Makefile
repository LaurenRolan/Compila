etapa2: y.tab.o lex.yy.o hash.o
	gcc -Wall -o etapa1 lex.yy.o hash.o
y.tab.o: y.tab.c
	gcc -c y.tab.c
hash.o: hash.c
	gcc -Wall -c hash.c
lex.yy.o: lex.yy.c
	gcc -Wall -c lex.yy.c
lex.yy.c: scanner.l
	lex scanner.l
y.tab.c: parser.y
	yacc -d parser.y
clean:
	rm *.o lex.yy.c etapa2
