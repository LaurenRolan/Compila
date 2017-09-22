%{
	int yylex();
	int yyerror(char *msg);
%}
%token TK_ID

%%
program: TK_ID;

%%
int yyerror(char *msg)
{
	exit(3);
}
