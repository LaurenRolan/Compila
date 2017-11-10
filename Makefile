etapa4: hash.o astree.o y.tab.o lex.yy.o semantic.o
	gcc -Wall -o etapa4 hash.o astree.o y.tab.o lex.yy.o semantic.o
y.tab.o: y.tab.c
	gcc -c y.tab.c
hash.o: hash.c
	gcc -Wall -c hash.c
astree.o: astree.c
	gcc -Wall -c astree.c
semantic.o: semantic.c
	gcc -Wall -c semantic.c
lex.yy.o: lex.yy.c
	gcc -Wall -c lex.yy.c
lex.yy.c: scanner.l
	lex scanner.l
y.tab.c: parser.y
	yacc -d parser.y
clean:
	rm *.o lex.yy.c y.tab.c y.tab.h etapa4
