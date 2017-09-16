%{
	#include "hash.h"
	#include "tokens.h"
	#include <stdio.h>
%}
%%
[a-zA-Z_][a-zA-Z_ 0-9]*		printf("Achou o id %s.\n", yytext);
[0-9]+				printf("Achou o int %s.\n", yytext);
([0-9]*\.[0-9]+)		printf("Achou o float %s.\n", yytext);
%%
	#include "main.c"
int yywrap(){
	return 1;
}
