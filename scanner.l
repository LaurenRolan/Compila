%{
#include "hash.h"
#include "tokens.h"
%}
%%
[a-zA-Z_][a-zA-Z_ 0-9]*          {printf("Achou o id %s\n", yytext); //Fazer coisas de identificadores}
[0-9]+                                  {printf("Achou o num %s\n", yytext);//Fazer coisas de literais inteiros}
([0-9]+)|([0-9]*\.[0-9]+)               {printf("Achou o float %s\n", yytext);//Fazer coisas de literais flutuantes}
%%
//#include "main.c"
int main(int argc, char **argv){
  FILE *fh;
  if(argc < 2) {
    fprintf(stderr, "Missing file name.\n Call ./a.out file_name.\n");
    exit(1);
  }

  if ((fh = fopen(argv[1], "r")))
        yyin = fh;
  yylex();
  return 0;
}
int yywrap(){
  return 1;
}
