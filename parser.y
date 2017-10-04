%{
	#include <stdlib.h>
	#include <stdio.h>
	int yyparse();
	int yylex();
	int yyerror(char *msg);
%}
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
%token TK_IDENTIFIER
%token LIT_INTEGER
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING
%token TOKEN_ERROR

%left '!' OPERATOR_AND OPERATOR_OR
%left OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%left '+' '-'
%left '*' '/'

%%
program : stmts
	;

stmts	: stmt ';' stmts
	|
	;

stmt	: TK_IDENTIFIER ':' type '=' expr
	| TK_IDENTIFIER ':' type '[' LIT_INTEGER ']' optinit
	| TK_IDENTIFIER '=' expr
	| TK_IDENTIFIER '[' expr ']' '=' expr
	| '(' type ')' TK_IDENTIFIER '(' ')' stmt
	| KW_IF '('expr')'KW_THEN stmts optelse
	| KW_WHILE '(' expr ')' stmt
	| KW_FOR '(' expr ';' expr ';' expr ')'
	| KW_READ expr
	| KW_RETURN expr
	| KW_PRINT expr
	| '{'stmts'}'
	;

type	: KW_BYTE
	| KW_SHORT
	| KW_LONG
	| KW_FLOAT
	| KW_DOUBLE
	;

literal : LIT_INTEGER
	| LIT_REAL
	| LIT_CHAR
	;

expr	: expr '+' expr
	| expr '-' expr
	| expr '*' expr
	| expr '/' expr
	| expr OPERATOR_AND expr
	| expr OPERATOR_OR expr
	| expr OPERATOR_NE expr
	| expr OPERATOR_EQ expr
	| expr OPERATOR_LE expr
	| expr OPERATOR_GE expr
	| literal
	| LIT_STRING
	| TK_IDENTIFIER
	| TK_IDENTIFIER '[' expr ']'
	| '(' expr ')'
	|
	;

optinit	: literal optinit
	|
	;

optelse	: KW_ELSE stmts
	| 
	;
%%
