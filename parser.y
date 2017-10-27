%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "hash.h"
	#include "astree.h"

	int yyparse();
	int yylex();
	int yyerror(char *msg);
%}
%union {
	AST *ast;
	HASH_NODE *symbol;
}

%token <symbol> KW_BYTE
%token <symbol> KW_SHORT
%token <symbol> KW_LONG
%token <symbol> KW_FLOAT
%token <symbol> KW_DOUBLE
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

%type <ast> expr
%type <ast> cmdlist
%type <ast> literal
%type <ast> cmd
%type <ast> type
%type <ast> optinit
%type <ast> optelse
%type <ast> printlist
%type <ast> printparam
%type <ast> optprint
%type <ast> paramlist
%type <ast> optparam
%type <ast> param
%type <ast> arglist
%type <ast> optarglist
%type <ast> block
%type <ast> stmtlist
%type <ast> stmt
%type <ast> optcmd

%%

program : stmtlist				{treePrint($1, 0);}
	;
	
stmtlist: stmt stmtlist				{$$ = astCreate(AST_CMDL, 0, $1, $2, 0, 0); /*Alterar para stmt list*/}
	|					{$$ = 0;}		
	;
stmt	: TK_IDENTIFIER ':' type '=' literal ';'			{$$ = astCreate(AST_DEC, $1, $3, $5, 0, 0);}
	| TK_IDENTIFIER ':' type '[' LIT_INTEGER ']' optinit ';'	{$$ = astCreate(AST_DEC, $1, $3, astCreate(AST_SYMBOL, $5, 0, 0, 0, 0), $7, 0);}
	| '(' type ')' TK_IDENTIFIER '(' paramlist ')' block		{$$ = astCreate(AST_DEC, $4, $2, $6, $8, 0);}
	;

cmdlist	: cmd optcmd				{$$ = astCreate(AST_CMDL, 0, $1, $2, 0, 0);}
	;

optcmd 	: ';' cmd optcmd			{$$ = astCreate(AST_CMDL, 0, $2, $3, 0, 0);}
	| 					{$$ = 0;}
	;

cmd	: TK_IDENTIFIER '=' expr		{$$ = astCreate(AST_ASS, $1, $3, 0, 0, 0);}
	| TK_IDENTIFIER '[' expr ']' '=' expr	{$$ = astCreate(AST_ASS, $1, $3, $6, 0, 0);}
	| KW_IF '('expr')' KW_THEN cmd optelse  {$$ = astCreate(AST_IF, 0, $3, $6, $7, 0);}
	| KW_WHILE '(' expr ')' cmd		{$$ = astCreate(AST_ASS, 0, $3, $5, 0, 0);}
	| KW_FOR '(' expr ';' expr ';' expr ')' cmd {$$ = astCreate(AST_ASS, 0, $3, $5, $7, $9);}
	| KW_READ '>' TK_IDENTIFIER		{$$ = astCreate(AST_READ, $3, 0, 0, 0, 0);}
	| KW_RETURN expr			{$$ = astCreate(AST_RETURN, 0, $2, 0, 0, 0);}
	| KW_PRINT printlist			{$$ = 0;}
	| block					{$$ = $1;}
	|					{$$ = 0;}
	;

block	: '{'cmdlist'}'				{$$ = $2; treePrint($2, 0);}
	;

type	: KW_BYTE		{$$ = astCreate(AST_BYTE, $1, 0, 0, 0, 0);}
	| KW_SHORT		{$$ = astCreate(AST_SHORT, $1, 0, 0, 0, 0);}
	| KW_LONG		{$$ = astCreate(AST_LONG, $1, 0, 0, 0, 0);}
	| KW_FLOAT		{$$ = astCreate(AST_FLOAT, $1, 0, 0, 0, 0);}
	| KW_DOUBLE		{$$ = astCreate(AST_DOUBLE, $1, 0, 0, 0, 0);}
	;

literal : LIT_INTEGER		{$$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
	| LIT_REAL		{$$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
	| LIT_CHAR		{$$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
	;

expr	: TK_IDENTIFIER			{$$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
	| expr '+' expr			{$$ = astCreate(AST_ADD, 0, $1, $3, 0, 0);}
	| expr '-' expr			{$$ = astCreate(AST_SUB, 0, $1, $3, 0, 0);}
	| expr '*' expr			{$$ = astCreate(AST_MUL, 0, $1, $3, 0, 0);}
	| expr '/' expr			{$$ = astCreate(AST_DIV, 0, $1, $3, 0, 0);}
	| expr '<' expr			{$$ = astCreate(AST_LES, 0, $1, $3, 0, 0);}
	| expr '>' expr			{$$ = astCreate(AST_GRE, 0, $1, $3, 0, 0);}
	| expr OPERATOR_AND expr	{$$ = astCreate(AST_AND, 0, $1, $3, 0, 0);}
	| expr OPERATOR_OR expr		{$$ = astCreate(AST_OR, 0, $1, $3, 0, 0);}
	| expr OPERATOR_NE expr		{$$ = astCreate(AST_NE, 0, $1, $3, 0, 0);}
	| expr OPERATOR_EQ expr 	{$$ = astCreate(AST_EQ, 0, $1, $3, 0, 0);}
	| expr OPERATOR_LE expr 	{$$ = astCreate(AST_LE, 0, $1, $3, 0, 0);}
	| expr OPERATOR_GE expr 	{$$ = astCreate(AST_GE, 0, $1, $3, 0, 0);}
	| literal			{$$ = $1;}
	| TK_IDENTIFIER '[' expr ']'	{$$ = astCreate(AST_VEC, $1, $3, 0, 0, 0);}
	| '(' expr ')'			{$$ = astCreate(AST_PAR, 0, $2, 0, 0, 0);}
	| TK_IDENTIFIER '(' arglist ')'	{$$ = astCreate(AST_FUN, $1, $3, 0, 0, 0);}
	| '!' expr			{$$ = astCreate(AST_NOT, 0, $2, 0, 0, 0);}
	;

optinit	: literal optinit		{$$ = astCreate(AST_LIST, 0, $1, $2, 0, 0);}
	|				{$$ = 0;}
	;

optelse	: KW_ELSE cmd			{$$ = $2;}
	| 				{$$ = 0;}
	;
printlist:	printparam optprint	{$$ = astCreate(AST_LIST, 0, $1, $2, 0, 0);}
		;

printparam	: LIT_STRING		{$$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
		| expr			{$$ = $1;}
		; 

optprint	: ',' printparam optprint	{$$ = astCreate(AST_LIST, 0, $2, $3, 0, 0);}
		|				{$$ = 0;}
		;
	
paramlist: 	param optparam		{$$ = astCreate(AST_LIST, 0, $1, $2, 0, 0);}
		|			{$$ = 0;}
		;
		
optparam	: ',' param optparam 	{$$ = astCreate(AST_LIST, 0, $2, $3, 0, 0);}
		| 			{$$ = 0;}
		;
			
param	: TK_IDENTIFIER ':' type	{$$ = astCreate(AST_PARAM, $1, $3, 0, 0, 0);}
	;

arglist	: expr optarglist		{$$ = astCreate(AST_LIST, 0, $1, $2, 0, 0);}
	| 				{$$ = 0;}
	;
		
optarglist	:	',' expr optarglist 	{$$ = astCreate(AST_LIST, 0, $2, $3, 0, 0);}
 		| 				{$$ = 0;}
		;
%%


