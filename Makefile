etapa3: hash.o astree.o y.tab.o lex.yy.o
	gcc -Wall -o etapa3 hash.o astree.o y.tab.o lex.yy.o
y.tab.o: y.tab.c
	gcc -c y.tab.c
hash.o: hash.c
	gcc -Wall -c hash.c
astree.o: astree.c
	gcc -Wall -c astree.c
lex.yy.o: lex.yy.c
	gcc -Wall -c lex.yy.c
lex.yy.c: scanner.l
	lex scanner.l
y.tab.c: parser.y
	yacc -d parser.y
clean:
	rm *.o lex.yy.c y.tab.c y.tab.h etapa3
