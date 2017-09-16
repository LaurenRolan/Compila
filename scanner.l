%{
	#include "hash.h"
	#include "tokens.h"
	#include <stdio.h>
%}

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


"<="		return OPERATOR_LE;
">="		return OPERATOR_GE;
"=="		return OPERATOR_EQ;
"!="		return OPERATOR_NE;
"&&"		return OPERATOR_AND;
"||"		return OPERATOR_OR;

<<EOF>>		return 0;

[a-zA-Z_][a-zA-Z_0-9]*		{	
								hashInsert(TK_IDENTIFIER, yytext);
								return TK_IDENTIFIER;
							}
[0-9]+						return 700;
([0-9]*\.[0-9]+)			return 900;

%%

	#include "main.c"
int yywrap(){
	return 1;
}
