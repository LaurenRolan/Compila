//Feito por Lauren Silva Rolan Sampaio
// e Nicolas Eymael da Silva
#include <stdio.h>
#include <stdlib.h>
#include "astree.h"

extern int yyparse(void);

int main(int argc, char **argv){
  if(argc < 2) {
    fprintf(stderr, "Missing file name.\n Call ./a.out file_name.\n");
    exit(1);
  }
  

  if ((yyin = fopen(argv[1], "r")))
  {
	yyparse();
  }
  
  else fprintf(stderr,"nao deu");
  
  printf("\n");
  hashPrint();
	
  return 0;
}
