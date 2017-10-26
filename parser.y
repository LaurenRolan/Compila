%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "hash.h"
	int yyparse();
	int yylex();
	int yyerror(char *msg);
%}
%union {
	HASH_NODE *symbol;
}

%token KW_BYTE
%token KW_SHORT
%token KW_LONG
%token KW_FLOAT
%token KW_DOUBLE
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_FOR
%token KW_READ
%token KW_RETURN
%token KW_PRINT
%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_NE
%token OPERATOR_AND
%token OPERATOR_OR
%token <symbol> TK_IDENTIFIER
%token <symbol> LIT_INTEGER
%token <symbol> LIT_REAL
%token <symbol> LIT_CHAR
%token <symbol> LIT_STRING
%token TOKEN_ERROR

%left '!' OPERATOR_AND OPERATOR_OR
%left OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE '>' '<'
%left '+' '-'
%left '*' '/'

%%

program : stmtlist
		;
	
stmtlist	: stmt stmtlist
			|
			;
stmt	: TK_IDENTIFIER ':' type '=' literal ';'			
		| TK_IDENTIFIER ':' type '[' LIT_INTEGER ']' optinit ';'
		| '(' type ')' TK_IDENTIFIER '(' paramlist ')' block
		;

cmdlist	: cmd optcmd
		;

optcmd 	: ';' cmd optcmd
		| 
		;

cmd	: TK_IDENTIFIER '=' expr
	| TK_IDENTIFIER '[' expr ']' '=' expr
	| KW_IF '('expr')' KW_THEN cmd optelse
	| KW_WHILE '(' expr ')' cmd
	| KW_FOR '(' expr ';' expr ';' expr ')' cmd
	| KW_READ '>' TK_IDENTIFIER
	| KW_RETURN expr
	| KW_PRINT printlist
	| block
	|
	;

block	: '{'cmdlist'}'
		;

type	: KW_BYTE
		| KW_SHORT
		| KW_LONG
		| KW_FLOAT
		| KW_DOUBLE
		;

literal : LIT_INTEGER			{fprintf(stderr, "Imprimindo: %s\n", $1->text);}
		| LIT_REAL		{fprintf(stderr, "Imprimindo: %s\n", $1->text);}
		| LIT_CHAR		{fprintf(stderr, "Imprimindo: %s\n", $1->text);}
		;

expr	: TK_IDENTIFIER			{fprintf(stderr, "Imprimindo: %s\n", $1->text);}
		| expr '+' expr
		| expr '-' expr
		| expr '*' expr
		| expr '/' expr
		| expr '<' expr
		| expr '>' expr
		| expr OPERATOR_AND expr
		| expr OPERATOR_OR expr
		| expr OPERATOR_NE expr
		| expr OPERATOR_EQ expr
		| expr OPERATOR_LE expr
		| expr OPERATOR_GE expr
		| literal
		| TK_IDENTIFIER '[' expr ']'
		| '(' expr ')'
		| TK_IDENTIFIER '(' arglist ')'
		| '!' expr
		;

optinit	: literal optinit
		|
		;

optelse	: KW_ELSE cmd
		| 
		;
printlist:	printparam optprint
		;

printparam	: LIT_STRING
		| expr
		; 

optprint	: ',' printparam optprint
			|
			;
	
paramlist: 	param optparam
			|
			;
		
optparam	: ',' param optparam
			| 
			;
			
param	: TK_IDENTIFIER ':' type
		;

arglist	: expr optarglist
		| 
		;
		
optarglist	:	',' expr optarglist
 			| 
			;
%%


