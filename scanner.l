%{
	//Feito por 
	//Lauren Silva Rolan Sampaio
	//Nicolas Eymael da Silva

	#include "hash.h"
	#include "astree.h"
	#include "y.tab.h"
	#include <stdio.h>
	
	int lineNumber = 1;
	int running = 1;

	//extern int yyparser();	
	void initMe(void);
	int isRunning(void);
	int getLineNumber(void);
%}

%x COMMENT

%%

"byte"		return KW_BYTE;
"short"		return KW_SHORT;
"long"		return KW_LONG;
"float"		return KW_FLOAT;
"double"	return KW_DOUBLE;
"if"		return KW_IF;
"then"		return KW_THEN;
"else"		return KW_ELSE;
"while"		return KW_WHILE;
"for"		return KW_FOR;
"read"		return KW_READ;
"return"	return KW_RETURN;
"print"		return KW_PRINT;

[-+*;()=,:{}/<>!&$#\[\]]		return yytext[0];

[ \t\r]		{}
"\n"		lineNumber++;

"<="		return OPERATOR_LE;
">="		return OPERATOR_GE;
"=="		return OPERATOR_EQ;
"!="		return OPERATOR_NE;
"&&"		return OPERATOR_AND;
"||"		return OPERATOR_OR;

"//".*		{}

"/*" 		BEGIN(COMMENT);

<COMMENT>.			{}
<COMMENT>\n			{lineNumber = lineNumber+1;}
<COMMENT>"*/"		{BEGIN(INITIAL);}



[a-zA-Z_]([a-zA-Z_ 0-9]*[a-zA-Z0-9_])?	{	
						yylval.symbol = hashInsert(SYMBOL_ID, yytext);
						return TK_IDENTIFIER;
					}
[0-9]+					{
						yylval.symbol = hashInsert(SYMBOL_LIT_INT, yytext);
						return LIT_INTEGER;
					}
([0-9]*\.[0-9]+)			{
						yylval.symbol = hashInsert(SYMBOL_LIT_REAL, yytext);
						return LIT_REAL;
					}
(')[^']?(')				{
						yylval.symbol = hashInsert(SYMBOL_LIT_CHAR, yytext);
						return LIT_CHAR;
					}
(\")([^\"]*|[.(\\\")]*)(\")		{
						yylval.symbol = hashInsert(SYMBOL_LIT_STRING, yytext);
						return LIT_STRING;
					}


.					return TOKEN_ERROR;

%%

	#include "main.c"
	
int yywrap()
{
	running = 0;
	return 1;
}

int getLineNumber()
{
	return lineNumber;
}

void initMe()
{
	hashInit();
	running = 1;
}

int isRunning()
{
	return running;
}

int yyerror(FILE *fileout, char *msg)
{
	printf("%s at line %d\n", msg, getLineNumber());
	exit(3);
}
